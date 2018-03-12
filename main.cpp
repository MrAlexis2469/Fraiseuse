#include <QApplication>
#include "fenetreprincipal.h"
#include <QDebug>

QString test[5];
int i = 0;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    FenetrePrincipal fp_lancement;

    fp_lancement.show();

    return app.exec();
}
