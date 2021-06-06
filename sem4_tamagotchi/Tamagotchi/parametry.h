#ifndef PARAMETRY_H
#define PARAMETRY_H

#include <thread>
#include <iostream>
#include <chrono>
#include <random>
#include <atomic>
#include <cstdlib>
#include <time.h>
#include <QMessageBox>
#include <QLCDNumber>
#include <QProgressBar>
#include <QStackedWidget>

#include "choroba.h"

class Parametry
{
    //czas
    std::chrono::system_clock::time_point pocz_zycia;
    std::atomic<int> godzina;

    //progessbary
    std::atomic<int> zdrowie;
    std::atomic<int> samopoczucie;
    std::atomic<int> dni;

    //aktywnosc danego dnia
    std::atomic<bool> dzis_zabawa =false;
    std::atomic<bool> dzis_sen =false;
    std::atomic<bool> dzis_jedzenie =false;

    //poziomy
    int poziom_glodu =0;
    int poziom_snu =0;

    QStackedWidget* wskWidget;
public:

    Parametry(QStackedWidget*);

    //set
    void Setgodzina(int h) {godzina =h;}
    void Setzdrowie(int z) {zdrowie = z;}
    void Setsamopoczucie(int s) {samopoczucie =s;}
    void Setdni(int d) {dni =d;}
    void Setpzglodu(int p) {poziom_glodu += p;}
    void Setpzsnu(int p) {poziom_snu += p;}
    void Setdzis_zab(bool b) {dzis_zabawa = b;}
    void Setdzis_sen(bool b) {dzis_sen = b;}
    void Setdzis_jedz(bool b) {dzis_jedzenie = b;}

    int Getgodzina() {return godzina;}
    int Getzdrowie() {return zdrowie;}
    int Getsamopoczucie() {return samopoczucie;}
    int Getdni() {return dni;}    
    int Getpoz_glodu() {return poziom_glodu;}
    int Getpoz_snu() {return poziom_snu;}

    void aktualizujZS(int, int);

    void zlicz15s(QLCDNumber *, QLCDNumber *, QLCDNumber *, std::shared_ptr<Choroba>&);

    void dodaj_czas_akcji(int);

    void obnizglodisen(int, int);

};

#endif // PARAMETRY_H
