#include "Prostopadloscian.hh"
#include "Wektor3D.hh"
#include "Wektor.hh"

#define SIZE 3
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Prostopadloscian, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
/******************************************************************************
 |  Realizuje porownanie dwoch prostopadloscianow.                            |
 |  Argumenty:                                                                |
 |      this - czyli pierwszy skladnik porownania,                            |
 |      cu - czyli drugi skladnik porownania.                                 |
 |  Zwraca:                                                                   |
 |      TRUE lub FALSE.                                                       |
 */
bool Cuboid::operator!=(const Cuboid &cu) const
{
    return !(*this == cu);
}
/******************************************************************************
 |  Realizuje porownanie dwoch prostopadloscianow.                            |
 |  Argumenty:                                                                |
 |      this - czyli pierwszy skladnik porownania,                            |
 |      cu -  czyli drugi skladnik porownania.                                |
 |  Zwraca:                                                                   |
 |      TRUE lub FALSE.                                                       |
 */
bool Cuboid::operator==(const Cuboid &cu) const
{
    bool wynik = true;
    for (int i = 0; i < SIZE_VERTEX; i++)
    {
        if ((cuboid[i] != cu.cuboid[i]))
            wynik = false;
    }
    return wynik;
}
/******************************************************************************
 |  Realizuje prownanie przeciwleglych bokow prostopadloscianu                |
 |  Argumenty:                                                                |
 |      brak                                                                  |
 |  Zwraca:                                                                   |
 |      Komunikat jesli dlugosci bokow sa identyczne lub sie roznia           |
 */
void Cuboid::length()
{
    /*Dluzsze przeciwlegle boki*/
    double side1 = cuboid[0].length(cuboid[2]);
    double side2 = cuboid[1].length(cuboid[3]);
    double side3 = cuboid[4].length(cuboid[6]);
    double side4 = cuboid[5].length(cuboid[7]);

    /*Krotsze przeciwlegle boki*/
    double side5 = cuboid[0].length(cuboid[1]);
    double side6 = cuboid[2].length(cuboid[3]);
    double side7 = cuboid[4].length(cuboid[5]);
    double side8 = cuboid[6].length(cuboid[7]);

    /*Poprzeczne przeciwlegle boki*/
    double side9 = cuboid[0].length(cuboid[6]);
    double side10 = cuboid[1].length(cuboid[7]);
    double side11 = cuboid[2].length(cuboid[4]);
    double side12 = cuboid[3].length(cuboid[5]);

    if ((side1 == side2) && (side3 == side4) && (side1 == side3) && (side2 == side4))
    {
        std::cout << ":) Dluzsze przeciwlegle boki sa sobie rowne." << std::endl
                  << "    Dlugosc pierwszego boku: " << side1 << std::endl
                  << "      Dlugosc drugiego boku: " << side2 << std::endl
                  << "    Dlugosc trzeciego boku: " << side3 << std::endl
                  << "      Dlugosc czwartego boku: " << side4 << std::endl;
        std::cout << std::endl;
    }
    else if ((side1 != side2) || (side3 != side4) || (side1 != side3) || (side2 != side4))
    {
        std::cout << ":o Dluzsze przeciwlegle boki nie sa sobie rowne!!!" << std::endl
                  << "    Dlugosc pierwszego boku: " << side1 << std::endl
                  << "      Dlugosc drugiego boku: " << side2 << std::endl
                  << "    Dlugosc trzeciego boku: " << side3 << std::endl
                  << "      Dlugosc czwartego boku: " << side4 << std::endl;
        std::cout << std::endl;
    }

    if ((side5 == side6) && (side7 == side8) && (side5 == side7) && (side6 == side8))
    {
        std::cout << ":) Krotsze przeciwlegle boki sa sobie rowne." << std::endl
                  << "    Dlugosc pierwszego boku: " << side5 << std::endl
                  << "      Dlugosc drugiego boku: " << side6 << std::endl
                  << "    Dlugosc trzeciego boku: " << side7 << std::endl
                  << "      Dlugosc czwartego boku: " << side8 << std::endl;
        std::cout << std::endl;
    }
    else if ((side5 != side6) || (side7 != side8) || (side5 != side7) || (side6 != side8))
    {
        std::cout << ":o Krotsze przeciwlegle boki nie sa sobie rowne!!!" << std::endl
                  << "    Dlugosc pierwszego boku: " << side5 << std::endl
                  << "      Dlugosc drugiego boku: " << side6 << std::endl
                  << "    Dlugosc trzeciego boku: " << side7 << std::endl
                  << "      Dlugosc czwartego boku: " << side8 << std::endl;
        std::cout << std::endl;
    }

    if ((side9 == side10) && (side11 == side12) && (side9 == side11) && (side10 == side12))
    {
        std::cout << ":) Poprzecze przeciwlegle boki sa sobie rowne." << std::endl
                  << "    Dlugosc pierwszego boku: " << side9 << std::endl
                  << "      Dlugosc drugiego boku: " << side10 << std::endl
                  << "    Dlugosc trzeciego boku: " << side11 << std::endl
                  << "      Dlugosc czwartego boku: " << side12 << std::endl;
        std::cout << std::endl;
    }
    else if ((side9 != side10) || (side11 != side12) || (side9 != side11) || (side10 != side12))
    {
        std::cout << ":o Poprzeczne przeciwlegle boki nie sa sobie rowne!!!" << std::endl
                  << "    Dlugosc pierwszego boku: " << side9 << std::endl
                  << "      Dlugosc drugiego boku: " << side10 << std::endl
                  << "    Dlugosc trzeciego boku: " << side11 << std::endl
                  << "      Dlugosc czwartego boku: " << side12 << std::endl;
        std::cout << std::endl;
    }
}
/******************************************************************************
 |  Realizuje przesuniecie wierzcholkow prostopadloscianu o zadany wktor.     |
 |  Argumenty:                                                                |
 |      vector - wektora o jaki ma zostac przesuniety prostokat.              |
 |  Zwraca:                                                                   |
 |      Przesuniety prostopadloscian o zadany wektor                          |
 */
void Cuboid::translation(const Vector3D &vector)
{
    *this = *this + vector;
}
Cuboid::Cuboid()
{
    for (int i = 0; i < SIZE_VERTEX; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cuboid[i][j] = 0;
        }
    }
}
/******************************************************************************
 |  Konstruktor klasy Cuboid                                                  |
 |  Argumenty:                                                                |
 |      vector - wektora o jaki ma zostac przesuniety prostokat.              |
 |      height - zmiana polozenia wierzcholka prostopadloscianu w osi z.      |
 |      width - zmiana polozenia wierzcholka prostopadloscianu w osi y.       |
 |      lenght - zmiana polozenia wierzcholka prostopadloscianu w osi x.      |
 |  Zwraca:                                                                   |
 |      Przesuniete wierzcholki prostopadloscianu o podany w argumencie wektor|
 */
Cuboid::Cuboid(const Vector3D &vector, double height, double width, double lenght)
{
    for (int i = 0; i < SIZE_VERTEX; i++)
        cuboid[i] = vector;

    cuboid[0][1] += width;

    cuboid[2][1] += width;
    cuboid[2][0] += lenght;

    cuboid[3][0] += lenght;

    cuboid[4][0] += lenght;
    cuboid[4][1] += width;
    cuboid[4][2] += height;

    cuboid[5][0] += lenght;
    cuboid[5][2] += height;

    cuboid[6][1] += width;
    cuboid[6][2] += height;

    cuboid[7][2] += height;
}
/******************************************************************************
 |  Realizuje dodawanie wektora do wspolrzednych prostopadloscianu.           |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
Cuboid Cuboid::operator+(const Vector3D &vector)
{
    Cuboid result;
    for (int i = 0; i < SIZE_VERTEX; i++)
    {
        result[i] = cuboid[i] + vector;
    }
    return result;
}
/******************************************************************************
 |  Realizuje odejmowanie wektora od wspolrzednych prostopadloscianu.         |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
Cuboid Cuboid::operator-(const Vector3D &vector)
{
    Cuboid result;
    for (int i = 0; i < SIZE_VERTEX; i++)
    {
        result[i] = cuboid[i] - vector;
    }
    return result;
}
/******************************************************************************
 |  Funktor prostopadloscianu.                                                |
 |  Argumenty:                                                                |
 |      index - index prostopadloscianu.                                      |
 |  Zwraca:                                                                   |
 |      Wartosc prostopadloscianu w danym miejscu tablicy jako stala.         |
 */
const Vector3D &Cuboid::operator[](int index) const
{
    if (index < 0 || index >= SIZE_VERTEX)
    {
        throw "Error: Prostokat jest poza zasiegiem!";
    } // lepiej byłoby rzucić wyjątkiem stdexcept
    return cuboid[index];
}
/******************************************************************************
 |  Funktor prostopadloscianu.                                                |
 |  Argumenty:                                                                |
 |      index - index prostopadloscianu.                                      |
 |  Zwraca:                                                                   |
 |      Wartosc prostopadloscianu w danym miejscu tablicy jako zmienna.       |
 */
Vector3D &Cuboid::operator[](int index)
{
    if (index < 0 || index >= SIZE_VERTEX)
    {
        throw "Error: Prostokat jest poza zasiegiem!";
    } // lepiej byłoby rzucić wyjątkiem stdexcept
    return cuboid[index];
}
/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wyjsciowy,                                             |
 |      tmp - prostokąt.                                                      |
 */
std::ostream &operator<<(std::ostream &out, Cuboid const &tmp)
{
    for (int i = 0; i < SIZE_VERTEX; ++i)
    {
        out << tmp[i] << std::endl;
    }
    return out;
}
