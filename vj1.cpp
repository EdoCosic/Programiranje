#include <iostream>
using namespace std;
/*Napisati program u kojem je potrebno unijeti odabrani broj cifara počevši od cifre
najveće težinske vrijednosti, pa od njih sastaviti i ispisati prirodni broj.
Unos cifara se prekida kada se unese broj manji od 0 ili veći od 9. Ispis neka bude oblika:

Upisi cifru: 2
Upisi cifru: 8
Upisi cifru: -1
Broj sastavljen od zadanih cifara je 28.*/

int main()
{
	int broj, temp = 0;

	for (size_t i = 0; i < 3; i++)
	{
		cout << "Unesite cifru " << endl;
		cin >> broj;
		if (broj < 0 || broj>9)
		{
			break;
		}
		else {
			temp = temp * 10 + broj;
		}
	}
	cout << "Broj sastavljen od zadanih cifara je: " << temp;

	return 0;
}
