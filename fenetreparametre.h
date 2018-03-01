#ifndef FENETREPARAMETRE_H
#define FENETREPARAMETRE_H

#include <QApplication>
#include <QWidget>
#include <QLabel>

class fenetreparametre : public QWidget
{
    Q_OBJECT
public:
    fenetreparametre();

private:
    QLabel *test;
};

#endif // FENETREPARAMETRE_H
