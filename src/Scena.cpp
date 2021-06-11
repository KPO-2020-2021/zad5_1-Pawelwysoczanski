#include "Scena.hh"

/*!
*\brief 
* Tworzy scene po ktorej poruszac sie beda drony.
*/
Scena::Scena()
{

  Lacze.ZmienTrybRys(PzG::TR_3D);

  Lacze.UstawZakresY(-300, 300);
  Lacze.UstawZakresX(-300, 300);
  Lacze.UstawZakresZ(-300, 300);

  double tab_wym[3] = {600, 600, 0};
  Vector3D wym_dna(tab_wym);
  dno = new Plaszczyzna(wym_dna, 20);
  Lacze.DodajNazwePliku(dno->GetNazwa().c_str(), PzG::RR_Ciagly, 2);
  dno->zapisz();
  for (int i = 0; i < N; i++)
  {
    double pozycja[3] = {(double)(rand() % 440 - 220), (double)(rand() % 440 - 220), 25};
    TabDronow[i] = new Dron(i, Lacze, Vector3D(pozycja));
    TabDronow[i]->Zapisz();
  }

  Lacze.Rysuj();
}
/*!
*\brief 
*Rysuje Scene 
*/
void Scena::Rysuj()
{

  Lacze.Rysuj();
}
/*!
*\brief 
* Metoda powoduje przejscie do sterowania dronem ktorego numer zostal podany metodzie Interfejs() 
*/
void Scena::RuchDronem()
{
  int nr; /*nr drona*/
  nr = this->nrDrona;
  if ((nr - 1) == 0)
  {
    TabDronow[0]->Sterowanie();
  }
  if ((nr - 1) == 1)
  {
    TabDronow[1]->Sterowanie();
  }
}
/*!
*\brief 
* Wykonuje przelot drona nr 2 po okregu.
*/
void Scena::RuchDronemMod()
{
  TabDronow[1]->Modyfikacja();
}
/*!
*\brief 
* Umozliwia wybor drona.
*/
bool Scena::Interfejs()
{
  cout << "Wybor aktywnego drona" << endl;
  int nr;
  cin >> nr;
  this->nrDrona = nr;
  if (nr < 3)
  {
    if (nr == 1)
    {
      cout << "1 - Polozenie <-- Dron aktywny" << endl;
      cout << "2 - Polozenie " << endl;
    }
    if (nr == 2)
    {
      cout << "1 - Polozenie " << endl;
      cout << "2 - Polozenie <-- Dron aktywny" << endl;
    }
  }
  else
  {
    return false;
  }
  return true;
}
/*!
*\brief 
* Usuwa tablice dronow.
*/
Scena::~Scena()
{
  delete dno;
  for (int i = 0; i < N; i++)
    delete TabDronow[i];
}