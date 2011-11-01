import QtQuick 1.0
import Qt 4.7
import com.nokia.symbian 1.0

    Item {
             id : combobox
             property string title: "Test"
             property string subTitle: selectBox.selectedIndex >= 0
                       ? selectBox.model.get(selectBox.selectedIndex).name
                       : selectBox.titleText
             width   : Math.max(200,titleText.width + selectText.width)
             height  : background.textSize*1.5
             property variant model ;


            signal clicked

             BorderImage {
                 id : comboBorder
                 width:parent.width
                 height: parent.height
                 border { left: 20; top: 20; right: 9; bottom: 9 }
                 horizontalTileMode: BorderImage.Repeat
                 verticalTileMode: BorderImage.Repeat
                 source: "button.png"
             }

            Item{
                width   : titleText.width + selectText.width
                height  : background.textSize
                anchors.centerIn: parent
                //anchors.centerIn: parent

                Text {
                    id: titleText
                    text: parent.parent.title + " : "
                    anchors.left: parent.left
                    anchors.top: parent.top
                    color: "white"
                    font.pixelSize: background.textSize
                }

                Text {
                    id: selectText
                    text: parent.parent.title
                    anchors.right: parent.right
                    anchors.top: parent.top
                    color: "white"
                    font.pixelSize: background.textSize
                }

                Rectangle {
                    id: selectBox
                    width   : selectText.width

                    color : "green"

                    anchors.top: selectText.bottom
                    anchors.left: selectText.left


                    property string titleText: "Select one of the values"
                    property int selectedIndex: -1
                    property variant model: parent.model

                    ListView {
                        id: comboElements
                        model: parent.model
                        anchors.top : parent.top
                        anchors.left: parent.left
                        delegate: Text {
                             text: name + ": " + number
                         }
                    }
                }
             }

             MouseArea {
                 id: mouseArea
                 smooth: true
                 anchors.fill: parent
                 onClicked: parent.clicked()
                 hoverEnabled: true
             }



             onClicked: selectionDialog.open()

         }

