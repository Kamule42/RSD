import QtQuick 1.0
import Qt 4.7

Rectangle {
    id: container

    property string text: "Button"

    signal clicked

    width: 150
    height: 30
    smooth: true

    border {
        width: 1
        color: "black"
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

    Text {
        id: buttonLabel
        text: container.text
        anchors.centerIn: container
        color: "white"
        font.pixelSize: 24
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
