#pragma once
#include<ctime>
#include<iostream>

//zawiera informacje podstawowe dla ka¿dego produktu
class Sprzet
{
protected:
	int _data_prod_dzien =0;
	int _data_prod_mies=0;
	int _data_prod_rok = 0;
	int _WZ;
	char _coto;

	int _wyd_godz=0;
	int _wyd_min=0;
	int _data_wyd_dzien=0;
	int _data_wyd_mies=0;
	int _data_wyd_rok=0;

public:
	void SetPROD(int, int, int);
	void SetWYD();
	void SetWZ(int);
	void Setcoto(char);
	
	void UstawDane();
	void UstawDane(int[]);

	int GetPROD_d() const { return _data_prod_dzien; }
	int GetPROD_m()const { return _data_prod_mies; }
	int GetPROD_r()const { return _data_prod_rok; }
	int GetWYD_h()const { return _wyd_godz; }
	int GetWYD_min()const { return _wyd_min; }
	int GetWYD_d()const { return _data_wyd_dzien; }
	int GetWYD_m()const { return _data_wyd_mies; }
	int GetWYD_r()const { return _data_wyd_rok; }
	char Getcoto() const { return _coto; }
	int GetWZ() const { return _WZ; }

	friend std::ostream& operator<<(std::ostream& os, const Sprzet& m);


};