import QtQuick 2.9
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Tabs")

//    SwipeView {
//        id: swipeView
//        anchors.fill: parent
//        currentIndex: tabBar.currentIndex

//        Page1Form {
//        }

//        Page2Form {
//        }
//    }

    SwipeView {
        id: view
        anchors.fill: parent
        currentIndex: view.currentIndex
        Repeater {
            model: 6
            Loader {
                active: SwipeView.isCurrentItem || SwipeView.isNextItem || SwipeView.isPreviousItem
                sourceComponent: Text {
                    text: index
                    color: "white"
                    anchors.centerIn: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 20
                    Component.onCompleted: console.info("created:", index)
                    Component.onDestruction: console.warn("destroyed:", index)
                }
            }
        }
    }

    PageIndicator {
        id: indicator

        count: view.count
        currentIndex: view.currentIndex

        anchors.bottom: view.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }

//    footer: TabBar {
//        id: tabBar
//        currentIndex: swipeView.currentIndex

//        TabButton {
//            text: qsTr("Page 1")
//        }
//        TabButton {
//            text: qsTr("Page 2")
//        }
//    }
}

//Rectangle {
//    width: 300
//    height: 300
//    color: "red"

//    SwipeView {
//        id: view
//        anchors.fill: parent
//        currentIndex: view.currentIndex

//        Item {

//        }

//        Item {

//        }
//    }

//    PageIndicator {
//         id: indicator

//         count: view.count
//         currentIndex: view.currentIndex

//         anchors.bottom: view.bottom
//         anchors.horizontalCenter: parent.horizontalCenter
//     }
//}
