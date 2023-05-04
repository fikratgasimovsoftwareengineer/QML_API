#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "jsonhandler.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<jsonHandler>("com.example", 1, 0, "JsonHandler");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/jsonData/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
