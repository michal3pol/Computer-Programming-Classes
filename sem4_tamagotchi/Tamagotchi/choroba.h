#ifndef CHOROBA_H
#define CHOROBA_H

#include <atomic>

#include "string"

class Choroba
{
    std::string nazwa;
    std::string ograniczenie;
    std::string odp_lekarz;

    std::atomic<int> minus_zdrowie;
    int wymagane_wizyty;
    int dzien_poprz_wizyty = 0;
    bool pierwsza_wizyta = true;

public:
    Choroba(int);
    Choroba(int, int, int, int);

    std::string Getodp_lek() {return odp_lekarz;}
    std::string Getogr() {return ograniczenie;}
    std::string Getnazwa() {return nazwa;}
    int Getmin_zdr() {return minus_zdrowie;}
    int Getwym_wiz() {return wymagane_wizyty;}
    int Getdz_p_wiz() {return dzien_poprz_wizyty;}
    bool Getpierw_wiz() {return pierwsza_wizyta;}

    void Setwym_wiz(int a) {wymagane_wizyty =a;}
    void Set_dzien_p_wiz(int a) {dzien_poprz_wizyty =a;}
    void Setpierw_wiz(bool b) {pierwsza_wizyta =b;}

    void odejm_wiz();

};

#endif // CHOROBA_H
