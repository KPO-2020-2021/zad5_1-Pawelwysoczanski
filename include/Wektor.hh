#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <cmath>
using namespace std;

template <int SIZE>
class Vector
{
    static int wszystkie;
    static int aktualne;
    double _wsp[SIZE];

public:
    Vector();
    Vector(Vector<SIZE> &wek)
    {
        for (int i = 0; i < SIZE; i++)
            _wsp[i] = wek._wsp[i];

        aktualne++;
    }
    constexpr Vector(const Vector &other)
    {
        for (int i = 0; i < SIZE; i++)
            _wsp[i] = other._wsp[i];
        aktualne++;
    }
    Vector &operator=(const Vector &other)
    {
        for (int i = 0; i < SIZE; i++)
            _wsp[i] = other._wsp[i];
        return *this;
    }

    Vector &operator=(const float &other)
    {
        for (int i = 0; i < SIZE; i++)
            _wsp[i] = other;
        return *this;
    }
    ~Vector();
    Vector(double _wsp[SIZE]);
    double operator[](int index) const;
    double &operator[](int index);
    Vector<SIZE> operator+(Vector<SIZE> &arg);
    Vector<SIZE> operator-(Vector<SIZE> &arg);
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