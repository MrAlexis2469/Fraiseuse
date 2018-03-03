#include <QApplication>
#include "fenetreprincipal.h"

/*test
#include <QSerialPortInfo>
#include <QDebug>
*/

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    FenetrePrincipal fp_lancement;

    fp_lancement.show();
/*test
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
            qDebug() << "Name : " << info.portName();
            qDebug() << "Description : " << info.description();
            qDebug() << "Manufacturer: " << info.manufacturer();
            qDebug() << info.portName();
            qDebug() << "Number of serial ports:" << QSerialPortInfo::availablePorts().count();}
*/
    return app.exec();
}
