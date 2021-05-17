/** @file */

#pragma once  //zabezpieczenie przed wielokrotnym do³¹czniem pliku


#include <iostream>   
#include <fstream> 
#include <sstream> 
#include <string>
#include <string.h>
#include <iomanip>
#include <ios>
using namespace std;


/**
Struktura opisuj¹ca sezon dla danego pi³karza, zrealizowana za pomoc¹ listy jednokierunkowej
*/
struct sezon
{
	string druzyna; ///< dru¿yna w której gra³ zawodnik w danym sezonie
	int poczatek; ///< rok w którym sezon siê rozpocz¹³
	int koniec;   ///< rok w którym sezon siê zakoñczy³
	sezon* nast; ///< wskaŸnik na nastêpny element listy
};

/**
Struktura opisuj¹ca pi³karza, zawiera wskaŸnik na nastêpnego pi³karza (lista jednokierunkowa)
*/
struct pilkarz
{
	string imie; ///< imiê pi³karza
	string nazwisko; ///< nazwisko pi³karza
	pilkarz* nastzawodnik; ///< wskaŸnik na nastêpnego pi³karza w liœcie pi³karzy 
	sezon* nastsezon; ///< wskaŸnik na nastêpny sezon w liœcie sezonów dla danego pi³karza 
};