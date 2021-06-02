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
  *\brief Konstruktor parametryczny klasy Prostopadloscian
  */
  Prostopadloscian(Vector3D SrodekBryly, double szerokosc, double dlugosc, double wysokosc, std::string Nazwa = "bryly_wzorcowe/prostopadloscian.dat");
  /*!
  *\brief Destrukto klasy Prostopadloscian.
  */
  ~Prostopadloscian() { delete Wymiar; }
};

#endif