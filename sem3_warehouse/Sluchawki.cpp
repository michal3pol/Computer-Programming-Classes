#include "Sluchawki.h"
#include <iostream>
void Sluchawki::SetPrzew(bool przew)
{
	_przewodowa = przew;
}

void Sluchawki::SetRodzaj(char rodzaj)
{
	_rodzaj = rodzaj;
}

void Sluchawki::SetMikro(bool mikro)
{
	_mikrofon = mikro;
}

void Sluchawki::SetPasmo(int pasm)
{
	_pasmo = pasm;
}

void Sluchawki::SetNextSluchawki(Sluchawki* nast)
{
	_nast = nast;
}

void Sluchawki::DodajCharakt()
{
	int dodano = 0, dodano1 = 0, dodano2 = 0, dodano3=0;
	bool przew, mikro;
	do {
		char decyzja;
		std::cout << "Czy sluchawki sa przewodowe? (format: T-tak N-nie): ";
		std::cin >> decyzja;
		if (decyzja == 'T' || decyzja == 't')
		{
			_przewodowa = true;
			//_przew = true;
			dodano++;
		}
		else if (decyzja == 'N' || decyzja == 'n')
		{
			_przewodowa = false;
			//przew = false;
			dodano++;
		}
		else
		{
			std::cout << "Podano zly format!" << std::endl;
		}
	} while (dodano == 0);
	do {
		char decyzja;
		std::cout << "Podaj rodzaj: (format: S-studyjne G-gamingowe D-douszne): ";
		std::cin >> decyzja;
		if (decyzja == 'S' || decyzja == 's' || decyzja == 'G' || decyzja == 'g' || decyzja == 'D' || decyzja == 'd')
		{
			this->SetRodzaj(decyzja);
			dodano1++;
		}
		else
		{
			std::cout << "Podano zly format!" << std::endl;
		}
	} while (dodano1 == 0);
	do {
		char decyzja;
		std::cout << "Czy sluchawki maja mikrofon? (format: T-tak N-nie): ";
		std::cin >> decyzja;
		if (decyzja == 'T' || decyzja == 't')
		{
			_mikrofon = true;
			dodano2++;
		}
		else if (decyzja == 'N' || decyzja == 'n')
		{
			_mikrofon = false;
			dodano2++;
		}
		else
		{
			std::cout << "Podano zly format!" << std::endl;
		}
	} while (dodano2 == 0);
	do {
		int decyzja;
		std::cout << "Podaj pasmo przenoszenia (wartosc maksymalna w Hz): ";
		std::cin >> decyzja;
		if (decyzja > 0 && decyzja < 1000000)
		{
			_pasmo = decyzja;
			dodano3++;
		}
		else
		{
			std::cout << "Podano zly format! Zakre to 0 - 1000 0000!" << std::endl;
		}
	} while (dodano3 == 0);
}

std::ostream& operator<<(std::ostream& os, const Sluchawki& m)
{
	os << "Rodzaj sluchawek: ";
	if (m._rodzaj == 'S' || m._rodzaj == 's')
	{
		os << "studyjne" << std::endl;
	}
	else if (m._rodzaj == 'G' || m._rodzaj == 'g')
	{
		os << "gamingowe" << std::endl;
	}
	else if (m._rodzaj == 'D' || m._rodzaj == 'd')
	{
		os << "douszne" << std::endl;
	}
	else
		os << "problem" << std::endl;
	os << "Komunikacja z komputerem: ";
	if (m._przewodowa) //jesli true-przewodowa
	{
		os << "przewodowa" << std::endl;
	}
	else
	{
		os << "bezprzewodowa" << std::endl;
	}
	if (m._mikrofon) //jesli true-maja mikrofon
	{
		os << "Sluchawki posiadaja mikrofon." << std::endl;
	}
	else
	{
		os << "Sluchawki nie posiadaja mikrofonu." << std::endl;
	}
	os << "Maksymalne pasmo przenoszenia sluchawek: " << m._pasmo << " Hz" << std::endl;
	return os;
}

Sluchawki::Sluchawki()
{
	_nast = nullptr;
}

/*
Sluchawki::~Sluchawki()
{
	delete _nast;
}*/
