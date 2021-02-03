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
            PropertyChanges {
                target: rotation
                angle: 180
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
            PropertyChanges {
                target: rotation
                angle: 0
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

    transform: Rotation {
        id: rotation
        origin.x: card.width / 2
        origin.y: card.height / 2
        axis.x: 0
        axis.y: 1
        axis.z: 0
    }

    transitions: [
        Transition {
            from: "*"
            to: "*"
            SequentialAnimation{
                NumberAnimation {
                    target: rotation
                    property: "angle"
                    duration: 1000
                    to: 90
                }
//                PropertyAnimation {
//                    target: card
//                    property: "color"
//                    duration: 0
//                }
                NumberAnimation {
                    target: rotation
                    property: "angle"
                    duration: 1000
                    to: 90
                }
            }
        }
    ]

}
