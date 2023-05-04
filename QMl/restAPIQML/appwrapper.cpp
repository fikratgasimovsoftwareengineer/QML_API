#include "appwrapper.h"
#include <QDebug>

AppWrapper::AppWrapper(QObject *parent)
    : QObject{parent},
    mNetManager(new QNetworkAccessManager (this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray),
    m_jokeId(-1)
{


}

void AppWrapper::fetchPost()
{

    const QUrl API_ENDPOINT("https://official-joke-api.appspot.com/jokes/random");

    QNetworkRequest request;
    request.setUrl(API_ENDPOINT);

    mNetReply = mNetManager->get(request);

    connect(mNetReply, &QIODevice::readyRead, this, &AppWrapper::dataReadRead);

    connect(mNetReply, &QNetworkReply::finished, this, &AppWrapper::dataReadFinished);
}

void AppWrapper::removeLast()
{

}

QString AppWrapper::getJoke() const
{
    return mJoke;

}

int AppWrapper::getJokeId() const
{
    return m_jokeId;

}


void AppWrapper::dataReadRead()
{
    mDataBuffer->append(mNetReply->readAll());
}

void AppWrapper::dataReadFinished()
{
    if (mNetReply->error()){

        qDebug() << "Error is incontered!, Load Again" << mNetReply->errorString();
    }else{

        // if there is not error, convert data to json doc
        QJsonDocument doc = QJsonDocument::fromJson(*mDataBuffer);

        //grab  value the array
        QJsonObject dataoObj = doc.object();

        // recieve strig
        mJoke = dataoObj.value("setup").toString() + "\n" + dataoObj.value("punchline").toString() + " ";

        mJokeArray.append(mJoke);

        int count = 0;

        for(int i=0; i < mJokeArray.size(); i+=1){

            qDebug() << mJokeArray[i] ;
            qDebug() << " ==============" << count ;
            count ++;

        }
        //recieve any type of value
        QVariant idVariant = dataoObj.value("id").toVariant();

        m_jokeId = idVariant.toInt();

        // emit signals
        emit jokeFetched();
        emit jokeIdChanged();

        mDataBuffer->clear();
        mNetReply->deleteLater();
    }

}
