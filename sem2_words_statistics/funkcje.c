/** @file */

#define _CRT_SECURE_NO_WARNINGS 

//biblioteki
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



//pliki
#include "funkcje.h"
#include "struktury.h"


void dodaj_slowo(slowo** glowa, char* dod_slowo, int dod_dlugosc)
{
	int dodane = 0;
	if ((*glowa) == NULL) //pierwszy element
	{
		(*glowa) = malloc(sizeof(slowo));
		(*glowa)->wyraz = malloc(sizeof(char) * (dod_dlugosc+1));
		strcpy((*glowa)->wyraz , dod_slowo);
		(*glowa)->dlugosc = dod_dlugosc;
		(*glowa)->nast = NULL;
		(*glowa)->wystapienia =1;
		dodane++;
	}

	slowo* tmp = (*glowa);
	while (tmp && dodane == 0) //sprawdzamy czy dane slowo wystepuje juz w liscie
	{
		if (strcmp(tmp->wyraz, dod_slowo)==0)
		{
			tmp->wystapienia = tmp->wystapienia + 1;
			dodane++;
		}
		else
			tmp = tmp->nast;
	}
	slowo* tmp1 = (*glowa);
	while (tmp1 && dodane == 0) //jesli nalezy dodac slowo
	{	
		if (dod_dlugosc > (*glowa)->dlugosc) //nale¿y dodaæ na poczatek
		{
			slowo* nowy = malloc(sizeof(slowo));
			nowy->wyraz = malloc(sizeof(char) * (dod_dlugosc + 1));
			strcpy(nowy->wyraz , dod_slowo);
			nowy->dlugosc = dod_dlugosc;
			nowy->nast = (*glowa);
			nowy->wystapienia = 1;
			(*glowa) = nowy;
			dodane++;
		}
		else if (tmp1->nast != NULL && tmp1->nast->dlugosc < dod_dlugosc) //zatrzymujemy sie przed pierwszym mniejszym
		{
			slowo* nowy = malloc(sizeof(slowo));
			nowy->wyraz = malloc(sizeof(char) * (dod_dlugosc + 1));
			strcpy(nowy->wyraz, dod_slowo);
			nowy->dlugosc = dod_dlugosc;
			nowy->wystapienia = 1;
			nowy->nast = tmp1->nast;
			tmp1->nast = nowy;
			dodane++;
		}
		else if (tmp1->nast == NULL) //nalezy dodac na koniec
		{
			slowo* nowy = malloc(sizeof(slowo));
			nowy->wyraz = malloc(sizeof(char) * (dod_dlugosc + 1));
			strcpy(nowy->wyraz, dod_slowo);
			nowy->dlugosc = dod_dlugosc;
			nowy->wystapienia = 1;
			tmp1->nast = nowy;
			nowy->nast = NULL;
			dodane++;
		}
		else
			tmp1 = tmp1->nast;

	}
}

void wypiszstatystyke(slowo* glowa, int zn_interp,FILE* strumien)
{
	int aktualna_dlugosc = glowa->dlugosc;
	int suma_slow=0;
	while (glowa != NULL)
	{
		if (glowa->dlugosc == aktualna_dlugosc)
			suma_slow= suma_slow + glowa->wystapienia;
		else 
		{
			fprintf(strumien, "Slowa o dlugosci  %d  wystepuja  %d  razy w pliku.\n", aktualna_dlugosc, suma_slow);
			aktualna_dlugosc = glowa->dlugosc;
			suma_slow = glowa->wystapienia;
		}
		if (glowa->nast == NULL)
		{
		fprintf(strumien, "Slowa o dlugosci  %d  wystepuja  %d  razy w pliku.\n", glowa->dlugosc, suma_slow);
		}
		glowa = glowa->nast;
	}
	fprintf(strumien, "Slowa o dlugosci  0  wystepuja  %d  razy w pliku.(znaki interpunkcyjne, spacje itp)\n", (zn_interp-1));

}

void wypisznajdluzsze(slowo* glowa, int ilosc, FILE* strumien)
{
	int numer = 1;
	fprintf(strumien ,"%d NAJDLUZSZYCH SLOW\n", ilosc);
	while (glowa != NULL && ilosc >0)
	{
		fprintf(strumien,"%d. Slowo: %s o dlugosci %d \n",numer, glowa->wyraz, glowa->dlugosc);
		glowa = glowa->nast;
		ilosc--;
		numer++;
	}
}

void wypisznajczestsze(slowo* glowa, int ilosc, FILE* strumien)
{
	//znajdz maximum
	slowo* tmp = glowa;
	int max = 0;
	while (tmp)
	{
		if (tmp->wystapienia > max)
			max = tmp->wystapienia;
		
		tmp = tmp->nast;
	}
	fprintf(strumien, "%d. NAJCZESCIEJ WYSTEPUJACYCH SLOW\n", ilosc);
	size_t max_petle = 9999999999;
	int numer = 1;
	for (int i = 0; i < max_petle; i++)
	{
		slowo* tmp1 = glowa;
		while (tmp1 && ilosc >0)
		{
			if (tmp1->wystapienia == max)
			{
				fprintf(strumien, "%d. Slowo: %s wystapilo %d razy \n", numer, tmp1->wyraz, tmp1->wystapienia);
				numer++;
				ilosc--;
			}
			tmp1 = tmp1->nast;
		}
		max--;
		if (ilosc == 0)
			break;
	}
}

void usun(slowo** glowa)
{
	while (*glowa)
	{
		free((*glowa)->wyraz);  
		slowo* tmp = (*glowa)->nast;
		free(*glowa);
		(*glowa) = tmp;
	}	
}

void wypiszslowa(slowo* glowa)
{
	while (glowa != NULL)
	{
		printf("%s wystapilo %d jego dlugosc %d \n", glowa->wyraz, glowa->wystapienia, glowa->dlugosc);
		glowa = glowa->nast;
	}
	printf("\n");
}