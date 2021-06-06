#include "pies.h"

Pies::Pies(QStackedWidget* ws): zwierze(ws)
{
    Id = 'p';
    setPixmap(standard);
    connect(zegar_zabawa, &QTimer::timeout, [=](){ animacja_zabawa(); });
    connect(zegar_sen, &QTimer::timeout, [=](){ animacja_sen(); });
    connect(zegar_jedzenie, &QTimer::timeout, [=](){ animacja_jedzenie(); });
}

Pies::Pies(std::vector<int> v,  QStackedWidget* ws): zwierze(v, ws)
{
    setPixmap(standard);
    connect(zegar_zabawa, &QTimer::timeout, [=](){ animacja_zabawa(); });
    connect(zegar_sen, &QTimer::timeout, [=](){ animacja_sen(); });
    connect(zegar_jedzenie, &QTimer::timeout, [=](){ animacja_jedzenie(); });
}

void Pies::aktywuj_animacje_zabawy(int a)
{
    zegar_zabawa->start(200);
    zabawa =a;
}

void Pies::animacja_zabawa()
{
    switch(zabawa)
    {
    case 1:
    {
        if(ruch == 0)
        {
            setPixmap(spacer1);
            ruch = 1;
            wykonane_ruchy++;
        }
        else
        {
            setPixmap(spacer2);
            ruch = 0;
            wykonane_ruchy++;
        }
        if(wykonane_ruchy == 10)
        {
            setPixmap(standard);
            zegar_zabawa->stop();
            wykonane_ruchy = 0;
        }
        break;
    }
    case 2:
    {
        if(ruch == 0)
        {
            setPixmap(zabawa11);
            ruch = 1;
            wykonane_ruchy++;
        }
        else
        {
            setPixmap(zabawa13);
            ruch = 0;
            wykonane_ruchy++;
        }
        if(wykonane_ruchy %4 ==0)
        {
            setPixmap(zabawa12);
        }

        if(wykonane_ruchy == 12)
        {
            setPixmap(standard);
            zegar_zabawa->stop();
            wykonane_ruchy = 0;
        }
        break;

    }
    case 3:
    {
        if(ruch == 0)
        {
            setPixmap(zabawa21);
            ruch = 1;
        }
        else
        {
            setPixmap(zabawa22);
            ruch = 0;
            wykonane_ruchy++;
        }
        if(wykonane_ruchy == 6)
        {
            setPixmap(standard);
            zegar_zabawa->stop();
            wykonane_ruchy = 0;
        }
        break;
    }
    }
}

void Pies::aktywuj_animacje_snu()
{
    zegar_sen->start(4000);
    setPixmap(senP);
}

void Pies::animacja_sen()
{   
   setPixmap(standard);
   zegar_sen->stop();
}

void Pies::aktywuj_animacje_jedzenie()
{
    zegar_jedzenie->start(1000);
}

void Pies::animacja_jedzenie()
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
