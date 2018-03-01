#include "fenetreparametre.h"

fenetreparametre::fenetreparametre() : QWidget()
{
    setWindowTitle("Paramètre");
    setMinimumSize(600,150);

    test = new QLabel();
    test->setText("coucou");
}
