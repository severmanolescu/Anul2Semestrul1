#include <iostream>
#include <conio.h>

using namespace std;

class Dreptunghi {
	int latime, lungime;

public:
	void setari_valori(int, int); 
	int aria(void)
	{
		return (latime * lungime);
	}
};

void Dreptunghi::setari_valori(int a, int b)
{
	latime = a;
	lungime = b;
}

int main()
{
	Dreptunghi a, * b, * c;
	Dreptunghi* d = new Dreptunghi[2];

	a.setari_valori(1, 2);
	c = &a;
	b = new Dreptunghi;

	b->setari_valori(3, 4);
	d->setari_valori(5, 6);
	d[1].setari_valori(7, 8);
	
	cout << "a aria: " << a.aria() << endl;
	cout << "*b aria: " << b->aria() << endl;
	cout << "*c aria: " << c->aria() << endl;
	cout << "d[0] aria: " << d[0].aria() << endl;
	cout << "d[1] aria: " << d[1].aria() << endl;

	_getch();
	return 0;
}