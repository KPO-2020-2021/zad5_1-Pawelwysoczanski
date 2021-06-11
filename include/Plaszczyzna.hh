#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH

#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include <fstream>
#include <vector>
/*!
*\file
*\brief Definicja klasy Plaszczyzna.
*/

/*!
*\brief Klasa Plaszczyzna.
*
* Klasa definiuje pojecie plaszczyzny sceny po ktorej porusza sie dron.
*/
class Plaszczyzna
{
protected:
    /*!
*\brief Wierzcholki plaszczyzny.
* Pojemnik przechowujacy wspolrzedne wierzcholkow plaszczyzny.
*/
    std::vector<Vector3D> WierzPlaszcz;
    /*!
*\brief Nazwa pliku.
* Przechowuje nazwe pliku zapisu plaszczyzny.
*/
    std::string NazwaPliku;
    /*!
*\brief Ilosc prostych w siatce plaszczyzny.
* Przechowuje ilosc prostych siatki plaszczyzny.
*/
    int ileP;

public:
    /*!
*\brief Konstruktor parametryczny klasy plaszczyzna.
*/
    Plaszczyzna(Vector3D wymiary = Vector3D(), int gestosc_siatki = 10, std::string nazwa = "../dat/plaszczyzna.dat");
    /*!
*\brief 
*/
    Vector3D &operator[](int index)
    {
        return WierzPlaszcz[index];
    }
    /*!
*\brief 
*/
    Vector3D operator[](int index) const
    {
        return WierzPlaszcz[index];
    }
    /*!
*\brief Metoda ktora utawia nazwe pliku zapisu plaszczyzny.
*/
    void SetNazwa(std::string NazwaPliku)
    {
        this->NazwaPliku = NazwaPliku;
    }
    /*!
*\brief Metoda ktora zwraca nazwe pliku zapisu plaszczyzny.
*/
    std::string GetNazwa() const
    {
        return NazwaPliku;
    }
    /*!
*\brief Metoda ktora zapisuje plaszczyzne do pliku.
*/
    void zapisz();
};

#endif