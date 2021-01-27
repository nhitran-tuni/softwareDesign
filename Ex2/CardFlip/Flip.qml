import QtQuick 2.0

Flipable {
    id: flipable
    anchors.fill: parent

    property bool flipped: false

    back: Rectangle {
        width: 300
        height: 500
        border.width: 10
        radius: 15
        color: "white"

        Text {
            id: cardValueFront
            anchors.centerIn: parent
            text: qsTr("10")
            color: "black"
            font.pointSize: 80
        }

        Image {
            id: imageFront
            anchors.top: cardValueFront.bottom
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
            id: cardValueBack
            anchors.centerIn: parent
            text: qsTr("Click me!")
            color: "#dea5a4"
            font.pointSize: 30
        }

        Image {
            id: imageBack
            anchors.top: cardValueBack.bottom
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
        anchors.fill: parent
        onClicked: flipable.flipped = !flipable.flipped
    }
}
