/** @file */

#pragma once  //zabezpieczenie przed wielokrotnym do��czniem pliku


#include <iostream>   
#include <fstream> 
#include <sstream> 
#include <string>
#include <string.h>
#include <iomanip>
#include <ios>
using namespace std;


/**
Struktura opisuj�ca sezon dla danego pi�karza, zrealizowana za pomoc� listy jednokierunkowej
*/
struct sezon
{
	string druzyna; ///< dru�yna w kt�rej gra� zawodnik w danym sezonie
	int poczatek; ///< rok w kt�rym sezon si� rozpocz��
	int koniec;   ///< rok w kt�rym sezon si� zako�czy�
	sezon* nast; ///< wska�nik na nast�pny element listy
};

/**
Struktura opisuj�ca pi�karza, zawiera wska�nik na nast�pnego pi�karza (lista jednokierunkowa)
*/
struct pilkarz
{
	string imie; ///< imi� pi�karza
	string nazwisko; ///< nazwisko pi�karza
	pilkarz* nastzawodnik; ///< wska�nik na nast�pnego pi�karza w li�cie pi�karzy 
	sezon* nastsezon; ///< wska�nik na nast�pny sezon w li�cie sezon�w dla danego pi�karza 
};