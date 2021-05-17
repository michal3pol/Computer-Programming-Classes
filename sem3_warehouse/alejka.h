#pragma once
#include<iostream>
#include "sprzet.h"
#include "mysz.h"
#include "Klawiatura.h"
#include "Sluchawki.h"

class Alejka
{
private:
	char _id;
	int _numer;
	
	Mysz* _glowaMysz;
	Klawiatura* _glowaKlawiatura;
	Sluchawki* _glowaSluchawki;
	
	Alejka* _nastALEJKA;
	
public:
	void SetId(char);
	void SetNr(int);
	void SetNext(Alejka*);
	//dodawanie nowego sprzetu:
	void DodajSprzet(char);
	void DodajSprzetZPliku(char, int [],int [], char);
	void PrzeszukajAlejki(char);
	void ZnajdzMiejsce();
	//usun sprzet
	std::string Sprzedaj(int, int);

	char GetId() const { return _id; }
	int GetNr() const { return _numer; }
	Mysz* GetGlowaMysz() {return _glowaMysz;}
	Klawiatura* GetGlowaKlawiatura() { return _glowaKlawiatura; }
	Sluchawki* GetGlowaSluchawki() { return _glowaSluchawki; }
	
	Alejka* GetNext() { return _nastALEJKA; }

	void UsunAlejke();

	//operatory
	void operator+=(Mysz*);
	void operator+=(Klawiatura*);
	void operator+=(Sluchawki*);

	void operator-=(Mysz*);
	void operator-=(Klawiatura*);
	void operator-=(Sluchawki*);

	Alejka();
	~Alejka();
};

