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
        avancement->setValue(0);
        bt_visu->setEnabled(true);
        ligne1->setText(QString("Gauche = %1 mm").arg(serie->ngauche));
        ligne2->setText(QString("Haut = %1 mm").arg(serie->nhaut));
        ligne3->setText(QString("Droit = %1 mm").arg(serie->ndroite));
    }
}

void FenetrePrincipal::mise_en_marche()
{
    bt_start->setEnabled(false);
    bt_parametre->setEnabled(false);
    bt_quitter->setEnabled(false);
    serie->portserie->write("1");
    serie->portserie->flush();
}

void FenetrePrincipal::lancementb()
{
    if(serie->debut == 1)
    {
        sec->start(100);
        compteur = 0;
        serie->debut = 0;
        bt_visu->setEnabled(false);
    }
}

void FenetrePrincipal::stop()
{
    bt_start->setEnabled(true);
    bt_parametre->setEnabled(true);
    serie->portserie->write("0");
    serie->portserie->flush();
    bt_quitter->setEnabled(true);
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
    bt_stop = new QPushButton("Stopper");
    bt_quitter = new QPushButton("Quitter");
    bt_visu = new QPushButton("Visualisation 3D");

    avancement = new QProgressBar();
    avancement->setValue(0);
    avancement->setRange(0,100);

    ligne1 = new QLabel();
    ligne2 = new QLabel();
    ligne3 = new QLabel();
    ligne1->setText(QString("Gauche = 0 mm"));
    ligne2->setText(QString("Haut = 0 mm"));
    ligne3->setText(QString("Droit = 0 mm"));
    ligne1->setAlignment(Qt::AlignCenter);
    ligne2->setAlignment(Qt::AlignCenter);
    ligne3->setAlignment(Qt::AlignCenter);


    layoutPrincipal = new QVBoxLayout();
    grid_principal =new QGridLayout();
    grid_principal->addWidget(bt_start,2,2,1,1);
    grid_principal->addWidget(bt_parametre,2,1,1,1);
    grid_principal->addWidget(bt_stop,2,0,1,1);
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
    connect(serie->portserie,SIGNAL(readyRead()),this,SLOT(lancementb()));
    connect(bt_stop, SIGNAL(pressed()),this,SLOT(stop()));

    setLayout(layoutPrincipal);
}
