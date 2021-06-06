#include "Plaszczyzna.hh"

/*!
*\brief Konstruktor parametryczny klasy plaszczyzna.
*/
Plaszczyzna::Plaszczyzna(Vector3D wymiary, int gestosc_siatki, std::string NazwaPliku)
{
    this->NazwaPliku = NazwaPliku;
    double tab[3];
    ileP = 0;
    for (int i = -wymiary[0] / 2; i < wymiary[0] / 2; i += gestosc_siatki)
    {
        for (int j = -wymiary[1] / 2; j < wymiary[1] / 2; j += gestosc_siatki)
        {
            tab[0] = i;
            tab[1] = j;

            WierzPlaszcz.push_back(tab);
        }
        ileP++;
    }
}
/*!
*\brief Metoda ktora zapisuje plaszczyzne do pliku.
*/
void Plaszczyzna::zapisz()
{
    std::fstream plik;

    plik.open(NazwaPliku, std::ios::out);
    for (int i = 0; i < (int)WierzPlaszcz.size(); i++)
    {
        if (i % ileP == 0)
            plik << std::endl;
        plik << WierzPlaszcz[i] << std::endl;
    }

    plik.close();
}