/** @file */

#ifndef FUNKCJE_H
#define FUNCKJE_H

#include <stdlib.h>


#include "struktury.h"

/** OPIS CO ROBI FUNKCJA
@param parametr
@return co zwraca */

/** Funkcja dodaje s³owo do posortowanej listy wg d³ugoœci wyrazów
@param glowa - wskaŸnik na pierwszy element listy
@param dod_slowo - s³owo które chcemy dodaæ
@param dod_dlugosc - d³ugoœæ s³owa które dodajemy
*/
void dodaj_slowo(slowo** glowa, char* dod_slowo, int dod_dlugosc);

/** Funkcja pomocnicza wypisujaca strukture
@param glowa struktury
*/
void wypiszslowa(slowo* glowa);

/** Funkcja wypisuje statystyke s³ów ze struktury slowo
@param glowa - przekazujemy wskaŸnik na strukturê
@param zn_interp - przekazujemy iloœæ znaków o d³ugosci 0
@param strumien - przekazujemy strumieñ w którym ma zostaæ wypisana statystyka
*/
void wypiszstatystyke(slowo* glowa, int zn_interp ,FILE * strumien);

/** Funkcja wypisuje podan¹ przez argument iloœæ najd³u¿szych s³ów
@param glowa - przekazujemy wskaŸnik na strukture
@param ilosc - ile s³ów nale¿y wypisaæ
@param strumien - przekazujemy strumieñ w którym ma zostaæ wypisana statystyka
*/
void wypisznajdluzsze(slowo* glowa, int ilosc, FILE * strumien);

/** Funkcja wypisuje podan¹ przez argument iloœæ najczêœciej wystêpuj¹cych s³ów na podany strumieñ
@param glowa - przekazujemy wskaŸnik na strukture
@param ilosc - ile s³ów nale¿y wypisaæ
@param strumien - przekazujemy strumieñ w którym ma zostaæ wypisana statystyka
*/
void wypisznajczestsze(slowo* glowa, int ilosc, FILE* strumien);

/** Funkcja czyœci pamiêæ
@param glowa - przekazujemy g³owe naszej struktury
*/
void usun(slowo** glowa);


#endif