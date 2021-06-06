#include "doktor.h"


Doktor::Doktor()
{
}

void Doktor::stworz_dok(const std::string i, const std::string n, const std::string s, const std::string d1, const std::string d2)
{
    imie = i;
    nazwisko = n;
    specjalizacja =s;
    diagnozy.push_back("Proszę udać się do innego lekarza."); //[0]
    diagnozy.push_back("Pozostałe wizyty: ");
    diagnozy.push_back("Zwierzątko jest zdrowe!");
    //dwie spersonalizowane diagnozy
    diagnozy.push_back(d1);
    diagnozy.push_back(d2);
}

void Doktor::wizyta(zwierze * z)
{
    QMessageBox msgb;
    QString w;
    if(z->GetChorob()->Getodp_lek() == specjalizacja)
    {
        if(z->GetChorob()->Getdz_p_wiz() == z->GetParam()->Getdni())
        {
            msgb.setText("Dziś już odbyłeś wizytę.");
            msgb.exec();
            return;
        }

        if(z->GetChorob()->Getpierw_wiz())
        {
            z->GetChorob()->Setpierw_wiz(false);
            z->GetChorob()->odejm_wiz();
            z->GetChorob()->Set_dzien_p_wiz(z->GetParam()->Getdni());
            z->GetParam()->aktualizujZS(5,5);
            //wyświetlenie informacji o wizycie dla uzytkownika
            QString l = QString::number(z->GetChorob()->Getwym_wiz());
            w = QString::fromStdString(diagnozy[3] + " "+ diagnozy[4]+" "+diagnozy[1] +" ");
            l.prepend(w);
            msgb.setText(l);
            msgb.exec();
            return;
        }
        if(z->GetChorob()->Getwym_wiz() == 1)
        {
            z->GetChorob()->odejm_wiz();
            z->GetChorob().reset(); //koniec choroby
            z->GetParam()->aktualizujZS(7,7);
            //wyświetlenie informacji o wizycie dla uzytkownika
            w = QString::fromStdString(diagnozy[2]);
            msgb.setText(w);
            msgb.exec();
            return;
        }
        z->GetChorob()->odejm_wiz();
        z->GetChorob()->Set_dzien_p_wiz(z->GetParam()->Getdni());
        z->GetParam()->aktualizujZS(5,5);
        //wyświetlenie informacji o wizycie dla uzytkownika
        QString l = QString::number(z->GetChorob()->Getwym_wiz());
        w = QString::fromStdString(diagnozy[4]+" "+diagnozy[1]+" ");
        l.prepend(w);
        msgb.setText(l);
        msgb.exec();

    }
    else
    {
        //nieodpowieni lekarz
        w = QString::fromStdString(diagnozy[0]);
        msgb.setText(w);
        msgb.exec();
    }


}
