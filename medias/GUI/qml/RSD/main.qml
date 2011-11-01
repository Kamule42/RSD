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
import "UI/Game"
import "UI/Army"
import "UI/Option"


Item{
    width   : 1000;
    height  : 800;
    id        : main
    state   : "default"

    Rectangle {
        id                      : background
        x                       : 0
        y                       : 0
        anchors.fill            : parent;
        color                   : "grey"
        anchors.rightMargin     : 0
        anchors.bottomMargin    : 0
        anchors.leftMargin      : 0
        anchors.topMargin       : 0

        property int textSize   : background.height * 0.025


        Title{
            id                          : title
            textSize                    : parent.height * 0.07
            anchors.top                 : parent.top
            anchors.topMargin           : 0
            anchors.horizontalCenter    : parent.horizontalCenter
        }

        Rectangle {
            id      : menuBack

            anchors.top           : title.bottom
            anchors.topMargin : parent.height * 0.15

            anchors.left            : parent.left
            anchors.right          : parent.right

            anchors.bottom          : parent.bottom
            anchors.bottomMargin : parent.height * 0.15

            color : "white"

            border {
                width: 1
                color: "black"
            }

            Menu{
                id      : menu
                clip    : false

                anchors.fill: parent

               anchors.top           : parent.top
               anchors.topMargin : parent.height * 0.15

               anchors.left            : parent.left
               anchors.leftMargin  : parent.width * 0.15


                Behavior on opacity {
                     NumberAnimation { properties:"opacity"; duration:500 }
                 }
            }

            Option{
                    id      : option
                    clip    : false
                    opacity : 0

                   anchors.top           : parent.top
                   anchors.topMargin : parent.height * 0.15

                   anchors.leftMargin  : parent.width * 0.15

                   anchors.left             : menu.right

                   Behavior on opacity {
                        NumberAnimation { properties:"opacity"; duration:500 }
                    }

            }

            Army{
                    id      : army
                    clip    : false
                    textSize: parent.height * 0.04
                    opacity : 0

                   anchors.top           : parent.top
                   anchors.topMargin : parent.height * 0.15

                   anchors.left            : menu.right
                   anchors.leftMargin  : parent.width * 0.15

                   Behavior on opacity {
                        NumberAnimation { properties:"opacity"; duration:500 }
                    }
            }
        }
    }


    states: [
        State{
             name: "default"

             PropertyChanges {
                 target: option
                 width: 191
                 height: 161
             }
        },
        State {
            name: "option"
            AnchorChanges {
                target: menu
                anchors.left  : background.right
            }
            PropertyChanges {
                target: menu
                opacity    : 0
            }
            AnchorChanges {
                target: option
                anchors.left  : option.parent.left
            }
            PropertyChanges {
                target: option
                opacity    : 1
            }
        },
        State {
            name: "army"
            AnchorChanges {
                target: menu
                anchors.left  : parent.right
            }
            PropertyChanges {
                target: menu
                opacity    : 0
            }
            AnchorChanges {
                target: army
                anchors.left  : army.parent.left
            }
            PropertyChanges {
                target: army
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
