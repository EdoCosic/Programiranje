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

int main()
{
	cout << Prost(17);



	system("pause>0");
	return 0;
}
