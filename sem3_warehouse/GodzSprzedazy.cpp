#include <ctime>
#include<iomanip>
#include "GodzSprzedazy.h"

GodzSprzedazy::GodzSprzedazy()
{
	struct tm czasowa;
	time_t czas = time(0);
	localtime_s(&czasowa, &czas);
	godz = czasowa.tm_hour;
	min = czasowa.tm_min;
	dzien = czasowa.tm_mday;
	miesiac = czasowa.tm_mon + 1;
	rok = czasowa.tm_year + 1900;
}

std::ostream& operator<<(std::ostream& os, const GodzSprzedazy& m)
{
	os << "Sprzedano: " << std::setw(2) << std::setfill('0') << m.dzien << "." << std::setw(2) << std::setfill('0') << m.miesiac << "." << m.rok << "r." << " o godz: " << std::setw(2) << std::setfill('0') << m.godz<< ":" << std::setw(2) << std::setfill('0') << m.min << std::endl;
	os << "---------------------------------------------" << std::endl;
	
	return os;
}
