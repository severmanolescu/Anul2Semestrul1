#include <iostream>
#include <conio.h>

using namespace std;

void negativ(int& i)
{
	i = -i;
}
int main()
{
	int valoare;

	cout << "Dati valoarea: "; cin >> valoare;

	negativ(valoare);
	cout << "Valoarea negativa este: " << valoare;

	_getch();
	return 0;
}