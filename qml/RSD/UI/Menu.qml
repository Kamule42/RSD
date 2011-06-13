import QtQuick 1.0
import Qt 4.7

Column {
    spacing: 10

    Button {
        id      : newGameButton
        text    : qsTr("Find game")
        //onClicked: Logic.startNewGame()
    }

    Button{
        id      : manageArmyButton
        text    : qsTr("Manage army")
    }

    Button {
        id          : exitButton
        text        : qsTr("Exit")
        onClicked   : Qt.quit()
    }
}
