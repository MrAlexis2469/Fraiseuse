#ifndef FENETREPARAMETRE_H
#define FENETREPARAMETRE_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QRadioButton>
#include "communicationserie.h"

class fenetreparametre : public QWidget
{
    Q_OBJECT
public:
    fenetreparametre(communicationserie *serie);
    void mise_a_jour();
    communicationserie *seriee;

private:
    QVBoxLayout *layoutgeneral;
    QGridLayout *layoutgrid;
    QPushButton *bt_confirme;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QComboBox *list1;
    QComboBox *list2;
    QRadioButton *box1;
    QRadioButton *box2;

signals:

public slots:
    void confirme_parametres();
};

#endif // FENETREPARAMETRE_H
