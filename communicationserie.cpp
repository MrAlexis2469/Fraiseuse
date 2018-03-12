#include "communicationserie.h"

communicationserie::communicationserie()
{
    car = 'A';
    portserie = new QSerialPort();
    portserie->setBaudRate(QSerialPort::Baud9600);
    portserie->setDataBits(QSerialPort::Data8);
    portserie->setFlowControl(QSerialPort::NoFlowControl);
    portserie->setParity(QSerialPort::NoParity);
    portserie->setStopBits(QSerialPort::OneStop);
    portserie->setPortName("/dev/ttyACM0");
    portserie->open(QIODevice::ReadWrite);
    portserie->write(&car);
    portserie->flush();
    portserie->close();
    qDebug () << "Erreur communication:" <<portserie->errorString();
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

void communicationserie::lecture()
{
    QByteArray lect =portserie->readAll();
    qDebug() << lect;
}

