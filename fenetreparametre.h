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

class fenetreparametre : public QWidget
{
    Q_OBJECT
public:
    fenetreparametre();

private:
    QVBoxLayout *layoutgeneral;
    QGridLayout *layoutgrid;
    QPushButton *bt_confirme;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *label5;
    QComboBox *list1;
    QComboBox *list2;
    QRadioButton *box1;
    QRadioButton *box2;

signals:

public slots:
};

#endif // FENETREPARAMETRE_H
