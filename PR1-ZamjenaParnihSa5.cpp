#include <iostream>
using namespace std;

/*
Napisati program koji omogucava unos pozitivnog broja n te pronalazi njegove parne cifre i formira novi broj u
kojem su parne cifre zamjenjene cifrom 5
Dodatno program treba ispisati razliku unesenog i broja koji se dobije nakon zamjene cifara
*/

int zamjenaCifara(int);

int main()
{
	int zamjenjenBroj;
	int n;
	do
	{
		cout << "Unesite prirodan broj" << endl;
		cin >> n;
	} while (n < 1);
	zamjenjenBroj = zamjenaCifara(n);
	cout << zamjenjenBroj << "-" << n << "=" << zamjenjenBroj - n << endl;

	system("pause>0");
	return 0;
}

int zamjenaCifara(int br)
{
	//123 --> 153
	int novi = 0;
	int temp = 0;
	int potencija = 0;
	while (br > 0)
	{
		temp = br % 10;
		if (temp % 2 == 0)
		{
			novi += 5 * pow(10, potencija);
		}
		else
		{
			novi += temp * pow(10, potencija);
		}
		br /= 10;
		potencija++;
	}
	return novi;
}
