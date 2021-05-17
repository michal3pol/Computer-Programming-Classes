#include <ctime>
#include<iostream>
#include <iomanip>
#include "sprzet.h"


void Sprzet::SetPROD(int dz, int mies, int rok)
{
	_data_prod_dzien = dz;
	_data_prod_mies = mies;
	_data_prod_rok = rok;
}

void Sprzet::SetWYD()
{
	struct tm czasowa;
	time_t czas = time(0);
	localtime_s(&czasowa, &czas);
	_wyd_godz = czasowa.tm_hour;
	_wyd_min = czasowa.tm_min;
	_data_wyd_dzien = czasowa.tm_mday;
	_data_wyd_mies = czasowa.tm_mon + 1;
	_data_wyd_rok = czasowa.tm_year + 1900;
}

void Sprzet::SetWZ(int nr)
{
	_WZ = nr;
}

void Sprzet::Setcoto(char ct)
{
	_coto = ct;
}

void Sprzet::UstawDane()
{
	int a, b, c, wz;
	int dodane = 0;
	do
	{
		std::cout << "Podaj date produkcji(format DD MM RRRR): ";
		std::cin >> a >> b >> c;
		if (a < 0 || a>32)
		{
			std::cout << "Podano zly dzien"<< std::endl;
		}
		else { dodane++; };
		if (b < 0 || b>13)
		{
			std::cout << "Podano zly miesiac"<<std::endl;
		}
		else { dodane++; };
		if (c < 1900 || a>2021)
		{
			std::cout << "Podano zly rok"<<std::endl;
		}
		else { dodane++; };
		if (dodane != 3)
			dodane = 0;
	} while (dodane < 3);
		std::cout << "Podaj nr WZ: ";
		std::cin >> wz;
	this->SetPROD(a, b, c);
	this->SetWYD();
	this->SetWZ(wz);
}

void Sprzet::UstawDane(int tab[])
{
	_WZ = tab[0];
	_data_prod_dzien = tab[1];
	_data_prod_mies = tab[2];
	_data_prod_rok = tab[3];
	_wyd_godz = tab[4];
	_wyd_min = tab[5];
	_data_wyd_dzien = tab[6];
	_data_wyd_mies = tab[7];
	_data_wyd_rok = tab[8];
}


std::ostream& operator<<(std::ostream& os, const Sprzet& m)
{
	os.width(2);
	os << "Wyprodukowany: " << std::setw(2) << std::setfill('0') << m._data_prod_dzien << "." << std::setw(2) << std::setfill('0') << m._data_prod_mies << "." << m._data_prod_rok << "r." << std::endl;
	os << "Przyjety: " << m._data_wyd_dzien << "." << m._data_wyd_mies << "." << m._data_wyd_rok << "r." << " o godz. "<< std::setw(2) << std::setfill('0')<< m._wyd_godz << ":"<< std::setw(2) << std::setfill('0') << m._wyd_min << std::endl;
	os << "Nr WZ: " << m._WZ << std::endl;
	return os;
}

