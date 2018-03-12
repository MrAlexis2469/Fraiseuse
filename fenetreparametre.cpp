#include "fenetreparametre.h"

fenetreparametre::fenetreparametre(communicationserie *serie) : QWidget()
{
    seriee = serie;
    setWindowModality(Qt::ApplicationModal);
    setWindowTitle("Paramètres");
    setMinimumSize(400,150);

    layoutgeneral = new QVBoxLayout();
    bt_confirme = new QPushButton("Confirmer");
    label1 = new QLabel("Communication Série");
    label1->setAlignment(Qt::AlignCenter);
    label2 = new QLabel("Baudrate:");
    label3 = new QLabel("COM: ");
    label4 = new QLabel("Nbs Bit Stop:");
    label5 =new QLabel("Paramètre application");
    label5->setAlignment(Qt::AlignCenter);
    list1 = new QComboBox(this);
    list2 = new QComboBox(this);
    layoutgrid = new QGridLayout();
    list1->addItem("1200");
    list1->addItem("2400");
    list1->addItem("4800");
    list1->addItem("9600");
    list1->addItem("19200");

    box1 = new QRadioButton("1 BIT");
    box1->setChecked(true);
    box2 = new QRadioButton("2 BIT");

    layoutgrid->addWidget(label2,0,0,1,1);
    layoutgrid->addWidget(list1,0,1,1,2);
    layoutgrid->addWidget(list2,1,1,1,2);
    layoutgrid->addWidget(label3,1,0,1,1);
    layoutgrid->addWidget(label4,2,0,1,1);
    layoutgrid->addWidget(box1,2,1,1,1);
    layoutgrid->addWidget(box2,2,2,1,1);

    layoutgeneral->addWidget(label1);
    layoutgeneral->addLayout(layoutgrid);
    layoutgeneral->addWidget(label5);
    layoutgeneral->addWidget(bt_confirme);

    connect(bt_confirme, SIGNAL(pressed()),this,SLOT(confirme_parametres()));

    setLayout(layoutgeneral);
}

void fenetreparametre::mise_a_jour()
{
    list2->clear();
    seriee->check_port();
    for(int x=0; x<(seriee->i); x++)
    {
        list2->addItem(seriee->list_ports[x]);
    }
    show();
}

void fenetreparametre::confirme_parametres()
{
    QString chaine = "/dev/" + list2->currentText();
    seriee->portserie->setPortName(chaine);
    if(box1->isChecked()==1)
        seriee->portserie->setStopBits(QSerialPort::OneStop);
    else
        seriee->portserie->setStopBits(QSerialPort::TwoStop);
    switch (list1->currentIndex())
    {
    case 0:
        seriee->portserie->setBaudRate(QSerialPort::Baud1200);
        break;
    case 1:
        seriee->portserie->setBaudRate(QSerialPort::Baud2400);
        break;
    case 2:
        seriee->portserie->setBaudRate(QSerialPort::Baud4800);
        break;
    case 3:
        seriee->portserie->setBaudRate(QSerialPort::Baud9600);
        break;
    case 4:
        seriee->portserie->setBaudRate(QSerialPort::Baud19200);
        break;
    default:
        break;
    }
    close();
}
