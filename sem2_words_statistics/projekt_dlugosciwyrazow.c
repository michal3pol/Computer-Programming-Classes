/** @file */
#define _CRT_SECURE_NO_WARNINGS 
#define _CRTDBG_MAP_ALLOC		

//biblioteki
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h> //?cmath nie dziala?
#include <crtdbg.h>

//pliki
#include "funkcje.h"
#include "struktury.h"


int main(int argc, char* argv[])
{
	
	if (argc < 2)
	{
		printf("Podaj odpowiednie dane\n");
		return 0;
	}
	
	char fnazwa[100];
	char fwyjnazwa[100];
	char najcz_slowa[1000];
	int wynik_najcz_slowa = 0;
	char najdluzsze_slowa [1000];
	int wynik_najdluzsze_slowa = 0;
	int wypisz = 0;
	int zlicz_znaki_interp = 0;

	for (int i = 0; i < argc; ++i)
	{
		
		if (!strcmp (argv[i], "-i")) //plik wejsciowy
		{
			strcpy(fnazwa,  argv[i + 1]);
			i++;
		}
		else if (!strcmp(argv[i], "-n")) //liczba najcześciej występujących słów
		{
			strcpy(najcz_slowa, argv[i + 1]);
			int ilosc_cyfr = strlen(najcz_slowa);
			for (int i = 0; i < ilosc_cyfr; i++)
			{
				int cyfra = najcz_slowa[i] - 48;
				int potega = ilosc_cyfr - (i + 1);
				int mnoznik = pow(10, potega);
				wynik_najcz_slowa = wynik_najcz_slowa + cyfra * mnoznik;
			}
			i++;
		}
		else if (!strcmp(argv[i], "-m")) //liczba słów o największej długości
		{
			strcpy(najdluzsze_slowa, argv[i + 1]);
			int ilosc_cyfr = strlen(najdluzsze_slowa);
			for (int i = 0; i < ilosc_cyfr; i++)
			{
				int cyfra = najdluzsze_slowa[i] - 48;
				int potega = ilosc_cyfr - (i+1);
				int mnoznik = pow(10,potega);
				wynik_najdluzsze_slowa = wynik_najdluzsze_slowa + cyfra*mnoznik;
			}
			i++;
		}
		else if (!strcmp(argv[i], "-o")) //plik wyjściowy
		{
			strcpy(fwyjnazwa , argv[i + 1]);
			i++;
		}
		else if (!strcmp(argv[i], "-p")) //drukuj wyjście na ekran
		{
			wypisz = 1; //da informacje pod koniec programu wby wypisać jego wynik na ekran	
		}
	}

	slowo* glowa = NULL;
	//PLIK WEJSCIOWY
	FILE* fwejsc = fopen(fnazwa, "r");
	if (fwejsc == NULL)
	{
		printf("Nie udało się otworzyć pliku");
		return 0;
	}
	char bufor[50];
	for (int i = 0; i < 50; i++) //wypelnij bufor zerami
	{
		bufor[i] = '\0';
	}
	int licz = 0;
	int a;
	do
	{
		a = fgetc(fwejsc);
		if (a == '.' || a == ' ' || a== '!' || a == '?' || a == ',' || a == ';' || a == ':' || a == ')' || a == '(' || a == '\n' || a == EOF || a == '"' || a == '-') //znak interpunkcyjny
		{
			zlicz_znaki_interp++;
			
			if (bufor[0] != '\0') //dodajemy słowo z bufora do listy
				dodaj_slowo(&glowa, bufor, licz);
			
			for (int i = 0; i < 50; i++) //wyczysc bufor
			{
				licz = 0;
				bufor[i] = '\0'; //?
				if (bufor[i + 1] == '\0') break;
			}
		}
		else 
		{	
			bufor[licz] = a;
			licz++;  //wskazuje długość słowa
		}
	} while (a != EOF);
	fclose(fwejsc);

	//PLIK WYJSCIOWY
	FILE* fwyjsciowy = fopen(fwyjnazwa, "w");
	if (!fwyjsciowy)
	{
		printf("Problem z plikiem wyjsciowym");
		return 0;
	}
	else
	{
		wypiszstatystyke(glowa, zlicz_znaki_interp, fwyjsciowy);
		wypisznajdluzsze(glowa, wynik_najdluzsze_slowa, fwyjsciowy);
		wypisznajczestsze(glowa, wynik_najcz_slowa, fwyjsciowy);
	}
	fclose(fwyjsciowy);


	if (wypisz == 1)
	{
		wypiszstatystyke(glowa, zlicz_znaki_interp, stdout);
		wypisznajdluzsze(glowa, wynik_najdluzsze_slowa, stdout);
		wypisznajczestsze(glowa, wynik_najcz_slowa, stdout);
	}

	//wypiszslowa(glowa);

	usun(&glowa);

	return 0;

}
