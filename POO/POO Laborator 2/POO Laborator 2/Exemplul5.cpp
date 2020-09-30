#include <iostream>
#include <conio.h>

using namespace std;

class Dreptunghi {
	unsigned lungime;
	unsigned latime;

public:
	Dreptunghi();
	Dreptunghi(unsigned, unsigned);

	int aria(void)
	{
		return (latime * lungime);
	}
};

Dreptunghi::Dreptunghi()
{
	latime = 5;
	lungime = 5;
}

Dreptunghi::Dreptunghi(unsigned a, unsigned b)
{
	latime = a;
	lungime = b;
}

int main()
{
	Dreptunghi drept(14, 19);
	Dreptunghi dreptb;

	cout << "Aria dreptunghi : " << drept.aria() << endl;
	cout << "Aria dreptunghi b: " << dreptb.aria() << endl;

	_getch();
	return 0;
}