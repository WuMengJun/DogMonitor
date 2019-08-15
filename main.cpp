#include "mainwindow.h"
#include <QApplication>
#include "systemdevicemonitor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SystemDeviceMonitor* monitor = new SystemDeviceMonitor();
    MainWindow w;
    w.setMonitor(monitor);
    a.installNativeEventFilter(monitor);
    w.show();

    return a.exec();
}
