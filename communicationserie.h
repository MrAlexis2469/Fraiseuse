#ifndef COMMUNICATIONSERIE_H
#define COMMUNICATIONSERIE_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>


class communicationserie
{
public:
    void check_port();
    void lecture();
    communicationserie();
    QString list_ports[30];
    int i;
    QSerialPort *portserie;
private:
     char car;
};

#endif // COMMUNICATIONSERIE_H
