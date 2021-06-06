#ifndef JEDZENIE_H
#define JEDZENIE_H

#include "aktywnosci.h"
#include "zwierze.h"

class Jedzenie : public Aktywnosci
{
    std::string nazwa_posilku;
    int kalorycznosc;

public:
    Jedzenie(const std::string, const std::string, int, char);

    const std::string Get_nazwa() {return nazwa_posilku;}
    int Getkalor() {return kalorycznosc;}

    void zjedz(zwierze*);

    bool operator==(const std::string);
    friend std::ostream& operator<<(std::ostream&, Jedzenie&);

};

#endif // JEDZENIE_H
