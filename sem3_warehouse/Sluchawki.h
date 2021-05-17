#pragma once
#include <iostream>
#include "sprzet.h"
class Sluchawki :
    public Sprzet
{
    bool _przewodowa;
    bool _mikrofon;
    int _pasmo; //maksymalne pasmo przenoszenia
    char _rodzaj; //studyjne, gamingowe, 
    Sluchawki* _nast;
public:
    void SetPrzew(bool);
    void SetRodzaj(char);
    void SetMikro(bool);
    void SetPasmo(int);
    void SetNextSluchawki(Sluchawki*);

    bool GetPrze() const { return _przewodowa; }
    char GetRodz() const { return _rodzaj; }
    bool GetMikro() const { return _mikrofon; }
    int GetPasmo() const { return _pasmo; }
    Sluchawki* GetNext() const { return _nast; }

    void DodajCharakt();
    
    friend std::ostream& operator<<(std::ostream& os, const Sluchawki& m);

    Sluchawki();
   // ~Sluchawki();

};

