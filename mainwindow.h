#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void replyFinish(QNetworkReply *reply);

private slots:
    void on_pB_cons_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *man;
};
#endif // MAINWINDOW_H
