#include "communicationserie.h"
#define SYN1 1
#define LECT1 2
#define LECT2 3
#define LECT3 4
#define FIN 5

communicationserie::communicationserie() : QWidget()
{
    portserie = new QSerialPort();
    portserie->setBaudRate(QSerialPort::Baud9600);
    portserie->setDataBits(QSerialPort::Data8);
    portserie->setFlowControl(QSerialPort::NoFlowControl);
    portserie->setParity(QSerialPort::NoParity);
    portserie->setStopBits(QSerialPort::OneStop);
    portserie->setPortName("/dev/ttyS0");
    portserie->open(QIODevice::ReadWrite);
    qDebug () << "Erreur communication:" <<portserie->errorString();
    connect(portserie, SIGNAL(readyRead()),this,SLOT(lecture()));
    mae = SYN1;
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
        QByteArray car = portserie->readAll();
        int ii = car.size();
        for(int a = 0; a<ii; a++)
        {
            switch(mae)
            {
                case SYN1:
                    if(car[a] == 'A')
                        mae = LECT1;
                break;
                case LECT1:
                    if(car[a] == 'B')
                        mae = LECT2;
                    else
                        bgauched += car[a];
                break;
                case LECT2:
                    if(car[a] == 'C')
                        mae = LECT3;
                    else
                        bgauchef += car[a];
                break;
                case LECT3:
                    if(car[a] == 'D')
                        mae = FIN;
                    else
                        lgauche += car[a];
                break;
            }
        }
        if(mae == FIN)
        {
            ndroite = bgauched.toInt();
            bgauched.clear();
            mae = SYN1;
        }
}

