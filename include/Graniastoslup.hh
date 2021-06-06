#ifndef GRANIASTOSLUP6_HH
#define GRANIASTOSLUP6_HH

#include "BrylaGeometryczna.hh"
/*!
*\file
*\brief Definicja klasy Prostopadloscian.
*/

/*!
*\brief Klasa Graniastoslup.
*Klasa definiuje pojecie Graniastoslupa.
*Klasa dziedziczy po klasie rodzica BrylaGeometryczna.
*/
class Graniastoslup6 : public BrylaGeometryczna
{
public:
    /*!
*\brief Konstruktor parametryczny klasy Graniastoslup
*/
    Graniastoslup6(Vector3D srodek = Vector3D(), double z = 10, double promien = 25, std::string nazwa = "../dat/garniastoslup.dat");
    /*!
*\brief Destruktor klasy Graniastoslup
*/
    ~Graniastoslup6() { delete wymiaryBryly; }
};

#endif
