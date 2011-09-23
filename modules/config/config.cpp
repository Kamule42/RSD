////////////////////////////////////////////////////////////
//
// RSD
// Copyright (C) 20/09/2011 Benjamin Herbomez (benjamin.herbomez@gmail.com)
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

#include "config.hpp"
#include "armyfactory.hpp"


#include <QtXml/QDomDocument>
#include "utils.hpp"

#include <QDebug>

namespace cf{
    Config::Config(){
        this->init();
    }

    QList<QObject*> Config::armyList(){
        return this->m_mArmyList;
    }

    void Config::init(){
        QDomElement root;
        try{
            root = Utils::openXml(":/Army/list.xml");
        }
        catch(...){
            return;
        }

        if(root.tagName() != "list")
            throw tr("Fichier mal formaté");
        QDomNode n = root.firstChild();

        ArmyFactory *factory = new ArmyFactory();

        while(!n.isNull()){
            QDomElement e = n.toElement();
            if(e.tagName() == "army" && e.nodeType() == QDomNode::ElementNode && e.childNodes().count()  == 1){
                QString ids =  e.attribute("id","");
                if(ids == "") //No id, and we need it !
                    continue;

                bool ok;
                qint32 id = ids.toInt(&ok);
                if(!ok) //it's not and Int
                    continue;

                this->m_mArmyList.push_back( factory->getArmy(e.text(),id));
            }

            n = n.nextSibling();
        }

    }
}//namespace cf
