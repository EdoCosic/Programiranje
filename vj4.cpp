#include <iostream>
using namespace std;

/*
Napisite program koji koristenjem rekurzivne funkcije ispisuje
binarni ekvivalent unesenog prirodnoh broja N.
*/



//ovo je iterativno
int main()
{
	int broj, binarni = 0, brojac = 0, ostatak;

	cout << "Unesite jedan prirodan broj " << endl;
	cin >> broj;

	if (broj < 0)
		broj = abs(broj); //funkcija abs() vraca apsolutnu vrijednost broja

	while (broj > 0)
	{
		ostatak = broj % 2;
		binarni = binarni + ostatak * pow(10.0, brojac);
		brojac++;
		broj /= 2;
	}

	cout << "Binarni ekvivalent unesenog broja je " << binarni << endl;

	system("pause>0");
	return 0;
}



//ovo je rekurzivno
//int binarniEkv(int, int);
//int main()
//{
//	int broj, i = 0;
//	do
//	{
//		cout << "Unesite prirodan broj" << endl;
//		cin >> broj;
//	} while (broj < 1);
//
//	cout << binarniEkv(broj, i) << endl;
//
//	system("pause>0");
//	return 0;
//}
//
//int binarniEkv(int br, int i)
//{
//	if (br == 0)
//		return 0;
//	return br % 2 * pow(10.0, i) + binarniEkv(br  / 2, i  + 1);
//}
