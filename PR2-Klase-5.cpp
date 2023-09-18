#include<iostream>
using namespace std;

template<class T>
class Kolekcija {
public:
	int trenutno;
	int max;
	T* elementi;

	Kolekcija(int max = 5)
	{
		this->max = max;
		trenutno = 0;
		elementi = new T[max];
	}

	~Kolekcija() {
		delete[]elementi;
		elementi = nullptr;
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

	void operator =(Kolekcija& orig) {
		if (this != &orig) {
			max = orig.max;
			trenutno = orig.trenutno;
			elementi = new T[max];

			for (int i = 0; i < trenutno; i++)
			{
				elementi[i] = orig.elementi[i];
			}
		}
	}

	//potrebne funkcije
	//operator += dodaje novi element u kolekciju
	// onemoguciti dodavanje istih elemenata
	//omoguciti prosirenje kolekcije ukoliko trenutno dostigne max

	void operator+=(T novi) {
		for (int i = 0; i < trenutno; i++)
		{
			if (elementi[i] == novi)
				throw exception("Nemoguce dodavati iste elemente.\n");
		}

		if (trenutno == max) {
			T* temp = new T[max];

			for (int i = 0; i < trenutno; i++)
			{
				temp[i] = elementi[i];
			}

			delete[]elementi;
			max += 5;
			elementi = new T[max];
			for (int i = 0; i < trenutno; i++)
			{
				elementi[i] = temp[i];
			}
		}

		elementi[trenutno++] = novi;
	}

	//operator -= dvije verzije: jedna prima element koji je potrebno ukloniti,
	//a druga verzija ovog operatora prima poziciju sa koje je potrebno ukloniti element

	void operator-=(T ukloni) {
		for (int i = 0; i < trenutno; i++)
		{
			if (elementi[i] == ukloni)
			{
				for (int j = i; j < trenutno - 1; j++)
				{
					elementi[j] = elementi[j + 1];
				}

				trenutno--;
				return;
			}
		}

		throw exception("Element nije pronadjen.\n");
	}

	void operator-=(int pozicija) {
		if (pozicija < 0 || pozicija >= trenutno)
			throw exception("Pozicija nije validna.\n");

		for (int j = pozicija; j < trenutno - 1; j++)
		{
			elementi[j] = elementi[j + 1];
		}
		trenutno--;
	}
	//operator <<

	friend ostream& operator <<(ostream& out, Kolekcija& k) {
		for (int i = 0; i < k.trenutno; i++)
		{
			out << "Redni broj " << i << ": " << k.elementi[i] << endl;
		}

		return out;
	}
};

class Datum {
public:

	int* _dan, * _mjesec, * _godina;
	//potrebne funkcije

	Datum(int d = 1, int m = 1, int g = 2000) {
		_dan = new int(d);
		_mjesec = new int(m);
		_godina = new int(g);
	}
	~Datum() {
		delete _dan, _mjesec, _godina;
		_dan = _mjesec = _godina = nullptr;
	}
	Datum(Datum& original) {
		_dan = new int(*original._dan);
		_mjesec = new int(*original._mjesec);
		_godina = new int(*original._godina);
	}
	void operator=(Datum& original) {
		if (this != &original) {
			*_dan = (*original._dan);
			*_mjesec = (*original._mjesec);
			*_godina = (*original._godina);
		}
	}
	friend ostream& operator<<(ostream& out, Datum& obj) {
		out << *obj._dan << "." << *obj._mjesec << "." << *obj._godina;
		return out;
	}
	bool operator==(Datum d) {
		return (*_dan == *d._dan && *_mjesec == *d._mjesec && *_godina == *d._godina);
	}
};


class Kategorija {
public:
	char* _oznakaKategorije;
	Datum* _datumPolaganja;
	char* _komentar;//oznacava komentar koji ce komisija dati nakon zavrsenog polaganja
	//potrebne funkcije

	Kategorija(const char* oznaka = "---", Datum d = 0, const char* comment = "---")
	{
		_oznakaKategorije = new char[strlen(oznaka) + 1];
		strcpy_s(_oznakaKategorije, strlen(oznaka) + 1, oznaka);

		_datumPolaganja = new Datum(d);

		_komentar = new char[strlen(comment) + 1];
		strcpy_s(_komentar, strlen(comment) + 1, comment);
	}

	Kategorija(Kategorija& orig) {
		_oznakaKategorije = new char[strlen(orig._oznakaKategorije) + 1];
		strcpy_s(_oznakaKategorije, strlen(orig._oznakaKategorije) + 1, orig._oznakaKategorije);

		_datumPolaganja = new Datum(*orig._datumPolaganja);

		_komentar = new char[strlen(orig._komentar) + 1];
		strcpy_s(_komentar, strlen(orig._komentar) + 1, orig._komentar);
	}

	void operator =(Kategorija& orig) {
		if (this != &orig) {
			_oznakaKategorije = new char[strlen(orig._oznakaKategorije) + 1];
			strcpy_s(_oznakaKategorije, strlen(orig._oznakaKategorije) + 1, orig._oznakaKategorije);

			_datumPolaganja = new Datum(*orig._datumPolaganja);

			_komentar = new char[strlen(orig._komentar) + 1];
			strcpy_s(_komentar, strlen(orig._komentar) + 1, orig._komentar);
		}
	}

	bool operator ==(Kategorija& k) {
		return strcmp(_oznakaKategorije, k._oznakaKategorije) == 0;
	}

	bool operator ==(Kategorija* k) {
		return strcmp(_oznakaKategorije, k->_oznakaKategorije) == 0;
	}

	bool operator ==(char* oznaka) {
		return strcmp(_oznakaKategorije, oznaka) == 0;
	}

	~Kategorija() {
		delete[]_oznakaKategorije, _komentar;
		delete _datumPolaganja;

		_oznakaKategorije = nullptr;
		_komentar = nullptr;
		_datumPolaganja = nullptr;
	}

	friend ostream& operator<<(ostream& out, Kategorija& obj) {
		out << "Oznaka kategorije: " << obj._oznakaKategorije << endl;
		out << "Datum polaganja: " << *obj._datumPolaganja << endl;
		out << "Komentar: " << obj._komentar << endl;
		return out;
	}

	friend ostream& operator<<(ostream& out, Kategorija* obj) {
		out << "Oznaka kategorije: " << obj->_oznakaKategorije << endl;
		out << "Datum polaganja: " << *obj->_datumPolaganja << endl;
		out << "Komentar: " << obj->_komentar << endl;
		return out;
	}
};



class Kandidat {
public:
	char* _imePrezime;
	char* _JMBG;
	char* _adresa;
	Datum* _datumRodjenja;
	Kolekcija<Kategorija*> _polozeneKategorije;

	Kandidat(const char imePrezime[] = "---", const char jmbg[] = "---", const char adresa[] = "---", Datum datumRodjenja = 0) {
		_imePrezime = new char[strlen(imePrezime) + 1];
		strcpy_s(_imePrezime, strlen(imePrezime) + 1, imePrezime);

		_JMBG = new char[strlen(jmbg) + 1];
		strcpy_s(_JMBG, strlen(jmbg) + 1, jmbg);

		_adresa = new char[strlen(adresa) + 1];
		strcpy_s(_adresa, strlen(adresa) + 1, adresa);

		_datumRodjenja = new Datum(datumRodjenja);
	}

	Kandidat(Kandidat& orig) {
		_imePrezime = new char[strlen(orig._imePrezime) + 1];
		strcpy_s(_imePrezime, strlen(orig._imePrezime) + 1, orig._imePrezime);

		_JMBG = new char[strlen(orig._JMBG) + 1];
		strcpy_s(_JMBG, strlen(orig._JMBG) + 1, orig._JMBG);

		_adresa = new char[strlen(orig._adresa) + 1];
		strcpy_s(_adresa, strlen(orig._adresa) + 1, orig._adresa);

		_datumRodjenja = new Datum(*orig._datumRodjenja);

		_polozeneKategorije = orig._polozeneKategorije;
	}

	void operator =(Kandidat& orig) {
		if (this != &orig)
		{
			_imePrezime = new char[strlen(orig._imePrezime) + 1];
			strcpy_s(_imePrezime, strlen(orig._imePrezime) + 1, orig._imePrezime);

			_JMBG = new char[strlen(orig._JMBG) + 1];
			strcpy_s(_JMBG, strlen(orig._JMBG) + 1, orig._JMBG);

			_adresa = new char[strlen(orig._adresa) + 1];
			strcpy_s(_adresa, strlen(orig._adresa) + 1, orig._adresa);

			_datumRodjenja = new Datum(*orig._datumRodjenja);

			_polozeneKategorije = orig._polozeneKategorije;
		}
	}

	~Kandidat() {
		delete[]_imePrezime, _JMBG, _adresa;
		delete _datumRodjenja;

		_imePrezime = nullptr;
		_JMBG = nullptr;
		_adresa = nullptr;
		_datumRodjenja = nullptr;
	}

	friend ostream& operator<<(ostream& out, Kandidat& obj) {
		out << "Kandidat: " << obj._imePrezime << endl;
		out << "JMBG: " << obj._JMBG << endl;
		out << "Adresa: " << obj._adresa << endl;
		out << "Datum rodjenja: " << *obj._datumRodjenja << endl;
		out << "Polozene kategorije:\n" << obj._polozeneKategorije << endl;

		return out;
	}

	bool DodajKategoriju(Kategorija k) {
		//Voditi racuna da kandidat ne moze imati iste kategorije

		for (int i = 0; i < _polozeneKategorije.trenutno; i++)
		{
			if (*_polozeneKategorije.elementi[i] == k)
				return false;
		}

		try {
			_polozeneKategorije += (new Kategorija(k));
			return true;
		}
		catch (exception& ex) {
			cout << ex.what();
			return false;
		}
	}

	bool RemoveKategorija(char* oznaka) {
		//Korisnik unosi oznaku kategorije, te se uklanja kategorija sa istom oznakom iz niza
		//U zavisnosti od uspjesnosti operacije, funkcija vraca true ili false

		for (int i = 0; i < _polozeneKategorije.trenutno; i++)
		{
			if (*_polozeneKategorije.elementi[i] == oznaka) {
				try {
					_polozeneKategorije -= (i);
					return true;
				}
				catch (exception& ex) {
					cout << ex.what();
					return false;
				}
			}
		}

		return false;
	}

	bool operator==(Kandidat& drugi) {
		return strcmp(_JMBG, drugi._JMBG) == 0;
	}

};
class Autoskola {
public:
	char* _naziv;
	char* _adresa;
	Kolekcija<Kandidat> _listaKandidata;//lista kandidata koja je polozila u autoskoli

	Autoskola(const char* naziv = "---", const char* adresa = "---") {
		_naziv = new char[strlen(naziv) + 1];
		strcpy_s(_naziv, strlen(naziv) + 1, naziv);

		_adresa = new char[strlen(adresa) + 1];
		strcpy_s(_adresa, strlen(adresa) + 1, adresa);
	}

	~Autoskola() {
		delete[]_naziv, _adresa;
		_naziv = _adresa = nullptr;
	}

	Autoskola(Autoskola& orig) {
		_naziv = new char[strlen(orig._naziv) + 1];
		strcpy_s(_naziv, strlen(orig._naziv) + 1, orig._naziv);

		_adresa = new char[strlen(orig._adresa) + 1];
		strcpy_s(_adresa, strlen(orig._adresa) + 1, orig._adresa);

		_listaKandidata = orig._listaKandidata;
	}

	void operator =(Autoskola& orig) {
		if (this != &orig) {
			_naziv = new char[strlen(orig._naziv) + 1];
			strcpy_s(_naziv, strlen(orig._naziv) + 1, orig._naziv);

			_adresa = new char[strlen(orig._adresa) + 1];
			strcpy_s(_adresa, strlen(orig._adresa) + 1, orig._adresa);

			_listaKandidata = orig._listaKandidata;
		}
	}

	bool DodajKandidata(Kandidat novi) {
		//Nije moguce dodati u niz kandidate koji nisu punoljetni
		//Takodjer nije moguce u niz dodavati iste kandidate
		//U zavisnosti od uspjesnosti, funkcija vraca true ili false	

		if ((2019 - (*novi._datumRodjenja->_godina)) < 18) {
			cout << "Kandidat nije punoljetan.\n";
			return false;
		}

		try {
			_listaKandidata += novi;
			return true;
		}
		catch (exception& ex) {
			cout << ex.what();
			return false;
		}
	}

	bool DodajKategorijuKandidatu(Kategorija k) {
		//Funkcija izlistava sve kandidate
		//Korisnik odabere redni broj kandidata, te u skladu s tim dodaje odgovarajuću kategoriju kandidatu
		int redBr;

		cout << _listaKandidata;
		cout << "Unesite redni broj kandidata: " << endl;
		cin >> redBr;

		try {
			return (_listaKandidata.elementi[redBr].DodajKategoriju(k));
		}
		catch (exception& ex) {
			cout << ex.what();
			return false;
		}

	}

	bool UkloniKategorijuKandidatu(Kategorija k) {
		//Funkcija izlistava sve kandidate
		//Korisnik odabere redni broj kandidata, te u skladu s tim uklanja kategoriju kandidatu
		int redBr;

		cout << _listaKandidata;
		cout << "Unesite redni broj kandidata: " << endl;
		cin >> redBr;

		try {
			return (_listaKandidata.elementi[redBr].RemoveKategorija(k._oznakaKategorije));
		}
		catch (exception& ex) {
			cout << ex.what();
			return false;
		}
	}

	friend ostream& operator <<(ostream& out, Autoskola& a) {
		out << "Autoskola: " << a._naziv << endl;
		out << "Adresa: " << a._adresa << endl;
		out << "Kandidati: " << endl;
		out << a._listaKandidata << endl;

		return out;
	}
};

void GetKandidatiByDatum(Autoskola* autoskola, Datum datumPretrage) {
	//funkcija treba da ispise podatke o svim kandidatima koji su polozili vozacki ispit na datum koji 
	//je proslijeđen kao parametar

	cout << "Kandidati koji su polagali na datum " << datumPretrage << " su: " << endl;

	for (int i = 0; i < autoskola->_listaKandidata.trenutno; i++)
	{
		for (int j = 0; j < autoskola->_listaKandidata.elementi[i]._polozeneKategorije.trenutno; j++)
		{
			if (*(autoskola->_listaKandidata.elementi[i]._polozeneKategorije.elementi[j]->_datumPolaganja) == datumPretrage)
				cout << autoskola->_listaKandidata.elementi[i] << endl;
		}
	}

}

Kandidat* VratiKandidata(Autoskola* autoskola, char* imePrezime) {
	//Funckija prima ime i prezime kandidata koji se pretrazuje.
	//Funkcija treba da pronadje i vrati kandidata sa unesenim imenom

	for (int i = 0; i < autoskola->_listaKandidata.trenutno; i++)
	{

		if (strcmp(autoskola->_listaKandidata.elementi[i]._imePrezime, imePrezime) == 0)
			return &autoskola->_listaKandidata.elementi[i];
	}

	return nullptr;
}

void GetKandidatiByKomentar(Autoskola autoskola) {
	//funkcija treba da ispise imena i prezimena kandidata koji su nakon polaganja dobili komentar: Odlicno uradjeno!.
	//a polagali su u 2019.godini i to kategoriju B.

	cout << "Kandidati koji su polagali u 2019 godini B kategoriju sa komentarom 'Odlicno uradjeno!' su: " << endl;

	for (int i = 0; i < autoskola._listaKandidata.trenutno; i++)
	{
		for (int j = 0; j < autoskola._listaKandidata.elementi[i]._polozeneKategorije.trenutno; j++)
		{
			if (*(autoskola._listaKandidata.elementi[i]._polozeneKategorije.elementi[j]->_datumPolaganja->_godina) == 2019)
			{
				if (autoskola._listaKandidata.elementi[i]._polozeneKategorije.elementi[j]->_oznakaKategorije == "B")
				{
					if (autoskola._listaKandidata.elementi[i]._polozeneKategorije.elementi[j]->_komentar == "Odlicno uradjeno!")
					{
						cout << autoskola._listaKandidata.elementi[i] << endl;
					}
				}
			}
		}
	}
}

bool ProvjeriKorisnika(Autoskola autoskola, char* JMBG) {
	//Funckija prima JMBG korisnika kojeg trazimo. Provjeravamo da li je korisnik polozio 
	//vise od 2 vozacke kategorije u ovoj autoskoli.

	int brojac = 0;

	for (int i = 0; i < autoskola._listaKandidata.trenutno; i++)
	{
		if (strcmp(autoskola._listaKandidata.elementi[i]._JMBG, JMBG) == 0) {
			return autoskola._listaKandidata.elementi[i]._polozeneKategorije.trenutno > 2;
		}
	}

	return false;
}

void main() {
	Datum dr1(27, 9, 1995);
	Datum dr2(18, 3, 2000);
	Datum dr3(29, 12, 1994);
	Datum dr4(11, 10, 2005);


	Datum d1(27, 9, 2010);
	Datum d2(18, 3, 2015);
	Datum d3(29, 12, 2017);
	Datum d4(11, 10, 2018);


	Kandidat k1("Kandidat 1", "123", "Adresa 1", dr1);
	Kandidat k2("Kandidat 2", "456", "Adresa 2", dr2);
	Kandidat k3("Kandidat 3", "789", "Adresa 3", dr3);
	Kandidat k4("Kandidat 4", "321", "Adresa 4", dr4);

	Autoskola autoskola("Autoskola Test", "Adresa bb");

	try {
		autoskola.DodajKandidata(k1);
		autoskola.DodajKandidata(k2);
		autoskola.DodajKandidata(k3);
		autoskola.DodajKandidata(k4);//Izuzetak: Kandidat maloljetan
	}
	catch (exception& ex) {
		cout << ex.what();
	}

	/*system("cls");
	cout << autoskola << endl;*/

	Kategorija kat1("A", d1, "Odlicno uradjeno!");
	Kategorija kat2("B", d2, "No comment.");
	Kategorija kat3("C", d3, "Na granici prolaska.");
	Kategorija kat4("B", d1, "Odlicno uradjeno!");
	Kategorija kat5("A", d1, "---");
	Kategorija kat6("B", d4, "---");

	try {
		autoskola.DodajKategorijuKandidatu(kat1);
		autoskola.DodajKategorijuKandidatu(kat1);

		autoskola.DodajKategorijuKandidatu(kat2);
		autoskola.DodajKategorijuKandidatu(kat3);
		autoskola.DodajKategorijuKandidatu(kat4);
		autoskola.DodajKategorijuKandidatu(kat5);
		autoskola.DodajKategorijuKandidatu(kat6);
	}
	catch (exception& ex) {
		cout << ex.what();
	}

	//system("cls");
	//cout << autoskola << endl;

	try {
		autoskola.UkloniKategorijuKandidatu(kat1);
		autoskola.UkloniKategorijuKandidatu(kat2);
	}
	catch (exception& ex) {
		cout << ex.what();
	}

	system("cls");
	cout << autoskola << endl;

	GetKandidatiByDatum(&autoskola, d1);
	Kandidat* pok = VratiKandidata(&autoskola, k1._imePrezime);

	if (pok != nullptr)
		cout << "Kandidat sa imenom " << k1._imePrezime << " je " << *pok << endl;


	GetKandidatiByKomentar(autoskola);
	if (ProvjeriKorisnika(autoskola, k1._JMBG))
		cout << "Kandidat " << k1._imePrezime << " ima vise od 2 položene kategorije.\n";
	else
		cout << "Kandidat " << k1._imePrezime << " nema vise od 2 položene kategorije.\n";

	system("pause>0");
}
