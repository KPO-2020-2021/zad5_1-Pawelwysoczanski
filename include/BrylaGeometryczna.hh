#ifndef BRYLAGEOMETRYCZNA_HH_
#define BRYLAGEOMETRYCZNA_HH_

#include "Wektor3D.hh"
#include "Mcierz3x3.hh"
#include <fstream>
#include <vector>

/*!
*\file
*\brief Definicja klasy BrylaGeometryczna.
*/

/*!
*\brief Klasa BrylaGeometryczna
*Klasa definiuje pojecie bryly geometryacznej.
*Klasa jest rodzicem dla klas dziedzicznych Prostopadloscian i Graniastoslup.
*/
class BrylaGeometryczna
{

protected:
    /*!
  *\brief Wskaznik na wektor przechowujacy
  */
    Vector3D *Wymiar;
    /*!
    *\brief Zmienna przechowujaca pozycje wierzcholkow bryly geometrycznej.
    */
    std::vector<Vector3D> Wierz;
    /*!
    *\brief Wektor przechowujacy polozenie srodka bryly geometrycznej.
    */
    Vector3D SrodekBryly;
    /*!
    *\brief Zmienna przechowujaca nazwe pliku docelowego dla bryly geometrycznej.
    */
    std::string Nazwa;

public:
    /*!
*\brief 
*/
    Vector3D &operator[](int index)
    {
        return Wierz[index];
    }
    /*!
*\brief 
*/
    Vector3D
    operator[](int index) const
    {
        return Wierz[index];
    }
    /*!
*\brief 
*/
    void SetSrodekBryly(Vector3D srodek)
    {
        this->SrodekBryly = SrodekBryly;
    }
    /*!
*\brief 
*/
    void SetNazwa(std::string nazwa)
    {
        this->Nazwa = Nazwa;
    }
    /*!
*\brief 
*/
    Vector3D GetSrodekBryly() const
    {
        return SrodekBryly;
    }
    /*!
*\brief 
*/
    std::string GetNazwa() const
    {
        return Nazwa;
    }
    /*!
*\brief Metoda klasy BrylaGeometryczna wykonujaca przesuniecie bryly o zadany wektor.
*/
    void Przesun(Vector3D przesun);
    /*!
*\brief Metoda klasy BrylaGeometryczna wykonujaca obrot bryly o zadany kat. 
*/
    void Translacja(Macierz3x3 obrot);
    /*!
*\brief Metoda klasy BrylaGeometryczna zapisujaca do pliku ksztalt bryly.
*/
    void Zapisz();
};

#endif