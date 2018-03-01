#include "fenetreprincipal.h"

FenetrePrincipal::FenetrePrincipal() : QWidget()
{
    setWindowTitle("Lancement");
    setMinimumSize(600,150);
    //construction

    bt_start = new QPushButton("Démarrer");
    bt_parametre = new QPushButton("Paramètres");
    bt_init = new QPushButton("Initialisation");

    avancement = new QProgressBar();
    avancement->setValue(50);
    avancement->setRange(0,100);

    ligne1 = new QLabel();
    ligne2 = new QLabel();
    ligne3 = new QLabel();
    ligne1->setText("Ligne n°1 : 40");
    ligne2->setText("Ligne n°2 : 75");
    ligne3->setText("Ligne n°3 : 80");
    ligne1->setAlignment(Qt::AlignCenter);
    ligne2->setAlignment(Qt::AlignCenter);
    ligne3->setAlignment(Qt::AlignCenter);


    layoutPrincipal = new QVBoxLayout();
    grid_principal =new QGridLayout();
    grid_principal->addWidget(bt_start,2,2,1,1);
    grid_principal->addWidget(bt_parametre,2,1,1,1);
    grid_principal->addWidget(bt_init,2,0,1,1);
    grid_principal->addWidget(avancement,1,0,1,3);
    grid_principal->addWidget(ligne1,0,0,1,1);
    grid_principal->addWidget(ligne2,0,1,1,1);
    grid_principal->addWidget(ligne3,0,2,1,1);

    layoutPrincipal->addLayout(grid_principal);

    setLayout(layoutPrincipal);
}
