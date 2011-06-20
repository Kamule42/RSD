////////////////////////////////////////////////////////////
//
// RSD
// Copyright (C) 16/06/2011 Benjamin Herbomez (benjamin.herbomez@gmail.com)
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

#include "network.hpp"
#include "anetworkquery.hpp"

#include <QTime>
#include <iostream>

namespace nwk{
    Network::Network() : Module(){
        this->init();
    }

    void Network::init(){
        this->isRun = false;
    }

    void Network::run(){
        this->isRun = true;
        while(this->isRun){
            QTime t1 = QTime::currentTime();
            QList<ANetworkQuery*>::iterator it, end = this->mQuery.end();

            for(it = this->mQuery.begin(); it != end; ++it)
                (*it)->start();

            int diff = t1.msecsTo(QTime::currentTime());
            std::cout << diff << std::endl;
            //this->sleep();
        }
    }

    void Network::add(ANetworkQuery *q){
        this->mQuery.push_back(q);
    }
}
