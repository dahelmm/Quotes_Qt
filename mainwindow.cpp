#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    down = new Downloader(this);

    connect(down,SIGNAL(downloadProgress(quint64,quint64)),this,SLOT(slotDownloadProgress(quint64,quint64)));
    connect(down,SIGNAL(done(const QUrl&,const QByteArray&)),this, SLOT(slotDone(const QUrl&,const QByteArray &)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::slotDone(const QUrl&url, const QByteArray &array)
{
    QFile file("./file.xml");
    if(file.open(QIODevice::WriteOnly))
    {
        file.write(array);
    }
    else
    {
        qDebug()<<"Error read link";
    }
}
void MainWindow::slotGo()
{
    down->download(QUrl(ui->lE_link->text()));
}
void MainWindow::slotError()
{
    QMessageBox::critical(0,"Error","Error");
}
void MainWindow::slotDownloadProgress(quint64 x,quint64 y)
{
    if(y<=0)
    {
        slotError();
        return;
    }
    ui->ppB_progress->setValue(100*x/y);
}

void MainWindow::on_pB_go_clicked()
{
    slotGo();
}
