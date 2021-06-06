#include "sen.h"

Sen::Sen()
{

}

void Sen::spij(zwierze * zw, int dl_snu)
{
    int mnoznik = zw->Getsennosc();

    zw->GetParam()->dodaj_czas_akcji(dl_snu);
    zw->GetParam()->aktualizujZS(10, dl_snu+mnoznik);
    zw->GetParam()->Setpzsnu(dl_snu);
    zw->GetParam()->Setdzis_sen(true);
}
