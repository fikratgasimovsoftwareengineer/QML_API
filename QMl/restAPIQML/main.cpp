#include <QGuiApplication>
#include "appwrapper.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    AppWrapper m_appWrapper;

    QQmlApplicationEngine m_engine;

    m_engine.rootContext()->setContextProperty("AppWrapper",&m_appWrapper);

    const QUrl url(u"qrc:/restAPIQML/Main.qml"_qs);

    QObject::connect(&m_engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    m_engine.load(url);


    return app.exec();
}
