#include <iostream>
#include<conio.h>

using namespace std;

class Dreptunghi
{
	unsigned latime;
	unsigned lungime;
public:

	Dreptunghi(unsigned, unsigned);

	int calcul_arie(void)
	{

		return (latime * lungime);
	}
};

Dreptunghi::Dreptunghi(unsigned a, unsigned b)
{
	latime = a;
	lungime = b;
}

int main()
{

	Dreptunghi drepta(10, 11);

	Dreptunghi dreptb(7, 9);

	cout << "Aria primului dreptunghi este: " << drepta.calcul_arie() << endl;
	cout << "Aria celui de-al doilea dreptunghi este: " << dreptb.calcul_arie() << endl;

	_getch();
	return 0;
}