#include <iostream>
using namespace std;

/* ::NAPOMENA::
Radi jednostavnije izrade i lakseg testiranja zadataka, komentirajte testni dio koda, koji je obuhvacen funkcijama sa prefixom 'Zadatak'.
Kako budete implementirali odredjene funkcionalnosti, tada lagano pocnite sa 'otkrivanjem' komentiranih dijelova koda.
*/

//Z0.1
char* AlocirajIKopiraj(const char* tekst)
{
        if (tekst == nullptr)
            return nullptr;
        int vel = strlen(tekst) + 1;
        char* novi = new char[vel];
        strcpy_s(novi, vel, tekst);
        return novi;
}

struct Datum
{
    int* _dan = nullptr;
    int* _mjesec = nullptr;
    int* _godina = nullptr;
    //Z1.1
    void postaviDatum(int d, int m, int g)
    {
        SetDan(d);
        SetMjesec(m);
        SetGodina(g);
    }
    void Unos(int d, int m, int g) //
    {
        /*
        * _dan = new int;
        * _mjesec = new int;
        * -godina = new int;
        * *_dan = d;
        * *_mjesec = m;
        * *_godina = g;
        */
        postaviDatum(d, m, g);

    }
    //Z1.2
    void Unos(Datum& datum)
    {
        _dan = new int;
        _mjesec = new int;
        _godina = new int;
        *_dan = *datum._dan;
        *_mjesec = *datum._mjesec;
        *_godina = *datum._godina;
    }
    //Z1.3
    void Unos(Datum* datum)
    {
        _dan = new int;
        _mjesec = new int;
        _godina = new int;
        *_dan = *datum->_dan;
        *_mjesec = *datum->_mjesec;
        *_godina = *datum->_godina;

    }
    //Z1.4
    int GetDan()
    {
        if (_dan == nullptr)
            return -1;
        return *_dan;
      
    }
    int GetMjesec()
    {
        if (_mjesec == nullptr)
            return -1;
        return *_mjesec;
    }
    int GetGodina()
    {
        if (_godina == nullptr)
            return -1;
        return *_godina;
    }
    //Z1.5
    void SetDan(int dan)
    {
        if (_dan == nullptr)
            _dan = new int;
        *_dan = dan;

    }
    //Z1.6
    void SetMjesec(int mjesec)
    {
        if (_mjesec == nullptr)
            _mjesec = new int;
        *_mjesec = mjesec;
    }
    //Z1.7
    void SetGodina(int godina)
    {
        if (_godina == nullptr)
            _godina = new int;
         *_godina = godina;
    }
    //Z1.8
    void Ispis()
    {
        cout << *_dan << "." << *_mjesec << "." << *_godina;
    }
    //Z1.9
    void Dealokacija()
    {
        delete _dan;
        _dan = nullptr;
        delete _mjesec;
        _mjesec = nullptr;
        delete _godina;
        _godina = nullptr;
    }
};
//Z1.10
bool JeLiIsti(Datum& d1, Datum& d2)
{
    return d1.GetDan() == d2.GetDan() &&
        d1.GetMjesec() == d2.GetMjesec() &&
         d1.GetGodina() == d2.GetGodina();
}
//Z1.11
Datum& GetStarijiDatum(Datum& d1, Datum& d2)
{
    if (d1.GetGodina() < d2.GetGodina())
        return d1;
    else if (d1.GetGodina() == d2.GetGodina())
    {
        if (d1.GetMjesec() < d2.GetMjesec())
            return d1;
        else if (d1.GetMjesec() == d2.GetMjesec())
        {
            if (d1.GetDan() < d1.GetDan())
                return d1;
            return d2;
        }
        return d2;
    }   
    return d2;
}

//Z1.12
Datum& GetNovijiDatum(Datum& d1, Datum& d2)
{
    if (JeLiIsti(GetStarijiDatum(d1, d2), d1))
        return d2;
    return d1;
}
//Z1.13
Datum* GetNajstarijiDatum(Datum datum[], int size)
{
    Datum* najstariji = &datum[0];
    for (int i = 0; i < size; i++)
        najstariji = &GetStarijiDatum(*najstariji, datum[i]);
    return najstariji;
}

//Z1.14
Datum* GetNajnovijiDatum(Datum datum[], int size)
{
    Datum* najnoviji = &datum[0];
    for (int i = 0; i < size; i++)
        najnoviji = &GetNovijiDatum(*najnoviji, datum[i]);
    return najnoviji;
}

//struct Glumac {
//    char _jmbg[14] = "";
//    char* _ime = nullptr;
//    char* _prezime = nullptr;
//    Datum* _datumRodjenja = nullptr;
//    char* _mjestoRodjenja = nullptr;
//    char _drzava[100];
//    bool _spol; //1:Muski, 0:Zenski
//    //Z2.1
//    void Unos(const char* jmbg, const char* ime, const char* prezime, Datum& datumRodjenja, const char* mjestoRodjenja, const char* drzava, bool spol);
//    //Z2.2
//    void Unos(Glumac& glumac);
//    //Z2.3
//    void SetJmbg(const char* jmbg);
//    //Z2.4
//    void SetIme(const char* ime);
//    //Z2.5
//    void SetPrezime(const char* prezime);
//    //Z2.6
//    void SetDatumRodjenja(Datum& datumRodjenja);
//    //Z2.7
//    void SetMjestoRodjenja(const char* mjestoRodjenja);
//    //Z2.8
//    void SetDrzava(const char* drzava);
//    //Z2.9
//    void SetSpol(bool spol);
//    //Z2.10
//    void Ispis();
//    //Z2.11
//    void Dealokacija();
//};
//
//struct Film {
//    char _filmID[50] = ""; //prema ISAN standardu
//    char* _naziv = nullptr;
//    char _zanr[40];
//    int _godinaIzlaska;
//    int _trenutnoGlumaca = 0;
//    Glumac _glumackaPostava[20];
//    int _trenutnoOcjena = 0;
//    int* _ocjene = nullptr; //Dinamicki prosirivati ovaj niz svakim novim dodavanjem
//    //Z3.1
//    void Unos(const char* filmID, const char* naziv, const char* zanr, int godinaIzlaska);
//    //Z3.2
//    void Unos(Film& film);
//    //Z3.3
//    bool DodajGlumca(Glumac& g);
//    //Z3.4
//    bool DodajOcjenu(int ocjena);
//    //Z3.5
//    void Ispis();
//    //Z3.6
//    float GetProsjecnaOcjena();
//    //Z3.7
//    void Dealokacija();
//};

void Zadatak1() {
    cout << ":Zadatak 1:" << endl;
    Datum prviMart, danNezavisnosti, danDrzavnosti;
    prviMart.Unos(1, 3, 2021);
    danNezavisnosti.Unos(prviMart);
    danDrzavnosti.Unos(&prviMart);
    danDrzavnosti.SetDan(25);
    danDrzavnosti.SetMjesec(11);
    danDrzavnosti.SetGodina(2021);

    cout << "Dan nezavisnosti: " << endl;
    danNezavisnosti.Ispis();
    cout << endl << "Dan drzavnosti: " << endl;
    danDrzavnosti.Ispis();
    prviMart.Dealokacija();
    danNezavisnosti.Dealokacija();
    danDrzavnosti.Dealokacija();

    Datum danD, operacijaBarbarossa, sarajevskiAtentat, apolloSlijetanje, blackThursday;
    danD.Unos(6, 6, 1944);
    operacijaBarbarossa.Unos(22, 6, 1941);
    sarajevskiAtentat.Unos(28, 6, 1914);
    apolloSlijetanje.Unos(24, 7, 1969);
    blackThursday.Unos(24, 10, 1929);

    Datum historijskiDogadjaji[5];
    historijskiDogadjaji[0].Unos(danD);
    historijskiDogadjaji[1].Unos(operacijaBarbarossa);
    historijskiDogadjaji[2].Unos(sarajevskiAtentat);
    historijskiDogadjaji[3].Unos(apolloSlijetanje);
    historijskiDogadjaji[4].Unos(blackThursday);

    cout << endl << "Najstariji datum: " << endl;
    GetNajstarijiDatum(historijskiDogadjaji, 5)->Ispis();
    cout << endl << "Najnoviji datum: " << endl;
    GetNajnovijiDatum(historijskiDogadjaji, 5)->Ispis();

    //DEALOKACIJE
    danD.Dealokacija();
    operacijaBarbarossa.Dealokacija();
    sarajevskiAtentat.Dealokacija();
    apolloSlijetanje.Dealokacija();
    blackThursday.Dealokacija();
    for (size_t i = 0; i < 5; i++)
        historijskiDogadjaji[i].Dealokacija();
    cout << endl << "Dealokacija uspjesna!" << endl;
}
//
//void Zadatak2() {
//    cout << ":Zadatak 2:" << endl;
//
//    Glumac alPacino, deNiro;
//    Datum temp1, temp2;
//    temp1.Unos(25, 4, 1940);
//    temp2.Unos(17, 8, 1943);
//    alPacino.Unos("1304996055555", "Alfredo", "Pacino", temp1, "Manhattan, NYC", "SAD", 1);
//    deNiro.Unos(alPacino);
//    deNiro.SetIme("Robert");
//    deNiro.SetPrezime("De Niro");
//    deNiro.SetDatumRodjenja(temp2);
//    deNiro.SetMjestoRodjenja("Greenwich Village");
//    deNiro.SetDrzava("SAD");
//    deNiro.SetSpol(1);
//
//    Datum datumi[5];
//    datumi[0].Unos(7, 6, 1995);
//    datumi[1].Unos(7, 11, 1991);
//    datumi[2].Unos(3, 6, 1995);
//    datumi[3].Unos(5, 6, 1992);
//    datumi[4].Unos(1, 6, 1993);
//    Glumac glumciNarodnogPozorista[5];
//    glumciNarodnogPozorista[0].Unos("0706995088888", "Barb", "Dwyer", datumi[0], "Mostar", "BiH", 1);
//    glumciNarodnogPozorista[1].Unos("0711991144488", "Anna", "Graham", datumi[1], "Ostrozac", "BiH", 0);
//    glumciNarodnogPozorista[2].Unos("0306995099999", "Benjamin", "Button", datumi[2], "Sarajevo", "BiH", 1);
//    glumciNarodnogPozorista[3].Unos("0506992011993", "Jack", "Pott", datumi[3], "Vogosca", "BiH", 1);
//    glumciNarodnogPozorista[4].Unos("0106993094444", "Justin", "Case", datumi[4], "Kotor-Varos", "BiH", 1);
//
//    cout << "Ispis svih glumaca:: " << endl;
//    for (size_t i = 0; i < 5; i++) {
//        cout << "-----------------------------------------------" << endl;
//        glumciNarodnogPozorista[i].Ispis();
//    }
//    cout << "-----------------------------------------------" << endl;
//    cout << endl;
//
//    //DEALOKACIJE
//    temp1.Dealokacija();
//    temp2.Dealokacija();
//    alPacino.Dealokacija();
//    deNiro.Dealokacija();
//    for (size_t i = 0; i < 5; i++) {
//        datumi[i].Dealokacija();
//        glumciNarodnogPozorista[i].Dealokacija();
//    }
//    cout << "Dealokacija uspjesna!" << endl;
//}
//
//void Zadatak3() {
//    Datum temp1, temp2;
//    temp1.Unos(25, 4, 1940);
//    temp2.Unos(17, 8, 1943);
//    Glumac alPacino, deNiro;
//    alPacino.Unos("2504940555551", "Alfredo", "Pacino", temp1, "Manhattan, NYC", "SAD", 1);
//    deNiro.Unos("1708943055555", "Robert", "De Niro", temp2, "NYC", "SAD", 1);
//
//    Film irishman;
//    irishman.Unos("XXXX-AAAA-BBBB-CCCC", "The Irishman", "Biografija, krimi, drama", 2019);
//    irishman.DodajGlumca(alPacino);
//    irishman.DodajGlumca(deNiro);
//    irishman.DodajOcjenu(10);
//    irishman.DodajOcjenu(8);
//    irishman.DodajOcjenu(9);
//    irishman.DodajOcjenu(8);
//    irishman.DodajOcjenu(8);
//    Film kopija;
//    kopija.Unos(irishman);
//    kopija.Ispis();
//    //DEALOKACIJE
//    irishman.Dealokacija();
//    kopija.Dealokacija();
//    alPacino.Dealokacija();
//    deNiro.Dealokacija();
//    temp1.Dealokacija();
//    temp2.Dealokacija();
//}
//
void Menu() {
    int nastaviDalje = 1;
    while (nastaviDalje == 1) {
        int izbor = 0;
        do {
            system("cls");
            cout << "::Zadaci::" << endl;
            cout << "(1) Zadatak 1" << endl;
            cout << "(2) Zadatak 2" << endl;
            cout << "(3) Zadatak 3" << endl;
            cout << "Unesite odgovarajuci broj zadatka za testiranje: -->: ";
            cin >> izbor;
            cout << endl;
        } while (izbor < 1 || izbor > 3);
        switch (izbor) {
        case 1: Zadatak1(); cout << "Done." << endl; break;
  /*      case 2: Zadatak2(); cout << "Done." << endl; break;
        case 3: Zadatak3(); cout << "Done." << endl; break;*/
        default:break;
        }
        do {
            cout << "DA LI ZELITE NASTAVITI DALJE? (1/0): ";
            cin >> nastaviDalje;
        } while (nastaviDalje != 0 && nastaviDalje != 1);
    }
}

int main() {
    Menu();
    return 0;
}

