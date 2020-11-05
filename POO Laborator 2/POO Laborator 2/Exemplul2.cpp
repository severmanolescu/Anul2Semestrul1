#include <iostream>
#include<conio.h>

using namespace std;

class Dreptunghi {

	int* latime;
	int* lungime;
public:

	Dreptunghi(int, int);
	~Dreptunghi();
	int calcul_arie(void);
};

int Dreptunghi::calcul_arie(void)
{
	return (*latime * *lungime);
}

Dreptunghi::Dreptunghi(int a, int b)
{
	latime = new int;
	lungime = new int;
	*latime = a;
	*lungime = b;
}

Dreptunghi::~Dreptunghi()
{

	delete latime;
	delete lungime;
	printf("\nAm eliberat memoria!\n");
}

int main()
{
	Dreptunghi drept1(3, 4);
	Dreptunghi drept2(5, 6);

	cout << "Aria primului dreptunghi este: " << drept1.calcul_arie() << endl;
	cout << "Aria celui de-al doilea dreptunghi este: " << drept2.calcul_arie() << endl;

	drept1.~Dreptunghi();
	drept2.~Dreptunghi();

	_getch();
	return 0;
}