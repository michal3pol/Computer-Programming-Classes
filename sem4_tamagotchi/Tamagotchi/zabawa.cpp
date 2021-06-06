#include "zabawa.h"

Zabawa::Zabawa(const std::string n_akt,const std::string n_zab, char przez)
{
    nazwa_akt = n_akt;
    nazwa_zabawy =n_zab;
    id_przeznaczenia = przez;
}

bool Zabawa::odpowiednia_zabawa(char id_zw)
{
    if(id_zw == id_przeznaczenia)
        return true;
    else
        return false;
}

bool Zabawa::operator==(const std::string n)
{
    if(nazwa_zabawy == n)
        return true;
    else
        return false;
}

void Zabawa::baw_sie(zwierze * zw, int dl)
{  
    if(zw->GetChorob() != nullptr and zw->GetChorob()->Getogr() == "Zabawa")
    {
        zw->GetParam()->aktualizujZS(1,1);
        zw->GetParam()->dodaj_czas_akcji(dl);
        zw->GetParam()->Setdzis_zab(true);
        return;
    }
    dlugosc =dl;
    int mnoznik = zw->Getnazewnatrz();
    if(odpowiednia_zabawa(zw->GetId())) //to odpowiednia zabawa dla tego typu zwierzatka
    {
        zw->GetParam()->obnizglodisen(-2,-1);
        zw->GetParam()->dodaj_czas_akcji(dl);
        reg_zdrowia = dl+5;
        reg_samopoczucia = dl*2+13;
        if(nazwa_akt == "nazewnatrz")
            reg_zdrowia += (0.5*mnoznik);
        zw->GetParam()->aktualizujZS(reg_zdrowia, reg_samopoczucia);
    }
    else
    {
        zw->GetParam()->obnizglodisen(-2,-2);
        zw->GetParam()->dodaj_czas_akcji(dl);
        reg_zdrowia = 1;
        reg_samopoczucia = -8;
        zw->GetParam()->aktualizujZS(reg_zdrowia, reg_samopoczucia);
    }  
    zw->GetParam()->Setdzis_zab(true);
}
