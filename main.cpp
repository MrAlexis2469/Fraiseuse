#include <QApplication>
#include "fenetreprincipal.h"

/*test
 *
 * */
#include <QSerialPortInfo>
#include <QDebug>

QString test[5];
int i = 0;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    FenetrePrincipal fp_lancement;

    fp_lancement.show();
/*test
    */
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
            qDebug() << "Name : " << info.portName();
            test[i] = info.portName();
            i++;
            qDebug() << "Description : " << info.description();
            qDebug() << "Manufacturer: " << info.manufacturer();
            qDebug() << "Number of serial ports:" << QSerialPortInfo::availablePorts().count();}
            qDebug() << "mon test :" << test[0] << test[1];

    return app.exec();
}
