#ifndef SEN_H
#define SEN_H

#include "aktywnosci.h"
#include "zwierze.h"

class Sen : public Aktywnosci
{

public:
    Sen();

    static void spij(zwierze*, int);

};

#endif // SEN_H
