////////////////////////////////////////////////////////////
//
// RSD
// Copyright (C) 23/09/2011 Benjamin Herbomez (benjamin.herbomez@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#include "armyfactory.hpp"
#include "army.hpp"
#include "unit.hpp"

#include <QtXml/QDomDocument>
#include "utils.hpp"

#include <QDebug>

namespace cf{
    ArmyFactory::ArmyFactory(QObject *parent) : QObject(parent){
        this->loadSectionNames();
    }


     void ArmyFactory::loadSectionNames(){
         QDomElement root;
         try{
             root = Utils::openXml(":/Army/section.xml");
         }
         catch(...){
             return;
         }

         if(root.tagName() != "sections")
             throw tr("Fichier mal formaté");

         QDomNode n = root.firstChild();

         while(!n.isNull()){
             QDomElement e = n.toElement();
             if(e.tagName() == "section"){
                 bool ok;
                 qint32 id =e.attribute("id","-1").toInt(&ok);
                 if(!ok)
                     id = -1;
                 this->m_sectionsNames.insert(id,e.text());
             }

              n = n.nextSibling();
          }
     }

    Army* ArmyFactory::getArmy(QString name, qint32 id){
        Army *r = new Army(name,id);
        this->loadArmyUnits(r);
        return r;
    }

     void ArmyFactory::loadArmyUnits(Army *army){
        QDomElement root;
        try{
            root = Utils::openXml(":/Army/"+QString::number(army->id())+".xml");
        }
        catch(...){
            return;
        }

        if(root.tagName() != "army")
            throw tr("Fichier mal formaté");

        QDomNode n = root.firstChild();

        Unit *caracBase;

        while(!n.isNull()){
            QDomElement e = n.toElement();
            if(e.tagName() == "caracBase"){
                caracBase = this->getCarac(&e);
            }
            else if(e.tagName() == "unit"){
                army->addUnit(this->getUnit(&e,caracBase));
            }

             n = n.nextSibling();
         }

     }

     Unit* ArmyFactory::getCarac(QDomElement *caracNode, Unit *def){
        Unit *r =def;
        if(r == 0)
             r = new Unit();
        QDomNode n = caracNode->firstChild();
        while(!n.isNull()){
            QDomElement e = n.toElement();

            QString name   =  e.attribute("name","");
            bool ok;
            qint32 v            = e.attribute("value","-1").toInt(&ok);

            if(ok){
                if(name == "pv")
                    r->setPv(v);
                else if(name == "mv")
                    r->setMv(v);
                else if(name == "dx")
                    r->setDx(v);
                else if(name == "st")
                    r->setSt(v);
                else if(name == "atk")
                    r->setAtk(v);
                else if(name == "ml")
                    r->setMl(v);
            }
            n = n.nextSibling();
        }

        return r;
     }

     Unit* ArmyFactory::getUnit(QDomElement *unitNode, Unit* def){
         Unit *r = new Unit(def);
        QString type = "";

        QDomNode n = unitNode->firstChild();
        while(!n.isNull()){
            QDomElement e = n.toElement();
            if(e.tagName() == "id")
                r->setId(e.text().toInt());
            else if(e.tagName() == "name")
                r->setName(e.text());
            else if(e.tagName() == "type")
                type = e.text();
            else if(e.tagName() == "caracs"){
                this->getCarac(&e,r);
            }
            n = n.nextSibling();
        }

        return r;
     }

}//namespace cf
