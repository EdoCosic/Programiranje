#include <iostream>
using namespace std;

int main()
{
	int N;
	cout << "Unesite cijeli broj N" << endl;
	cin >> N;
	int p = 1;
	int brojac = 0;
	for (int i = 1; i <= N; i++)
	{
		if (i % 2 != 0 && i % 5 == 0) {
			p *= i;
			brojac++;
		}
	}
	cout << "Geom sredina: " << pow(p, 1.0 / brojac) << endl;
	system("pause>0");
	return 0;
}
