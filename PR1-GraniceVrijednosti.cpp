#include <iostream>
using namespace std;

/*
Kreirati prigram koji ce pronaci i ispisati sve brojeve od X i Y(ukljucujuci granicne vrijednosti)
koji su djeljivi svim svojim ciframa. Na primjer, broj 36 je djeljiv sa 3 i 6.
Brojeve X i Y unosi korisnik i moraju biti u opsegu od 10 do 6000.
Obavezno koristiti bar jednu funkciju.
Primjer: 32 37
Brojevi u navedenom opsegu koji zadovoljavaju uslob su: 33, 36.*/

bool DjeljivSvimSvojimCiframa(int);
int main()
{
	int x, y;
	do
	{
		cout << "Unesite granice intervala" << endl;
		cin >> x >> y;
	} while (x < 10 || x>6000 || y < 10 || y>6000);

	for (int i = x; i <= y; i++)
	{
		if (DjeljivSvimSvojimCiframa(i) == true)
		{
			cout << i << endl;
		}
	}

	system("pause>0");
	return 0;
}

bool DjeljivSvimSvojimCiframa(int broj)
{
	// 543, trebamo ispitati jel djeljivo sa 3 pa sa 4 pa sa 5... samo ako je sa svim onda je tacno
	int zadnja;
	int temp = broj;
	while (broj > 0)
	{
		zadnja = broj % 10;
		if (zadnja != 0)
		{
			if (temp % zadnja != 0)
				return false;
		}
		broj /= 10;
	}
	return true;
}
