#include <iostream>
using namespace std;

bool Prost(int broj)
{
	for (int i = 2; i < broj; i++)
	{
		if (broj % i == 0)
		{
			return false;
		}

	}
	return true;
}

bool Rastuci(int broj)
{
	do
	{
		if (broj % 10 <= broj / 10 % 10)
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
	int n;
	do
	{
		cout << "Unesite n" << endl;
		cin >> n;
	} while (n <= 10 || n >= 1000);

	for (int i = 10; i <= n; i++)
	{
		if (Prost(i) && Rastuci(i))
		{
			cout << i << " ";
		}
	}

	system ("pause>0");
	return 0;
}
