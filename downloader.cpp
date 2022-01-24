#include "downloader.h"
#include <QFile>

Downloader::Downloader(QObject *parent):QObject(parent)
{
    man = new QNetworkAccessManager(this);
    connect(man,SIGNAL(finished(QNetworkReply*)),this,SLOT(slotFinished(QNetworkReply*)));
}

void Downloader::download(const QUrl &url)
{
    QNetworkRequest req(url);
    QNetworkReply *rep = man->get(req);
    connect(rep,SIGNAL(downloadProgress(quint64,quint64)),this,SIGNAL(downloadProgress(quint64,quint64)));
}

void Downloader::slotFinished(QNetworkReply *reply)
{
    if(reply->error() != QNetworkReply::NoError)
    {
        qDebug()<<"ERROR";
        qDebug()<<reply->errorString();
//        emit error();
    }
    else
    {
        QFile *file = new QFile("./file.xml");
        if(file->open(QIODevice::WriteOnly))
        {
            file->write(reply->readAll());
            file->close();
            qDebug()<<"Downloading is completed";
//            emit done(reply->url(),reply->readAll());

        }
    }
    reply->deleteLater();
}
