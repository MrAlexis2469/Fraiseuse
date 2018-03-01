#include <QApplication>
#include "fenetreprincipal.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    FenetrePrincipal fp_lancement;

    fp_lancement.show();

    return app.exec();
}
