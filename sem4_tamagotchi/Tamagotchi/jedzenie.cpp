#include "jedzenie.h"

Jedzenie::Jedzenie(const std::string na, const std::string nazwa_j, int kal, char prze)
{
    nazwa_akt = na;
    nazwa_posilku = nazwa_j;
    kalorycznosc = kal;
    id_przeznaczenia = prze;

    reg_zdrowia = kal*0.05;
    reg_samopoczucia = kal*0.05;
}

void Jedzenie::zjedz(zwierze * zw)
{
    if(zw->GetChorob() != nullptr and zw->GetChorob()->Getogr() == "Jedzenie")
    {
        if(kalorycznosc <100) //bylo zalecenie od doktora aby jesc niskokaloryczne posilki
        {
            zw->GetParam()->aktualizujZS(reg_zdrowia, reg_samopoczucia);
            zw->GetParam()->Setpzglodu(3);
            zw->GetParam()->Setdzis_jedz(true);
        }
        else
        {
            zw->GetParam()->aktualizujZS(1,1);
            zw->GetParam()->Setpzglodu(1);
            zw->GetParam()->Setdzis_jedz(true);
        }
            return;
    }
    //jesli glodomor to oblicz ze wiecej doda
    int mnoznik = zw->Getglodomor();
    if(zw->GetId() == id_przeznaczenia)
    {
        zw->GetParam()->Setpzglodu(kalorycznosc*0.01);
        zw->GetParam()->aktualizujZS(reg_zdrowia, reg_samopoczucia + mnoznik);
        zw->GetParam()->Setdzis_jedz(true);
    }
    else
    {
        //minimalnie zwieksza zdrowie i smp bo produkt dla innego zwierzaka
        zw->GetParam()->Setpzglodu(1);
        zw->GetParam()->aktualizujZS(2, 2);
        zw->GetParam()->Setdzis_jedz(true);
    }
}


bool Jedzenie::operator==(const std::string np)
{
    if(nazwa_posilku == np)
        return true;
    else
        return false;
}

