#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QProgressBar>
#include <thread>
#include <memory>
#include <list>
#include <string>
#include <regex>

#include <QListWidget>
#include <QListWidgetItem>

#include "sha256.h"
#include "uzytkownik.h"
#include "scena.h"
#include "kot.h"
#include "pies.h"
#include "parametry.h"
#include "jedzenie.h"
#include "sen.h"
#include "zabawa.h"
#include "choroba.h"
#include "doktor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_zapisz_clicked();

    void on_button_jedzenie_clicked();

    void on_button_zabawa_clicked();

    void on_button_wroc_clicked();

    void on_button_wroc_2_clicked();

    void on_button_wroc_3_clicked();

    void on_button_wroc_4_clicked();

    void on_button_wroc_5_clicked();

    void on_button_sen_clicked();

    void on_button_wizyta_clicked();

    void on_button_ng_pies_clicked();

    void on_button_zaloguj_clicked();

    void on_button_nowe_konto_clicked();

    void on_button_ng_kot_clicked();

    void on_listWidget_jedzenie_itemDoubleClicked(QListWidgetItem *item);

    void on_button_dod_posilek_clicked();

    void on_button_wroc_6_clicked();

    void on_button_zatw_posilek_clicked();

    void on_button_dodaj_menu_clicked();

    void on_horizontalSlider_czas_snu_valueChanged(int value);

    void on_button_uspij_clicked();

    void on_listWidget_zabawy_itemDoubleClicked(QListWidgetItem *item);

    void on_button_dermatolog_clicked();

    void on_button_radiolog_clicked();

    void on_button_chirurg_clicked();

    void on_button_nz_przegrana_clicked();

    void on_button_nk_przegrana_clicked();

    void on_button_wynik_clicked();

private:
    Ui::MainWindow *ui;
    Scena* scena;

    std::vector<uzytkownik> lista_uzytkownikow;
    std::list<Jedzenie> lista_menu;
    std::list<Zabawa> lista_zabaw;

    std::unique_ptr<uzytkownik> uzytkownik_zalogowany;

    //wskazniki na zwierze
    std::unique_ptr<zwierze> z1_wsk;

    //doktorzy
    Doktor dermatolog;
    Doktor chirurg;
    Doktor radiolog;

};
#endif // MAINWINDOW_H
