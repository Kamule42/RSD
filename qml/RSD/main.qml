import Qt 4.7

import "UI"
import "JS/window.js" as Window

Item{

    width   : 1000;
    height  : 800;

    Rectangle {
        id: background
        anchors.fill: parent;
        color : "grey"


        Menu{
            clip    : false
            x       : parent.width*0.2
            y       : 75
        }
    }
}
