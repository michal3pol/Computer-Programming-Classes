#include "zwierze.h"

zwierze::zwierze( QStackedWidget* ws)
{
    Param = std::shared_ptr<Parametry>(new Parametry(ws));

    //losowanie cech zwierzaka:
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1,10);
    sennosc = dist(gen);
    glodomor = dist(gen);
    na_zewnatrz = dist(gen);

    Param->Setdni(1);
    Param->Setsamopoczucie(70);
    Param->Setzdrowie(70);
    Param->Setpzsnu(10);
    Param->Setpzglodu(10);
}


zwierze::zwierze(std::vector<int> v,  QStackedWidget* ws)
{
    Param = std::shared_ptr<Parametry>(new Parametry(ws));

    //przypisanie wartosci zmiennych w kolejnosci jak ich deklaracja w klasach
    sennosc = v[0];
    glodomor = v[1];
    na_zewnatrz = v[2];
    if(v[3]== 0)
        Id = 'k';
    else if(v[3]== 1)
        Id = 'p';
    Param->Setgodzina(v[4]);
    Param->Setzdrowie(v[5]);
    Param->Setsamopoczucie(v[6]);
    Param->Setdni(v[7]);
    Param->Setpzglodu(v[8]);
    Param->Setpzsnu(v[9]);
    if(v[10] == 1) //ma chorobe
    {
        choroba = std::shared_ptr<Choroba> (new Choroba(v[11],v[12],v[13],v[14]));
    }

}

void zwierze::wyzdrowiej()
{
    choroba = nullptr;
}
