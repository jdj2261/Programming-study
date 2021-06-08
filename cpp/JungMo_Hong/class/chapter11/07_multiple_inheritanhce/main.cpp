#include <iostream>
using namespace std;

class USBDevice
{
private:
    long m_id;

public:
    USBDevice(long id) : m_id(id) {}

    long getID() { return m_id; }
    void plugAndPlay() {}
};

class NetworkDevice
{
private:
    long m_id;

public:
    NetworkDevice(long id) : m_id(id) {}

    long getID() { return m_id; }
    void networking() {}
};

//  다이아몬드 상속 구조는 피하자.
class USBNetworkDevice : public USBDevice, public NetworkDevice
{
public:
    USBNetworkDevice(long usb_id, long net_id)
        : USBDevice(usb_id), NetworkDevice(net_id)
    {
    }
};

int main()
{
    USBNetworkDevice my_device(3.14, 6.1);

    my_device.networking();
    my_device.plugAndPlay();

    // 이렇게 구분
    my_device.USBDevice::getID();
    my_device.NetworkDevice::getID();

    return 0;
}