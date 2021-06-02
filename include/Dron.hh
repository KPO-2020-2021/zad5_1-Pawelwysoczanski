#ifndef DRON_HH_
#define DRON_HH_

#include "Prostopadloscian.hh"
#include "Graniastoslup.hh"
#include "lacze_do_gnuplota.hh"
#include <unistd.h> 
#define CZAS_PRZELOTU 10000

/*!
*\file
*\brief Definicja klasy Dron.
*/

/*!
*\brief Klasa Dron
*Klasa definiuje pojecie Drona.
*Klasa tworzy model drona z bryl geometrycznych.
*/

class Dron
{
private:
/*!
*\brief Przechowuje oryginalny prostopadloscian.
*/
    Prostopadloscian oryginalny;
  /*!
*\brief Przechowuje kopie oryginalnego prostopadloscianu.
*/
    Prostopadloscian kopia;
/*!
*\brief Przechowuje tablice oryginalnych rotorow.
*/
    Graniastoslup wir_o[4];
  /*!
*\brief Przechowuje tablice kopi oryginalnych rotorow.
*/
    Graniastoslup wir_k[4];
/*!
*\brief 
*/
    Macierz3x3 obrot;
  /*!
*\brief Przechowuje informacje o tym jaka droge ma pokonac dron w czasie przelotu.
*/
    Vector3D droga;
/*!
*\brief Pojemnik na punkty trasy przelotu drona.
*/
    std::vector<Vector3D> trasa;
  /*!
*\brief 
*/
    PzG::LaczeDoGNUPlota &Lacze;
/*!
*\brief Przechowuje informacje o zadanym kacie o jaki ma sie obrocic dron.
*/
    double kat;
  /*!
*\brief Przechowuje informacje o tym ktory dron jest aktywny.
*/
    int nr;

public:
/*!
*\brief Konstrukto parametryczny klasy Dron
*/
    Dron(int nr, PzG::LaczeDoGNUPlota &Lacze, Vector3D pozycja);
    /*!
*\brief Metoda klasy Dron wykonuje wznoszenie drona.
*/
    void Wznoszenie(double droga);
  /*!
*\brief Metoda klasy Dron wykonuje przesuniecie drona. 
*/
    void Przesun(double droga);
  /*!
*\brief Metoda klasy Dron wykonuje obrot drona.
*/
    void Obrot(double kat);
  /*!
*\brief Metoda klasy Dron wykonuje obrot rotorow w czasie przelotu drona.
*/
    void ObrotRotrow();
  /*!
*\brief Metoda klasy Dron wykonuje zapis drona do pliku.
*/
    void Zapis();
  /*!
*\brief Metoda klasy Dron tworzaca interfejs sterowania dronem. 
*/
    void Sterowanie();
  /*!
*\brief Metoda klasy Dron rysujaca droge po jakiej porusza sie dron.
*/
    void RysujDroge(double droga);
};

#endif