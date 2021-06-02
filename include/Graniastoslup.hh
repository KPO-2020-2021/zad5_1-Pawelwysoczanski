#ifndef GRANIASTOSLUP_HH_
#define GRANIASTOSLUP_HH_

#include "BrylaGeometryczna.hh"

/*!
*\file
*\brief Definicja klasy Prostopadloscian.
*/

/*!
*\brief Klasa Graniastoslup
*Klasa definiuje pojecie Graniastoslupu.
*Klasa dziedziczy po klasie rodzica BrylaGeometryczna.
*/
class Graniastoslup : public BrylaGeometryczna
{

public:
   /*!
*\brief Konstruktor parametryczny klasy Graniastoslup.
*/
   Graniastoslup(Vector3D SrodekBryly, double promien = 40, double z = 10, std::string Nazwa = "bryly_wzorcowe/szescian.dat");
   /*!
   *\brief Destruktor klasy Garaniastoslup.
   */
   ~Graniastoslup() { delete Wymiar; }
};

#endif