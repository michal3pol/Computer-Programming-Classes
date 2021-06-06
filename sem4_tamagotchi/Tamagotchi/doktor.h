#ifndef DOKTOR_H
#define DOKTOR_H

#include <string>
#include <vector>

#include <QMessageBox>

#include "zwierze.h"

class Doktor
{
    std::string imie;
    std::string nazwisko;
    std::string specjalizacja;

    std::vector<std::string> diagnozy; //pod [0] nieodpowiedni lekarz

public:
    Doktor();
    void stworz_dok(const std::string, const std::string, const std::string, const std::string, const std::string);

    void wizyta(zwierze *);
};

#endif // DOKTOR_H
