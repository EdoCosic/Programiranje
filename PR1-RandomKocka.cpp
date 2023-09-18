#include <iostream>
using namespace std;

int main()
{
	int n;
	do {
		cout << "Unesite n" << endl;
		cin >> n;
	} while (n < 10 || n>1000);
	int brojac1 = 0;
	int brojac2 = 0;
	int brojac3 = 0;
	int brojac4 = 0;
	int brojac5 = 0;
	int brojac6 = 0;

	for (int i = 0; i < n; i++)
	{
		int bacanje = rand() % 6 + 1;
		switch (bacanje)
		{
		case 1:
			brojac1++;
			break;
		case 2:
			brojac2++;
			break;
		case 3:
			brojac3++;
			break;
		case 4:
			brojac4++;
			break;
		case 5:
			brojac5++;
			break;
		case 6:
			brojac6++;
			break;
		default:
			break;
		}
	}
	cout << "Broj 1: " << brojac1 * 100.0 / n << "%" << endl;
	cout << "Broj 2: " << brojac2 * 100.0 / n << "%" << endl;
	cout << "Broj 3: " << brojac3 * 100.0 / n << "%" << endl;
	cout << "Broj 4: " << brojac4 * 100.0 / n << "%" << endl;
	cout << "Broj 5: " << brojac5 * 100.0 / n << "%" << endl;
	cout << "Broj 6: " << brojac6 * 100.0 / n << "%" << endl;


	system("pause>0");
	return 0;
}
