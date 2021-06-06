// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "exampleConfig.h"
#include "example.h"
#include "Scena.hh"
#include "../include/lacze_do_gnuplota.hh"

int main()
{
     PzG::LaczeDoGNUPlota Lacze;
     Lacze.ZmienTrybRys(PzG::TR_3D);
     std::cout << "Project Rotation 2D based on C++ Boiler Plate v"
               << PROJECT_VERSION_MAJOR /*duże zmiany, najczęściej brak kompatybilności wstecz */
               << "."
               << PROJECT_VERSION_MINOR /* istotne zmiany */
               << "."
               << PROJECT_VERSION_PATCH /* naprawianie bugów */
               << "."
               << PROJECT_VERSION_TWEAK /* zmiany estetyczne itd. */
               << std::endl;
     Vector3D wek;
     Scena s;

     char opcja;

     std::cout << "a - wybierz aktywnego drona" << std::endl;
     std::cout << "p - zadaj parametry przelotu" << std::endl;
     std::cout << "m - wyswietl menu" << std::endl
               << std::endl;
     std::cout << "k - koniec dzialania programu" << std::endl;
     std::cout << std::endl;
     wek.informacje();

     do
     {
          std::cout << std::endl;
          std::cout << "Twoj wybor, m - menu> ";
          std::cin >> opcja;
          switch (opcja)
          {
          case 'a':
               s.Interfejs();
               break;
          case 'p':
               s.RuchDronem();
               break;
          case 'm':
               std::cout << "a - wybierz aktywnego drona" << std::endl;
               std::cout << "p - zadaj parametry przelotu" << std::endl;
               std::cout << "m - wyswietl menu" << std::endl
                         << std::endl;
               std::cout << "k - koniec dzialania programu" << std::endl;
               std::cout << std::endl;
               break;
          default:
               break;
          }
     } while (opcja != 'k');

     Dummy d = Dummy();
     return d.doSomething() ? 0 : -1;
}
