#include "uzytkownik.h"

uzytkownik::uzytkownik(const std::string n, const std::string h)
{
    Nazwa_uzytkownika = n;
    Haslo = h;
    Nazwa_pliku_menu = n+"_menu";
}

bool uzytkownik::operator==(const uzytkownik &u1)
{
    if(Nazwa_uzytkownika == u1.Nazwa_uzytkownika and Haslo == u1.Haslo)
        return true;
    else
        return false;
}

bool uzytkownik::operator==(const std::string s)
{
    if(Nazwa_uzytkownika == s)
        return true;
    else
        return false;
}

void uzytkownik::usun_zwierze()
{
    std::fstream plik;
    plik.open(Nazwa_uzytkownika+".txt", std::fstream::out);
    if(plik)
    {
        plik << "0";
    }
    plik.close();
}

void uzytkownik::zapisz_plik_menu( std::list<Jedzenie> lj)
{
    std::fstream plik;
    plik.open(Nazwa_pliku_menu+".txt", std::fstream::out);
    if(plik)
    {
        for(auto i = lj.begin(); i != lj.end() ; ++i)
        {
            plik << *i; //operator
        }
    }
    plik.close();
}

void uzytkownik::zapisz_plik_uzytkownika(zwierze * z)
{
    std::fstream plik;
    plik.open(Nazwa_uzytkownika+".txt", std::fstream::out);
    if(plik)
    {
        //zapisanie zmiennych zgodnie z kolejnoscia deklaracji w klasach
        plik << *z; //operator
    }
    plik.close();
}

std::vector<int> uzytkownik::odczytaj_plik_uzytkownika()
{
    //doczytywanie do wektora zgodnie z kolejnoscia deklaracji zmiennych w klasach
    std::vector<int> v;
    std::fstream plik;
    plik.open(Nazwa_uzytkownika+".txt", std::ios::in);
    if(plik)
    {
        std::string linia;
        std::getline(plik,linia);
        if(linia == "0")
        {
            v.push_back(0);
            return v;
        }
        std::stringstream ss(linia);
        for(int i =0; i< 10; i++)
        {
            std::string tmp;
            std::getline(ss, tmp,',');
            if(i!=3)
            {
                int rz = std::stoi(tmp);
                v.push_back(rz);
            }
            else //i==3 id zwierzaka
            {
                if(tmp == "k")
                    v.push_back(0); //kot
                else
                    v.push_back(1); //pies
            }
        }
        std::string tmpch;
        std::getline(ss, tmpch,',');
        if(tmpch == "n")
            v.push_back(0); //nie ma choroby
        else
        {
            std::string tmprch;
            std::getline(ss, tmprch,','); //indeksy chorób zgodnie z konstruktorem
            if(tmprch == "Zwichnięta noga")
                v.push_back(0);
            else if(tmprch == "Mały guz w jelitach")
                v.push_back(1);
            else if(tmprch == "Wysypka")
                v.push_back(2);

            for (int i =0; i < 4; i++) //4 ostatnie statystki choroby
            {
                std::string tmp;
                std::getline(ss, tmp,',');
                int rz = std::stoi(tmp);
                v.push_back(rz);
            }
        }
        plik.close();
    }
    else
        v.push_back(0);
    return v;
}

void uzytkownik::odczytaj_plik_menu(std::list<Jedzenie> & lj)
{
    std::fstream plik;
    plik.open(Nazwa_pliku_menu+".txt", std::ios::in);
    if(plik)
    {
        std::string linia;
        while(std::getline(plik,linia))
        {
            std::stringstream ss(linia);
            std::string na, nj, tmp;
            int rz,rs, ka;
            char ip;

            std::getline(ss, na,',');
            std::getline(ss, tmp,',');
            rz = std::stoi(tmp);
            std::getline(ss, tmp,',');
            rs = std::stoi(tmp);
            std::getline(ss, tmp,',');
            ip = tmp[0];
            std::getline(ss, nj,',');
            std::getline(ss, tmp,',');
            ka = std::stoi(tmp);

            lj.emplace_back(na, nj, ka, ip);
        }

        plik.close();
    }
}

void uzytkownik::dodaj_menu_uz(const std::string n, std::list<Jedzenie> & lj, QListWidget* ljw_wsk)
{
    std::fstream plik;
    plik.open(n+"_menu.txt", std::ios::in);
    if(plik)
    {
        std::string linia;
        while(std::getline(plik,linia))
        {
            std::stringstream ss(linia);
            std::string na, nj, tmp;
            int rz,rs, ka;
            char ip;

            std::getline(ss, na,',');
            std::getline(ss, tmp,',');
            rz = std::stoi(tmp);
            std::getline(ss, tmp,',');
            rs = std::stoi(tmp);
            std::getline(ss, tmp,',');
            ip = tmp[0];
            std::getline(ss, nj,',');
            std::getline(ss, tmp,',');
            ka = std::stoi(tmp);

            if (std::find(lj.begin(), lj.end(), nj) == lj.end())
            {
                lj.emplace_back(na, nj, ka, ip);
                new QListWidgetItem(QString::fromStdString(nj), ljw_wsk);
            }
        }

        plik.close();
    }
}
