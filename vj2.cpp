#include <iostream>
using namespace std;
/*Napisati program koji omogućava korisniku unos integer vrijednosti veće od 100. Napisati funckiju koja će provjeriti da li je uneseni broj u isto vrijeme i prost i "palindrom",
odnosno da li je isti broj i kada se obrnnu sve cifre.
Po potrebi koristiti dodatne funkcije. Npr. brojevi 383, 727, 757, 787, 797, 919, 929 su u isto vrijeme i prosti brojevi i "palindromi".*/

//void NekaFunkcija(int);



int  NekaFunkcija(int nekiBr) {
	int temp = 0;
	if (nekiBr % 2 == 0) {
		cout << "Ovaj broj nije prost";
	}

	cout << "Ovaj broj je prost." << endl;
	while (nekiBr > 0) {
		temp = temp * 10 + (nekiBr % 10);
		nekiBr /= 10;
	};
	return temp;
}
int main()
{
	int broj;
	cout << "Unesite broj veci do 100: " << endl;
	cin >> broj;
	int Vracen;
	if (broj > 99) {
		Vracen = NekaFunkcija(broj);
	}
	if (Vracen == broj) {
		cout << "Ovaj broj je polindrom";
	}
	else
		cout << "nije polindrom";

	return 0;
}
