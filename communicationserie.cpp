#include "communicationserie.h"

communicationserie::communicationserie()
{
    portserie = new QSerialPort();
}

void communicationserie::check_port()
{
    i=0;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
            list_ports[i] = info.portName();
            i++;
    }
}

