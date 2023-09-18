#include <iostream>
using namespace std;

/*
Data su dva prirodna broja X i Y iz intervala od 10 do 5000.
Kreirati prigram koji ce prebrojati i ispisati koliko brojeva od X do Y
(ukljucujuci granicne vrijedosti) zadovoljava uslov da im je suma svih
cifara djeljiva sa brojem koji se dobije kad se saberu prva i zadnja cifra.
U rjesenju koristiti najmanje jednu funkciju.
Npr. Za broj 162 vrjedi da mu je suma cifara 9(1+6+2) a suma prve i zadnje je 3(1+2).
Broj 9 je djeljiv sa brojem 3.
*/

int SumaSvihCifara(int);
int SumaPrveiZadnjeCifre(int);

int main()
{
	int x, y;
	int brojac = 0;
	do
	{
		cout << "Unesite granice intervala" << endl;
		cin >> x >> y;
	} while (x < 0 || x>5000 || y < 10 || y>5000);

	for (int i = x; i <= y; i++)
	{
		if (SumaSvihCifara(i) % SumaPrveiZadnjeCifre(i) == 0)
		{
			cout << i << endl;
			brojac++;
		}
	}
	cout << "Dati uslov ispunjava: " << brojac << " brojeva" << endl;

	system("pause>0");
	return 0;
}

int SumaSvihCifara(int br)
{
	int suma = 0;
	int temp = 0;
	while (br > 0)
	{
		temp = br % 10;
		suma += temp;
		br /= 10;
	}
	return suma;
}

int SumaPrveiZadnjeCifre(int br)
{
	int zadnja = br % 10;
	while (br >= 10)
	{
		br /= 10;
	}
	return br + zadnja;
}
