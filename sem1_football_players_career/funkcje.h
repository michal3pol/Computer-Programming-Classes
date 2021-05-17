/** @file */

#pragma once  //zabezpieczenie przed wielokrotnym do³¹czniem pliku

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

/** Funkcja dodaje pi³karza na koniec listy jeœli jeszcze go w niej nie ma 
@param[in,out] zawodnik przekazujemy dane pilkarza którego chcemy dodaæ
@param[in,out] glowa przekazujemy g³owê listy pi³karzy
*/
void dodajpilkarzadolisty(pilkarz& zawodnik, pilkarz*& glowa);

/** Funkcja odczytuje plik tekstowy i korzystaj¹c z funkcji dodajpilkarzadolisty oraz dodajsezondlapilkarza uzupe³nia listê odpowiednimi wartoœciami
@param tekst nazwa pliku tekstowego do odczytu
@param[in, out] glowa przekazujemy g³owê listy
*/
void odczytaj(string tekst, pilkarz*& glowa);


/**Funkcja dodaje sezon dla pi³karza, czyli dru¿ynê i lata w których gra³ do listy podwieszonej od razu sortuj¹c wed³ug roku rozpoczêcia sezonu
@param glowa przekazujemy wskaŸnik na listê pi³karzy
@param zawodnik przekazjemy pilkarza dla którego chcemy dodaæ nowy sezon
@param[in, out] druzyna jest to nazwa dru¿yny w której gra³ pi³karz
@param[in, out] poczsezonu przekazujemy rok w którym sezon siê rozpocz¹³
@param[in, out] konsezonu przekazujemy rok w którym seozn siê zakoñczy³
*/
void dodajsezondlapilkarza(pilkarz* glowa, pilkarz zawodnik, string& druzyna, int& poczsezonu, int& konsezonu);

/**Funkcja tworzy pliki przebiegu kariery dla pi³karzy znajduj¹cych siê w liœcie
@param glowa przekazujemy wskaŸnik na listê pi³karzy
*/
void utworzpliki(pilkarz* glowa);


/**Funkcja usuwa listê pi³arzy i ich sezony
@param[in,out] glowa przekazujemy wskaŸnik na listê pi³karzy
*/
void usunlistepilkarzyisezony(pilkarz*& glowa);

/**Funkcja usuwa listê sezonów pi³karzy
@param[in,out] nast przekazujemy wskaŸnik na listê sezonów
*/
void usunsezony(sezon*& nast);
