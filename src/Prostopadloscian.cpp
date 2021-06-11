#include "Prostopadloscian.hh"

/*!
  *\brief Konstruktor parametryczny klasy Prostopadloscian.
  *Tworzy prostopaloscian o stalych wymiarach i zapisuje go w pliku.
  */
Prostopadloscian::Prostopadloscian(Vector3D SrodekBryly, double x, double y, double z, std::string NazwaPliku)
{
  double tab[] = {x, y, z};
  wymiaryBryly = new Vector3D(tab);
  this->NazwaPliku = NazwaPliku;
  this->SrodekBryly = SrodekBryly;
  Vector3D vector;

  vector[0] = SrodekBryly[0] - (x / 2);
  vector[1] = SrodekBryly[1] + (y / 2);
  vector[2] = SrodekBryly[2] + (z / 2);
  WierzBryly.push_back(vector);

  vector[0] = SrodekBryly[0] - (x / 2);
  vector[1] = SrodekBryly[1] + (y / 2);
  vector[2] = SrodekBryly[2] - (z / 2);
  WierzBryly.push_back(vector);

  vector[0] = SrodekBryly[0] + (x / 2);
  vector[1] = SrodekBryly[1] + (y / 2);
  vector[2] = SrodekBryly[2] + (z / 2);
  WierzBryly.push_back(vector);

  vector[0] = SrodekBryly[0] + (x / 2);
  vector[1] = SrodekBryly[1] + (y / 2);
  vector[2] = SrodekBryly[2] - (z / 2);
  WierzBryly.push_back(vector);

  vector[0] = SrodekBryly[0] + (x / 2);
  vector[1] = SrodekBryly[1] - (y / 2);
  vector[2] = SrodekBryly[2] + (z / 2);
  WierzBryly.push_back(vector);

  vector[0] = SrodekBryly[0] + (x / 2);
  vector[1] = SrodekBryly[1] - (y / 2);
  vector[2] = SrodekBryly[2] - (z / 2);
  WierzBryly.push_back(vector);

  vector[0] = SrodekBryly[0] - (x / 2);
  vector[1] = SrodekBryly[1] - (y / 2);
  vector[2] = SrodekBryly[2] + (z / 2);
  WierzBryly.push_back(vector);

  vector[0] = SrodekBryly[0] - (x / 2);
  vector[1] = SrodekBryly[1] - (y / 2);
  vector[2] = SrodekBryly[2] - (z / 2);
  WierzBryly.push_back(vector);
}
