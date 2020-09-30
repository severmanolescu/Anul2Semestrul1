#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class Carte
{
	string titlu;
	string nume_autori;
	string editura;
	unsigned short an_publicare;

public:
	Carte();
	Carte(string titlu_c, string nume_autori_c, string editura_s, unsigned short an_publicatie_s);
	inline void afisare();
};

Carte::Carte(string titlu_c, string nume_autori_c, string editura_s, unsigned short an_publicatie_s)
{
	titlu = titlu_c;
	nume_autori = nume_autori_c;
	editura = editura_s;
	an_publicare = an_publicatie_s;
}

inline void Carte::afisare(void)
{
	cout << "Titlul cartii este: " << titlu << endl
	     << "Editura cartii este: " << editura << endl
	     << "Numele autorilor cartii este: " << nume_autori << endl
	     << "Anul publicatiei cartii este: " << an_publicare << endl;
}

int main()
{
	string titlu;
	string editura;
	string nume_autori;
	unsigned short an_publicatie = 0;

	cout << " Titlul cartii este: ";           cin >> titlu;
	cout << " Editura cartii este: ";          cin >> editura;
	cout << " Autorii cartii este: ";          cin >> nume_autori;
	cout << " Anul publicatiei cartii este: "; cin >> an_publicatie;
	cout << endl;

	Carte carti(titlu, editura, nume_autori, an_publicatie);
	carti.afisare();
	
	_getch();
	return 0;
}