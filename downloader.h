#ifndef DOWNLOADER_H
#define DOWNLOADER_H
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>


class Downloader : public QObject
{
public:
    Downloader(QObject *parent = nullptr);
    void download(const QUrl &url);

signals:
    void downloadProgress(quint64,quint64);
    void done(const QUrl &,const QByteArray&);
    void error();

private slots:
    void slotFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager *man;

};

#endif // DOWNLOADER_H
