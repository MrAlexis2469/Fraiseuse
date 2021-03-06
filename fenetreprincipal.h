#ifndef FENETREPRINCIPAL_H
#define FENETREPRINCIPAL_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGridLayout>
#include <QProgressBar>
#include <QLabel>
#include <QTimer>
#include "fenetreparametre.h"
#include <QDesktopServices>
#include <QUrl>
#include "communicationserie.h"
#include <QFile>
#include <QTextStream>

class FenetrePrincipal : public QWidget
{
    Q_OBJECT
public:
    FenetrePrincipal();
    communicationserie *serie;
    QLabel *ligne1;
    QLabel *ligne2;
    QLabel *ligne3;

private:
    QVBoxLayout *layoutPrincipal;
    QGridLayout *grid_principal;
    QPushButton *bt_start;
    QPushButton *bt_parametre;
    QPushButton *bt_stop;
    QPushButton *bt_quitter;
    QPushButton *bt_visu;
    QProgressBar *avancement;
    QTimer *sec;
    int compteur;
    fenetreparametre *fn_parametre;
    QUrl site;



signals:

public slots:
    void mise_en_marche(void);
    void maj_comtage(void);
    void oparametre();
    void ouverturesite();
    void lancementb();
    void stop();
};

#endif // FENETREPRINCIPAL_H
