import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("rest api jokes")

   ColumnLayout{
        anchors.fill: parent
        spacing: 0

        ListView{
            id: mListView
            model: 15
            delegate: Rectangle{

                width:parent.width
                height: joketext.height + 30
                color:"beige"
                border.color: "yellowgreen"
                radius:5


                Text{
                    id:joketext

                    /*anchors{
                        left:mButton.right
                        leftMargin: 15
                        top:parent.top
                    }*/

                    width: parent.width
                    height: parent.height
                    anchors.centerIn: parent

                   // text: modelData

                    text: AppWrapper.joke
                    font.pointSize: 13
                    wrapMode: Text.wrapMode
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    color:"blue"

                    visible: false


                    font.pixelSize: 18


                    MouseArea{
                        anchors.fill: parent

                        onClicked:{
                            joketext.visible = false

                        }

                    } // finish Mouse Area

                    Connections {
                        target:AppWrapper
                        function onJokeFetched() {
                            joketext.visible = true
                        }

                    } // connection finished
                } // text finished
            }

            Layout.fillHeight: true
            Layout.fillWidth: true
         }
        Button{

            id:mButton
            text:"Fetch"
            Layout.fillWidth: true
            onClicked: {
                AppWrapper.fetchPost()
            }

        }

    }


}
