import QtQuick 1.0



Text {

    FontLoader {
        id: localFont
        source: "./DARK11__.ttf"
    }

    text: "Rhapsody for the Scarlet Devil"

    font{
        family: localFont.name
        pointSize: 42
        capitalization: Font.Capitalize
    }
}
