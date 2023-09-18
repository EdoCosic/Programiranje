#include <iostream>
using namespace std;
int PronadjiM(int n) {
	int minM = INT_MAX;
	for (int k = 2; k < n; k++)
	{
		for (int l = 2; l < n; l++)
		{
			int m = pow(k, l);
			if (m >= n && m <= minM)
				minM = m;
		}
	}
	return minM;
}

int main()
{
	int n;
	do {
		cout << "Unesite prirodni broj" << endl;
		cin >> n;
	} while (n < 1);
	cout << "To je broj: " << PronadjiM(n);
	system("pause>0");
	return 0;
}
