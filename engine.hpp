////////////////////////////////////////////////////////////
//
// RSD
// Copyright (C) %DATE% Benjamin Herbomez (benjamin.herbomez@gmail.com)
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

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <QObject>
#include "modules/config/config.hpp"

class Engine : public QObject
{
    Q_OBJECT
    private:
        cf::Config *mConf;
    public:
        explicit Engine(QObject *parent = 0);

        void run();


        Q_INVOKABLE cf::Config* config();
    signals:

    public slots:

};

#endif // ENGINE_HPP
