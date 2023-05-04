#ifndef APPWRAPPER_H
#define APPWRAPPER_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QStringList>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


class AppWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString joke READ getJoke NOTIFY jokeFetched)
    Q_PROPERTY(int jokeId READ getJokeId NOTIFY jokeIdChanged)

public:
    explicit AppWrapper(QObject *parent = nullptr);

    Q_INVOKABLE void fetchPost();

    Q_INVOKABLE void removeLast();

    QString getJoke() const;

    int getJokeId() const;

    bool initializeEngine();

signals:

    void jokeFetched();

    void jokeIdChanged();

public slots:

    void dataReadRead();

    void dataReadFinished();

private:
    QNetworkAccessManager *mNetManager;
    QNetworkReply *mNetReply;
    QByteArray *mDataBuffer; //feed data from reply
    QString mJoke;

    int m_jokeId;

    QStringList mJokeArray;


};

#endif // APPWRAPPER_H
