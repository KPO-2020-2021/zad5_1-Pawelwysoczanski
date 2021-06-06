#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "BrylaGeometryczna.hh"

/*!
*\file
*\brief Definicja klasy Prostopadloscian.
*/

/*!
*\brief Klasa Prostopadloscian
*Klasa definiuje pojecie Prostopadloscianu.
*Klasa dziedziczy po klasie rodzica BrylaGeometryczna.
*/
class Prostopadloscian : public BrylaGeometryczna
{

public:
    /*!
  *\brief Konstruktor parametryczny klasy Prostopadloscian.
  */
    Prostopadloscian(Vector3D srodek = Vector3D(), double x = 100, double y = 50, double z = 50, std::string nazwa = "../dat/prostopadloscian.dat");
    /*!
  *\brief Destruktor klasy Prostopadloscian.
  */
    ~Prostopadloscian()
    {
        delete wymiaryBryly;
    }
};

#endif