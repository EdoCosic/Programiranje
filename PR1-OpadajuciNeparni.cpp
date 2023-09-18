#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


bool Neparne(int broj)
{
	do
	{
		if (broj % 10 % 2 == 0)
		{
			return false;
		}
		else
		{
			broj /= 10;
		}
	} while (broj > 0);
	return true;
}

bool Opadajuci(int broj)
{
	do
	{
		if (broj % 10 >= broj / 10 % 10)
		{
			return false;
		}
		else
		{
			broj /= 10;
		}
	} while (broj > 10);
	return true;
}

int main()
{
	int m, n;
	do
	{
		cout << "Unesite m i n" << endl;
		cin >> m >> n;
	} while (n <= 10 || n >= 1000 || m > n);

	for (int i = m; i <= n; i++)
	{
		if (Neparne(i) && Opadajuci(i))
		{
			cout << i << " ";
		}
	}

	system("pause>0");
	return 0;
}
