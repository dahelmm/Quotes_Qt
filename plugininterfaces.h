#ifndef PLUGININTERFACES_H
#define PLUGININTERFACES_H
#include "mainwindow.h"

class pluginInterfaces : public interface
{
    Q_OBJECT
    Q_INTERFACES(interface);
    Q_PLUGIN_METADATA(IID "t.2kL1EpX_fMa2Z3YFM8gLixrgXqZpZl5YiugRYhmb-1PpdF3UY8kF4ihOYYChEHMiQ2yahqJcHcWU3PPHH0Emhw");
public:
    explicit pluginInterfaces();
    ~pluginInterfaces();
    QString getString(QString str);
};

#endif // PLUGININTERFACES_H
