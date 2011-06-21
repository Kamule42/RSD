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

Rectangle {
    id: container

    property string text: "Button"
    property int textSize: 10

    signal clicked

    width   : 250
    height  : textSize*1.5
    smooth  : true

    border {
        width: 1
        color: "black"
    }

    Text {
        id: buttonLabel
        text: container.text
        anchors.centerIn: container
        color: "white"
        font.pixelSize: parent.textSize
    }


    radius: 8

    gradient: Gradient {
        GradientStop {
            id: gradientstop1
            position: 0.0
            color: "#56d5ff"
        }
        GradientStop {
            id: gradientstop2
            position: 0.1
            color: "#564eff"
        }
        GradientStop {
            id: gradientstop3
            position: 1.0
            color: "#122c6e"
        }

    }

    MouseArea {
        id: mouseArea
        smooth: true
        anchors.fill: parent
        onClicked: container.clicked()
        hoverEnabled: true
    }


    states: [
        State {
            name: "over"
            when: mouseArea.containsMouse == true

            PropertyChanges {
                target: gradientstop1
                position: 0
                color: "#122c6e"
            }

            PropertyChanges {
                target: gradientstop2
                position: 0.3
                color: "#56d5ff"
            }

            PropertyChanges {
                target: gradientstop3
                position: 1
                color: "#122c6e"
            }

        },
        State {
            name: "pressed"
            PropertyChanges {
                target: gradientstop1
                position: 0
                color: "#56d5ff"
            }

            PropertyChanges {
                target: gradientstop2
                position: 1
                color: "#122c6e"
            }

            PropertyChanges {
                target: gradientstop3
                position: "1"
                color: "#122c6e"
            }
        }
    ]
    transitions: [
         Transition {
             from: ""; to: "pressed"; reversible: true
             ParallelAnimation {
                 ColorAnimation { duration: 30 }
             }
         }
    ]
}
