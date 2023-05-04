import QtQuick
import QtQuick.Window
import com.example 1.0
import QtQuick.Controls 2.12
Window {
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
            text: "Send JSON"
            onClicked: {

                jsonHandler.sendJsonFile();
            }
        }
    }


}
