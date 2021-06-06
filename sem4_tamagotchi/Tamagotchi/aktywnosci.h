#ifndef AKTYWNOSCI_H
#define AKTYWNOSCI_H

#include <string>

class Aktywnosci
{
protected:
    std::string nazwa_akt;
    int reg_zdrowia;
    int reg_samopoczucia;
    //k-kot p-pies, w-wszystkie
    char id_przeznaczenia;

public:
    Aktywnosci();

    const std::string Getnazwaakt() {return nazwa_akt;}
    int Getregsam() {return  reg_samopoczucia;}
    int Getregzdr() {return reg_zdrowia;}
    char Getidprz() {return id_przeznaczenia;}

};

#endif // AKTYWNOSCI_H
