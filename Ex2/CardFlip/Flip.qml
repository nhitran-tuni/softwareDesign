import QtQuick 2.0

Flipable {
    id: flipable
    width: 300
    height: 500
    anchors.centerIn: parent

    property bool flipped: false
    property alias cardValueText: cardValue.text

    back: Rectangle {
        width: 300
        height: 500
        border.width: 10
        radius: 15
        color: "white"

        Text {
            id: cardValue
            anchors.centerIn: parent
            text: cardValueText
            color: "black"
            font.pointSize: 80
        }

        Image {
            id: imageFront
            anchors.top: cardValue.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            source: "cardFront.jpg"
            fillMode: Image.PreserveAspectFit
            width: 180
            height: 200
        }
    }

    front: Rectangle {
        width: 300
        height: 500
        border.width: 10
        radius: 15
        color: "black"

        Text {
            id: cardValueFront
            anchors.centerIn: parent
            text: qsTr("Click me!")
            color: "#dea5a4"
            font.pointSize: 30
        }

        Image {
            id: imageBack
            anchors.top: cardValueFront.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            source: "cardBack.jpg"
            fillMode: Image.PreserveAspectFit
            width: 180
            height: 200
        }
    }

    transform: Rotation {
        id: rotation
        origin.x: flipable.width/2
        origin.y: flipable.height/2
        axis.x: 0; axis.y: 1; axis.z: 0     // set axis.y to 1 to rotate around y-axis
        angle: 0    // the default angle
    }

    states: State {
        name: "back"
        PropertyChanges { target: rotation; angle: 180 }
        when: flipable.flipped
    }

    transitions: Transition {
        NumberAnimation { target: rotation; property: "angle"; duration: 1000 }
    }   

    MouseArea {
        id: flipCard
        anchors.fill: parent
        onClicked:
            if (flipped) {
                flipable.flipped = !flipable.flipped
            }
    }
}
