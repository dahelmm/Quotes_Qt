#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    man = new QNetworkAccessManager(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::replyFinished()
{
    QNetworkReply *rep = (QNetworkReply*)sender();
    if(rep->error() == QNetworkReply::NoError)
    {
        QByteArray content = rep->readAll();
        ui->lineEdit->setText(content);
    }
    else
    {
        QMessageBox::critical(this,"Error","Данные не считались");
    }
    rep->deleteLater();
}


void MainWindow::on_pB_cons_clicked()
{
    QUrl url("t.2kL1EpX_fMa2Z3YFM8gLixrgXqZpZl5YiugRYhmb-1PpdF3UY8kF4ihOYYChEHMiQ2yahqJcHcWU3PPHH0Emhw");
//    QUrl url("https://progi.pro/qnetworkreply-t28190");
    QNetworkRequest req(url);
    QByteArray test;
    QNetworkReply * rep = man->post(req,test);

    connect(rep,SIGNAL(finished()),this, SLOT(replyFinished()));
}
