#ifndef PIES_H
#define PIES_H

#include <QGraphicsPixmapItem>

#include "zwierze.h"
#include "scena.h"

class Pies : public zwierze
{
    Q_OBJECT
    //rysunki qpixmap
    QPixmap standard = QPixmap(":/images/dog_s.png");

    QPixmap spacer1 = QPixmap(":/images/dog_r1.png");
    QPixmap spacer2 = QPixmap(":/images/dog_r2.png");

    QPixmap senP = QPixmap(":/images/dog_sleep.png");

    QPixmap jedzenie1 = QPixmap(":/images/dog_e1.png");
    QPixmap jedzenie2 = QPixmap(":/images/dog_e2.png");

    QPixmap zabawa11 = QPixmap(":/images/dog_z1_1.png");
    QPixmap zabawa12 = QPixmap(":/images/dog_z1_2.png");
    QPixmap zabawa13 = QPixmap(":/images/dog_z1_3.png");

    QPixmap zabawa21 = QPixmap(":/images/dog_z2_1.png");
    QPixmap zabawa22 = QPixmap(":/images/dog_z2_2.png");

    int sen = 0;
    int zabawa = 0;
    int ruch =0;
    int wykonane_ruchy = 0;
public:
    Pies(QStackedWidget*);
    Pies(std::vector<int>, QStackedWidget*);

    //funkcje overload
    void aktywuj_animacje_zabawy(int);
    void animacja_zabawa();

    void aktywuj_animacje_snu();
    void animacja_sen();

    void aktywuj_animacje_jedzenie();
    void animacja_jedzenie();
};

#endif // PIES_H
