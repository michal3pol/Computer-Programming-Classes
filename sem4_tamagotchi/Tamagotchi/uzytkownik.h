#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>
#include <fstream>
#include <list>
#include <sstream>
#include <QListWidget>

#include "jedzenie.h"

class uzytkownik
{
private:
    std::string Nazwa_uzytkownika;
    std::string Haslo;
    std::string Nazwa_pliku_menu;

public:
    uzytkownik(const std::string n , const std::string h );

    //zapisywanie i odczytywanie zwierzatka
    std::vector<int> odczytaj_plik_uzytkownika();
    void zapisz_plik_uzytkownika(zwierze *);

    //obsluga menu uzytkownika
    void odczytaj_plik_menu(std::list<Jedzenie>&);
    void zapisz_plik_menu(const std::list<Jedzenie>);
    void dodaj_posilek(const Jedzenie);
    void dodaj_menu_uz(const std::string,std::list<Jedzenie>&,  QListWidget* );

    //metoda czyszczaca plik uzytkownika po przegranej
    void usun_zwierze();

    bool operator==(const uzytkownik& u1);
    bool operator==(const std::string);
};

#endif // UZYTKOWNIK_H
