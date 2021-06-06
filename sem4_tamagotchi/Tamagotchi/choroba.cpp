#include "choroba.h"

Choroba::Choroba(int a)
{
    switch(a)
    {
    case 0:
    {
        nazwa = "Zwichnięta noga";
        ograniczenie = "Zabawa";
        odp_lekarz = "Chirurg";

        minus_zdrowie = -3;
        wymagane_wizyty = 4;
        break;
    }
    case 1:
    {
        nazwa = "Mały guz w jelitach";
        ograniczenie = "Jedzenie";
        odp_lekarz = "Radiolog";

        minus_zdrowie = -5;
        wymagane_wizyty = 6;
        break;
    }
    case 2:
    {
        nazwa = "Wysypka";
        ograniczenie = "brak";
        odp_lekarz = "Dermatolog";

        minus_zdrowie = -2;
        wymagane_wizyty = 3;
        break;
    }
    }

}

Choroba::Choroba(int a, int ww, int dpw, int pw)
{
    switch(a)
    {
    case 0:
    {
        nazwa = "Zwichnięta noga";
        ograniczenie = "Zabawa";
        odp_lekarz = "Chirurg";
        break;
    }
    case 1:
    {
        nazwa = "Mały guz w jelitach";
        ograniczenie = "Jedzenie";
        odp_lekarz = "Radiolog";
        break;
    }
    case 2:
    {
        nazwa = "Wysypka";
        ograniczenie = "brak";
        odp_lekarz = "Dermatolog";
        break;
    }
    }
    wymagane_wizyty = ww;
    dzien_poprz_wizyty =dpw;
    pierwsza_wizyta = pw;

}

void Choroba::odejm_wiz()
{
    wymagane_wizyty--;
}
