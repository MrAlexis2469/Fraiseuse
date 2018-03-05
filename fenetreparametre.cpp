#include "fenetreparametre.h"

fenetreparametre::fenetreparametre() : QWidget()
{
    communicationserie test;
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

    for(int x; x<(test.i); x++)
    {
        list2->addItem(test.list_ports[x]);
    }

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

    connect(bt_confirme, SIGNAL(pressed()),this,SLOT(close()));

    setLayout(layoutgeneral);
}
