#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPluginLoader>

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


void MainWindow::on_pB_cons_clicked()
{

}

void MainWindow::on_searchPlugin_clicked()
{

}
