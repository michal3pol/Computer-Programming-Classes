#pragma once
#include "sprzet.h"
#include<string>

class Mysz :
    public Sprzet
{
    bool _przewodowa; //tak,nie
    char _rodzaj; //mechaniczna(kulkowa), diodowa, laserowa
    Mysz* _nast;

public:
    void SetPrzew(bool);
    void SetRodzaj(char);
    void SetNextMysz(Mysz*);

    bool GetPrze() const { return _przewodowa; }
    char GetRodz() const { return _rodzaj; }
    Mysz* GetNext() const { return _nast; }

    void DodajCharakt();

    Mysz();
   // ~Mysz(); ?? powoduje problemu przy usuwaniu pojedynczego elementu, i zapamietaniu reszty listy

    friend std::ostream& operator <<(std::ostream& os, const Mysz& m);
};

