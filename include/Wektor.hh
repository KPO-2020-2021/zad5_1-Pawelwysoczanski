#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <cmath>
/*Szablona klasy Vector*/
template <int SIZE>
class Vector
{
private:
    double ve[SIZE];

    static inline unsigned int stworzone = 0;

    static inline unsigned int istniejace = 0;

public:
    Vector();

    Vector(double[SIZE]);

    ~Vector(){istniejace--};

    Vector(std::initializer_list<int> list);

    static int GetStworzone(){return stworzone};

    static int GetIstniejace(){return istniejace};

    Vector operator+(const Vector &v);

    Vector operator-(const Vector &v);

    Vector operator*(const double &tmp);

    Vector operator/(const double &tmp);

    const double &operator[](int index) const;

    bool operator==(const Vector &v) const;

    bool operator!=(const Vector &v) const;

    double &operator[](int index);

    double length(const Vector &v);
};

template <int SIZE>
std::ostream &operator<<(std::ostream &out, Vector<SIZE> const &tmp);

template <int SIZE>
std::istream &operator>>(std::istream &in, Vector<SIZE> &tmp);
/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
template <int SIZE>
Vector<SIZE>::Vector()
{
    for (int i = 0; i < SIZE; i++)
    {
        ve[i] = 0;
    }
}
/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */

template <int SIZE>
Vector<SIZE>::Vector(double tmp[SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        ve[i] = tmp[i];
    }
}
template <int SIZE>
Vector<SIZE>::Vector(std::initializer_list<int> list)
{
    if (list.size() != SIZE)
    {
        cerr << "[!]Incorrect number of arguments in Vector" << endl;
        exit(1);
    }

    int i = 0;
    for (int arg : list)
        this->ve[i++] = arg;

    istniejace++;
    stworzone++;
}
/******************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator+(const Vector &v)
{
    Vector result;
    for (int i = 0; i < SIZE; i++)
    {
        result[i] = ve[i] + v[i];
    }
    return result;
}
/******************************************************************************
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator-(const Vector &v)
{
    Vector result;
    for (int i = 0; i < SIZE; i++)
    {
        result[i] = ve[i] - v[i];
    }
    return result;
}
/******************************************************************************
 |  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu double).                     |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator*(const double &tmp)
{
    Vector result;
    for (int i = 0; i < SIZE; i++)
    {
        result[i] = ve[i] * tmp;
    }
    return result;
}
/******************************************************************************
 |  Realizuje dzielenie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - licznik dzielenia,                                             |
 |      v - mianownik dzielenia.                                              |
 |  Zwraca:                                                                   |
 |      Iloraz dwoch skladnikow przekazanych jako wskaznik                    |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator/(const double &tmp)
{
    Vector result;
    for (int i = 0; i < SIZE; i++)
    {
        result[i] = ve[i] / tmp;
    }
    return result;
}
/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
template <int SIZE>
const double &Vector<SIZE>::operator[](int index) const
{
    if ((index < 0) || (index >= SIZE))
    {
        throw "ERROR: Wektor jest poza zasięgiem!";
    }
    return ve[index];
}
/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
template <int SIZE>
double &Vector<SIZE>::operator[](int index)
{
    return const_cast<double &>(const_cast<const Vector *>(this)->operator[](index));
}
/******************************************************************************
 |  Realizuje porownanie dwoch wektorow.                                      |
 |  Argumenty:                                                                |
 |      this - vector, czyli pierwszy skladnik porownania,                    |
 |      v- vector, czyli drugi skladnik porownania.                           |
 |  Zwraca:                                                                   |
 |      TRUE lub FALSE.                                                       |
 */
template <int SIZE>
bool Vector<SIZE>::operator==(const Vector &v) const
{
    bool result = true;
    for (int i; i < SIZE; i++)
    {
        if ((ve[i] != v.ve[i]))
            result = false;
    }
    return result;
}
/******************************************************************************
 |  Realizuje porownanie dwoch wektorow.                                      |
 |  Argumenty:                                                                |
 |      this - vector, czyli pierwszy skladnik porownania,                    |
 |      v- vector, czyli drugi skladnik porownania.                           |
 |  Zwraca:                                                                   |
 |      TRUE lub FALSE.                                                       |
 */
template <int SIZE>
bool Vector<SIZE>::operator!=(const Vector &v) const
{
    return !(*this == v);
}
/*****************************************************************************
|  Metoda klasy Vector wyliczajaca odleglosc miedzy punktami.                | 
|  Argumeny:                                                                 |
|      this - vector, czyli pierwszy skladnik metody,                        |
|      v- vector, czyli drugi skladnik metody.                               |
|   Zwraca:                                                                  |
|      Dlugosc odleglosci miedzy punktammi.                                  |
|                                                                            |
*/
template <int SIZE>
double Vector<SIZE>::length(const Vector<SIZE> &v)
{
    double suma = 0;
    for (int i = 0; i < SIZE; i++)
        suma += pow(ve[i] - v[i], 2);
    return sqrt(suma);
}

/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wyjsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
template <int SIZE>
std::ostream &operator<<(std::ostream &out, Vector<SIZE> const &tmp)
{
    for (int i = 0; i < SIZE; i++)
    {
        out << tmp[i] << " ";
    }

    return out;
}
/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wejsciowy,                                              |
 |      tmp - wektor.                                                         |
 */
template <int SIZE>
std::istream &operator>>(std::istream &in, Vector<SIZE> &tmp)
{

    for (int i = 0; i < SIZE; i++)
    {
        in >> tmp[i];
        if (in.fail())
        {
            for (int i = 0; i < SIZE; i++)
            {
                tmp[i] = 0;
            }
        }
    }
    std::cout << std::endl;
    return in;
}

#endif
