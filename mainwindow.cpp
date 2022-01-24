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
    down = new Downloader(this);


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
