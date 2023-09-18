#include <iostream>
using namespace std;

/*
Kreirajte strukturu ucenik koja ce imati sljedeca obiljezja: redni broj, ime i prezime, niz ocjena (5)

a) Kreirati 2 objekta tipa ucenik; kreirati funkcije za unos i ispis obiljezja jednog objekta;
pozvati funkciju za oba objekta;
b) Kreirati niz objekata tipa ucenik; upotrijebiti funkcije iz zadatka a) za unos i ispis obiljezja;
c) Kreirati funkcije za unos i ispis obiljezja niza objekata tipa ucenik;
d) Kreirati funkciju float prosjecna (ucenik); koja racuna prosjecnu ocjenu za jendog ucenika;
e) Kreirati funkciju ucenik najgori (ucenik [], int;)
koja ce vracati ucenika koji ima najmanju prosjecnu ocjenu; upotrijebiti funkciju za ispis iz zadatka pod a)
*/

int g = 1;
struct ucenik
{
	int RB;
	char ime[10];
	char prezime[15];
	int ocjene[5];
};
void unos(ucenik&);//funkcija prima jedan parametar tipa ucenik po referenci
void ispis(ucenik);//funkcija prima jedan parametar tipa ucenik po vrijednosti

void UNOS(ucenik[], int);//funkcija prima kao parametar niz tipa ucenik
void ISPIS(ucenik[], int);//funkcija prima kao parametar tipa ucenik

float prosjecna(ucenik);//funckija prima jedan parametar tipa ucenik po vrijednosti
float PROSJEK(int[]);//funckija prima kao parametar samo jedno obiljezje objekta tipa ucenik

ucenik najgori(ucenik[], int);//funckija prima ucenika a vraca jedan objekt tipa ucenik
int main()
{

	ucenik niz[3];

	UNOS(niz, 3);

	cout << "\nISPIS\n" << endl;

	ISPIS(niz, 3);

	cout << "\nPROSJEK" << endl;
	//for (int i = 0; i < 3; i++)
	//	cout << prosjecna(niz[i]) << endl;

	for (int i = 0; i < 3; i++)
		cout << "Prosjek ucenika " << i + 1 << " iznosi - " << PROSJEK(niz[i].ocjene) << endl;

	cout << endl;

	cout << "Ucenik sa najgorim prosjekom je";
	ispis(najgori(niz, 3));

	system("pause > 0");
	return 0;
}

void unos(ucenik& O1)
{
	//cout << "Unesite redni broj" << endl;
	//cin >> O1.RB;
	O1.RB = g++;
	//cin.ignore();//ova funkcija ce ocistiti sadrzaj input buffera

	cout << "Unesite ime" << endl;
	cin.getline(O1.ime, 10);

	cout << "Unesite prezime" << endl;
	cin.getline(O1.prezime, 15);

	cout << "Unesite ocjene" << endl;
	for (int i = 0; i < 5; i++)
	{
		cin >> O1.ocjene[i];
		if (O1.ocjene[i] < 1 || O1.ocjene[i]>5)
			i--;
	}
	cin.ignore();
}

void ispis(ucenik O1)
{
	cout << "\nRB - " << O1.RB << endl;
	cout << "ime - " << O1.ime << endl;
	cout << "prezime - " << O1.prezime << endl;
	cout << "Ocjene su - ";
	for (int i = 0; i < 5; i++)
	{
		cout << " " << O1.ocjene[i];
	}
	cout << endl;
}

void UNOS(ucenik niz[], int v)
{
	for (int i = 0; i < v; i++)
	{
		niz[i].RB = g++;
		//cin.ignore();//ova funkcija ce ocistiti sadrzaj input buffera

		cout << "Unesite ime" << endl;
		cin.getline(niz[i].ime, 10);

		cout << "Unesite prezime" << endl;
		cin.getline(niz[i].prezime, 15);

		cout << "Unesite ocjene" << endl;
		for (int j = 0; j < 5; j++)
		{
			cin >> niz[i].ocjene[j];
			if (niz[i].ocjene[j] < 1 || niz[i].ocjene[j]>5)
				j--;
		}
		cin.ignore();
	}
}

void ISPIS(ucenik niz[], int v)
{
	for (int i = 0; i < v; i++)
	{
		cout << "\nRB - " << niz[i].RB << endl;
		cout << "ime - " << niz[i].ime << endl;
		cout << "prezime - " << niz[i].prezime << endl;
		cout << "Ocjene su - ";
		for (int j = 0; j < 5; j++)
		{
			cout << " " << niz[i].ocjene[j];
		}
	}
}

float prosjecna(ucenik O)
{
	int s = 0;
	for (int i = 0; i < 5; i++)
		s += O.ocjene[i];

	return s / 5.0;

}

float PROSJEK(int ocjene[])
{
	int s = 0;
	for (int i = 0; i < 5; i++)
		s += ocjene[i];

	return s / 5.0;
}

ucenik najgori(ucenik niz[], int v)
{
	if (PROSJEK(niz[0].ocjene) < PROSJEK(niz[1].ocjene) && PROSJEK(niz[0].ocjene) < PROSJEK(niz[2].ocjene))
		return niz[0];
	else
		if (PROSJEK(niz[1].ocjene) < PROSJEK(niz[0].ocjene) && PROSJEK(niz[1].ocjene) < PROSJEK(niz[2].ocjene))
			return niz[1];
		else
			return niz[2];
}
