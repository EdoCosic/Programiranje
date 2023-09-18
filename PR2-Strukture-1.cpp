#include<iostream>
using namespace std;
struct Datum {
	int* dan, mjesec, * godina;
	void Unos(int d, int m, int g) {
		dan = new int(d);
		mjesec = m;
		godina = new int(g);
	}
	void Ispis() {
		cout << *dan << "." << mjesec << "." << *godina << endl;
	}
	void Dealociraj() {
		delete dan;
		delete godina;
		dan = nullptr;
		godina = nullptr;
	}
};
struct Dijagnoza
{
	char* Naziv;
	char Opis[100];
	void Unos(const char* n, const char* o) {
		Naziv = new char[strlen(n) + 1];
		strcpy_s(Naziv, strlen(n) + 1, n);
		strcpy_s(Opis, strlen(o) + 1, o);
	}
	void Ispis() {
		cout << "Naziv dijagnoze: " << Naziv << endl;
		cout << "Opis dijagnoze: " << Opis << endl;
	}
	void Dealociraj() {
		delete[]Naziv;
		Naziv = nullptr;
	}
};
struct Pacijent {
	char* ImePrezime;
	char JMBG[14];
	Datum* DatumRodjenja;
	Dijagnoza* _dijagnoze[100];//niz pokazivaca
	int* trenutnoDijagnoza;
	void Unos(const char* ip, const char* jmbg, Datum* datum) {
		trenutnoDijagnoza = new int(0);//brojac u funkciji za unos MORA ici na 0
		ImePrezime = new char[strlen(ip) + 1];
		strcpy_s(ImePrezime, strlen(ip) + 1, ip);
		strcpy_s(JMBG, 14, jmbg);
		DatumRodjenja = new Datum;
		DatumRodjenja->Unos(*datum->dan, datum->mjesec, *datum->godina);
	}
	void Ispis() {
		cout << "Podaci o pacijentu: " << endl;
		cout << "Ime i prezime: " << ImePrezime << endl;
		cout << "JMBG: " << JMBG << endl;
		cout << "Datum rodjenja: "; DatumRodjenja->Ispis();
		cout << "Dijagnoze: " << endl;
		for (int i = 0; i < *trenutnoDijagnoza; i++)
		{
			_dijagnoze[i]->Ispis();
		}
	}
	void Dealociraj() {
		delete[]ImePrezime;
		ImePrezime = nullptr;
		DatumRodjenja->Dealociraj();
		delete DatumRodjenja;
		DatumRodjenja = nullptr;
		for (int i = 0; i < *trenutnoDijagnoza; i++)
		{
			_dijagnoze[i]->Dealociraj();
			delete _dijagnoze[i];
			_dijagnoze[i] = nullptr;
		}
		delete trenutnoDijagnoza;
		trenutnoDijagnoza = nullptr;
	}
	bool DodajDijagnozu(Dijagnoza d)
	{
		//Dodati novu dijagnozu pacijentu.
		//Voditi racuna o velicini niza
		//Onemoguciti dupliranje dijagnoza
		if (*trenutnoDijagnoza == 100)
			return false;
		for (int i = 0; i < *trenutnoDijagnoza; i++)
		{
			if (strcmp(d.Naziv, _dijagnoze[i]->Naziv) == 0)
				return false;
		}
		_dijagnoze[*trenutnoDijagnoza] = new Dijagnoza;
		_dijagnoze[*trenutnoDijagnoza]->Unos(d.Naziv, d.Opis);
		(*trenutnoDijagnoza)++;
		return true;
	}
};
void main() {
	int vel = 3;
	Pacijent* niz = new Pacijent[vel];
	Datum datum1, datum2, datum3;
	datum1.Unos(5, 2, 2001);
	datum2.Unos(1, 12, 2005);
	datum3.Unos(7, 10, 1990);
	niz[0].Unos("Adela Nefic", "223428913450563", &datum1);
	niz[1].Unos("Amina Zec", "1452983255568", &datum2);
	niz[2].Unos("Adna", "125675003", &datum3);
	Dijagnoza dijagnoza1, dijagnoza2, dijagnoza3;
	dijagnoza1.Unos("Temperatura", "Visoka temperatura, iznad 39");
	dijagnoza2.Unos("COVID", "Izgubljeni culo okusa i mirisa");
	dijagnoza3.Unos("Glavobolja", "Jake i ucestale glavobolje");

	if (niz[0].DodajDijagnozu(dijagnoza1) == true)
		cout << "Pacijentu " << niz[0].ImePrezime << " dodana nova dijagnoza" << endl;
	else
		cout << "Pacijentu " << niz[0].ImePrezime << " nije dodana nova dijagnoza" << endl;

	if (niz[0].DodajDijagnozu(dijagnoza2) == true)
		cout << "Pacijentu " << niz[0].ImePrezime << " dodana nova dijagnoza" << endl;
	else
		cout << "Pacijentu " << niz[0].ImePrezime << " nije dodana nova dijagnoza" << endl;

	if (niz[1].DodajDijagnozu(dijagnoza3) == true)
		cout << "Pacijentu " << niz[1].ImePrezime << " dodana nova dijagnoza" << endl;
	else
		cout << "Pacijentu " << niz[1].ImePrezime << " nije dodana nova dijagnoza" << endl;

	if (niz[1].DodajDijagnozu(dijagnoza2) == true)
		cout << "Pacijentu " << niz[1].ImePrezime << " dodana nova dijagnoza" << endl;
	else
		cout << "Pacijentu " << niz[1].ImePrezime << " nije dodana nova dijagnoza" << endl;

	for (int i = 0; i < vel; i++)
	{
		niz[i].Ispis();
	}
}
