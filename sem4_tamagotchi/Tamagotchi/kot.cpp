#include "kot.h"

Kot::Kot( QStackedWidget* ws): zwierze(ws)
{
    Id = 'k';
    setPixmap(standard);
    connect(zegar_zabawa, &QTimer::timeout, [=](){ animacja_zabawa(); });
    connect(zegar_sen, &QTimer::timeout, [=](){ animacja_sen(); });
    connect(zegar_jedzenie, &QTimer::timeout, [=](){ animacja_jedzenie(); });
}

Kot::Kot(std::vector<int> v,  QStackedWidget* ws): zwierze(v, ws)
{
    setPixmap(standard);
    connect(zegar_zabawa, &QTimer::timeout, [=](){ animacja_zabawa(); });
    connect(zegar_sen, &QTimer::timeout, [=](){ animacja_sen(); });
    connect(zegar_jedzenie, &QTimer::timeout, [=](){ animacja_jedzenie(); });
}

//uruchamianie zegarów odpowiedzialnych za wywoływanie funckji animujacych
void Kot::aktywuj_animacje_zabawy(int a)
{
    zegar_zabawa->start(500);
    zabawa = a;
}

void Kot::aktywuj_animacje_snu()
{
    zegar_sen->start(100);
}

void Kot::aktywuj_animacje_jedzenie()
{
    zegar_jedzenie->start(1000);
}

void Kot::animacja_zabawa()
{

    switch(zabawa)
    {
    case 1: //zabawa z marszem
    {
        if(ruch == 0)
        {
            setPixmap(standard);
            ruch = 1;
            wykonane_ruchy++;
        }
        else
        {
            setPixmap(spacer1);
            ruch = 0;
            wykonane_ruchy++;
        }
        if(wykonane_ruchy == 10)
        {
            zegar_zabawa->stop();
            wykonane_ruchy = 0;
            setPixmap(standard);
        }
        break;
    }
    case 2: //zabawa z włóczką
    {
        if(wykonane_ruchy%2 ==0)
        {
            setPixmap(zabawa12);
            wykonane_ruchy++;
        }
        else if(ruch_gora ==0)
        {
            setPixmap(zabawa11);
            wykonane_ruchy++;
            ruch_gora++;
        }
        else
        {
            setPixmap(zabawa13);
            wykonane_ruchy++;
            ruch_gora--;
        }
        if(wykonane_ruchy == 15)
        {
            zegar_zabawa->stop();
            wykonane_ruchy = 0;
            setPixmap(standard);
        }
        break;
    }
    case 3: //podskoki
    {
        ruch++;
        switch(ruch)
        {
        case 1:
        {
        setPixmap(zabawa21);
        wykonane_ruchy++;
        break;
        }
        case 2:
        {
        setPixmap(zabawa22);
        wykonane_ruchy++;
        break;
        }
        case 3:
        {
        setPixmap(zabawa23);
        wykonane_ruchy++;
        break;
        }
        case 4:
        {
        setPixmap(zabawa24);
        wykonane_ruchy++;
        break;
        }case 5:
        {
        setPixmap(zabawa22);
        wykonane_ruchy++;
        break;
        }case 6:
        {
        setPixmap(zabawa25);
        ruch =0;
        wykonane_ruchy++;
        break;
        }
        }

        if(wykonane_ruchy >13)
        {
            zegar_zabawa->stop();
            wykonane_ruchy = 0;
            setPixmap(standard);
        }
    break;
    }

    }
}

void Kot::animacja_sen()
{
    if(sen ==40)
    {
        zegar_sen->stop();
        setPixmap(standard);
        sen =0;
    }
    else
    {
        setPixmap(senP);
        sen++;
    }
}

void Kot::animacja_jedzenie()
{
    if(ruch == 0)
    {
        setPixmap(jedzenie1);
        ruch = 1;
        wykonane_ruchy++;
    }
    else
    {
        setPixmap(jedzenie2);
        ruch = 0;
        wykonane_ruchy++;
    }
    if(wykonane_ruchy == 10)
    {
        zegar_jedzenie->stop();
        wykonane_ruchy = 0;
        setPixmap(standard);
    }
}
