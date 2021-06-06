#include "parametry.h"


Parametry::Parametry(QStackedWidget* ws)
{
    auto pocz_zycia = std::chrono::system_clock::now();
    godzina = 0;
    wskWidget = ws;
}

void Parametry::zlicz15s(QLCDNumber * lcd_dni, QLCDNumber * lcd_zdrowie, QLCDNumber * lcd_samopoczucie, std::shared_ptr<Choroba>& choroba)
{   
    dzis_jedzenie =true;
    dzis_sen =true;
    dzis_zabawa = true;
    while(zdrowie > 0)
    {
        auto akt_czas = std::chrono::system_clock::now();

        std::chrono::duration<double> roznica = (akt_czas-pocz_zycia);

        if(zdrowie != lcd_zdrowie->value() or samopoczucie != lcd_samopoczucie->value() or dni != lcd_dni->value())
        {
            lcd_zdrowie->display(zdrowie);
            lcd_samopoczucie->display(samopoczucie);
            lcd_dni->display(dni);
        }

        if(godzina >= 24)
        {
            godzina -= 24;
            lcd_dni->display(++dni);
            srand(time(NULL));
            int prawdop = rand()%100+1;
            if(prawdop %5 ==0 and choroba == nullptr) //20% prawd na chorobe
            {
                choroba = std::shared_ptr<Choroba>(new Choroba(prawdop%3));
            }
            if(choroba != nullptr)
            {
                aktualizujZS(choroba->Getmin_zdr()*2,-10);
            }
            //sprawdz czy wszystkie 3 aktywnosci zostaly wykonane tego dnia
            if(!dzis_jedzenie)
                aktualizujZS(-20,-30);
            if(!dzis_zabawa)
                aktualizujZS(-20,-30);
            if(!dzis_sen)
                aktualizujZS(-20,-30);
            dzis_jedzenie =false;
            dzis_sen =false;
            dzis_zabawa = false;
        }

        if(roznica.count() > 5) //z kazda godzina spada zdrowie i samopoczucie
        {

            if(poziom_glodu == 0 or poziom_snu ==0) //jesli glodny obniz szybciej
            {
                aktualizujZS(-1,-1);
            }
            if (samopoczucie == 0)
            {
                aktualizujZS(-1,0);
            }
            aktualizujZS(-1,-1);
            lcd_zdrowie->display(zdrowie);
            lcd_samopoczucie->display(samopoczucie);

            pocz_zycia = std::chrono::system_clock::now();

            //obnizyc poziomy glodu i snu
            obnizglodisen(-1,-1);

            godzina++;

        }

        std::this_thread::sleep_for (std::chrono::milliseconds(500));
    }
}

void Parametry::aktualizujZS(int z, int s)
{
    zdrowie = (zdrowie+z) <=100 ? (zdrowie+z) :100;
    if((zdrowie+z) < 0) {zdrowie =0;}
    samopoczucie = (samopoczucie+s) <=100 ? (samopoczucie+s) :100;
    if((samopoczucie+s) < 0) {samopoczucie =0;}

    if(zdrowie ==0)
    {
        //przejdz na widok konca gry
        wskWidget->setCurrentIndex(7);
        wskWidget->setVisible(1);
    }
}

void Parametry::obnizglodisen(int odj_sen, int odj_glod)
{
    poziom_glodu = (poziom_glodu+odj_glod) >=0 ? poziom_glodu+odj_glod : 0;
    if(poziom_glodu>10) {poziom_glodu =10;}
    poziom_snu = (poziom_snu+odj_sen) >=0 ? poziom_snu+odj_sen : 0;
    if(poziom_snu>10) {poziom_snu =10;}
}

void Parametry::dodaj_czas_akcji(int h)
{
    godzina += h;
}
