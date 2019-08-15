#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::setMonitor(SystemDeviceMonitor *monitor)
{
    m_monitor = monitor;
    handleDog(monitor->dogName());
    connect(m_monitor, &SystemDeviceMonitor::dogFounded, this, &MainWindow::handleDog);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleDog(const QString &dogName)
{
    ui->lblDogName->setText(dogName);
}
