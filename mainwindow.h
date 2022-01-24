#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QtWebChannel/QWebChannel>
#include <QUrl>
#include <QMessageBox>
#include <QOAuth2AuthorizationCodeFlow>
#include "downloader.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void slotGo();
    void slotError();
    void slotDownloadProgress(quint64,quint64);
    void slotDone(const QUrl &url, const QByteArray&array);

private:
    Ui::MainWindow *ui;
    QOAuth2AuthorizationCodeFlow *tin;
    Downloader *down;

};
#endif // MAINWINDOW_H
