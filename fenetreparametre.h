#ifndef FENETREPARAMETRE_H
#define FENETREPARAMETRE_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class fenetreparametre : public QWidget
{
    Q_OBJECT
public:
    fenetreparametre();

private:
    QVBoxLayout *layout1;
    QPushButton *bt_quitter;


signals:

public slots:
};

#endif // FENETREPARAMETRE_H
