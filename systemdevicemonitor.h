#ifndef SYSTEMDEVICEMONITOR_H
#define SYSTEMDEVICEMONITOR_H
#include <QAbstractNativeEventFilter>
#include "windows.h"
#include <QByteArray>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
typedef char * (*PGetUsbdog)();

class SystemDeviceMonitor : public QObject, public QAbstractNativeEventFilter
{
    Q_OBJECT
public:
    SystemDeviceMonitor();
    bool nativeEventFilter(const QByteArray &eventType, void *message, long *) override;
    QString dogName();

private:
    PGetUsbdog getUsbdog;
    bool checkDog();
    QString m_dogName;

signals:
    void dogFounded(const QString& dogName);
};


#endif // SYSTEMDEVICEMONITOR_H
