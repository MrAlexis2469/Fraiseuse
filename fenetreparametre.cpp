#include "fenetreparametre.h"

fenetreparametre::fenetreparametre() : QWidget()
{
    setWindowModality(Qt::ApplicationModal);
    setWindowTitle("Paramètre");
    setMinimumSize(300,100);

    layout1 = new QVBoxLayout();
    bt_quitter = new QPushButton("Confirmer", this);

    layout1->addWidget(bt_quitter);

    connect(bt_quitter, SIGNAL(pressed()),this,SLOT(close()));
    setLayout(layout1);
}
