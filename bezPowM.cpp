#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int rekuzivna(int temp, int n, int k)
{
	if (temp >= n)
	{
		return temp;
	}
	temp *= k;
	rekuzivna(temp, n, k);
}

int NajManjiM(int n)
{
	int minM = INT_MAX;
	for (int k = 2; k < n; k++)
	{
		for (int l = 2; l < n; l++)
		{
			int temp = k;
			int m = rekuzivna(temp, n, k);
			if (m >= n && m <= minM)
			{
				minM = m;
			}
		}
	}
	return minM;
}

int main()
{

	int n;
	do
	{
		cout << "Unesite prirodan broj" << endl;
		cin >> n;
	} while (n < 1);

	cout << "Broj je: " << NajManjiM(n);

	system("pause>0");
	return 0;
}
