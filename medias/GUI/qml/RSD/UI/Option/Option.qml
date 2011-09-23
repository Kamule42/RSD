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

import QtQuick 1.0
import Qt 4.7

import "../JS/main.js" as Controler

Rectangle{

    anchors.topMargin : parent.height * 0.15
    state : "default"

    property int textSize: 42

    OptionMain{
        id      : optionMain
        clip    : false

        textSize: parent.textSize
        opacity : 1

        anchors.top           : parent.top
        anchors.left           : parent.left
        anchors.leftMargin  : parent.width * 0.15

        Behavior on opacity {
             NumberAnimation { properties:"opacity"; duration:500 }
         }
    }

    OptionGame{
            id      : optionGame
            clip    : false
            textSize: parent.textSize
            opacity : 0

           anchors.top           : parent.top
           anchors.leftMargin  : parent.width * 0.15

            Behavior on opacity {
                 NumberAnimation { properties:"opacity"; duration:500 }
             }
    }

    states: [
        State{
            name : "default"
            AnchorChanges {
                target: optionMain
                anchors.left  : optionMain.parent.left
            }
            PropertyChanges {
                target: optionMain
                opacity    : 1
            }
            AnchorChanges {
                target: optionGame
                anchors.left  : optionMain.right
            }
            PropertyChanges {
                target: optionGame
                x: 265
                y: 0
                anchors.topMargin: 0
                opacity    : 0
            }
        },
        State{
            name :"game"
            AnchorChanges {
                target: optionMain
                anchors.right  : optionMain.right
            }
            PropertyChanges {
                target: optionMain
                opacity    : 0
            }
            AnchorChanges {
                target: optionGame
                anchors.left  : optionGame.parent.left
            }
            PropertyChanges {
                target: optionGame
                opacity    : 1
            }
        }

    ]

    transitions: [
        Transition {
            AnchorAnimation { duration: 500}
        }
    ]
}
