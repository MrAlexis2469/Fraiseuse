#ifndef FENETREPRINCIPAL_H
#define FENETREPRINCIPAL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGridLayout>
#include <QProgressBar>
#include <QLabel>

class FenetrePrincipal : public QWidget
{
    Q_OBJECT
public:
    FenetrePrincipal();

private:
    QVBoxLayout *layoutPrincipal;
    QGridLayout *grid_principal;
    QPushButton *bt_start;
    QPushButton *bt_parametre;
    QPushButton *bt_init;
    QProgressBar *avancement;
    QLabel *ligne1;
    QLabel *ligne2;
    QLabel *ligne3;

signals:

public slots:

};

#endif // FENETREPRINCIPAL_H
