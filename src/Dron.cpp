
#include "Dron.hh"

/*!
*\brief Konstruktor parametryczny klasy dron.
*/
Dron::Dron(int id, PzG::LaczeDoGNUPlota &Lacze, Vector3D pozycja) : Lacze(Lacze)
{
    kat = 0;
    this->id = id;
    orginalny.SetNazwaPliku("../dat/korpus" + std::to_string(id) + ".dat");

    for (int i = 0; i < 4; i++)
        wir_o[i].SetNazwaPliku("../dat/wirnik" + std::to_string(i) + std::to_string(id) + ".dat");

    Lacze.DodajNazwePliku(orginalny.GetNazwaPliku().c_str(), PzG::RR_Ciagly, 2);
    for (int i = 0; i < 4; i++)
        Lacze.DodajNazwePliku(wir_o[i].GetNazwaPliku().c_str(), PzG::RR_Ciagly, 2);
    kopia = orginalny;

    kopia.Przesun(pozycja);
    for (int i = 0; i < 4; i++)
        wir_k[i] = wir_o[i];

    for (int i = 0; i < 4; i++)
        wir_k[i].Przesun(orginalny[i * 2] + pozycja);

    this->droga = this->droga + pozycja;
}
/*!
  *\brief Metoda ktora wykonuje operacje wznoszenia drona na wysokosc przelotu.
  */
void Dron::Wznoszenie(double droga)
{
    Vector3D droga_o;
    droga_o[2] = droga;

    this->droga = this->droga + droga_o;
    kopia.Translacja(obrot);
    kopia.Przesun(this->droga);
}
/*!
  *\brief Metoda ktora wykonuje operacje przesuniecia drona.
  */
void Dron::Przesun(double droga)
{
    Vector3D droga_o;
    droga_o[0] = droga * cos(kat * M_PI / 180);
    droga_o[1] = droga * sin(kat * M_PI / 180);
    this->droga = this->droga + droga_o;
    kopia.Translacja(obrot);
    kopia.Przesun(this->droga);
}
/*!
  *\brief Metoda ktora wykonuje operacje obrotu drona.
  */
void Dron::Obrot(double kat)
{
    this->kat += kat;
    Macierz3x3 nowa;
    obrot = nowa * mac_obr_z(this->kat);
    kopia.Translacja(obrot);
    kopia.Przesun(this->droga);
}
/*!
  *\brief Metoda ktora wykonuje operacje obrotow rotorow drona.
  */
void Dron::ObrotRotrow()
{
    static int kat = 0;
    kat += 3;
    if (kat == 360)
        kat = 0;

    Macierz3x3 nowa;
    nowa = nowa * mac_obr_z(kat);
    for (int i = 0; i < 4; i++)
    {
        wir_k[i].Translacja(nowa);
    }

    for (int i = 0; i < 4; i++)
    {
        wir_k[i].Przesun(kopia[i * 2]);
    }
}
/*!
  *\brief Metoda ktora wykonuje operacje zapisu drona do pliku.
  */
void Dron::Zapisz()
{
    kopia.Zapisz();
    for (int i = 0; i < 4; i++)
        wir_k[i].Zapisz();
}
/*!
  *\brief Metoda ktora wykonuje operacje sterowania dronem.
  */
void Dron::Sterowanie()
{
    double droga;
    double kat;

    Zapisz();
    cout << "Podaj kierunek lotu(kat w stopniach)>";
    cin >> kat;
    cout << "Podaj dlugosc lotu>";
    cin >> droga;
    RysujDroge(droga, kat);
    usleep(CZAS);
    Lacze.DodajNazwePliku("../dat/trasa.dat", PzG::RR_Ciagly, 2);
    cout << "Realizacja przelotu..." << endl;
    cout << "Wznoszenie.." << endl;
    for (int i = 0; i < 100; i++)
    {
        kopia = orginalny;
        for (int j = 0; j < 4; j++)
            wir_k[j] = wir_o[j];
        Wznoszenie(1);
        ObrotRotrow();
        Zapisz();
        Lacze.Rysuj();
        usleep(CZAS);
    }

    if (kat > 0)
    {
        cout << "Obrot.." << endl;
        for (int i = 0; i < kat; i++)
        {
            kopia = orginalny;
            for (int i = 0; i < 4; i++)
                wir_k[i] = wir_o[i];
            Obrot(1);
            ObrotRotrow();
            Zapisz();
            Lacze.Rysuj();
            usleep(CZAS);
        }
    }
    else
    {
        cout << "Obrot.." << endl;
        for (int i = 0; i > kat; i--)
        {
            kopia = orginalny;
            Obrot(-1);
            ObrotRotrow();
            Zapisz();
            Lacze.Rysuj();
            usleep(CZAS);
        }
    }
    cout << "Przelot" << endl;
    for (int i = 0; i < droga; i++)
    {
        kopia = orginalny;
        for (int j = 0; j < 4; j++)
            wir_k[j] = wir_o[j];
        Przesun(1);
        ObrotRotrow();
        Zapisz();
        Lacze.Rysuj();
        usleep(CZAS);
    }
    cout << "Opadanie" << endl;
    for (int i = 0; i < 100; i++)
    {
        kopia = orginalny;
        for (int j = 0; j < 4; j++)
            wir_k[j] = wir_o[j];
        Wznoszenie(-1);
        ObrotRotrow();
        Zapisz();
        Lacze.Rysuj();
        usleep(CZAS);
    }
    Lacze.UsunOstatniaNazwe();
    Lacze.Rysuj();
}
/*!
  *\brief Metoda ktora wykonuje operacje rysowania trasy przelotu drona.   
  */
void Dron::RysujDroge(double droga, double kat)
{
    Vector3D nastepny = kopia.GetSrodekBryly();
    nastepny[2] = 0;
    trasa.push_back(nastepny);
    nastepny[2] = 100;
    trasa.push_back(nastepny);
    nastepny[0] = nastepny[0] + droga * cos(kat * M_PI / 180);
    nastepny[1] = nastepny[1] + droga * sin(kat * M_PI / 180);
    trasa.push_back(nastepny);
    nastepny[2] = 0;
    trasa.push_back(nastepny);

    std::fstream plik;

    plik.open("../dat/trasa.dat", std::ios::out);
    for (int i = 0; i < (int)trasa.size(); i++)
    {
        plik << trasa[i] << std::endl;
    }
    plik.close();
}

void Dron::Modyfikacja()
{
    double droga = 100;
    double kat = 45;

    cout << "Przelot do miejsca rozpoczecia zataczania okregu" << endl;
    for (int i = 0; i < 100; i++)
    {
        kopia = orginalny;
        for (int j = 0; j < 4; j++)
            wir_k[j] = wir_o[j];
        Wznoszenie(1);
        ObrotRotrow();
        Zapisz();
        Lacze.Rysuj();
        usleep(1000);
    }
    cout << "Obrot.." << endl;
    for (int i = 0; i < kat; i++)
    {
        kopia = orginalny;
        for (int i = 0; i < 4; i++)
            wir_k[i] = wir_o[i];
        Obrot(1);
        ObrotRotrow();
        Zapisz();
        Lacze.Rysuj();
        usleep(1000);
    }
    cout << "Przelot" << endl;
    for (int i = 0; i < 200; i++)
    {
        kopia = orginalny;
        for (int j = 0; j < 4; j++)
            wir_k[j] = wir_o[j];
        Przesun(1);
        ObrotRotrow();
        Zapisz();
        Lacze.Rysuj();
        usleep(1000);
    }
    cout << "Opadanie" << endl;
    for (int i = 0; i < 100; i++)
    {
        kopia = orginalny;
        for (int j = 0; j < 4; j++)
            wir_k[j] = wir_o[j];
        Wznoszenie(-1);
        ObrotRotrow();
        Zapisz();
        Lacze.Rysuj();
        usleep(1000);
    }
    Lacze.DodajNazwePliku("../dat/trasa.dat", PzG::RR_Ciagly, 2);
    cout << "Rozpoczecie zataczania okregu" << endl;
    RysujDroge(100, 90);
    for (int i = 0; i < 100; i++)
    {
        kopia = orginalny;
        for (int j = 0; j < 4; j++)
            wir_k[j] = wir_o[j];
        Wznoszenie(1);
        ObrotRotrow();
        Zapisz();
        Lacze.Rysuj();
        usleep(1000);
    }
    cout << "Obrot.." << endl;
    for (int i = 0; i < kat; i++)
    {
        kopia = orginalny;
        for (int i = 0; i < 4; i++)
            wir_k[i] = wir_o[i];
        Obrot(1);
        ObrotRotrow();
        Zapisz();
        Lacze.Rysuj();
        usleep(1000);
    }
  //  RysujDroge(droga, kat);
    for (int i = 0; i < droga; i++)
    {
        kopia = orginalny;
        for (int j = 0; j < 4; j++)
            wir_k[j] = wir_o[j];
        Przesun(1);
        ObrotRotrow();
        Zapisz();
        Lacze.Rysuj();
        usleep(1000);
    }
    //RysujDroge(droga, kat);
    cout << "Wlasciwy punkt rozpoczecia" << endl;
    cout << "Obrot.." << endl;
    for (int i = 0; i < 90; i++)
    {
        kopia = orginalny;
        for (int i = 0; i < 4; i++)
            wir_k[i] = wir_o[i];
        Obrot(-1);
        ObrotRotrow();
        Zapisz();
        Lacze.Rysuj();
        usleep(1000);
    }
    for (int i = 0; i < droga; i++)
    {
        kopia = orginalny;
        for (int j = 0; j < 4; j++)
            wir_k[j] = wir_o[j];
        Przesun(1);
        ObrotRotrow();
        Zapisz();
        Lacze.Rysuj();
        usleep(1000);
    }
    for (int i = 0; i < 7; i++)
    {
      //  RysujDroge(droga, kat);

        cout << "Obrot.." << endl;
        for (int i = 0; i < kat; i++)
        {
            kopia = orginalny;
            for (int i = 0; i < 4; i++)
                wir_k[i] = wir_o[i];
            Obrot(-1);
            ObrotRotrow();
            Zapisz();
            Lacze.Rysuj();
            usleep(1000);
        }
        for (int i = 0; i < droga; i++)
        {
            kopia = orginalny;
            for (int j = 0; j < 4; j++)
                wir_k[j] = wir_o[j];
            Przesun(1);
            ObrotRotrow();
            Zapisz();
            Lacze.Rysuj();
            usleep(1000);
        }
    }
    cout << "Porot do pozycji" << endl;
    cout << "Obrot.." << endl;
    for (int i = 0; i < 135; i++)
    {
        kopia = orginalny;
        for (int i = 0; i < 4; i++)
            wir_k[i] = wir_o[i];
        Obrot(-1);
        ObrotRotrow();
        Zapisz();
        Lacze.Rysuj();
        usleep(1000);
    }
    for (int i = 0; i < droga; i++)
    {
        kopia = orginalny;
        for (int j = 0; j < 4; j++)
            wir_k[j] = wir_o[j];
        Przesun(1);
        ObrotRotrow();
        Zapisz();
        Lacze.Rysuj();
        usleep(1000);
    }
    for (int i = 0; i < 100; i++)
    {
        kopia = orginalny;
        for (int j = 0; j < 4; j++)
            wir_k[j] = wir_o[j];
        Wznoszenie(-1);
        ObrotRotrow();
        Zapisz();
        Lacze.Rysuj();
        usleep(1000);
    }
}
