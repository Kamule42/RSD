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

import Qt 4.7

import "UI"

Item{

    width   : 1000;
    height  : 800;

    Rectangle {
        id: background
        anchors.fill: parent;
        color : "grey"


        Menu{
            id      : menu
            clip    : false

            textSize: parent.height * 0.04

            anchors.top           : title.bottom
            anchors.topMargin : parent.height * 0.15

            anchors.left           : parent.left
            anchors.leftMargin : parent.width * 0.09
        }

        Title{
            id                                   : title
            textSize                          : parent.height * 0.07
            anchors.top                     : parent.top
            anchors.topMargin           : 0
            anchors.horizontalCenter  : parent.horizontalCenter
        }
    }
}