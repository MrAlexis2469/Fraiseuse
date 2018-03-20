#include "fenetreprincipal.h"

void FenetrePrincipal::ouverturesite()
{
    QFile file("test.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug()<<"fichier non ouvert";
    QTextStream flux(&file);
    flux.setCodec("UTF-8");
    flux << serie->ndroite << endl << "Nous sommes "<<endl;
    site = "https://google.fr";
    QDesktopServices::openUrl(site);
}

void FenetrePrincipal::oparametre()
{
    fn_parametre->mise_a_jour();
    //fn_parametre.show();
}

void FenetrePrincipal::maj_comtage()
{
    compteur++;
    avancement->setValue(compteur);
    if(avancement->value()==100)
    {
        sec->stop();
        bt_start->setEnabled(true);
        bt_parametre->setEnabled(true);
        bt_init->setEnabled(true);
        bt_visu->setEnabled(true);
        avancement->setValue(0);
        ligne1->setText(QString("Ligne n°1 = %1 cm").arg(serie->ndroite));
        serie->portserie->write("0");
        serie->portserie->flush();
    }
}

void FenetrePrincipal::mise_en_marche()
{
    bt_start->setEnabled(false);
    bt_parametre->setEnabled(false);
    bt_init->setEnabled(false);
    bt_visu->setEnabled(false);
    sec->start(20);
    compteur = 0;
    serie->portserie->write("1");
    serie->portserie->flush();
}

FenetrePrincipal::FenetrePrincipal() : QWidget()
{
    serie = new communicationserie();
    fn_parametre = new fenetreparametre(serie);
    setWindowTitle("Lancement");
    setMinimumSize(600,200);
    //construction

    sec = new QTimer();

    bt_start = new QPushButton("Démarrer");
    bt_parametre = new QPushButton("Paramètres");
    bt_init = new QPushButton("Initialisation");
    bt_quitter = new QPushButton("Quitter");
    bt_visu = new QPushButton("Visualisation 3D");

    avancement = new QProgressBar();
    avancement->setValue(0);
    avancement->setRange(0,100);

    ligne1 = new QLabel();
    ligne2 = new QLabel();
    ligne3 = new QLabel();
    ligne1->setText(QString("Ligne n°1 = 0 cm"));
    ligne2->setText(QString("Ligne n°2 = 0 cm"));
    ligne3->setText(QString("Ligne n°3 = 0 cm"));
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
    layoutPrincipal->addWidget(bt_visu);
    layoutPrincipal->addWidget(bt_quitter);

    connect(bt_start, SIGNAL(pressed()), this, SLOT(mise_en_marche()));
    connect(bt_quitter, SIGNAL(pressed()), qApp, SLOT(quit()));
    connect(sec, SIGNAL(timeout()), this, SLOT(maj_comtage()));
    connect(bt_parametre,SIGNAL(pressed()), this,SLOT(oparametre()));
    connect(bt_visu, SIGNAL(pressed()), this, SLOT(ouverturesite()));

    setLayout(layoutPrincipal);
}
