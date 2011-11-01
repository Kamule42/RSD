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

#include "army.hpp"
#include <QDebug>

namespace cf{
    Army::Army(QString name, qint32 id) :  QObject(){
        this->m_name = name;
        this->m_id       = id;
    }

    QString  Army::name(){
        return this->m_name;
    }

    qint32 Army::id(){
        return this->m_id;
    }

    QVector<Unit*>  Army::units(){
        return this->m_units;
    }

    QList<QObject*>  Army::unitsObj(){
        QList<QObject*> r;
        int i, j = this->m_units.size();
        for(i=0;i < j;++i){
            r.push_back(reinterpret_cast<QObject *>(this->m_units[i]));
        }
        return r;
    }

    void Army::addUnit(Unit *u){
        this->m_units.push_back(u);
        emit unitsChanged();
    }

}
