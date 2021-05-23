#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <cmath>
#include <iostream>
#include "Wektor.hh"
#include "Prostopadloscian.hh"

template <int SIZE>
class Matrix
{
private:
  double matrix[SIZE][SIZE];

public:
  Matrix();

  Matrix(double tmp[SIZE][SIZE]);

  Vector<SIZE> operator*(const Vector<SIZE> &tmp);

  Cuboid operator*(Cuboid tmp); // Operator mnozenia macierzy

  Matrix operator+(const Matrix &tmp);

  bool operator==(const Matrix &m) const;

  bool operator!=(const Matrix &m) const;

  double &operator()(unsigned int row, unsigned int column);

  const double &operator()(unsigned int row, unsigned int column) const;

  void rotuj_x(double kat);

  void rotuj_y(double kat);

  void rotuj_z(double kat);

  void ModRotacji(double alpha, double beta, double gamma, Vector3D ve);

  void WyswietlWynik();
};

template <int SIZE>
std::istream &operator>>(std::istream &in, Matrix<SIZE> &tmp);

template <int SIZE>
std::ostream &operator<<(std::ostream &out, const Matrix<SIZE> &tmp);
/******************************************************************************
 |  Konstruktor klasy Matrix.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
template <int SIZE>
Matrix<SIZE>::Matrix()
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      matrix[i][j] = 0;
    }
  }
}
/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix.                                   |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                  |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
template <int SIZE>
Matrix<SIZE>::Matrix(double tmp[SIZE][SIZE])
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      matrix[i][j] = tmp[i][j];
    }
  }
}
/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */
template <int SIZE>
Vector<SIZE> Matrix<SIZE>::operator*(const Vector<SIZE> &tmp)
{
  Vector<SIZE> result;
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      result[i] += matrix[i][j] * tmp[j];
    }
  }
  return result;
}
/******************************************************************************
 |  Realizuje mnozenie macierzy i wierzcholkow prostokata.                    |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia,                                    |
 |      tmp - drugi skladnik mnozenia.                                        |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template <int SIZE>
Cuboid Matrix<SIZE>::operator*(Cuboid tmp)
{
  Cuboid result;
  for (int i = 0; i < SIZE_VERTEX; ++i)
  {

    result[i] = *this * tmp[i];
  }
  return result;
}
/******************************************************************************
 |  Realizuje porownanie dwoch macierzy.                                      |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik porownania,                   |
 |      m - macierz, czyli drugi skladnik porownania.                         |
 |  Zwraca:                                                                   |
 |      TRUE lub FALSE.                                                       |
 */
template <int SIZE>
bool Matrix<SIZE>::operator==(const Matrix<SIZE> &m) const
{

  bool wynik = true;
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {

      if ((matrix[i][j] != m.matrix[i][j]))
        wynik = false;
    }
  }
  return wynik;
}
/******************************************************************************
 |  Realizuje porownanie dwoch macierzy.                                      |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik porownania,                   |
 |      m - macierz, czyli drugi skladnik porownania.                         |
 |  Zwraca:                                                                   |
 |      TRUE lub FALSE.                                                       |
 */
template <int SIZE>
bool Matrix<SIZE>::operator!=(const Matrix<SIZE> &m) const
{
  return !(*this == m);
}
/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
template <int SIZE>
double &Matrix<SIZE>::operator()(unsigned int row, unsigned int column)
{
  if (row >= SIZE)
  {
    std::cout << "Error: Macierz jest poza zasiegiem";
    exit(0);
  }
  if (column >= SIZE)
  {
    std::cout << "Error: Macierz jest poza zasiegiem";
    exit(0);
  }
  return matrix[row][column];
}
/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
template <int SIZE>
const double &Matrix<SIZE>::operator()(unsigned int row, unsigned int column) const
{
  if (row >= SIZE)
  {
    std::cout << "Error: Macierz jest poza zasiegiem";
    exit(0);
  }
  if (column >= SIZE)
  {
    std::cout << "Error: Macierz jest poza zasiegiem";
    exit(0);
  }
  return matrix[row][column];
}
/******************************************************************************
 |  Przeciążenie dodawania macierzy                                           |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                    |
 |      v - wektor, czyli drugi skladnik dodawania.                           |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                            |
 */
template <int SIZE>
Matrix<SIZE> Matrix<SIZE>::operator+(const Matrix<SIZE> &tmp)
{
  Matrix result;
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      result(i, j) = this->matrix[i][j] + tmp(i, j);
    }
  }
  return result;
}
/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                        |
 */
template <int SIZE>
std::istream &operator>>(std::istream &in, Matrix<SIZE> &tmp)
{
  for (int i = 0; i < SIZE; ++i)
  {
    for (int j = 0; j < SIZE; ++j)
    {
      in >> tmp(i, j);
    }
  }
  return in;
}
/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
template <int SIZE>
std::ostream &operator<<(std::ostream &out, const Matrix<SIZE> &tmp)
{
  for (int i = 0; i < SIZE; ++i)
  {
    for (int j = 0; j < SIZE; ++j)
    {
      out << "| " << tmp(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
    }
    std::cout << std::endl;
  }
  return out;
}
/******************************************************************************
|  Tworzy macierz rotacji i wylicza jej skałdniki podane z przez uzytkownika  | 
|  Argumenty:                                                                 |
|       angle - kat o jaki ma zostac obrocony prostokat                       |      
|       wymiar - wybor osi wedlug ktorej zosatnie wykonana rotacja            |
|  Zwraca:                                                                    |
|                                                                             |
*/

template <int SIZE>
void Matrix<SIZE>::rotuj_x(double kat)
{
  double radian = kat * M_PI / 180;

  matrix[0][0] = 1;
  matrix[0][1] = 0;
  matrix[0][2] = 0;
  matrix[1][0] = 0;
  matrix[1][1] = cos(radian);
  matrix[1][2] = -sin(radian);
  matrix[2][0] = 0;
  matrix[2][1] = sin(radian);
  matrix[2][2] = cos(radian);
}
template <int SIZE>
void Matrix<SIZE>::rotuj_y(double kat)
{
  double radian = kat * M_PI / 180;

  matrix[0][0] = cos(radian);
  matrix[0][1] = 0;
  matrix[0][2] = sin(radian);
  matrix[1][0] = 0;
  matrix[1][1] = 1;
  matrix[1][2] = 0;
  matrix[2][0] = -sin(radian);
  matrix[2][1] = 0;
  matrix[2][2] = cos(radian);
}
template <int SIZE>
void Matrix<SIZE>::rotuj_z(double kat)
{
  double radian = kat * M_PI / 180;

  matrix[0][0] = cos(radian);
  matrix[0][1] = -sin(radian);
  matrix[0][2] = 0;
  matrix[1][0] = sin(radian);
  matrix[1][1] = cos(radian);
  matrix[1][2] = 0;
  matrix[2][0] = 0;
  matrix[2][1] = 0;
  matrix[2][2] = 1;
}
template <int SIZE>
void Matrix<SIZE>::ModRotacji(double alpha, double beta, double gamma, Vector3D ve)
{
  matrix[0][0] = (cos(alpha) * cos(beta));
  matrix[0][1] = (cos(alpha) * sin(beta) * sin(gamma)) - (sin(alpha) * cos(gamma));
  matrix[0][2] = (cos(alpha) * sin(beta) * cos(gamma)) + (sin(alpha) * sin(gamma));
  matrix[0][3] = ve[0];
  matrix[1][0] = sin(alpha) * cos(beta);
  matrix[1][1] = (sin(alpha) * sin(beta) * sin(gamma)) + (cos(alpha) * cos(gamma));
  matrix[1][2] = (sin(alpha) * sin(beta) * cos(gamma)) - (cos(alpha) * cos(gamma));
  matrix[1][3] = ve[1];
  matrix[2][0] = -sin(beta);
  matrix[2][1] = cos(beta) * cos(gamma);
  matrix[2][2] = cos(beta) * cos(gamma);
  matrix[2][3] = ve[2];
  matrix[3][0] = 0;
  matrix[3][1] = 0;
  matrix[3][2] = 0;
  matrix[3][3] = 1;
}
template <int SIZE>
void Matrix<SIZE>::WyswietlWynik()
{
  matrix[0][0] = 0.275963;
  matrix[0][1] = -0.0666459;
  matrix[0][2] = 0.958855;
  matrix[0][3] = 3;
  matrix[1][0] = 0.446998;
  matrix[1][1] = 0.892049;
  matrix[1][2] = 0.104389;
  matrix[1][3] = 4;
  matrix[2][0] = -0.850904;
  matrix[2][1] = 0.275963;
  matrix[2][2] = 0.275963;
  matrix[2][3] = 6;
  matrix[3][0] = 0;
  matrix[3][1] = 0;
  matrix[3][2] = 0;
  matrix[3][3] = 1;
}
#endif