#ifndef SCENA_HH
#define SCENA_HH
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Graniastoslup.hh"
#include "lacze_do_gnuplota.hh"
#include "Dron.hh"
#include "Plaszczyzna.hh"

#define N 2

class Scena
{
    PzG::LaczeDoGNUPlota Lacze;
    Dron *TabDronow[N];
    Plaszczyzna *dno;
    int nrDrona;

public:
    Scena();
    void RuchDronem();
    void Rysuj();
    bool Interfejs();
    ~Scena();
};

#endif
