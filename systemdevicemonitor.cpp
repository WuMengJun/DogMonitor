#include "systemdevicemonitor.h"


bool SystemDeviceMonitor::checkDog()
{
    char* dogname = getUsbdog();
    QString tempDogName = QString(dogname);
    if(tempDogName != m_dogName)
    {
        m_dogName = tempDogName;
        emit dogFounded(m_dogName);
        return true;
    }
    return false;
}

SystemDeviceMonitor::SystemDeviceMonitor()
{
    HMODULE hModule = LoadLibraryA("UsbdogDll.dll");
    getUsbdog = (PGetUsbdog)::GetProcAddress(hModule,"GetUsbdog");
    checkDog();
}

bool SystemDeviceMonitor::nativeEventFilter(const QByteArray &eventType, void *message, long *)
{
    if (eventType == "windows_generic_MSG" ||
            eventType == "windows_dispatcher_MSG") {
        MSG* pMsg = reinterpret_cast<MSG*>(message);
        if(pMsg->message == WM_DEVICECHANGE)
        {
            switch(pMsg->wParam)
            {
            case 0x00000007:
                checkDog();
                break;
            }
        }
    }
    return false;
}

QString SystemDeviceMonitor::dogName()
{
    return m_dogName;
}
