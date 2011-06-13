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
            x       : parent.width*0.2
            y       : 75
        }

        Title{
            id      : title
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
