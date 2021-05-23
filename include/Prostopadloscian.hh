#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include <iostream>
#include "Wektor3D.hh"
#include "Wektor.hh"

#define SIZE_VERTEX 8

/*!
 * \file
 * \brief Plik zawiera ...
 *
 * Plik ...
 */

/*!
 *  \brief Skrócony opis klasy
 *
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */

class Cuboid
{

private:
  Vector3D cuboid[SIZE_VERTEX];

public:
  Cuboid();

  Cuboid(const Vector3D &vector, double height, double width, double lenght);

  Cuboid operator+(const Vector3D &vector);

  Cuboid operator-(const Vector3D &vector);

  const Vector3D &operator[](int index) const;

  Vector3D &operator[](int index);

  bool operator==(const Cuboid &cu) const;

  bool operator!=(const Cuboid &cu) const;

  void translation(const Vector3D &vector);

  void length();
};

/*!
 * \brief Skrócony opis ...
 *
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */

std::ostream &operator<<(std::ostream &out, Cuboid const &tmp);

std::istream &operator>>(std::istream &in, Cuboid &tmp);

#endif
