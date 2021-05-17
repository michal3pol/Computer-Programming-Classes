#include <iostream>
#include<iomanip>
#include <ctime>
#include <crtdbg.h>
#include "Lista_alejek.h"
#include "sprzet.h"
#include "mysz.h"

int main()
{
	Lista_alejek lista;

	std::cout << "Witaj w magazynie sprzetu komputerowego!";

	while (1)
	{
		std::string wybor;
		std::cout << std::endl << "Wybierz co chcesz zrobic:" << std::endl;
		std::cout << "1. Przyjmij element. Uzupelnij zapas" << std::endl;
		std::cout << "2. Wydaj element. Sprzedaz(zapisywane do pliku)" << std::endl;
		std::cout << "3. Sprawdz stan elementu" << std::endl;
		std::cout << "4. Sprawdz miejsce na regalach" << std::endl;
		std::cout << "5. Wczytaj plik." << std::endl;
		std::cout << "6. Zapisz plik" << std::endl;
		std::cout << "7. Zlicz wszystkie elementy" << std::endl;
		std::cout << "8. Zakoncz" << std::endl;
		std::cin >> wybor;
		switch (wybor[0])
		{
		case '1':
		{
			std::string dane, decyzja;
			std::cout << "Podaj lokalizacje alejki(format:A105): ";
			std::cin >> dane;
			if (std::cin.fail())
			{
				std::cout << "Blad w podawaniu formatu!\n";
				break;
			} 
			int nr = (dane[1]-48) * 100 + (dane[2]-48) * 10 + (dane[3]-48) * 1;
			auto tmp = lista.zlokalizujAlejke(dane[0], nr);
			if (tmp == nullptr) { std::cout << "Podana zla alejke"; break; }
			std::cout << "Podaj jakiego rodzaju to sprzet (format: M-mysz, K-klawiatura, S-sluchawki) ";
			std::cin >> decyzja;
			tmp->DodajSprzet(decyzja[0]);
			break;
		}
		case '2':
		{
			std::string dane, decyzja;
			int wuzet;
			std::cout << "Z ktorej alejki zabrales przedmiot?(format:A105): ";
			std::cin >> dane;
			int nr = (dane[1] - 48) * 100 + (dane[2] - 48) * 10 + (dane[3] - 48) * 1;
			auto tmp = lista.zlokalizujAlejke(dane[0], nr);
			if (tmp == nullptr) { std::cout << "Podana zla alejke"; break; }
			std::cout << "Podaj jakiego rodzaju to sprzet (format: M-mysz, K-klawiatura, S-sluchawki) ";
			std::cin >> decyzja;
			std::cout << "Podaj nr WZ sprzedawanego sprzetu: ";
			std::cin >> wuzet;
			std::cout << tmp->Sprzedaj(decyzja[0], wuzet);
			break;
		}
		case '3':
		{
			std::string szukane;
			std::cout << "Ktorego elementu stan chcesz sprawdzic?(format: M-mysz, K-klawiatura, S-sluchawki) ";
			std::cin >> szukane;
			std::cout << "----------------------------------------------------------------" << std::endl;
			auto tmp = lista.GetGLOWAALEJEK();
			tmp->PrzeszukajAlejki(szukane[0]);
			break;
		}
		case '4':
		{
			auto tmp = lista.GetGLOWAALEJEK();
			tmp->ZnajdzMiejsce();
			break;
		}
		case '5':
		{
			std::string nazwa;
			std::cout << "Podaj nazwe pliku z ktorego chcesz odczytac stan magazynu (preferowane rozszerzenie .csv): " << std::endl;
			std::cin >> nazwa;
			lista.OdczytajPlik(nazwa);
			break;
		}
		case '6':
		{
			std::string nazwa;
			std::cout << "Podaj nazwe pliku do ktorego chcesz zapisac stan magazynu (preferowane rozszerzenie .csv): " << std::endl;
			std::cin >> nazwa;
			lista.ZapiszDoPliku(nazwa);
			break;
		}
		case '7':
		{
			++lista;
			break;
		}
		case '8':
		{
			lista.UsunListe();
			_CrtDumpMemoryLeaks();
			return 0;
			break; 
		}
		default:
		{
			std::cout << "PODAJ LICZBE OD 1 DO 7 Z MENU!\n";
			break;
		}
		}

	}
}