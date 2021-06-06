#ifndef KOT_H
#define KOT_H

#include <QGraphicsPixmapItem>
#include <thread>
#include <QTimer>

#include "windows.h"

#include "zwierze.h"
#include "scena.h"

class Kot : public zwierze
{
    Q_OBJECT
    //rysunki qpixmap
    QPixmap standard = QPixmap(":/images/catr0.png");
    QPixmap spacer1 = QPixmap(":/images/catr1.png");

    QPixmap zabawa11 = QPixmap(":/images/cat_z1_1.png");
    QPixmap zabawa12 = QPixmap(":/images/cat_z1_2.png");
    QPixmap zabawa13 = QPixmap(":/images/cat_z1_3.png");

    QPixmap zabawa21 = QPixmap(":/images/cat_z2_1.png");
    QPixmap zabawa22 = QPixmap(":/images/cat_z2_2.png");
    QPixmap zabawa23 = QPixmap(":/images/cat_z2_3.png");
    QPixmap zabawa24 = QPixmap(":/images/cat_z2_4.png");
    QPixmap zabawa25 = QPixmap(":/images/cat_z2_5.png");
    QPixmap zabawa26 = QPixmap(":/images/cat_z2_6.png");

    QPixmap jedzenie1 = QPixmap(":/images/cat_e1.png");
    QPixmap jedzenie2 = QPixmap(":/images/cat_e2.png");

    QPixmap senP = QPixmap(":/images/cat_sleep.png");

    int zabawa =0;
    int ruch =0;
    int sen =0;
    int wykonane_ruchy=1;
    int ruch_gora =0;
public:
    Kot(QStackedWidget *);
    Kot(std::vector<int> v, QStackedWidget *);

    //funkcje overload
    void aktywuj_animacje_zabawy(int);
    void animacja_zabawa();

    void aktywuj_animacje_snu();
    void animacja_sen();

    void aktywuj_animacje_jedzenie();
    void animacja_jedzenie();


};

#endif // KOT_H
