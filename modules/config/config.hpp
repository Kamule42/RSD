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

#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <QObject>
#include <QList>

#include "army.hpp"

namespace cf{
    class Config: public QObject{
        Q_OBJECT
        Q_PROPERTY(QList<QObject*> mArmyList READ armyList())

        private:
            QList<QObject*> m_mArmyList;

        public:
            Config();

            Q_INVOKABLE QList<QObject*> armyList();



        private:
            void init();


    };
} // namespace cfs
#endif // CONFIG_HPP
