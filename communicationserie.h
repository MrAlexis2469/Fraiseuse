#ifndef COMMUNICATIONSERIE_H
#define COMMUNICATIONSERIE_H

#include <QSerialPort>
#include <QSerialPortInfo>


class communicationserie
{

public:
    communicationserie();
private:
     QSerialPort *portserie;
};

#endif // COMMUNICATIONSERIE_H
