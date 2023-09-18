#include <iostream>
using namespace std;

template<class T>
class Kolekcija {
public:
    T* elementi;
    int max;
    int trenutno;

    Kolekcija(int max = 5) {
        this->max = max;
        this->trenutno = 0;
        elementi = new T[max];
    }

    Kolekcija(Kolekcija& orig) {
        max = orig.max;
        trenutno = orig.trenutno;
        elementi = new T[max];
        for (int i = 0; i < trenutno; i++)
        {
            elementi[i] = orig.elementi[i];
        }
    }

    Kolekcija& operator=(Kolekcija& orig) {
        if (this != &orig) {
            delete[] elementi;
            this->max = orig.max;
            this->trenutno = orig.trenutno;
            elementi = new T[max];

            for (int i = 0; i < trenutno; i++)
            {
                elementi[i] = orig.elementi[i];
            }
            return *this;
        }
    }

    void operator+=(T novi) {
        if (trenutno >= max) {
            throw exception("Greska! Nije moguce dodati vise elemenata.");
        }

        for (int i = 0; i < trenutno; i++)
        {
            if (elementi[i] == novi) {
                throw exception("Greska! Element je vec dodat u kolkciju.");
            }
        }

        elementi[trenutno] = novi;
        trenutno++;
    }

    void operator-=(T el) {
        for (int i = 0; i < elementi; i++)
        {
            if (elementi[i] == el) {
                for (int j = 0; j < trenutno - 1; j++)
                {
                    elementi[j] = elementi[j + 1];
                }
                trenutno--;
                return;
            }
        }

        throw exception("Greska! Uklanjanje nije uspjesno. Element nije pronadjen.");
    }

    T& operator[] (T el) {
        for (int i = 0; i < trenutno; i++)
        {
            if (elementi[i] == el) {
                return elementi[i];
            }
        }

        throw exception("Greska! Element nije pronadjen. (operator [])");
    }

    T& operator[] (int pozicija) {
        if (pozicija < 0 || pozicija >= trenutno) {
            throw exception("Greska! Pozicija nije validna. (operator [])");
        }

        return elementi[pozicija];
    }

    friend ostream& operator<<(ostream& COUT, Kolekcija& k) {

        COUT << "::Elementi::" << endl;
        for (int i = 0; i < k.trenutno; i++)
        {
            COUT << k.elementi[i] << endl;
        }
        return COUT;
    }
};
ostream& operator<<(ostream& COUT, Kolekcija<class T>& k);

class Artikal
{
public:
    char* kod;
    char* naziv;
    float cijena;
    int kolicinaNaSkladistu;

    Artikal(
        const char kod[] = "---",
        const char naziv[] = "---",
        float cijena = 0,
        int kolicinaNaSkladistu = 0
    ) {
        int vel = strlen(kod) + 1;
        this->kod = new char[vel];
        strcpy_s(this->kod, vel, kod);

        vel = strlen(naziv) + 1;
        this->naziv = new char[vel];
        strcpy_s(this->naziv, vel, naziv);

        this->cijena = cijena;
        this->kolicinaNaSkladistu = kolicinaNaSkladistu;
    }

    Artikal(Artikal& orig) {
        int vel = strlen(orig.kod) + 1;
        this->kod = new char[vel];
        strcpy_s(this->kod, vel, orig.kod);

        vel = strlen(orig.naziv) + 1;
        this->naziv = new char[vel];
        strcpy_s(this->naziv, vel, orig.naziv);

        this->cijena = orig.cijena;
        this->kolicinaNaSkladistu = orig.kolicinaNaSkladistu;
    }

    ~Artikal() {
        delete[] kod, naziv;
        kod = nullptr;
        naziv = nullptr;
    }

    Artikal& operator=(Artikal& orig) {
        if (this != &orig) {
            delete[] kod, naziv;
            int vel = strlen(orig.kod) + 1;
            this->kod = new char[vel];
            strcpy_s(this->kod, vel, orig.kod);

            vel = strlen(orig.naziv) + 1;
            this->naziv = new char[vel];
            strcpy_s(this->naziv, vel, orig.naziv);

            this->cijena = orig.cijena;
            this->kolicinaNaSkladistu = orig.kolicinaNaSkladistu;
        }
        return *this;
    }

    bool operator == (Artikal& a) {
        return strcmp(kod, a.kod) == 0;
    }

    friend ostream& operator<<(ostream& COUT, Artikal a)
    {
        COUT << "Kod: " << a.kod << endl;
        COUT << "Naziv: " << a.naziv << endl;
        COUT << "Cijena: " << a.cijena << " KM" << endl;
        COUT << "Stanje na skladistu: " << a.kolicinaNaSkladistu << endl;
        return COUT;
    }

    friend istream& operator>>(istream& CIN, Artikal a)
    {
        char temp[100];
        cout << "Unesite kod: ";
        CIN.getline(temp, 100);
        int vel = strlen(temp) + 1;
        a.kod = new char[vel];
        strcpy_s(a.kod, vel, temp);

        cout << "Unesite naziv: ";
        CIN.getline(temp, 100);
        vel = strlen(temp) + 1;
        a.naziv = new char[vel];
        strcpy_s(a.naziv, vel, temp);

        cout << "Unesite cijenu: ";
        CIN >> a.cijena;

        cout << "Unesite stanje na skladistu: ";
        CIN >> a.kolicinaNaSkladistu;

        return CIN;
    }
};

class PrehrambeniArtikal : public Artikal
{
public:
    float gramaza;

    PrehrambeniArtikal(
        const char kod[] = "---",
        const char naziv[] = "---",
        float cijena = 0,
        int kolicinaNaSkladistu = 0,
        float gramaza = 0
    ) : Artikal(kod, naziv, cijena, kolicinaNaSkladistu) {
        this->gramaza = gramaza;
    }

    PrehrambeniArtikal(PrehrambeniArtikal& orig) : Artikal(orig) {
        this->gramaza = gramaza;
    }

    PrehrambeniArtikal& operator=(PrehrambeniArtikal& orig) {
        Artikal::operator=(orig);
        this->gramaza = gramaza;
        return *this;
    }


    friend ostream& operator<<(ostream& COUT, PrehrambeniArtikal& a) {
        COUT << (Artikal&)a << endl;
        COUT << "Grama: " << a.gramaza << endl;
        return COUT;
    }

    friend istream& operator>>(istream& CIN, PrehrambeniArtikal& a) {
        CIN >> (Artikal&)a;
        cout << "Unesite iznos grama: ";
        CIN >> a.gramaza;
        return CIN;
    }
};

ostream& operator<<(ostream& out, PrehrambeniArtikal& a);
istream& operator>>(istream& in, PrehrambeniArtikal& a);

class Odjeca : public Artikal
{
public:
    char* velicina; // xs, s, m, l, xl ...
    char* materijal;

    Odjeca(
        const char kod[] = "---",
        const char naziv[] = "---",
        float cijena = 0,
        int kolicinaNaSkladistu = 0,
        const char velicina[] = "---",
        const char materijal[] = "---"
    ) : Artikal(kod, naziv, cijena, kolicinaNaSkladistu) {
        int vel = strlen(velicina) + 1;
        this->velicina = new char[vel];
        strcpy_s(this->velicina, vel, velicina);

        vel = strlen(materijal) + 1;
        this->materijal = new char[vel];
        strcpy_s(this->materijal, vel, materijal);
    }

    Odjeca(Odjeca& orig) : Artikal(orig) {
        int vel = strlen(orig.velicina) + 1;
        this->velicina = new char[vel];
        strcpy_s(this->velicina, vel, orig.velicina);

        vel = strlen(orig.materijal) + 1;
        this->materijal = new char[vel];
        strcpy_s(this->materijal, vel, orig.materijal);
    }

    Odjeca& operator=(Odjeca& orig) {
        Artikal::operator=(orig);
        if (this != &orig) {
            delete[] materijal, velicina;

            int vel = strlen(orig.velicina) + 1;
            this->velicina = new char[vel];
            strcpy_s(this->velicina, vel, orig.velicina);

            vel = strlen(orig.materijal) + 1;
            this->materijal = new char[vel];
            strcpy_s(this->materijal, vel, orig.materijal);
        }
        return *this;
    }

    friend ostream& operator<<(ostream& COUT, Odjeca& a) {
        COUT << (Artikal&)a << endl;
        COUT << "Velicina: " << a.velicina << endl;
        COUT << "Materijal: " << a.materijal << endl;
        return COUT;
    }

    friend istream& operator>>(istream& CIN, Odjeca& a) {
        CIN >> (Artikal&)a;
        CIN.ignore();
        char temp[100];
        cout << "Unesite velicinu: ";
        CIN.getline(temp, 100);
        int vel = strlen(temp) + 1;
        a.velicina = new char[vel];
        strcpy_s(a.velicina, vel, temp);

        cout << "Unesite materijal: ";
        CIN.getline(temp, 100);
        vel = strlen(temp) + 1;
        a.materijal = new char[vel];
        strcpy_s(a.materijal, vel, temp);
        return CIN;
    }
};
ostream& operator<<(ostream& COUT, Odjeca& a);
istream& operator>>(istream& CIN, Odjeca& a);

class Prodavnica
{
public:
    char* naziv;
    char* adresa;

    Kolekcija<Odjeca> odjeca;
    Kolekcija<PrehrambeniArtikal> prehrana;

    Prodavnica(const char naziv[] = "---", const char adresa[] = "---") {
        int vel = strlen(naziv) + 1;
        this->naziv = new char[vel];
        strcpy_s(this->naziv, vel, naziv);

        vel = strlen(adresa) + 1;
        this->adresa = new char[vel];
        strcpy_s(this->adresa, vel, adresa);
    }

    Prodavnica(Prodavnica& orig) {
        int vel = strlen(orig.naziv) + 1;
        this->naziv = new char[vel];
        strcpy_s(this->naziv, vel, orig.naziv);

        vel = strlen(orig.adresa) + 1;
        this->adresa = new char[vel];
        strcpy_s(this->adresa, vel, orig.adresa);

        odjeca = orig.odjeca;
        prehrana = orig.prehrana;
    }

    Prodavnica& operator = (Prodavnica& orig) {
        if (this != &orig) {
            delete[] naziv, adresa;
            int vel = strlen(orig.naziv) + 1;
            this->naziv = new char[vel];
            strcpy_s(this->naziv, vel, orig.naziv);

            vel = strlen(orig.adresa) + 1;
            this->adresa = new char[vel];
            strcpy_s(this->adresa, vel, orig.adresa);

            odjeca = orig.odjeca;
            prehrana = orig.prehrana;
        }
        return *this;
    }


    bool DodajOdjecu()
    {
        Odjeca o;
        cin >> o;
        try
        {
            odjeca += o;
            return true;
        }
        catch (exception& ex)
        {
            cout << ex.what();
            return false;
        }
    }

    bool DodajPrehrambeniArtikal()
    {
        PrehrambeniArtikal a;
        cin >> a;
        try
        {
            prehrana += a;
            return true;
        }
        catch (exception& ex)
        {
            cout << ex.what();
            return false;
        }
    }

    bool UvecajStanjeNaSkladistu(PrehrambeniArtikal a)
    {
        try
        {
            prehrana[a].kolicinaNaSkladistu++;
            return true;
        }
        catch (exception& ex)
        {
            cout << ex.what();
            return false;
        }
    }

    bool UvecajStanjeNaSkladistu(Odjeca o)
    {
        try
        {
            odjeca[o].kolicinaNaSkladistu++;
            return true;
        }
        catch (exception& ex)
        {
            cout << ex.what();
            return false;
        }
    }

    bool UmanjiStanjeNaSkladistu(PrehrambeniArtikal a)
    {
        try
        {
            prehrana[a].kolicinaNaSkladistu--;
            return true;
        }
        catch (exception& ex)
        {
            cout << ex.what();
            return false;
        }
    }

    bool UmanjiStanjeNaSkladistu(Odjeca o)
    {
        try
        {
            odjeca[o].kolicinaNaSkladistu--;
            return true;
        }
        catch (exception& ex)
        {
            cout << ex.what();
            return false;
        }
    }

    friend ostream& operator<<(ostream& COUT, Prodavnica& p) {
        COUT << "Prodavnica: " << endl;
        COUT << "Naziv: " << p.naziv << endl;
        COUT << "Adresa: " << p.adresa << endl;
        COUT << "Prehrambeni artikli" << endl;
        COUT << p.prehrana << endl;
        COUT << "Odjeca: " << endl;
        COUT << p.odjeca << endl;
        return COUT;
    }
};

void main()
{
    Prodavnica p("Moja Prodavnica", "Adresa bb");

    p.DodajOdjecu();
    p.DodajOdjecu();
    /* p.DodajOdjecu();
     p.DodajOdjecu();
     p.DodajOdjecu();
     p.DodajOdjecu();*/

    p.DodajPrehrambeniArtikal();
    cin.ignore();
    p.DodajPrehrambeniArtikal();
    cin.ignore();

    /*p.DodajPrehrambeniArtikal();
    cin.ignore();
    p.DodajPrehrambeniArtikal();*/

    system("cls");

    cout << p;

    Odjeca o = p.odjeca[0];
    p.UmanjiStanjeNaSkladistu(o);
    p.UmanjiStanjeNaSkladistu(o);
    p.UvecajStanjeNaSkladistu(o);

    PrehrambeniArtikal pa = p.prehrana[1];
    p.UmanjiStanjeNaSkladistu(pa);
    p.UmanjiStanjeNaSkladistu(pa);
    p.UvecajStanjeNaSkladistu(pa);

    cout << endl
        << "::::::::::::::::::: Nakon promjene stanja na skladistu :::::::::::::::::::::: " << endl;
    cout  << p  << endl;
}
