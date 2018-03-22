#include "communicationserie.h"
#define SYN1 1
#define LECT1 2
#define LECT2 3
#define LECT3 4
#define LECT4 5
#define LECT5 6
#define LECT6 7
#define LECT7 8
#define LECT8 9
#define LECT9 10
#define LECT10 11
#define LECT11 12
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
                    {
                        mae = LECT1;
                        captdebut.clear();
                        captdebutl.clear();
                        bgauched.clear();
                        bgauchef.clear();
                        lgauche.clear();
                        bhautd.clear();
                        bhautf.clear();
                        lhaut.clear();
                        bdroited.clear();
                        bdroitef.clear();
                        ldroite.clear();
                    }
                break;
                case LECT1:
                    if(car[a] == 'B')
                        mae = LECT2;
                    else
                        captdebut += car[a];
                break;
                case LECT2:
                    if(car[a] == 'C')
                        mae = LECT3;
                    else
                        captdebutl += car[a];
                break;
                case LECT3:
                    if(car[a] == 'D')
                        mae = LECT4;
                    else
                        bgauched += car[a];
                break;
                case LECT4:
                    if(car[a] == 'E')
                        mae = LECT5;
                    else
                        bgauchef += car[a];
                break;
                case LECT5:
                    if(car[a] == 'F')
                        mae = LECT6;
                    else
                        lgauche += car[a];
                break;
                case LECT6:
                    if(car[a] == 'G')
                        mae = LECT7;
                    else
                        bhautd += car[a];
                break;
                case LECT7:
                    if(car[a] == 'H')
                        mae = LECT8;
                    else
                        bhautf += car[a];
                break;
                case LECT8:
                    if(car[a] == 'I')
                        mae = LECT9;
                    else
                        lhaut += car[a];
                break;
                case LECT9:
                    if(car[a] == 'J')
                        mae = LECT10;
                    else
                        bdroited += car[a];
                break;
                case LECT10:
                    if(car[a] == 'K')
                        mae = LECT11;
                    else
                        bdroitef += car[a];
                break;
                case LECT11:
                    if(car[a] == 'Z')
                        mae = FIN;
                    else
                        ldroite += car[a];
                break;
            }
        }
        if(mae == FIN)
        {
            ndroite = ldroite.toInt();
            nhaut = lhaut.toInt();
            ngauche = lgauche.toInt();
            mae = SYN1;
        }
}

