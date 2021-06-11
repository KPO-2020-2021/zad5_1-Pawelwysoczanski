#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <cmath>
using namespace std;

/*!
*\file
*\brief Definicja szablonu klasy Vector.
*/

/*!
*\brief Szablon klasy Vector
* Definiuje pojecie Wektora jako szablonu o dowolnym wymiarze
*/
template <int SIZE>
class Vector
{
    /*!
    *\brief Przechowuje ilosc wszytskich stworzonych konstruktorow klasy Vector.
    */
    static int wszystkie;
       /*!
    *\brief Przechowuje ilosc aktualnie stworzonych konstruktorow klasy Vector.
    */
    static int aktualne;
       /*!
    *\brief Tbalica przechowujaca polozenie wspolrzednych wektora.
    */
    double _wsp[SIZE];

public:
   /*!
    *\brief Konstruktor bezparametryczny kalsy Vectro.
    */
    Vector();
       /*!
    *\brief Metoda zliczajaca ilosc stworzonych konstruktorow.
    */
    Vector(Vector<SIZE> &wek)
    {
        for (int i = 0; i < SIZE; i++)
            _wsp[i] = wek._wsp[i];

        aktualne++;
    }
       /*!
    *\brief Metoda zliczajaca ilosc stworzonych konstruktorow.
    */
    constexpr Vector(const Vector &other)
    {
        for (int i = 0; i < SIZE; i++)
            _wsp[i] = other._wsp[i];
        aktualne++;
    }
       /*!
    *\brief Operator przypiasania Vectora do Vectora.
    */
    Vector &operator=(const Vector &other)
    {
        for (int i = 0; i < SIZE; i++)
            _wsp[i] = other._wsp[i];
        return *this;
    }
   /*!
    *\brief Operator przypiasania wartosci zmienno przecinkowych do Vectora.
    */
    Vector &operator=(const float &other)
    {
        for (int i = 0; i < SIZE; i++)
            _wsp[i] = other;
        return *this;
    }
       /*!
    *\brief Destruktor klasy Vector
    */
    ~Vector();
       /*!
    *\brief Konstruktor parametryczny klasy Vector wykorzystujacy tablice double.
    */
    Vector(double _wsp[SIZE]);
       /*!
    *\brief Funktor wektora.
    */
    double operator[](int index) const;
       /*!
    *\brief Funktor wektora.
    */
    double &operator[](int index);
       /*!
    *\brief Operator dodawnia Vectora do Vectora.
    */
    Vector<SIZE> operator+(Vector<SIZE> &arg);
       /*!
    *\brief Operator odjemowania Vectora od Vectora.
    */
    Vector<SIZE> operator-(Vector<SIZE> &arg);
       /*!
    *\brief Metoda wyswietlajaca ilosc wszytkich stworzonych konstruktorow oraz ilosc obecnie stworzonych.
    */
    void informacje();
};

template <int SIZE>
int Vector<SIZE>::wszystkie = 0;

template <int SIZE>
int Vector<SIZE>::aktualne = 0;

template <int SIZE>
void Vector<SIZE>::informacje()
{
    cout << "akturalne obiekty: " << aktualne << endl;
    cout << "wszystkie obiekty: " << wszystkie << endl;
}

template <int SIZE>
Vector<SIZE>::Vector()
{
    for (int i = 0; i < SIZE; i++)
        _wsp[i] = 0;
    aktualne++;
    wszystkie++;
}

template <int SIZE>
Vector<SIZE>::Vector(double _wsp[SIZE])
{
    for (int i = 0; i < SIZE; i++)
        this->_wsp[i] = _wsp[i];
    aktualne++;
    wszystkie++;
}

template <int SIZE>
Vector<SIZE>::~Vector()
{
    aktualne--;
}

template <int SIZE>
double Vector<SIZE>::operator[](int index) const
{
    if (index > SIZE || index < 0)
    {
        std::cerr << "Indeks poza skala" << std::endl;
        exit(1);
    }
    return _wsp[index];
}

template <int SIZE>
double &Vector<SIZE>::operator[](int index)
{
    if (index > SIZE || index < 0)
    {
        std::cerr << "Indeks poza skala" << std::endl;
        exit(1);
    }
    return _wsp[index];
}

template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator+(Vector<SIZE> &arg)
{
    Vector<SIZE> Wynik;
    for (int i = 0; i < SIZE; i++)
    {
        Wynik[i] = _wsp[i] + arg[i];
    }
    return Wynik;
}

template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator-(Vector<SIZE> &arg)
{
    Vector<SIZE> Wynik;
    for (int i = 0; i < SIZE; i++)
    {
        Wynik[i] = _wsp[i] - arg[i];
    }
    return Wynik;
}

template <int SIZE>
std::istream &operator>>(std::istream &Strm, Vector<SIZE> &Wek)
{
    for (int i = 0; i < SIZE; i++)
    {
        Strm >> Wek[i];
    }
    return Strm;
    return Strm;
}

template <int SIZE>
inline std::ostream &operator<<(std::ostream &Strm, const Vector<SIZE> &Wek)
{
    for (int i = 0; i < SIZE; i++)
    {
        Strm << Wek[i] << " ";
    }
    return Strm;
}

#endif