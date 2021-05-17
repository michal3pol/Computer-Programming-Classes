#pragma once
#include <iostream>

class GodzSprzedazy
{
private:
	int godz;
	int min;
	int dzien;
	int miesiac;
	int rok;
public:

	GodzSprzedazy();

	friend std::ostream& operator<<(std::ostream& os, const GodzSprzedazy& m);
};

