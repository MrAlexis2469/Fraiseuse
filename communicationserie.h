#ifndef COMMUNICATIONSERIE_H
#define COMMUNICATIONSERIE_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QWidget>
#include <QLabel>


class communicationserie : public QWidget
{
       Q_OBJECT
public:
    void check_port();
    communicationserie();
    QString list_ports[30];
    int i;
    QSerialPort *portserie;
    int ndroite, nhaut, ngauche;
private:
    char mae;
    QString bgauched, bgauchef,lgauche;
    QString bhautd, bhautf,lhaut;
    QString bdroited, bdroitef,ldoite;
public slots:
     void lecture();
};

#endif // COMMUNICATIONSERIE_H
