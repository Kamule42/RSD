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

#ifndef UNIT_HPP
#define UNIT_HPP

#include <QObject>

namespace cf{
    class Unit : public QObject
    {
        Q_OBJECT

        Q_PROPERTY(qint32 id READ id WRITE setId NOTIFY idChanged)
        Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
        Q_PROPERTY(qint32 pv READ pv WRITE setPv NOTIFY pvChanged)
        Q_PROPERTY(qint32 mv READ mv WRITE setMv NOTIFY mvChanged)
        Q_PROPERTY(qint32 dx READ dx WRITE setDx NOTIFY dxChanged)
        Q_PROPERTY(qint32 pr READ ml WRITE setPr NOTIFY prChanged)
        Q_PROPERTY(qint32 st READ st WRITE setSt NOTIFY stChanged)
        Q_PROPERTY(qint32 atk READ atk WRITE setAtk NOTIFY atkChanged)
        Q_PROPERTY(qint32 ml READ ml WRITE setMl NOTIFY mlChanged)
    public:
        explicit Unit(QObject *parent = 0);
        explicit Unit(Unit *c);

    private:
        qint32 m_id;
        QString m_name;
        qint32 m_pv;
        qint32 m_mv;
        qint32 m_dx;
        qint32 m_pr;
        qint32 m_st;
        qint32 m_atk;
        qint32 m_ml;

    signals:
        void idChanged();
        void nameChanged();
        void pvChanged();
        void mvChanged();
        void dxChanged();
        void prChanged();
        void stChanged();
        void atkChanged();
        void mlChanged();

    public slots:
        Q_INVOKABLE qint32 id();
        Q_INVOKABLE QString name();
        Q_INVOKABLE qint32 pv();
        Q_INVOKABLE qint32 mv();
        Q_INVOKABLE qint32 dx();
        Q_INVOKABLE qint32 pr();
        Q_INVOKABLE qint32 st();
        Q_INVOKABLE qint32 atk();
        Q_INVOKABLE qint32 ml();

        Q_INVOKABLE void setId(qint32 id);
        Q_INVOKABLE void setName(QString name);
        Q_INVOKABLE void setPv(qint32 pv);
        Q_INVOKABLE void setMv(qint32 mv);
        Q_INVOKABLE void setDx(qint32 dx);
        Q_INVOKABLE void setPr(qint32 dr);
        Q_INVOKABLE void setSt(qint32 st);
        Q_INVOKABLE void setAtk(qint32 atk);
        Q_INVOKABLE void setMl(qint32 ml);
    };
}//namespace cf
#endif // UNIT_HPP
