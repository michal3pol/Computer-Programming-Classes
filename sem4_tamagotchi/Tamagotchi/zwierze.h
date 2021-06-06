#ifndef ZWIERZE_H
#define ZWIERZE_H

#include <memory>
#include <random>
#include <QGraphicsPixmapItem>
#include <QTimer>

#include "parametry.h"
#include "choroba.h"
#include "scena.h"

class zwierze: public QObject ,public QGraphicsPixmapItem
{
protected:

    //cechy zwierzaka (w natezeniu 1-10)
    int sennosc;
    int glodomor;
    int na_zewnatrz; //zabawy na zewnatrz
    char Id;

    //zdrowie, samopoczucie, czas
    std::shared_ptr<Parametry> Param;

    //wkaznik na chorobe
    std::shared_ptr<Choroba> choroba;

    //zegary
    QTimer * zegar_sen = new QTimer(this);
    QTimer * zegar_zabawa = new QTimer(this);
    QTimer * zegar_jedzenie = new QTimer(this);
public:

    zwierze(QStackedWidget*);
    zwierze(std::vector<int>,  QStackedWidget*);
    virtual ~zwierze() {}

    std::shared_ptr<Parametry> GetParam() {return this->Param;}
    std::shared_ptr<Choroba>& GetChorob() {return this->choroba;}
    void wyzdrowiej();

    int Getsennosc(){return sennosc;}
    int Getglodomor(){return glodomor;}
    int Getnazewnatrz(){return na_zewnatrz;}
    char GetId() {return Id;}

    QTimer* Get_zeg_s() {return zegar_sen;}
    QTimer* Get_zeg_z() {return zegar_zabawa;}
    QTimer* Get_zeg_j() {return zegar_jedzenie;}

    //animacje funkcje virtual
    virtual void aktywuj_animacje_zabawy(int)=0;
    virtual void animacja_zabawa()=0;

    virtual void aktywuj_animacje_snu()=0;
    virtual void animacja_sen()=0;

    virtual void aktywuj_animacje_jedzenie()=0;
    virtual void animacja_jedzenie()=0;

    friend std::ostream& operator<<(std::ostream&, zwierze&);
};

#endif // ZWIERZE_H
