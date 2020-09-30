#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class Persoana
{
	string nume;
	string prenume;
	unsigned short varsta;

public:
	Persoana();
	Persoana(string n, string p, unsigned short v);
	void afisare(void)
	{
		cout << nume << endl;
		cout << prenume << endl;
		cout << varsta << endl;
	}
	~Persoana();
};

Persoana::Persoana(string n, string p, unsigned short v)
{
	nume = n;
	prenume = p;
	varsta = v;
}

Persoana::~Persoana()
{
	cout << "S-a apelat destructorul!" << endl;
}

int main()
{
	string nume1, prenume1;
	unsigned short varsta1;

	cout << "Nume1: "; getline(cin, nume1);
	cout << "Prenume1: "; getline(cin, prenume1);
	cout << "Varsta1: "; cin >> varsta1;

	Persoana p(nume1, prenume1, varsta1);
	p.afisare();

	Persoana p1("Ionescu", "Dan", 30);
	Persoana p2("Popescu", "Ionut", 40);
	Persoana p3("Ionescu", "Maria", 26);

	p1.afisare();
	p2.afisare();
	p3.afisare();

	_getch();
	return 0;
}