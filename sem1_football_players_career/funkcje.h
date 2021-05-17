/** @file */

#pragma once  //zabezpieczenie przed wielokrotnym do��czniem pliku

#include <iostream>   
#include <fstream> 
#include <sstream> 
#include <vector>
#include <string>
#include <string.h>
#include <iomanip>
#include <ios>

#include "struktury.h"
using namespace std;

/** Funkcja dodaje pi�karza na koniec listy je�li jeszcze go w niej nie ma 
@param[in,out] zawodnik przekazujemy dane pilkarza kt�rego chcemy doda�
@param[in,out] glowa przekazujemy g�ow� listy pi�karzy
*/
void dodajpilkarzadolisty(pilkarz& zawodnik, pilkarz*& glowa);

/** Funkcja odczytuje plik tekstowy i korzystaj�c z funkcji dodajpilkarzadolisty oraz dodajsezondlapilkarza uzupe�nia list� odpowiednimi warto�ciami
@param tekst nazwa pliku tekstowego do odczytu
@param[in, out] glowa przekazujemy g�ow� listy
*/
void odczytaj(string tekst, pilkarz*& glowa);


/**Funkcja dodaje sezon dla pi�karza, czyli dru�yn� i lata w kt�rych gra� do listy podwieszonej od razu sortuj�c wed�ug roku rozpocz�cia sezonu
@param glowa przekazujemy wska�nik na list� pi�karzy
@param zawodnik przekazjemy pilkarza dla kt�rego chcemy doda� nowy sezon
@param[in, out] druzyna jest to nazwa dru�yny w kt�rej gra� pi�karz
@param[in, out] poczsezonu przekazujemy rok w kt�rym sezon si� rozpocz��
@param[in, out] konsezonu przekazujemy rok w kt�rym seozn si� zako�czy�
*/
void dodajsezondlapilkarza(pilkarz* glowa, pilkarz zawodnik, string& druzyna, int& poczsezonu, int& konsezonu);

/**Funkcja tworzy pliki przebiegu kariery dla pi�karzy znajduj�cych si� w li�cie
@param glowa przekazujemy wska�nik na list� pi�karzy
*/
void utworzpliki(pilkarz* glowa);


/**Funkcja usuwa list� pi�arzy i ich sezony
@param[in,out] glowa przekazujemy wska�nik na list� pi�karzy
*/
void usunlistepilkarzyisezony(pilkarz*& glowa);

/**Funkcja usuwa list� sezon�w pi�karzy
@param[in,out] nast przekazujemy wska�nik na list� sezon�w
*/
void usunsezony(sezon*& nast);
