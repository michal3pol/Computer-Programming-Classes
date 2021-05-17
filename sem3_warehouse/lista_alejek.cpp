#include "Lista_alejek.h"
#include <fstream>
#include <iostream>
#include <sstream>

void Lista_alejek::UsunListe()
{
	auto tmp = _glowaALEJKA;
	while (tmp)
	{
		auto bufor_a = tmp->GetNext();
		tmp->UsunAlejke();
		tmp = bufor_a;
	}

	_glowaALEJKA = nullptr;
}

Lista_alejek::Lista_alejek()
{
	_glowaALEJKA = nullptr;
	for (int i = 0; i < 6; i++)
	{
		if (_glowaALEJKA == nullptr)
		{
			Alejka* nowy = new Alejka;
			nowy->SetId('D');
			nowy->SetNr(105);
			nowy->SetNext(nullptr);
			_glowaALEJKA = nowy;
		}
		else
		{
			Alejka* nowy = new Alejka;
			nowy->SetId('D');
			nowy->SetNr(105-i);
			nowy->SetNext(_glowaALEJKA);
			_glowaALEJKA = nowy;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		Alejka* nowy = new Alejka;
		nowy->SetId('C');
		nowy->SetNr(105 - i);
		nowy->SetNext(_glowaALEJKA);
		_glowaALEJKA = nowy;
	}
	for (int i = 0; i < 6; i++)
	{
		Alejka* nowy = new Alejka;
		nowy->SetId('B');
		nowy->SetNr(105 - i);
		nowy->SetNext(_glowaALEJKA);
		_glowaALEJKA = nowy;
	}for (int i = 0; i < 6; i++)
	{
		Alejka* nowy = new Alejka;
		nowy->SetId('A');
		nowy->SetNr(105 - i);
		nowy->SetNext(_glowaALEJKA);
		_glowaALEJKA = nowy;
	}
}

int& Lista_alejek::operator++()
{
	int liczba = 0;
	int liczba1=0;
	int liczba2 = 0;
	int liczba3 = 0;
	auto tmp = _glowaALEJKA;
	while (tmp)
	{
		auto tmp1 = tmp->GetGlowaKlawiatura();
		auto tmp2 = tmp->GetGlowaMysz();
		auto tmp3 = tmp->GetGlowaSluchawki();
		while (tmp1)
		{
			liczba++;
			liczba1++;
			tmp1 = tmp1->GetNext();
		}
		while (tmp2)
		{
			liczba++;
			liczba2++;
			tmp2 = tmp2->GetNext();
		}
		while (tmp3)
		{
			liczba++;
			liczba3++;
			tmp3 = tmp3->GetNext();
		}
		tmp = tmp->GetNext();
	}

	std::cout << "W magazynie znajduje sie " << liczba << " elementow\n";
	std::cout << "w tym " << liczba1 << " klawiatur\n";
	std::cout << "w tym " << liczba2 << " myszek\n";
	std::cout << "w tym " << liczba3 << " sluchawek\n";

	return liczba;
	// TODO: tu wstawiæ instrukcjê return
}

void Lista_alejek::wypiszAlejki()
{
	auto tmp = _glowaALEJKA;
	while (tmp)
	{
		std::cout << "Alejka: " << tmp->GetId() << tmp->GetNr() << std::endl;
		tmp = tmp->GetNext();
	}
}

void Lista_alejek::OdczytajPlik(std::string nazwa)
{
	std::ifstream plik(nazwa);
	if (plik)
	{
		std::string linia;
		while (std::getline(plik, linia))
		{
			std::string id, snr, rodzaj;
			std::istringstream ss(linia);
			//pobranie inf o alejce
			std::getline(ss, id, ',');
			std::getline(ss, snr, ',');
			int nr = stoi(snr);
			std::getline(ss, rodzaj, ','); //jaki to sprzet
			auto tmp = zlokalizujAlejke(id[0], nr);
			int tab[9]; //tablica zapisuje podstawowe inf o sprzecie
			for (size_t i = 0; i < 9; i++)
			{
				std::string dana;
				std::getline(ss, dana, ',');
				int dana_jako_int = stoi(dana);
				tab[i] = dana_jako_int;
			}
			switch (rodzaj[0])
			{
			case 'M':
			{
				int tab1[1]; //w tym przypadku nie ma sensu, ale jest to uogolnienie, bo inne sprzety moga miec wiecej "intowych" danych 
				std::string przewod, rodzaj_sprzetu;
				std::getline(ss, przewod, ',');
				int przewod_jako_int = stoi(przewod);
				tab1[0] = przewod_jako_int;
				std::getline(ss, rodzaj_sprzetu);
				tmp->DodajSprzetZPliku(rodzaj[0], tab, tab1, rodzaj_sprzetu[0]);
				break;
			}
			case 'K':
			{
				int tab1[1]; //w tym przypadku nie ma sensu, ale jest to uogolnienie, bo inne sprzety moga miec wiecej "intowych" danych 
				std::string przewod, rodzaj_sprzetu;
				std::getline(ss, przewod, ',');
				int przewod_jako_int = stoi(przewod);
				tab1[0] = przewod_jako_int;
				std::getline(ss, rodzaj_sprzetu);
				tmp->DodajSprzetZPliku(rodzaj[0], tab, tab1, rodzaj_sprzetu[0]);
				break;
			}
			case 'S':
			{
				int tab1[3]; //tutaj ma wiekszy sens
				std::string rodzaj_sprzetu;
				for (size_t i = 0; i < 3; i++)
				{
					std::string danaS;
					std::getline(ss, danaS, ',');
					int danaS_jako_int = stoi(danaS);
					tab1[i] = danaS_jako_int;
				}
				std::getline(ss, rodzaj_sprzetu);
				tmp->DodajSprzetZPliku(rodzaj[0], tab, tab1, rodzaj_sprzetu[0]);
				break;
			}
			default:
			{
				std::cout << "W pliku wejsciowym zle podany rodzaj sprzetu!\n";
				break;
			}

			}
		}
	}
	plik.close();
}

void Lista_alejek::ZapiszDoPliku(std::string nazwa)
{
	std::ofstream plik(nazwa);
	auto tmp = _glowaALEJKA;
	if (plik)
	{
		while (tmp)
		{
			if (tmp->GetGlowaMysz() != nullptr)
			{
				auto tmpGL = tmp->GetGlowaMysz();
				while (tmpGL)
				{
					Sprzet* tmp1 = tmpGL;
					//podstawowe inf
					plik << tmp->GetId() << ',' << tmp->GetNr() << ',' << tmp1->Getcoto() << ',' << tmp1->GetWZ() << ',' << tmp1->GetPROD_d() << ',' << tmp1->GetPROD_m() << ',' << tmp1->GetPROD_r() << ',' << tmp1->GetWYD_h() << ',' << tmp1->GetWYD_min() << ',' << tmp1->GetWYD_d() << ',' << tmp1->GetWYD_m() << ',' << tmp1->GetWYD_r();
					//charakterystyczne
					plik << ',' << tmpGL->GetPrze() << ',' << tmpGL->GetRodz();
					plik << std::endl;
					tmpGL = tmpGL->GetNext();
				}
			}
			if (tmp->GetGlowaKlawiatura() != nullptr)
			{
				auto tmpGL = tmp->GetGlowaKlawiatura();
				while (tmpGL)
				{
					Sprzet* tmp1 = tmpGL;
					//podstawowe inf
					plik << tmp->GetId() << ',' << tmp->GetNr() << ',' << tmp1->Getcoto() << ',' << tmp1->GetWZ() << ',' << tmp1->GetPROD_d() << ',' << tmp1->GetPROD_m() << ',' << tmp1->GetPROD_r() << ',' << tmp1->GetWYD_h() << ',' << tmp1->GetWYD_min() << ',' << tmp1->GetWYD_d() << ',' << tmp1->GetWYD_m() << ',' << tmp1->GetWYD_r();
					//charakterystyczne
					plik << ',' << tmpGL->GetPrze() << ',' << tmpGL->GetRodz();
					plik << std::endl;
					tmpGL = tmpGL->GetNext();
				}
			}
			if (tmp->GetGlowaSluchawki() != nullptr)
			{
				auto tmpGL = tmp->GetGlowaSluchawki();
				while (tmpGL)
				{
					Sprzet* tmp1 = tmpGL;
					//podstawowe inf
					plik << tmp->GetId() << ',' << tmp->GetNr() << ',' << tmp1->Getcoto() << ',' << tmp1->GetWZ() << ',' << tmp1->GetPROD_d() << ',' << tmp1->GetPROD_m() << ',' << tmp1->GetPROD_r() << ',' << tmp1->GetWYD_h() << ',' << tmp1->GetWYD_min() << ',' << tmp1->GetWYD_d() << ',' << tmp1->GetWYD_m() << ',' << tmp1->GetWYD_r();
					//charakterystyczne
					plik << ',' << tmpGL->GetPrze() << ',' << tmpGL->GetMikro() << ',' << tmpGL->GetPasmo() << ',' << tmpGL->GetRodz();
					plik << std::endl;
					tmpGL = tmpGL->GetNext();
				}
			}
			//kolejne
		
			tmp = tmp->GetNext();
		}
	}
	plik.close();
}

Alejka* Lista_alejek::zlokalizujAlejke(char id, int nr)
{
	auto tmp = _glowaALEJKA;
	while (tmp)
	{
		if (tmp->GetId() == id && tmp->GetNr() == nr)
		{
			return tmp;
		}
		else
		{
			tmp = tmp->GetNext();
		}
	}
	return nullptr; //nie znaleziono
}

