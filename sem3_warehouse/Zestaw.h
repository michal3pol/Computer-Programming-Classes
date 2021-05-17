#pragma once
#include "Klawiatura.h"
#include "mysz.h"
#include "Sluchawki.h"

class Zestaw :
    public Klawiatura, public Mysz, public Sluchawki 
{
private:
    Klawiatura* _k1;
    Mysz* _m1;
    Sluchawki* _s1;

public:



    Zestaw& operator()(const Klawiatura*&, const Mysz*&,const Sluchawki*&);

};

