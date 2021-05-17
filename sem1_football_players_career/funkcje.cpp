/** @file */

#include <iostream>   
#include <fstream> 
#include <sstream> 
#include <string>
#include <string.h>
#include <iomanip>
#include <ios>

#include "funkcje.h"

using namespace std;


void dodajpilkarzadolisty(pilkarz& zawodnik, pilkarz*& glowa)
{
	if (not glowa) //jeœli lista pusta
		glowa = new pilkarz{ zawodnik.imie, zawodnik.nazwisko, nullptr, nullptr };
	else
	{
		auto p = glowa; //g³owe podaliœmy przez referencje wiêc teraz nie mo¿emy jej zmieniaæ - potrzebujemy zmiennej
		bool dodaj = 1; //dodaj jest prawd¹
		while (p->nastzawodnik)
		{
			if (p->imie == zawodnik.imie and p->nazwisko == zawodnik.nazwisko) //jeœli taki zawodnik jest ju¿ w liœcie
				dodaj = 0; //zmieñ "dodaj" na fa³sz -> nie dodamy zawodnika

			p = p->nastzawodnik;
		}
		//p wskazuje na ostatni element listy
		if (dodaj) //jeœli "dodaj" jest prawd¹ - dodaj pi³karza NA KONIEC
			p->nastzawodnik = new pilkarz{ zawodnik.imie, zawodnik.nazwisko, nullptr, nullptr };
	}
}

void dodajsezondlapilkarza(pilkarz* glowa, pilkarz zawodnik, string& druzyna, int& poczsezonu, int& konsezonu)
{
	int dodane = 0;

	while (glowa)
	{
		if (glowa->imie == zawodnik.imie and glowa->nazwisko == zawodnik.nazwisko) //lokalizujemy pi³karza w liœcie dla którego chcemy dodaæ sezon
		{
			auto ps = glowa->nastsezon;
			if (not ps) //jeœli lista sezonów jest pusta dodaj na pocz¹tek
			{
				glowa->nastsezon = new sezon{ druzyna, poczsezonu, konsezonu, glowa->nastsezon };
				dodane++;

			}
			//DODAWANIE Z SORTOWANIEM LISTY!
			while (ps and dodane == 0)
			{
				if ((ps->poczatek) > poczsezonu)
				{
					glowa->nastsezon = new sezon{ druzyna, poczsezonu, konsezonu, glowa->nastsezon }; // dodajemy na pocz¹tek
					dodane++;
				}
				else if ((ps->nast) != nullptr /*jeœli nastêpny wgl istnieje*/ and (ps->nast->poczatek) > poczsezonu) //glowa zatrzymuje sie na liczbie po ktorej mamy dodac, bo sprawdza wartosc "po dodanej"
				{
					auto pododanej = ps->nast;
					ps->nast = new sezon{ druzyna, poczsezonu, konsezonu, pododanej };
					dodane++;
				}
				else if ((ps->nast) == nullptr) //doszliœmy do koñca listy
				{
					ps->nast = new sezon{ druzyna, poczsezonu, konsezonu, nullptr };
					dodane++;
				}
				else // ¿aden z powy¿szych -> idŸ do nastêpnego sezonu
					ps = ps->nast;

			}
			return;
		}
		else //jeœli to nie ten pi³karz, idŸ do nastêpnego
			glowa = glowa->nastzawodnik;
	}
}


void odczytaj(string tekst, pilkarz*& glowa)
{
	ifstream plik(tekst);
	
	int nr_linii = 1;
	int pocz, kon; //zmienna pokazuj¹ca któr¹ linijke sprawdzamy
	string linia, sezonpocz, sezonkon, nazwadruzyny;
	stringstream sezon; //zapamietujemy nazwe druzyny, poczatek i koniec sezonu
	string imie, nazwisko;
	pilkarz zawodnik;

	if (plik)
	{
		
			while (getline(plik, linia))
			{

				switch (nr_linii)
				{
				case 1:								//w pierwszej linijce ka¿dego pliku jest nazwa dru¿yny
					nazwadruzyny = linia;
					nr_linii++;
					break;

				case 2:									 // w drugiej linijce pliku zapisane s¹ sezony
					sezon << linia;						//pobieramy ca³¹ linijke...
					sezon >> sezonpocz >> sezonkon;  // ...i rozdzielamy wg spacji (bia³ych znaków)

					pocz = stoi(sezonpocz);
					kon = stoi(sezonkon);

					nr_linii++;
					break;

				default:									 //kolejne linijki to imiona i nazwiska zawodników
				{
					stringstream im_nazw;
					im_nazw << linia;
					im_nazw >> imie >> nazwisko;

					zawodnik.imie = imie;
					zawodnik.nazwisko = nazwisko;
					dodajpilkarzadolisty(zawodnik, glowa);
					dodajsezondlapilkarza(glowa, zawodnik, nazwadruzyny, pocz, kon);

					nr_linii++;

					break;
				}
				}

			}
		
	}
	else
		cout << "Podany plik: " << tekst << " nie istnieje!" << endl;


	plik.close();
}

void utworzpliki(pilkarz* glowa)
{
	while (glowa) //dla ka¿dego zawodnika w liœcie
	{

		string nazwapliku = (glowa->imie) + (glowa->nazwisko);
		ofstream kariera(nazwapliku); //tworzymy nowy plik

		if (kariera) // sprawdzenie czy plik otwarty
		{
			auto ps = glowa->nastsezon;
			while (ps)
			{
				kariera << ps->druzyna << endl;
				kariera << ps->poczatek << " - " << ps->koniec << endl;
				ps = ps->nast;
			}

			kariera.close();
		}

		glowa = glowa->nastzawodnik; //nastêpny zawodnik
	}
}



void usunsezony(sezon*& nast)
{
	if (nast)
	{
		usunsezony(nast->nast);
		delete nast;
		nast = nullptr;
	}
}


void usunlistepilkarzyisezony(pilkarz*& glowa)
{
	if (glowa)
	{
		//usuñ sezony dla pi³karza
		usunsezony(glowa->nastsezon);

		//a póŸniej usuñ liste pi³akrzy
		usunlistepilkarzyisezony(glowa->nastzawodnik);
		delete glowa;
		glowa = nullptr;
	}
}





