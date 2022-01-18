#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::replyFinish(QNetworkReply *reply)
{
    QString answer = QString::fromUtf8(reply->readAll());
    qDebug()<<answer;
}


void MainWindow::on_pB_cons_clicked()
{
    QString siteUrl = ui->lineEdit->text();
    man = new QNetworkAccessManager;
    connect(man,SIGNAL(finished(QNetworkReply *)),this, SLOT(replyFinish(QNetworkReply *)));
    man->post(QNetworkRequest(QUrl(siteUrl)),);
}
