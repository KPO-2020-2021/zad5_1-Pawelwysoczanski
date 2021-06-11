#ifndef MACIERZ3X3_HH
#define MACIERZ3X3_HH


#include <iostream>
#include "Macierz.hh"

/*!
 * \file
 * \brief Macierz3x3.
 */

/*!
 * \brief Klasa Macierz3x3 ma być instancją szablonu Macierz<>
 *
 *  Tutaj trzeba opisac instancję szablonu. Jakie pojecie ona modeluje 
 *  i jakie ma glowne cechy.
 */
typedef Matrix<3>  Macierz3x3;

/*!
 * \brief Tworzy macierz rotacji wokol osi x.
 */
Macierz3x3 mac_obr_x(double kat);
/*!
 * \brief Tworzy macierz rotacji wokol osi y.
 */
Macierz3x3 mac_obr_y(double kat);
/*!
 * \brief Tworzy macierz rotacji wokol osi z.
 */
Macierz3x3 mac_obr_z(double kat);

#endif
