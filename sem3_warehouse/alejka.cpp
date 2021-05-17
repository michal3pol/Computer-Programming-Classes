#include <iostream>
#include <fstream>
#include "Alejka.h"
#include "mysz.h"
#include "Klawiatura.h"
#include "GodzSprzedazy.h"

void Alejka::SetId(char znak)
{	
	_id = znak;
}

void Alejka::SetNr(int nr)
{
	_numer = nr;
}

void Alejka::SetNext(Alejka* nast)
{
	_nastALEJKA = nast;
}

void Alejka::DodajSprzet(char decyzja)
{
	int dodane = 0;
	do
	{
		if (decyzja != 'M' && decyzja != 'm' && decyzja != 'S' && decyzja != 's' && decyzja != 'K' && decyzja != 'k')
		{
			std::cout << "Bledne dane. Nie ma takiego sprzetu!\n";
			return;
		}

		if (decyzja == 'M' || decyzja == 'm')
		{
			Mysz* nowy = new Mysz;
			nowy->Setcoto('M');
			nowy->UstawDane();
			nowy->DodajCharakt();
			*this += nowy;
			dodane++;
		}
		else if (decyzja == 'k' || decyzja == 'K')
		{
			Klawiatura* nowy = new Klawiatura;
			nowy->Setcoto('K');
			nowy->UstawDane();
			nowy->DodajCharakt();
			*this += nowy;
			dodane++;
		}
		else if (decyzja == 'S' || decyzja == 's')
		{
			Sluchawki* nowy = new Sluchawki;
			nowy->Setcoto('S');
			nowy->UstawDane();
			nowy->DodajCharakt();
			*this += nowy;
			dodane++;
		}

		else
		{
			std::cout << "Podano bledny format." << std::endl;
		}
		//kolejne klasy
	} while (dodane ==0);
}

void Alejka::DodajSprzetZPliku(char coto, int tab[], int tab1[], char rodzaj)
{
	if (coto == 'M')
	{
		Mysz* nowy = new Mysz;
		nowy->Setcoto(coto);
		nowy->UstawDane(tab);
		nowy->SetPrzew(tab1[0]);
		nowy->SetRodzaj(rodzaj);
		*this += nowy;
	}
	else if (coto == 'K')
	{
		Klawiatura* nowy = new Klawiatura;
		nowy->Setcoto(coto);
		nowy->UstawDane(tab);
		nowy->SetPrzew(tab1[0]);
		nowy->SetRodzaj(rodzaj);
		*this += nowy;
	}
	else if (coto == 'S')
	{
		Sluchawki* nowy = new Sluchawki;
		nowy->Setcoto(coto);
		nowy->UstawDane(tab);
		nowy->SetPrzew(tab1[0]);
		nowy->SetMikro(tab1[1]);
		nowy->SetPasmo(tab1[2]);
		nowy->SetRodzaj(rodzaj);
		*this += nowy;
	}
	else
	{
		std::cout << "Nie rozpoznano jednego z elementow! Sprawdz poprawnosc danych w pliku wejsciowym\n";
	}
}

void Alejka::PrzeszukajAlejki( char szukany)
{
	if (szukany != 'M' && szukany != 'm' && szukany != 'S' && szukany != 's' && szukany != 'K' && szukany != 'k')
	{
		std::cout << "Bledne dane. Nie ma takiego sprzetu!\n";
		return;
	}
	auto tmp = this;
	while (tmp)
	{
		auto tmp1 = tmp->GetGlowaMysz();
		auto tmp2 = tmp->GetGlowaKlawiatura();
		auto tmp3 = tmp->GetGlowaSluchawki();
		if (szukany == 'M' || szukany == 'm')
		{
			while (tmp1)
			{
				Sprzet* tmp12 = tmp1;
				std::cout << "Alejka: " << tmp->GetId() << tmp->GetNr() << std::endl;
				std::cout << *(tmp12);
				std::cout << *(tmp1);
				std::cout << "----------------------------------------------------------------" << std::endl;
				tmp1 = tmp1->GetNext();
			}
		}
		if (szukany == 'K'|| szukany == 'k')
		{
			while (tmp2)
			{
				std::cout << "Alejka: " << tmp->GetId() << tmp->GetNr() << std::endl;
				Sprzet* tmp12 = tmp2;
				std::cout << *(tmp12);
				std::cout << *(tmp2);
				std::cout << "----------------------------------------------------------------" << std::endl;
				tmp2 = tmp2->GetNext();
			}
		}
		if (szukany == 'S' || szukany == 's')
		{
			while (tmp3)
			{
				std::cout << "Alejka: " << tmp->GetId() << tmp->GetNr() << std::endl;
				Sprzet* tmp12 = tmp3;
				std::cout << *(tmp12);
				std::cout << *(tmp3);
				std::cout << "----------------------------------------------------------------" << std::endl;
				tmp3 = tmp3->GetNext();
			}
		}
	//kolejne klasy
		tmp = tmp->GetNext();
	}
}

void Alejka::ZnajdzMiejsce()
{
	std::cout << "xx-oznacza ze na regale znajduje sie co najmniej 1 przedmiot.\n";
	auto tmp = this;
	std::cout.fill('.');
	while (tmp)
	{
		if (tmp->GetNr() == 100) //nalezy przedrukowac 
		{
			for (int i = 0; i < 6; i++)
			{
				std::cout << "| " << tmp->GetId() <<"10" << i << " |";
			}
			std::cout << std::endl;
		}

		if (tmp->GetGlowaKlawiatura() != nullptr || tmp->GetGlowaMysz() != nullptr || tmp->GetGlowaSluchawki() != nullptr)
		{
			std::cout << "|..xx..|";
		}
		else
		{
			std::cout << "|......|";
		}

		if (tmp->GetNr() == 105)
		{
			std::cout << std::endl << std::endl;
		}
		tmp = tmp->GetNext();
	}
}

std::string Alejka::Sprzedaj( int usuwany, int wzUsuwanego)
{
	if (usuwany != 'M' && usuwany != 'm' && usuwany != 'S' && usuwany != 's' && usuwany != 'K' && usuwany != 'k')
	{
		return"Bledne dane. Nie ma takiego sprzetu!\n";
	}

	std::string komunikat;
	std::ofstream plik("plik_sprzedaz.txt", std::ios::app);
	if (plik)
	{
		auto tmp1 = this->GetGlowaMysz();
		auto tmp2 = this->GetGlowaKlawiatura();
		auto tmp3 = this->GetGlowaSluchawki();
		if (tmp1 == nullptr && tmp2 == nullptr && tmp3 == nullptr)
		{
			komunikat = "Blad! Ta alejka jest pusta!\n";
			return komunikat;
		}

		if (usuwany == 'M' || usuwany == 'm')
		{
			if (_glowaMysz == nullptr)
			{
				return komunikat = "Na tym regale nie ma myszy!\n";
			}
			if (_glowaMysz->GetWZ() == wzUsuwanego) //jesli to glowa do usuniecia
			{
				Mysz* bufor = _glowaMysz->GetNext();
				//TUTAJ FUNCKJA WPISUJACA DO PLIKU!!!
				plik << std::endl <<"SPRZEDANO MYSZ"<< std::endl;
				Sprzet* tmp12 = _glowaMysz;
				plik << *(tmp12);
				plik << *(_glowaMysz);
				GodzSprzedazy n1;
				plik << n1;
				//
				*this -= _glowaMysz;
				_glowaMysz = bufor;
				return komunikat = "Sprzedano!\n";
			}
			auto tmp1 = _glowaMysz;
			while (tmp1)
			{
				if (tmp1->GetNext() != nullptr)
				{
					if (tmp1->GetNext()->GetWZ() == wzUsuwanego)
					{
						auto bufor = tmp1->GetNext()->GetNext();
						//TUTAJ FUNKCJA WPISUJACA DO PLIKU
						plik << std::endl << "SPRZEDANO MYSZ" << std::endl;
						Sprzet* tmp12 = tmp1;
						plik << *(tmp12);
						plik << *(tmp1);
						GodzSprzedazy n1;
						plik << n1;
						//
						delete tmp1->GetNext();
						tmp1->SetNextMysz(bufor);
						return komunikat = "Sprzedano!\n";
					}
				}
				tmp1 = tmp1->GetNext();
				if (tmp1 == nullptr)
				{
					return komunikat = "Nie znaleziono przedmiotu o takim numerze WZ na tym regale!\n";
				}
			}
		}
		if (usuwany == 'K' || usuwany == 'k')
		{
			if (_glowaKlawiatura == nullptr)
			{
				return komunikat = "Na tym regale nie ma klawiatur!\n";
			}
			if (_glowaKlawiatura->GetWZ() == wzUsuwanego) //jesli to glowa do usuniecia
			{
				auto bufor = _glowaKlawiatura->GetNext();
				//TUTAJ FUNCKJA WPISUJACA DO PLIKU!!!
				plik << std::endl << "SPRZEDANO KLAWIATURE" << std::endl;
				Sprzet* tmp12 = _glowaKlawiatura;
				plik << *(tmp12);
				plik << *(_glowaKlawiatura);
				GodzSprzedazy n1;
				plik << n1;
				//
				*this -= _glowaKlawiatura;
				_glowaKlawiatura = bufor;
				return komunikat = "Sprzedano!\n";
			}
			auto tmp1 = _glowaKlawiatura;
			while (tmp1)
			{
				if (tmp1->GetNext() != nullptr)
				{
					if (tmp1->GetNext()->GetWZ() == wzUsuwanego)
					{
						auto bufor = tmp1->GetNext()->GetNext();
						//TUTAJ FUNKCJA WPISUJACA DO PLIKU
						plik << std::endl << "SPRZEDANO KLAWIATURE" << std::endl;
						Sprzet* tmp12 = tmp1;
						plik << *(tmp12);
						plik << *(tmp1);
						GodzSprzedazy n1;
						plik << n1;
						//
						delete tmp1->GetNext();
						tmp1->SetNextKlawiatura(bufor);
						return komunikat = "Sprzedano!\n";
					}
				}
				tmp1 = tmp1->GetNext();
				if (tmp1 == nullptr)
				{
					return komunikat = "Nie znaleziono przedmiotu o takim numerze WZ na tym regale!\n";
				}
			}
		}
		if (usuwany == 'S' || usuwany == 's')
		{
			if (_glowaSluchawki == nullptr)
			{
				return komunikat = "Na tym regale nie ma sluchawek!\n";
			}
			if (_glowaSluchawki->GetWZ() == wzUsuwanego) //jesli to glowa do usuniecia
			{
				auto bufor = _glowaSluchawki->GetNext();
				//TUTAJ FUNCKJA WPISUJACA DO PLIKU!!!
				plik << std::endl << "SPRZEDANO SLUCHAWKI" << std::endl;
				Sprzet* tmp12 = _glowaSluchawki;
				plik << *(tmp12);
				plik << *(_glowaSluchawki);
				GodzSprzedazy n1;
				plik << n1;
				//
				*this -= _glowaSluchawki;
				_glowaSluchawki = bufor;
				return komunikat = "Sprzedano!\n";
			}
			auto tmp1 = _glowaSluchawki;
			while (tmp1)
			{
				if (tmp1->GetNext() != nullptr)
				{
					if (tmp1->GetNext()->GetWZ() == wzUsuwanego)
					{
						auto bufor = tmp1->GetNext()->GetNext();
						//TUTAJ FUNKCJA WPISUJACA DO PLIKU
						plik << std::endl << "SPRZEDANO SLUCHAWKI" << std::endl;
						Sprzet* tmp12 = tmp1;
						plik << *(tmp12);
						plik << *(tmp1);
						GodzSprzedazy n1;
						plik << n1;
						//
						delete tmp1->GetNext();
						tmp1->SetNextSluchawki(bufor);
						return komunikat = "Sprzedano!\n";
					}
				}
				tmp1 = tmp1->GetNext();
				if (tmp1 == nullptr)
				{
					return komunikat = "Nie znaleziono przedmiotu o takim numerze WZ na tym regale!\n";
				}
			}
		}
		
	}
	else
	{
		return komunikat = "BLAD PLIKU!\n";
	}
	plik.close();
}


void Alejka::UsunAlejke()
{
	if (_glowaMysz != nullptr)
	{
		auto myszki = _glowaMysz;
		while (myszki)
		{
			auto bufor = myszki->GetNext();
			delete myszki;
			myszki = bufor;
		}
		_glowaMysz = nullptr;
	}
	if (_glowaKlawiatura != nullptr)
	{
		auto klawy = _glowaKlawiatura;
		while (klawy)
		{
			auto bufor = klawy->GetNext();
			delete klawy;
			klawy = bufor;
		}
		_glowaKlawiatura = nullptr;
	}
	if (_glowaSluchawki != nullptr)
	{
		auto slucha = _glowaSluchawki;
		while (slucha)
		{
			auto bufor = slucha->GetNext();
			delete slucha;
			slucha = bufor;
		}
		_glowaSluchawki = nullptr;
	}

	delete this;
}

void Alejka::operator+=(Mysz* nowy)
{
	if (!_glowaMysz)
	{
		_glowaMysz = nowy;
	}
	else
	{
		nowy->SetNextMysz(_glowaMysz);
		_glowaMysz = nowy;
	}
}

void Alejka::operator+=(Klawiatura* nowy)
{
	if (!_glowaKlawiatura)
	{
		_glowaKlawiatura = nowy;
	}
	else
	{
		nowy->SetNextKlawiatura(_glowaKlawiatura);
		_glowaKlawiatura = nowy;
	}
}

void Alejka::operator+=(Sluchawki* nowy)
{
	if (!_glowaSluchawki)
	{
		_glowaSluchawki = nowy;
	}
	else
	{
		nowy->SetNextSluchawki(_glowaSluchawki);
		_glowaSluchawki = nowy;
	}
}

void Alejka::operator-=(Mysz* m1)
{
	delete _glowaMysz;
	_glowaMysz = nullptr;
}

void Alejka::operator-=(Klawiatura* k1)
{
	delete _glowaKlawiatura;
	_glowaKlawiatura = nullptr;
}

void Alejka::operator-=(Sluchawki*)
{ 
	delete _glowaSluchawki;
	_glowaSluchawki = nullptr;
}

Alejka::Alejka()
{
	_nastALEJKA = nullptr;
	_glowaKlawiatura = nullptr;
	_glowaMysz = nullptr;
	_glowaSluchawki = nullptr;
}

Alejka::~Alejka()
{

}


