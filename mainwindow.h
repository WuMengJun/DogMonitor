#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "systemdevicemonitor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void setMonitor(SystemDeviceMonitor* monitor);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    SystemDeviceMonitor* m_monitor;
    Ui::MainWindow *ui;

private slots:
    void handleDog(const QString& dogName);
};

#endif // MAINWINDOW_H
