#include "downloader.h"

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
        emit error();
    }
    else
    {
        emit done(reply->url(),reply->readAll());
    }
    reply->deleteLater();
}
