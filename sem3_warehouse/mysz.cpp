#include "mysz.h"
#include "alejka.h"
#include<iostream>
#include <string>

void Mysz::SetPrzew(bool przewodowa)
{
	_przewodowa = przewodowa;	
}

void Mysz::SetRodzaj(char rodzaj)
{
	_rodzaj = rodzaj;
}


void Mysz::SetNextMysz(Mysz* nast)
{
	_nast = nast;
}



void Mysz::DodajCharakt()
{
	int dodano = 0, dodano1=0;
	bool przew;
	do {
		char decyzja;
		std::cout << "Czy mysz jest przewodowa? (format: T-tak N-nie): ";
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
	} while (dodano ==0);
	this->SetPrzew(przew);
	do {
		char decyzja;
		std::cout << "Podaj rodzaj: (format: M-mechaniczna D-diodowa L-laserowa): ";
		std::cin >> decyzja;
		if (decyzja == 'L' || decyzja == 'l' || decyzja == 'M' || decyzja == 'm' || decyzja == 'd' || decyzja == 'D')
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

std::ostream& operator<<(std::ostream& os, const Mysz& m)
{
	os << "Rodzaj myszy: ";
	if (m._rodzaj == 'M' || m._rodzaj == 'm')
	{
		os << "mechaniczna(kulkowa)" << std::endl;
	}
	else if (m._rodzaj == 'D' || m._rodzaj == 'd')
	{
		os << "diodowa" << std::endl;
	}
	else if (m._rodzaj == 'L' || m._rodzaj == 'l')
	{
		os << "laserowa" << std::endl;
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

Mysz::Mysz()
{
	_nast = nullptr;
}


