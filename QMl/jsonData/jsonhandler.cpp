#include "jsonhandler.h"

jsonHandler::jsonHandler(QObject *parent)
    : QObject{parent}
{

}



void jsonHandler::writeJsonFile()
{
    QJsonObject obj1;
    obj1.insert("Name", "Fikrat");
    obj1.insert("Surname", "Gasimov");
    obj1.insert("Age", 27);
    obj1.insert("Job", "Developer");

    QJsonObject content;
    content.insert("obj1", obj1);

    QJsonDocument document;
    document.setObject(content); //set json obj to json doc

    // convert document to bytes of order
    QByteArray bytes = document.toJson(QJsonDocument::Indented);

    filename ="/home/fikrat/QML_API/QMl/jsonData/test.json";
    // create file string
    QFile fileName(filename);

    // file string is open, write bytes to it
    if (fileName.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)){
        QTextStream istream(&fileName);

        istream.setEncoding(QStringConverter::Utf8);
        istream << bytes;
        fileName.close();
    }

    else{

        qWarning() << "Failed to open File: ", filename.toStdString();

    }
}



QJsonObject jsonHandler::readJsonFile()
{
    filename = "/home/fikrat/QML_API/QMl/jsonData/test.json";
    QFile file(filename);
    QJsonObject result;

    if(file.open(QIODevice::ReadOnly)){
        QByteArray array = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(array);
        result = doc.object();
        file.close();
    }
    else{
        qWarning() << "Failed to open file for reading" << filename;
    }

    return result;
}

void jsonHandler::sendJsonFile()
{
    QJsonObject data = readJsonFile();
    sendData(data);
}

void jsonHandler::sendData(const QJsonObject &jsonObjSend)
{
    manager = new QNetworkAccessManager(this);

    QNetworkRequest request;

    request.setUrl(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonDocument data(jsonObjSend);
    QByteArray array = data.toJson();

    reply = manager->post(request, array);

    connect(reply, &QNetworkReply::finished, this, [this] {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "Data sent successfully";
        } else {
            qDebug() << "Error sending data:" << reply->errorString();
        }
        reply->deleteLater();
    });
}

jsonHandler::~jsonHandler(){
    delete manager;
    delete reply;
}

