#ifndef JSONHANDLER_H
#define JSONHANDLER_H

#include <QObject>
#include <QJsonObject>
#include <QFile> // ifstream
#include <QJsonDocument> // read & write json doc
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QByteArray>
#include <QTextStream>
#include <QDebug>
#include <QVariantList>
#include <QVariant>

class jsonHandler : public QObject
{
    Q_OBJECT
public:
    explicit jsonHandler(QObject *parent = nullptr);
    ~jsonHandler();


    // qstring , qsjonobject{key:value pair}
    Q_INVOKABLE void writeJsonFile();
    //
    Q_INVOKABLE QJsonObject readJsonFile();

    // parse to qml
    Q_INVOKABLE QVariantList parseJsonFile();

    // qstring filename, qstring endpointurl
    Q_INVOKABLE void sendJsonFile();

    const QString url =  "http://127.0.0.1:5000/test";

    QString filename;

signals:

private:

    // takes jsonobject and qstring
    void sendData (const QJsonObject &jsonObjSend);
    QString name;
    double price;
    QNetworkAccessManager *manager;

    QNetworkReply *reply;
};

#endif // JSONHANDLER_H
