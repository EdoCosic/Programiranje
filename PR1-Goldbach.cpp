#include <iostream>
using namespace std;
bool Prost(int broj)
{
	for (int i = 2; i < broj; i++)
	{
		if (broj % i == 0)
			return false;
	}
	return true;
}

void RastaviBroj(int broj)
{
	for (int i = 1; i < broj; i++)
	{
		if (Prost(i) == true)
		{
			for (int j = 1; j < broj; j++)
			{
				if (Prost(j) == true && (i + j) == broj)
				{
					cout << broj << "=" << i << "+" << j << endl;
					return;
				}
			}
		}
	}
}
void GoldBach(int n1, int n2) {
	for (int i = n1; i <= n2; i++)
	{
		if (i % 2 == 0)
			RastaviBroj(i);
	}
}
int main()
{
	int n1, n2;
	do {
		cout << "unesite granice intervala" << endl;
		cin >> n1 >> n2;
	} while (n1 < 1 || n2 < 1 || n2 <= n1);
	GoldBach(n1, n2);
	return 0;
}
