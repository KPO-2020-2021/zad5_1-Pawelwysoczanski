#ifndef MACIERZ_HH
#define MACIERZ_HH


#include <iostream>
#include "Wektor.hh"
#include <cmath>
using namespace std;

template <int SIZE>
class Matrix{

  double Mac[SIZE][SIZE];
  public:

Matrix();
double operator()(int index_x, int index_y) const;
double &operator()(int index_x, int index_y);
Vector<SIZE> operator *( Vector<SIZE> wsp);
Matrix<SIZE> operator *( Matrix<SIZE> wsp);
};

template <int SIZE>
Matrix<SIZE> ::Matrix()
{
  for(int i = 0; i < SIZE; ++i)
  {
    for(int j = 0; j < SIZE; ++j)
    {
      if(i==j)
      {
        Mac[i][j]=1;
      }
      else
      {
        Mac[i][j]=0;
      }
    }
  }
}

template <int SIZE>
double Matrix<SIZE> ::operator()(int index_x, int index_y) const
{
    if (index_x > SIZE|| index_x < 0 || index_y > SIZE || index_y < 0) 
    {
        std::cerr << "Indeks poza skala" << std::endl;
        exit(1);
    }
    return Mac[index_x][index_y];
}

template <int SIZE>
double &Matrix<SIZE> ::operator()(int index_x, int index_y)
{
    if (index_x > SIZE || index_x < 0 || index_y > SIZE || index_y < 0) 
    {
        std::cerr << "Indeks poza skala" << std::endl;
        exit(1);
    }
    return Mac[index_x][index_y];
}

template <int SIZE>
Vector<SIZE> Matrix<SIZE> ::operator *( Vector<SIZE> wsp)
{
  Vector<SIZE> Wynik;

  for(int i = 0; i < SIZE; ++i)
  {
    for(int j = 0; j < SIZE; ++j)
    {
      Wynik[i] += Mac[i][j] * wsp[j];
    }
  }
    return Wynik;
}

template <int SIZE>
Matrix<SIZE> Matrix<SIZE>::operator *( Matrix<SIZE> wsp)
{
  Matrix
<SIZE> Wynik;

  for(int i = 0; i < SIZE; ++i)
  {
    for(int j = 0; j < SIZE; ++j)
    {
      Wynik(i,j) =0;
         for(int k = 0; k < SIZE; k++ ) Wynik(i,j) += Mac [ i ][ k ] * wsp(k,j) ;
    }
  }
    return Wynik;
}


template <int SIZE>
inline
std::ostream& operator << (std::ostream &Strm, const Matrix<SIZE> &wsp)
{
   for(int i = 0; i < SIZE; ++i)
  {
    for(int j = 0; j < SIZE; ++j)
    {
     cout<<wsp(i,j)<<" ";
    }
         cout<<endl;
  }
  return Strm;  
}


#endif
