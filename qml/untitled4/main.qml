import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Window 2.11
import QtQuick.Controls 2.0

//Window {
//    visible: true
//    width: 640
//    height: 480
//    title: qsTr("Hello World")
//}


//Rectangle {
//    width: Screen.desktopAvailableWidth
//    height: Screen.desktopAvailableHeight
//    color: "red"
//}


//Rectangle {
//    width: 100; height: 100
//    color: "red"

//    MouseArea {
//        anchors.fill: parent
//        onClicked: console.info("Button clicked!")
//    }
//}

//Column {
//    Button { width: 50; height: 50; background: Rectangle {
//            implicitWidth: 100
//            implicitHeight: 40
//            opacity: enabled ? 1 : 0.3
//            color: "red"
//        }
//    }
//    Button { x: 50; width: 100; height: 50; background: Rectangle {
//            implicitWidth: 100
//            implicitHeight: 40
//            opacity: enabled ? 1 : 0.3
//            color: "blue"
//        }
//    }
//    Button { width: 50; height: 50; background: Rectangle {
//            implicitWidth: 100
//            implicitHeight: 40
//            opacity: enabled ? 1 : 0.3
//            color: "green"
//        }
//    }

//    Image {
//        source: "./image/11.jpg"
//        fillMode: Image.PreserveAspectFit
//    }
//}

//A file is a data type
//Rectangle { id: rect1; width: 200; height: 200; color: "red" }


import QtQuick 2.0

ListView {
    id: view
    width: 300
    height: width
    snapMode: ListView.SnapToItem
    highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
    focus: true

    delegate: Component {
        id: component
        Rectangle {
            id: wrapper
            width: 180
            height: 50
            color: ListView.isCurrentItem ? "blue" : "red"
            Text {
                elide: Text.ElideMiddle
                text: name + number
                color: wrapper.ListView.isCurrentItem ? "red" : "black"
            }
        }
    }

    model: ListModel {
        id: listmodel
        ListElement {
            name: "Bill Smith"
            number: "555 3264"
        }
        ListElement {
            name: "John Brown"
            number: "555 8426"
        }
        ListElement {
            name: "Sam Wise"
            number: "555 0473"
        }
    }

}



