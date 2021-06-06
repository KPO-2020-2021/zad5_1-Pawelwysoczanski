#include "Graniastoslup.hh"

/*!
*\brief Konstruktor parametryczny klasy Graniastoslup
*/
Graniastoslup6::Graniastoslup6(Vector3D SrodekBryly, double z, double promien, std::string NazwaPliku)
{
    double tab[] = {0, 0, z};
    wymiaryBryly = new Vector3D(tab);
    this->NazwaPliku = NazwaPliku;
    this->SrodekBryly = SrodekBryly;
    Vector3D vector;
    for (int i = 0; i < 360; i += 60)
    {
        vector[0] = promien * cos(i * M_PI / 180);
        vector[1] = promien * sin(i * M_PI / 180);
        vector[2] = SrodekBryly[2] + (z / 2);
        WierzBryly.push_back(vector);
        vector[0] = promien * cos(i * M_PI / 180);
        vector[1] = promien * sin(i * M_PI / 180);
        vector[2] = SrodekBryly[2] - (z / 2);
        WierzBryly.push_back(vector);
    }
}