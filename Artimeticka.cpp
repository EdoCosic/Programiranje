#include <iostream>
using namespace std;

/*
Napisati program koji izracunava artimeticku sredinu svih savrsenih brojeva iz zadatog intervala.
Za neki broj se kaze da je savrsen ukoliko je jednak sumi svih svojih djelilaca
(ne ukljucujuci njega samog). Npr. 28: 1, 2, 4, 7, 14 = 28 a to su i njegovi djelioci.
Jedini savrsen broj u opsegu od 1 do 100 su 6 i 28. U rjesenju koristi funkciju sljedeceg prototipa:
bool IsSavrsen(int)
Primjer
Unesite granice intervala 1 500
Artimeticka sredina savrsenih brojeva iz zadatog intervala je: 176.667
*/

bool IsSavrsen(int br)
{
	int suma = 0;
	for (int i = 1; i < br; i++)
	{
		if (br % i == 0)
		{
			suma += i;
		}
		if (suma == br)
			return true;
		else
			return false;
	}
}

int main()
{
	int x, y, brojacSavrsenih = 0;
	double suma = 0;
	cout << "Uensite granice intervala" << endl;
	cin >> x >> y;
	for (int i = x; i <= y; i++)
	{
		if (IsSavrsen(i))
		{
			suma += i;
			brojacSavrsenih++;
		}
	}
	cout << "Artimeticka sredina iznosi " << suma / brojacSavrsenih << endl;


	system("pause>0");
	return 0;
}
