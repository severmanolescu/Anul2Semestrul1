#include <iostream>
#include <conio.h>

using namespace std;

class Dreptunghi
{
	unsigned short lungime;
	unsigned short latime;
	
public:
	void setare_valori(unsigned short, unsigned short);
	int aria(void);
};

void Dreptunghi::setare_valori(unsigned short a, unsigned short b)
{
	lungime = a;
	latime = b;
}

int Dreptunghi::aria(void)
{
	return (lungime * latime);
}
int main()
{
	Dreptunghi drept;

	drept.setare_valori(3, 8);

	cout << "Aria este: " << drept.aria();

	_getch();
	return 0;
}