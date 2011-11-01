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

#ifndef ARMY_HPP
#define ARMY_HPP

#include <QObject>
#include <QString>
 #include <QVector>


namespace cf{

    class Unit;

    class Army : public QObject{
        Q_OBJECT
        Q_PROPERTY(QString name READ name NOTIFY nameChanged)
        Q_PROPERTY(QString id READ id NOTIFY idChanged)
        Q_PROPERTY(QList<QObject*> units READ unitsObj NOTIFY unitsChanged)

        private:
            QString m_name;
            qint32 m_id;
            QVector<Unit*> m_units;

        public:
            explicit Army(QString name, qint32 id);

            Q_INVOKABLE QString name();
            Q_INVOKABLE qint32 id();
            Q_INVOKABLE QVector<Unit*> units();
            Q_INVOKABLE QList<QObject*> unitsObj();

        signals:
             void nameChanged();
             void idChanged();
             void unitsChanged();

        public slots:
             void addUnit(Unit *u);
    };
}
#endif // ARMY_HPP
