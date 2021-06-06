#include "Scena.hh"

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
void Scena::Rysuj()
{

  Lacze.Rysuj();
}

void Scena::RuchDronem()
{
  int nr;
  nr = this->nrDrona;
  if (nr == 0)
  {
    TabDronow[0]->Sterowanie();
  }
  if (nr == 1)
  {
    TabDronow[1]->Sterowanie();
  }
}
bool Scena::Interfejs()
{
  cout << "Wybor aktywnego drona" << endl;
  int nr;
  cin >> nr;
  this->nrDrona = nr;
  if (nr < N)
  {
    if (nr == 0)
    {
      cout << "1 - Polozenie <-- Dron aktywny" << endl;
      cout << "2 - Polozenie " << endl;
    }
    if (nr == 1)
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

Scena::~Scena()
{
  delete dno;
  for (int i = 0; i < N; i++)
    delete TabDronow[i];
}