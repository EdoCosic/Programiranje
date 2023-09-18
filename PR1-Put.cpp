1.
#include <iostream>
using namespace std;

int main()
{
	const float g = 9.81;
	for (int i = 3; i <= 60; i += 3)
	{
		cout << "Situacija u " << i << ". sekundi" << endl;
		cout << "Brzina: " << g * i << endl;
		cout << "Predjeni put: " << g / 2 * pow(i, 2) << endl;
	}
	system("pause>0");
	return 0;
}
