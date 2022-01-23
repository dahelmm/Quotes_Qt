#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPluginLoader>
#include <QAbstractOAuth2>
#include <QDesktopServices>
#include <QFile>
#include <QDir>
#include <QAbstractOAuth2>
#include <QNetworkReply>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->tin = new QOAuth2AuthorizationCodeFlow(this);
    this->tin->setScope("email");
//    this->tin->setToken("t.2kL1EpX_fMa2Z3YFM8gLixrgXqZpZl5YiugRYhmb-1PpdF3UY8kF4ihOYYChEHMiQ2yahqJcHcWU3PPHH0Emhw");

    connect(this->tin,&QOAuth2AuthorizationCodeFlow::authorizeWithBrowser,&QDesktopServices::openUrl);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pB_cons_clicked()
{

}

void MainWindow::on_searchPlugin_clicked()
{

}
