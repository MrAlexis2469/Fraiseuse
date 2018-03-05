#ifndef COMMUNICATIONSERIE_H
#define COMMUNICATIONSERIE_H

#include <QSerialPort>
#include <QSerialPortInfo>


class communicationserie
{

public:
    communicationserie();
    QString list_ports[30];
    int i;
private:
     QSerialPort *portserie;
};

#endif // COMMUNICATIONSERIE_H
