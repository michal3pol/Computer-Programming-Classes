#ifndef ZABAWA_H
#define ZABAWA_H

#include "aktywnosci.h"
#include "zwierze.h"

class Zabawa : public Aktywnosci
{
    std::string nazwa_zabawy;
    int dlugosc;
public:
    Zabawa(const std::string,const std::string, char);

    const std::string Get_nazwa() {return nazwa_zabawy;}

    bool odpowiednia_zabawa(char);
    void baw_sie(zwierze*, int);

    bool operator==(const std::string);
};

#endif // ZABAWA_H
