/** @file */

#ifndef STRUKTURY_H
#define STRUKTURY_H

/**
Struktura zawierająca wszystkie pojawiające się słowa, zrealizowana za pomocą listy jednokierunkowej posortowanej wg wystąpień
*/
typedef struct slowo_
{
	char* wyraz;     ///< słowo które przeczytaliœmy
	int dlugosc;	 ///< długość tego słowa
	int wystapienia; ///< ilość wystąpień tego słowa
	struct slowo_* nast; ///< wskaźnik na następne słowo

}slowo;



#endif
