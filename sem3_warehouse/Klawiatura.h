#pragma once
#include <iostream>
#include "sprzet.h"
class Klawiatura :
    public Sprzet
{
    bool _przewodowa; //tak,nie
    char _rodzaj; //mechaniczna, membranowa, hybryda
    Klawiatura* _nast;
public:
    void SetPrzew(bool);
    void SetRodzaj(char);
    void SetNextKlawiatura(Klawiatura*);

    bool GetPrze() const { return _przewodowa; }
    char GetRodz() const { return _rodzaj; }
    Klawiatura* GetNext() const { return _nast; }

    void DodajCharakt();

    Klawiatura();

    friend std::ostream& operator<<(std::ostream& os, const Klawiatura& m);
};

