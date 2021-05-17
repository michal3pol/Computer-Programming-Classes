#pragma once
#include <iostream>

#include"Sprzet.h"
#include"Alejka.h"

//konstruktor tworzy liste alejek A100...D105
class Lista_alejek
{
private:
	Alejka* _glowaALEJKA;
public:
	void wypiszAlejki();//testy

	//pliki
	void OdczytajPlik(std::string);
	void ZapiszDoPliku(std::string);
	
	Alejka* zlokalizujAlejke(char, int);
	Alejka* GetGLOWAALEJEK() { return _glowaALEJKA; }

	void UsunListe();

	Lista_alejek();
	
	int& operator++();
	
};