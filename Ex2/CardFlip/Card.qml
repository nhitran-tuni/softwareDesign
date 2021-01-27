import QtQuick 2.12

Rectangle {
    id: card
    width: 300
    height: 500
    border.width: 10
    radius: 15
    state: "BACK"

    Text {
        id: cardValue
        anchors.centerIn: parent
        property alias cardValueText: cardValue.text
        property alias cardSize: cardValue.font.pointSize
    }

    Image {
        id: image
        anchors.top: cardValue.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        property alias imageSource: image.source
        fillMode: Image.PreserveAspectFit
        width: 180
        height: 200
    }

    states: [
        State {
            name: "BACK"
            PropertyChanges {
                target: card
                color: "black"
            }
            PropertyChanges {
                target: cardValue
                cardValueText: "CLICK ME!"
                color: "white"
                cardSize: 30
            }
            PropertyChanges {
                target: image
                imageSource: "cardBack.jpg"
            }
        },
        State {
            name: "FRONT"
            PropertyChanges {
                target: card
                color: "white"
            }
            PropertyChanges {
                target: cardValue
                cardValueText: "10"
                color: "darkred"
                cardSize: 80
            }
            PropertyChanges {
                target: image
                imageSource: "cardFront.jpg"
            }
        }
    ]

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (parent.state == "BACK") {
                parent.state = "FRONT"
            }
            else {
                parent.state = "BACK"
            }
        }
    }
}
