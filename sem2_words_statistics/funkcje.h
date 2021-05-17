/** @file */

#ifndef FUNKCJE_H
#define FUNCKJE_H

#include <stdlib.h>


#include "struktury.h"

/** OPIS CO ROBI FUNKCJA
@param parametr
@return co zwraca */

/** Funkcja dodaje s�owo do posortowanej listy wg d�ugo�ci wyraz�w
@param glowa - wska�nik na pierwszy element listy
@param dod_slowo - s�owo kt�re chcemy doda�
@param dod_dlugosc - d�ugo�� s�owa kt�re dodajemy
*/
void dodaj_slowo(slowo** glowa, char* dod_slowo, int dod_dlugosc);

/** Funkcja pomocnicza wypisujaca strukture
@param glowa struktury
*/
void wypiszslowa(slowo* glowa);

/** Funkcja wypisuje statystyke s��w ze struktury slowo
@param glowa - przekazujemy wska�nik na struktur�
@param zn_interp - przekazujemy ilo�� znak�w o d�ugosci 0
@param strumien - przekazujemy strumie� w kt�rym ma zosta� wypisana statystyka
*/
void wypiszstatystyke(slowo* glowa, int zn_interp ,FILE * strumien);

/** Funkcja wypisuje podan� przez argument ilo�� najd�u�szych s��w
@param glowa - przekazujemy wska�nik na strukture
@param ilosc - ile s��w nale�y wypisa�
@param strumien - przekazujemy strumie� w kt�rym ma zosta� wypisana statystyka
*/
void wypisznajdluzsze(slowo* glowa, int ilosc, FILE * strumien);

/** Funkcja wypisuje podan� przez argument ilo�� najcz�ciej wyst�puj�cych s��w na podany strumie�
@param glowa - przekazujemy wska�nik na strukture
@param ilosc - ile s��w nale�y wypisa�
@param strumien - przekazujemy strumie� w kt�rym ma zosta� wypisana statystyka
*/
void wypisznajczestsze(slowo* glowa, int ilosc, FILE* strumien);

/** Funkcja czy�ci pami��
@param glowa - przekazujemy g�owe naszej struktury
*/
void usun(slowo** glowa);


#endif