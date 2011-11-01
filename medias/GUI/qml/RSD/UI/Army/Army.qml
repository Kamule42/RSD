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
import QtDesktop 0.1

import com.rsd.config 1.0

import "../"

Rectangle {

    property int textSize: 42


    anchors.fill: parent


    Rectangle{

        width: 200
        height : 100

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        id:armyLeftPanel

        /*ListView {
            id: listArmy
            model: cppArmyList
            anchors.top: parent.top
            anchors.bottom: optionReturnButton.top
            delegate:
                Button {
                    text    : model.modelData.name
                    onClicked: {
                        listUnits.model = model.modelData.units;
                    }
                }
        }*/

        ComboBox{
            anchors.top: parent.top
            /*model:cppArmyList*/
            model: ListModel {
                     ListElement { name: "Helsinki" }
                     ListElement { name: "Oulu" }
                     ListElement { name: "Rovaniemi" }
                     ListElement { name: "Tampere" }
                     ListElement { name: "Vaasa" }
                 }
        }


        Button {
            id      : optionReturnButton
            text    : qsTr("Retour")

            anchors.bottom: parent.bottom
            anchors.bottomMargin: background.height*0.07

            onClicked: main.state = "default"

        }
    }

    Rectangle{
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: armyLeftPanel.right
        color : "red"
        width : 100

        ListView {
            id: listUnits
            anchors.fill: parent
            delegate:
                Button {
                    text    : model.modelData.name
                }
        }
    }

}
