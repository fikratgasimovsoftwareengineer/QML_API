import QtQuick
import QtQuick.Window
import com.example 1.0
import QtQuick.Controls 2.12

Window {
    id:mainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Image {
        id: imageBack
        anchors.fill:parent
        //source: "/home/fikrat/QML_API/QMl/jsonData/api.jpeg"
        source: Qt.resolvedUrl("file:///home/fikrat/QML_API/QMl/jsonData/api.jpg")

        fillMode: Image.PreserveAspectCrop
    }

    JsonHandler{
        id: jsonHandler
    }

    property var jsonDataParse: []

    function updateJsonData(){
        jsonDataParse = jsonHandler.parseJsonFile()
    }


    Column {
        anchors.centerIn: parent
        spacing: 10

        Button {
            text: "Write JSON";
            onClicked: {
                jsonHandler.writeJsonFile()
            }
        }

        Button {
            text: "Read JSON"
            onClicked: {
                var jsonData = jsonHandler.readJsonFile();
                console.log("JSON DATA", JSON.stringify(jsonData))


            }
        }
        Button {
            text: "Display JSON"
            onClicked: {
                updateJsonData()
                console.log("JSON PARSE", JSON.stringify(jsonDataParse))


            }
        }

        Button {
            text: "Send JSON"
            onClicked: {

                jsonHandler.sendJsonFile();
            }
        }
        ScrollView{
            id:mainWindowID

            Row{
                id:columns
                spacing:10
                Repeater{
                    model: jsonDataParse
                    delegate: Column{
                        spacing: 10
                        Text {

                            text: modelData.Name
                            color: "yellow"
                            font.pixelSize: 20
                        }
                        Column{
                            Repeater{
                                model:modelData.Values
                                delegate:Row{
                                    spacing:10
                                    Text {
                                        text: modelData.Name + ":"
                                        color: "red"
                                        font.pixelSize: 20
                                    }
                                    Text{
                                        text: modelData.Value

                                        color: "red"
                                        font.pixelSize: 20
                                    }
                                }

                            }
                        }

                    }

                }

            }
        }

    }


}
