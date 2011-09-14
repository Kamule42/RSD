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

#include "engine.hpp"
#include "modules/game/game.hpp"
#include "modules/network/network.hpp"

#include "modules/network/httpperiodquery.hpp"
#include "modules/network/httpquery.hpp"

Engine::Engine(QObject *parent) : QObject(parent){

}


void Engine::run(){
    nwk::HttpPeriodQuery *q = new nwk::HttpPeriodQuery("http://kamule.free.fr/RSD/API/index.php?action=ping&n=anonymous&p=4242",2);



    game::Game *game = game::Game::instance();
    if(!game->isRunning())
        game->start();

    nwk::Network *network = nwk::Network::instance();
    if(!network->isRunning())
        network->start();

    q->launch();

}
