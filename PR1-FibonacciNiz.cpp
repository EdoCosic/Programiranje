#include <iostream>
using namespace std;

/*
Zadatak 3: Napisati program u kojem cete kreirati dvije funkcije
(jednu iterativnu i jednu rekurzivnu)
ciji je zadatak racunanje n-tog clana Fibonacci-jevog niza.
*/

//1 1 2 3 5 8 13... fibonacijev niz (1+1=2), (2+1=3), (5+8=13),...

int Fibb1(int);
int Fibb2(int);
int main()
{
	int clan;
	do
	{
		cout << "Koji clan Fib. niza zelite?" << endl;
		cin >> clan;
	} while (clan < 1);

	cout << clan << " -ti clan Fib. niza je " << Fibb1(clan) << endl;
	return 0;
}

int Fibb1(int clan)
{
	int prvi = 1, drugi = 1, treci = 0;

	for (int i = 3; i <= clan; i++)
	{
		treci = prvi + drugi;
		prvi = drugi;
		drugi = treci;
	}
	return treci;
}

//int Fibb2(int n)
//{
//	if (n == 1 || n == 2)
//		return 1;
//	return Fibb2(n - 1) + Fibb2(n  - 2);
//}
