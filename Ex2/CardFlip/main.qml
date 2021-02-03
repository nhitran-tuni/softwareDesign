import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15

Window {
    width: 500
    height: 900
    visible: true
    color: "#FFF7F8"
    title: qsTr("Card Flipping")

    Flip {
        id: flipableCard
    }

    Row {
        id: rowButton
        spacing: 10
        anchors.top: flipableCard.bottom
        anchors.horizontalCenter: flipableCard.horizontalCenter
        anchors.topMargin: 40

        Button {
            id: bigButton
            text: "BIG"
            onClicked: {
                if (!flipableCard.flipped) {
                    flipableCard.flipped = !flipableCard.flipped
                    flipableCard.cardValueText = back.cardValueGet()
                    if (back.compare(false)) {
                        right.text = Number(right.text) + 1
                        guessStatus.text = "Correct"
                        guessStatus.color= "darkgreen"
                    } else {
                        wrong.text = Number(wrong.text) + 1
                        guessStatus.text = "Incorrect"
                        guessStatus.color= "darkred"
                    }
                }
            }
        }

        Button {
            id: smallButton
            text: "SMALL"
            onClicked: {
                if (!flipableCard.flipped) {
                    flipableCard.flipped = !flipableCard.flipped
                    flipableCard.cardValueText = back.cardValueGet()
                    if (back.compare(true)) {
                        right.text = Number(right.text) + 1
                        guessStatus.text = "Correct"
                        guessStatus.color= "darkgreen"
                    } else {
                        wrong.text = Number(wrong.text) + 1
                        guessStatus.text = "Incorrect"
                        guessStatus.color= "darkred"
                    }
                }
            }
        }
    }

    Button {
        id: restart
        text: "RESTART"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: rowButton.bottom
        anchors.topMargin: 20
        onClicked: {
            if (flipableCard.flipped) {
                flipableCard.flipped = !flipableCard.flipped
            }
            right.text = Number(0)
            wrong.text = Number(0)
            guessStatus.text =""
        }
    }

    Row {
        id: rowScore
        spacing: 10
        anchors.bottom: flipableCard.top
        anchors.horizontalCenter: flipableCard.horizontalCenter
        anchors.bottomMargin: 35


        Rectangle {
            width: 70
            height: 60
            color: "#FFF7F8"
            Text {
                id: rightText
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("Correct:")
                color: "darkgreen"
            }
            Text {
                id: right
                anchors.centerIn: parent
                text: qsTr("0")
                color: "darkgreen"
                font.pointSize: 20
            }
        }

        Rectangle {
            width: 70
            height: 60
            color: "#FFF7F8"
            Text {
                id: wrongText
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("Incorrect:")
                color: "darkred"
            }
            Text {
                id: wrong
                anchors.centerIn: parent
                text: qsTr("0")
                color: "darkred"
                font.pointSize: 20
            }
        }
    }

    Text {
        id: guessStatus
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: rowScore.top
        font.pointSize: 50
    }


}
