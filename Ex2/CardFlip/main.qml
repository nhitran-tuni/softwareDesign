import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 300
    height: 500
    visible: true
    title: qsTr("Card Flipping")

    Flip {
        id: flipableCard
    }
}
