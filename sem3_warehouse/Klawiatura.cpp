#include "Klawiatura.h"
#include <iostream>

void Klawiatura::SetPrzew(bool przewodowa)
{
	_przewodowa = przewodowa;
}

void Klawiatura::SetRodzaj(char rodzaj)
{
	_rodzaj = rodzaj;
}

void Klawiatura::SetNextKlawiatura(Klawiatura* nast)
{
	_nast = nast;
}

void Klawiatura::DodajCharakt()
{
	int dodano = 0, dodano1 = 0;
	bool przew;
	do {
		char decyzja;
		std::cout << "Czy klawiatura jest przewodowa? (format: T-tak N-nie): ";
		std::cin >> decyzja;
		if (decyzja == 'T' || decyzja == 't')
		{
			przew = true;
			dodano++;
		}
		else if (decyzja == 'N' || decyzja == 'n')
		{
			przew = false;
			dodano++;
		}
		else
		{
			std::cout << "Podano zly format!" << std::endl;
		}
	} while (dodano == 0);
	this->SetPrzew(przew);
	do {
		char decyzja;
		std::cout << "Podaj rodzaj: (format: M-mechaniczna E-membranowa H-hybryda): ";
		std::cin >> decyzja;
		if (decyzja == 'E' || decyzja == 'e' || decyzja == 'M' || decyzja == 'm' || decyzja == 'H' || decyzja == 'h')
		{
			this->SetRodzaj(decyzja);
			dodano1++;
		}
		else
		{
			std::cout << "Podano zly format!" << std::endl;
		}
	} while (dodano1 == 0);
  
}

Klawiatura::Klawiatura()
{
	_nast = nullptr;
}

std::ostream& operator<<(std::ostream& os, const Klawiatura& m)
{
	os << "Rodzaj klawiatury: ";
	if (m._rodzaj == 'M' || m._rodzaj == 'm')
	{
		os << "mechaniczna" << std::endl;
	}
	else if (m._rodzaj == 'E' || m._rodzaj == 'e')
	{
		os << "membranowa" << std::endl;
	}
	else if (m._rodzaj == 'H' || m._rodzaj == 'h')
	{
		os << "hybryda" << std::endl;
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
	return os;
}