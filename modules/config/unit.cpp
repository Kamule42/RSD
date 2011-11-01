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

#include "unit.hpp"

namespace cf{
    Unit::Unit(QObject *parent) :  QObject(parent){
        this->m_id = -1;
        this->m_pv = -1;
        this->m_mv = -1;
        this->m_dx = -1;
        this->m_pr = -1;
        this->m_st = -1;
        this->m_atk = -1;
        this->m_ml = -1;
    }

    Unit::Unit(Unit *c) : QObject(0){
        this->m_id = c->id();
        this->m_pv = c->pv();
        this->m_mv = c->mv();
        this->m_dx = c->dx();
        this->m_pr = c->pr();
        this->m_st = c->st();
        this->m_atk = c->atk();
        this->m_ml = c->ml();
    }

    qint32 Unit::id(){ return m_id;}
    QString Unit::name(){ return m_name;}
    qint32 Unit::pv(){ return m_pv;}
    qint32 Unit::mv(){ return m_mv;}
    qint32 Unit::dx(){ return m_dx;}
    qint32 Unit::pr(){ return m_pr;}
    qint32 Unit::st(){ return m_st;}
    qint32 Unit::atk(){ return m_atk;}
    qint32 Unit::ml(){ return m_ml;}

    void Unit::setId(qint32 id){ m_id = id;}
    void Unit::setName(QString name){ m_name = name;}
    void Unit::setPv(qint32 pv){ m_pv = pv;}
    void Unit::setMv(qint32 mv){ m_mv = mv;}
    void Unit::setDx(qint32 dx){ m_dx = dx;}
    void Unit::setPr(qint32 pr){ m_pr = pr;}
    void Unit::setSt(qint32 st){ m_st = st;}
    void Unit::setAtk(qint32 atk){ m_atk = atk;}
    void Unit::setMl(qint32 ml){ m_ml = ml;}
}
