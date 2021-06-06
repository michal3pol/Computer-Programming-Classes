#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <windows.h>

#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <fstream>

std::ostream& operator<<(std::ostream & os, Jedzenie & j)
{
    os << j.Getnazwaakt() << "," << j.Getregzdr() << ","<< j.Getregsam() << ","<< j.Getidprz() << ","<<j.Get_nazwa() << ","<< j.Getkalor() << std::endl;
    return os;
}

std::ostream& operator<<(std::ostream & os, zwierze & z)
{
    os << z.Getsennosc() << "," << z.Getglodomor() << "," << z.Getnazewnatrz() << "," << z.GetId() << ",";
    os << z.GetParam()->Getgodzina() << "," << z.GetParam()->Getzdrowie() << "," << z.GetParam()->Getsamopoczucie() << ","<< z.GetParam()->Getdni() << ","<< z.GetParam()->Getpoz_glodu() << ","<< z.GetParam()->Getpoz_snu() << ",";
    if(z.GetChorob() != nullptr)
    {
        os << "t" << "," << z.GetChorob()->Getnazwa() << "," << z.GetChorob()->Getmin_zdr() << "," << z.GetChorob()->Getwym_wiz() << "," << z.GetChorob()->Getdz_p_wiz() << "," << z.GetChorob()->Getpierw_wiz() << std::endl;
    }
    else
        os << "n" << std::endl;

    return os;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setVisible(1);
    ui->stackedWidget->setCurrentIndex(0);

    scena = new Scena(this);
    ui->graphicsView->setScene(scena);
    ui->graphicsView->sceneRect();

    //wczytanie uzytkownikow
    std::fstream plik;
    plik.open("uzytkownicy.txt", std::ios::in);
    if(plik)
    {
        std::string linia;
        while(std::getline(plik,linia))
        {
            int poz_separatora = linia.find(',');
            std::string nazwa = linia.substr(0, poz_separatora);
            std::string imie = linia.substr(poz_separatora+1);
            lista_uzytkownikow.push_back(uzytkownik(nazwa, imie));
        }

        plik.close();
    }

    //ustawienia slidera snu
    ui->horizontalSlider_czas_snu->setMinimum(1);
    ui->horizontalSlider_czas_snu->setMaximum(12);
    //ograniczenie czasu zabawy
    ui->spinBox_czas_zabawy->setMaximum(5);
    ui->spinBox_czas_zabawy->setMinimum(1);

    //tworzenie listy zabaw
    //pies
    lista_zabaw.emplace_back("nazewnatrz", "Spacer", 'p');
    lista_zabaw.emplace_back("nazewnatrz", "Rzut patykiem", 'p');
    lista_zabaw.emplace_back("nieokreslone", "Ćwiczenia zręcznościowe", 'p');
    lista_zabaw.emplace_back("wsrodku", "Sprzątanie zabawek", 'p');
    lista_zabaw.emplace_back("nazewnatrz", "Zabawa w chowanego", 'p');
    lista_zabaw.emplace_back("wsrodku", "Trening cierpliwości", 'p');
    lista_zabaw.emplace_back("wsrodku", "Zabawa z gryzakiem", 'p');
    //kot
    lista_zabaw.emplace_back("nazewnatrz", "Skakanie po dachu", 'k');
    lista_zabaw.emplace_back("wsrodku", "Zabawa na drapaku", 'k');
    lista_zabaw.emplace_back("wsrodku", "Zabawa z wędką", 'k');
    lista_zabaw.emplace_back("wsrodku", "Nakręcana mysz", 'k');
    lista_zabaw.emplace_back("nazewnatrz", "Zabawa kłębkiem wełny", 'k');
    lista_zabaw.emplace_back("wsrodku", "Zabawka z kocimiętką", 'k');
    lista_zabaw.emplace_back("nazewnatrz", "Poszukiwanie myszy", 'k');
    //razem
    lista_zabaw.emplace_back("nieokreslone", "Zabawa piłeczką", 'w');
    lista_zabaw.emplace_back("nieokreslone", "Tor do zabawy", 'w');
    lista_zabaw.emplace_back("nieokreslone", "Głaskanie", 'w');
    lista_zabaw.emplace_back("nieokreslone", "Zabawa z przysmakami", 'w');
    for(auto i = lista_zabaw.begin(); i != lista_zabaw.end() ; ++i)
        new QListWidgetItem(QString::fromStdString(i->Get_nazwa()), ui->listWidget_zabawy);

    //doktorzy
    dermatolog.stworz_dok("Jan", "Kowalski", "Dermatolog", "Okazuję się, że zwierzątko ma wysypkę.", "Proszę pamiętać, aby legowisko zwierzątka było czyste.");
    chirurg.stworz_dok("Andzej", "Malecki", "Chirurg", "Z mojej diagnozy wynika, że zwierzątko zwichneło nogę.", "Do zakończenia leczenia proszę ograniczyć zabawy do minimum.");
    radiolog.stworz_dok("Mariusz", "Koma", "Radiolog", "Prawdopodobnie zwierzątko ma małego guza na jelitach.", "Do zakończenia leczenie proszę podawać niskokaloryczne posiłki.");
}

MainWindow::~MainWindow()
{
    if(uzytkownik_zalogowany != nullptr) //jesli zamiast "zapisz" uzytkownik zamknie okno
    {
        uzytkownik_zalogowany->zapisz_plik_menu(lista_menu);
        uzytkownik_zalogowany->zapisz_plik_uzytkownika(z1_wsk.get());
        //wyczysc listy
        lista_menu.clear();
        ui->listWidget_jedzenie->clear();
        ui->listWidget_zabawy->clear();
        //usun zwierze/kota/psa zwolnij pamiec
        z1_wsk.reset();
        uzytkownik_zalogowany.reset();
    }
    delete ui;
}


void MainWindow::on_zapisz_clicked()
{
    //wraca do ekranu logowania
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->setVisible(1);

    //zapisz plik uzytkownika i menu
    uzytkownik_zalogowany->zapisz_plik_menu(lista_menu);
    uzytkownik_zalogowany->zapisz_plik_uzytkownika(z1_wsk.get());
    //wyczysc liste
    lista_menu.clear();
    ui->listWidget_jedzenie->clear();
    //usun zwierze/kota/psa zwolnij pamiec
    z1_wsk.reset();
    uzytkownik_zalogowany.reset();
}

void MainWindow::on_button_jedzenie_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->stackedWidget->setVisible(1);
}

void MainWindow::on_button_zabawa_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->stackedWidget->setVisible(1);
}

void MainWindow::on_button_sen_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->stackedWidget->setVisible(1);
}

void MainWindow::on_button_wizyta_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget->setVisible(1);
}

void MainWindow::on_button_dod_posilek_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_button_wroc_clicked()
{
    ui->stackedWidget->setVisible(0);
}

void MainWindow::on_button_wroc_2_clicked()
{
    ui->stackedWidget->setVisible(0);
}

void MainWindow::on_button_wroc_3_clicked()
{
    ui->stackedWidget->setVisible(0);
}

void MainWindow::on_button_wroc_4_clicked()
{
    ui->stackedWidget->setVisible(0);
}

void MainWindow::on_button_wroc_5_clicked()
{
    ui->stackedWidget->setVisible(0);
}

void MainWindow::on_button_wroc_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_button_zaloguj_clicked()
{
    QString nazwa1 = ui->lineEdit_nazwa->text();
    QString haslo1 = ui->lineEdit_haslo->text();
    if(nazwa1.isEmpty() or haslo1.isEmpty())
    {
        QMessageBox::warning(this, "Logowanie","Nazwa i hasło muszą składać się z co najmniej jednego znaku.");
        return;
    }
    std::string nazwa_uzytkownika = nazwa1.toStdString();
    std::string haslo_zaszyfr = haslo1.toStdString();
    std::string haslo = sha256(haslo_zaszyfr);

    uzytkownik uzytkownik_aktualny(nazwa_uzytkownika, haslo);

    if(std::find(lista_uzytkownikow.begin(), lista_uzytkownikow.end(), uzytkownik_aktualny) != lista_uzytkownikow.end()) //jesli uzytkownik jest w liscie
    {
        ui->stackedWidget->setVisible(0);

        uzytkownik_zalogowany = std::make_unique<uzytkownik>(nazwa_uzytkownika, haslo);
        //odczytaj plik i plik z menu
        uzytkownik_zalogowany->odczytaj_plik_menu(lista_menu);
        std::vector<int> vz = uzytkownik_zalogowany->odczytaj_plik_uzytkownika();

        for(auto i = lista_menu.begin(); i != lista_menu.end() ; ++i)
            new QListWidgetItem(QString::fromStdString(i->Get_nazwa()), ui->listWidget_jedzenie);

        if(vz[0]==0)
        {
            QMessageBox::warning(this, "Logowanie","Na twoim koncie nie jest utworzone zwierze, stwórz je!");
            ui->stackedWidget->setVisible(1);
            ui->stackedWidget->setCurrentIndex(1);
            return;
        }

        QStackedWidget * wskW = ui->stackedWidget;
        if(vz[3]==0)
            z1_wsk = std::make_unique<Kot>(vz, wskW);
        else if(vz[3] == 1)
            z1_wsk = std::make_unique<Pies>(vz, wskW);

        //dodanie zwierzaka do sceny, aby umozliwic animacje
        scena->addItem(z1_wsk.get());

        //poczatek odliczania
        QLCDNumber* lcdn_wsk = ui->lcdNumber;
        QLCDNumber* lcdn_wsk_zd = ui->lcdNumber_2_zdrowie;
        QLCDNumber* lcdn_wsk_sm = ui->lcdNumber_3_samopoczucie;

        std::shared_ptr<Parametry> Param = z1_wsk->GetParam();
        std::shared_ptr<Choroba>& ch = z1_wsk->GetChorob();
        std::thread t1(&Parametry::zlicz15s, Param.get(), lcdn_wsk, lcdn_wsk_zd, lcdn_wsk_sm, std::ref(ch));
        t1.detach();

        ui->lineEdit_nazwa->clear();
        ui->lineEdit_haslo->clear();
    }
    else
        QMessageBox::warning(this, "Logowanie","Podany uzytkownik nie istnieje!");



}

void MainWindow::on_button_nowe_konto_clicked()
{
    QString nazwa1 = ui->lineEdit_nazwa->text();
    QString haslo1 = ui->lineEdit_haslo->text();
    if(nazwa1.isEmpty() or haslo1.isEmpty())
    {
        QMessageBox::warning(this, "Logowanie","Nazwa i hasło muszą składać się z co najmniej jednego znaku.");
        return;
    }
    std::string nazwa_uzytkownika = nazwa1.toStdString();
    std::string haslo_niezasz = haslo1.toStdString();

    std::regex male_litery("[a-z]+");
    std::regex wielkie_litery("[A-Z]+");
    std::regex cyfry("[0-9]+");

    bool ml = std::regex_search(haslo_niezasz, male_litery);
    bool wl = std::regex_search(haslo_niezasz, wielkie_litery);
    bool c = std::regex_search(haslo_niezasz, cyfry);

    if(!ml or !wl or !c)
    {
        QMessageBox::warning(this, "Logowanie","Hasło powinno składać się z co najmniej jednej małej i jednej wielkiej litery oraz jednej cyfry");
        return;
    }

    std::string haslo = sha256(haslo_niezasz);
    uzytkownik uzytkownik_aktualny(nazwa_uzytkownika, haslo);

    if(std::find(lista_uzytkownikow.begin(), lista_uzytkownikow.end(), uzytkownik_aktualny) != lista_uzytkownikow.end()) //jesli uzytkownik jest w liscie
    {
        QMessageBox::warning(this, "Logowanie","Podany uzytkownik juz istnieje!");
    }
    else //nowy uzytkownik
    {
        uzytkownik_zalogowany = std::make_unique<uzytkownik>(nazwa_uzytkownika, haslo);
        lista_uzytkownikow.push_back(uzytkownik_aktualny);
        std::fstream plik;
        plik.open("uzytkownicy.txt", std::ios::app);
        if(plik)
        {
            plik << nazwa_uzytkownika << ',' << haslo << '\n';
            plik.close();
        }

        //przejdz do wyboru postaci
        ui->stackedWidget->setCurrentIndex(1);

        //tworzenie listy jedzenia
        lista_menu.push_back(Jedzenie("posilek", "Karma dla psa", 300, 'p'));
        lista_menu.emplace_back("posilek", "Woda", 100, 'w');
        lista_menu.emplace_back("posilek", "Karma dla kota", 300, 'k');
        lista_menu.emplace_back("przekaska", "Paluch DentaStick", 200, 'p');
        lista_menu.emplace_back("przekaska", "Zlota rybka", 400, 'k');
        lista_menu.emplace_back("posilek", "Wchiskas", 200, 'k');

        uzytkownik_zalogowany->zapisz_plik_menu(lista_menu);
        for(auto i = lista_menu.begin(); i != lista_menu.end() ; ++i)
        {
            new QListWidgetItem(QString::fromStdString(i->Get_nazwa()), ui->listWidget_jedzenie);
        }
    }

    ui->lineEdit_nazwa->clear();
    ui->lineEdit_haslo->clear();
}

void MainWindow::on_button_ng_pies_clicked()
{
    ui->stackedWidget->setVisible(0);
    //stworz dla uzytkownika psa
    QStackedWidget * wskW = ui->stackedWidget;
    z1_wsk = std::make_unique<Pies>(wskW);

    //dodanie zwierzaka do sceny, aby umozliwic animacje
    scena->addItem(z1_wsk.get());

    uzytkownik_zalogowany->zapisz_plik_uzytkownika(z1_wsk.get());

    QLCDNumber* lcdn_wsk = ui->lcdNumber;
    QLCDNumber* lcdn_wsk_zd = ui->lcdNumber_2_zdrowie;
    QLCDNumber* lcdn_wsk_sm = ui->lcdNumber_3_samopoczucie;
    std::shared_ptr<Parametry> Param = z1_wsk->GetParam();
    std::shared_ptr<Choroba>& ch = z1_wsk->GetChorob();
    std::thread t1(&Parametry::zlicz15s, Param.get(), lcdn_wsk, lcdn_wsk_zd, lcdn_wsk_sm, std::ref(ch));
    t1.detach();
}

void MainWindow::on_button_ng_kot_clicked()
{
    ui->stackedWidget->setVisible(0);
    //stworz dla uzytkownika kota
    QStackedWidget * wskW = ui->stackedWidget;
    z1_wsk = std::make_unique<Kot>(wskW);

    //dodanie zwierzaka do sceny, aby umozliwic animacje
    scena->addItem(z1_wsk.get());

    uzytkownik_zalogowany->zapisz_plik_uzytkownika(z1_wsk.get());

    QLCDNumber* lcdn_wsk = ui->lcdNumber;
    QLCDNumber* lcdn_wsk_zd = ui->lcdNumber_2_zdrowie;
    QLCDNumber* lcdn_wsk_sm = ui->lcdNumber_3_samopoczucie;
    std::shared_ptr<Parametry> Param = z1_wsk->GetParam();
    std::shared_ptr<Choroba>& ch = z1_wsk->GetChorob();
    std::thread t1(&Parametry::zlicz15s, Param.get(), lcdn_wsk, lcdn_wsk_zd, lcdn_wsk_sm, std::ref(ch));
    t1.detach();
}

void MainWindow::on_listWidget_jedzenie_itemDoubleClicked(QListWidgetItem *item)
{
   if(z1_wsk->Get_zeg_j()->isActive() or z1_wsk->Get_zeg_s()->isActive() or z1_wsk->Get_zeg_z()->isActive() )//zabezpieczenie przed podwojna akcja
   {
       QMessageBox::warning(this, "Animacja","Poczekaj na zakończenie animacji!");
       return;
   }
   std::string n_wybr_j = item->text().toStdString();
   auto do_zjedzenia = std::find(lista_menu.begin(), lista_menu.end(), n_wybr_j); //znajdz wybrany przez uzytkownika posilek

   do_zjedzenia->zjedz(z1_wsk.get());
   ui->stackedWidget->setVisible(0);
   z1_wsk->aktywuj_animacje_jedzenie();
}

void MainWindow::on_button_zatw_posilek_clicked()
{
    int tmp = 0, tmp1 = 0;
    std::string na, nj;
    int ka =0;
    char ip;
    if(ui->checkBox_4_przekaska->isChecked()) { na = "przekaska"; tmp++; }
    if(ui->checkBox_5_posilek->isChecked()){ na = "posilek"; tmp++; }
    QString nazwa_j = ui->lineEdit_2_nazwapos->text();
    nj = nazwa_j.toStdString();
    if(nj.empty())
        QMessageBox::warning(this, "BŁĄD","Podaj nazwe posiłku, pamiętaj, że musi być unikalna!");
    if(ui->checkBox_kot->isChecked()) { ip = 'k';tmp1++;}
    if(ui->checkBox_3_pies->isChecked()) { ip = 'p';tmp1++;}
    if(ui->checkBox_2_wszystkie->isChecked()) {ip = 'w'; tmp1++;}
    QString kalor_s = ui->lineEdit_3->text();
    std::string temps = kalor_s.toStdString();
    //sprawdzanie poprawności wprowadzonych danych
    if(temps.empty() or nj.empty())
        QMessageBox::warning(this, "BŁĄD","Podaj kaloryczność, pamietaj, aby była w zakresie 1-500 kcal!");
    else
        ka = std::stoi(temps);

    if(std::find(lista_menu.begin(), lista_menu.end(), nj) != lista_menu.end())
    {
        QMessageBox::warning(this, "BŁĄD","Potrawa o podanej nazwie juz istnieje!");
    }
    else if (tmp != 1 or tmp1 != 1)
    {
        QMessageBox::warning(this, "BŁĄD","W każdej grupie możesz zaznaczyć tylko jeden CheckBox!");
    }
    else if (ka <1 or ka>500)
    {
        QMessageBox::warning(this, "BŁĄD","Podaj kaloryczność w zakresie 1-500!");
    }
    else //jesli wszystko poprawnie wprowadzone - dodaj do list
    {
        lista_menu.emplace_back(na, nj, ka, ip);
        new QListWidgetItem(nazwa_j, ui->listWidget_jedzenie); //dodanie do widżetu
    }
}

void MainWindow::on_button_dodaj_menu_clicked()
{
    QString n_uz_menu = ui->lineEdit_nick->text();
    std::string nick = n_uz_menu.toStdString();
    if(std::find(lista_uzytkownikow.begin(), lista_uzytkownikow.end(), nick) != lista_uzytkownikow.end())
    {
        auto list_wsk = ui->listWidget_jedzenie;
        uzytkownik_zalogowany->dodaj_menu_uz(nick, lista_menu, list_wsk);
    }
    else
    {
        QMessageBox::warning(this, "BŁĄD","Podany użytkownik nie istnieje");
    }
}

//połączenie slidera z lcdNumber aby pokazywało aktulanie wybraną wartość
void MainWindow::on_horizontalSlider_czas_snu_valueChanged(int h)
{
    ui->lcdNumber_2_czas_snu->display(h);
}

void MainWindow::on_button_uspij_clicked()
{
    if(z1_wsk->Get_zeg_j()->isActive() or z1_wsk->Get_zeg_s()->isActive() or z1_wsk->Get_zeg_z()->isActive() ) //zabezpieczenie przed podwojna akcja
    {
        QMessageBox::warning(this, "Animacja","Poczekaj na zakończenie animacji!");
        return;
    }
   int a = ui->horizontalSlider_czas_snu->value(); 
   Sen::spij(z1_wsk.get(), a);
   z1_wsk->aktywuj_animacje_snu();
   ui->stackedWidget->setVisible(0);
}

void MainWindow::on_listWidget_zabawy_itemDoubleClicked(QListWidgetItem *item)
{
    if(z1_wsk->Get_zeg_j()->isActive() or z1_wsk->Get_zeg_s()->isActive() or z1_wsk->Get_zeg_z()->isActive() ) //zabezpieczenie przed podwojna akcja
    {
        QMessageBox::warning(this, "Animacja","Poczekaj na zakończenie animacji!");
        return;
    }
    std::string n_wybr_z = item->text().toStdString();
    int dlugosc_z = ui->spinBox_czas_zabawy->value();
    auto zabawa = std::find(lista_zabaw.begin(), lista_zabaw.end(), n_wybr_z); //znajdz wybrana zabawe w liscie

    zabawa->baw_sie(z1_wsk.get(), dlugosc_z);

    //wybranie odpowiedniej animacji
    if(zabawa->Getnazwaakt() == "nazewnatrz")
        z1_wsk->aktywuj_animacje_zabawy(1);
    else if(zabawa->Getnazwaakt() == "wsrodku")
        z1_wsk->aktywuj_animacje_zabawy(2);
    else
        z1_wsk->aktywuj_animacje_zabawy(3);

    ui->stackedWidget->setVisible(0);
}

void MainWindow::on_button_dermatolog_clicked()
{
    if(z1_wsk->GetChorob() != nullptr)
    {
        dermatolog.wizyta(z1_wsk.get());
    }
    else
        QMessageBox::warning(this,"Lekarz","Twoje zwierzątko jest zdrowe");
}

void MainWindow::on_button_radiolog_clicked()
{
    if(z1_wsk->GetChorob() != nullptr)
    {
        radiolog.wizyta(z1_wsk.get());
    }
    else
        QMessageBox::warning(this,"Lekarz","Twoje zwierzątko jest zdrowe");
}

void MainWindow::on_button_chirurg_clicked()
{
    if(z1_wsk->GetChorob() != nullptr)
    {
        chirurg.wizyta(z1_wsk.get());
    }
    else
        QMessageBox::warning(this,"Lekarz","Twoje zwierzątko jest zdrowe");
}


void MainWindow::on_button_wynik_clicked()
{
    ui->label_wynik1->setVisible(1);
    ui->label_wynik2->setVisible(1);
    ui->label_wynik3->setText(QString::number(z1_wsk->GetParam().get()->Getdni()));
    ui->label_wynik3->setVisible(1);
}

void MainWindow::on_button_nz_przegrana_clicked()
{
    //czysci plik ze statystykami zwierzatka
    uzytkownik_zalogowany->usun_zwierze();
    //przejdz do wyboru postaci
    ui->stackedWidget->setCurrentIndex(1);
    //zapisz plik uzytkownika i menu
    uzytkownik_zalogowany->zapisz_plik_menu(lista_menu);
    //usun zwierze/kota/psa zwolnij pamiec
    z1_wsk.reset();

}

void MainWindow::on_button_nk_przegrana_clicked()
{
    //usun zwierze/kota/psa zwolnij pamiec
    z1_wsk.reset();
    //usun uzytkownika i wyczysc plik ze statystykami zwierzatka
    uzytkownik_zalogowany->usun_zwierze();
    uzytkownik_zalogowany.reset();
    //wyczysc liste
    lista_menu.clear();
    ui->listWidget_jedzenie->clear();
    //wroc do ekranu logowania
    ui->stackedWidget->setCurrentIndex(0);
}

