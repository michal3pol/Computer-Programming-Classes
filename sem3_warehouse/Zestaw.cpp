#include "Zestaw.h"

Zestaw& Zestaw::operator()(const Klawiatura*& k1, const Mysz*& m1, const Sluchawki*& s1)
{
    std::cout << "stworzono zestaw\n";

    _k1 = k1;
    _m1 = m1;
    _s1 = s1;

    return *this;
    // TODO: tu wstawiæ instrukcjê return
}
