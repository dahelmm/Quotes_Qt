#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QtWebChannel/QWebChannel>
#include <QUrl>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class interface : public QObject
{
public:
    virtual ~interface() = default;
    virtual QString getString(QString str) = 0;

};

Q_DECLARE_INTERFACE(interface,"t.2kL1EpX_fMa2Z3YFM8gLixrgXqZpZl5YiugRYhmb-1PpdF3UY8kF4ihOYYChEHMiQ2yahqJcHcWU3PPHH0Emhw");

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pB_cons_clicked();
    void on_searchPlugin_clicked();

private:
    Ui::MainWindow *ui;
    interface *plugin;
};
#endif // MAINWINDOW_H
