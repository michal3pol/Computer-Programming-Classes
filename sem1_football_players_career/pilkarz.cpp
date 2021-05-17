/** @file */

#include <iostream>   
#include <fstream> 
#include <sstream> 
#include <string>
#include <string.h>
#include <iomanip>
#include <ios>

//dołączam własne pliki
#include "struktury.h"
#include "funkcje.h"

using namespace std;


int main(int argc, char* argv[])
{
    if (argc < 2)
    {   
        cout << "Nie podano plików do odczytu! Podaj co najmniej jeden plik do odczytu" << endl;
        return 0; 
    }

    //ODCZYTYWANIE PLIKÓW I TOWRZENIE LIST
    pilkarz* glowa = nullptr;
    for (int i = 1; i < argc; i++)
    {
        string nazwapliku = argv[i];
        odczytaj(nazwapliku, glowa);
    }

    //ZAPISYWANIE DO PLIKÓW Z UTWORZONEJ LISTY
    utworzpliki(glowa);
    //ZWALNIANIE PAMIĘCI
    usunlistepilkarzyisezony(glowa);

    _CrtDumpMemoryLeaks(); //sprawdzenie czy nie ma wycieków pamięci

    return 0;
}
