#ifndef FENETREPRINCIPAL_H
#define FENETREPRINCIPAL_H

#include <QApplication>
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
    QPushButton *bt_quitter;
    QPushButton *bt_visu;
    QProgressBar *avancement;
    QLabel *ligne1;
    QLabel *ligne2;
    QLabel *ligne3;


signals:

public slots:
    void mise_en_marche(void);

};

#endif // FENETREPRINCIPAL_H
