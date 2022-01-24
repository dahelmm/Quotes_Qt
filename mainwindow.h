#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "downloader.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void slotGo();
    void slotError();
    void slotDownloadProgress(quint64,quint64);
    void slotDone(const QUrl &url, const QByteArray&array);


    void on_pB_go_clicked();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Downloader *down;

};
#endif // MAINWINDOW_H
