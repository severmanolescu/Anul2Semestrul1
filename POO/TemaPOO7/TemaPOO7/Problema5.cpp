#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

class Lista;

class Magazin {
	bool tip_aparat;

	string producator;

	double pret;

	Magazin* next;

public:
	Magazin(string producator, double pret, bool tip_aparat)
	{
		this->producator = producator;
		this->pret = pret;
		this->tip_aparat = tip_aparat;
	}

	virtual void afisare()
	{
		cout << endl;
		cout << "Producator: " << producator << endl;
		cout << "Pret: " << pret << endl;
	}

	friend class Lista;
};

class Masina_Spalat : public Magazin 
{
	unsigned short numar_programe;

public:
	Masina_Spalat(string producator, double pret, bool tip_aparat, unsigned short numar_programe) : Magazin(producator, pret, tip_aparat)
	{
		this->numar_programe = numar_programe;
	}

	virtual void afisare()
	{
		Magazin::afisare();
		cout << "Numar programe: " << numar_programe << endl;
	}

	friend class Lista;
};

class Aragaz : public Magazin
{
	string tip_arzatoare;

public:
	Aragaz(string producator, double pret, bool tip_aparat, string tip_arzatoare) : Magazin(producator, pret, tip_aparat)
	{
		this->tip_arzatoare = tip_arzatoare;
	}

	virtual void afisare()
	{
		Magazin::afisare();
		cout << "Tip arzatoare: " << tip_arzatoare << endl;
	}

	friend class Lista;
};

class MyException {
public:
	string str_what;

	int what;

	MyException()
	{ 
		str_what = '\0';
		what = 0; 
	}

	MyException(string str_what, int what)
	{
		this->str_what = str_what;
		this->what = what;
	}
};

class Lista
{
public:
	Magazin* head;

	void adaugare(Magazin* aux);

	void afisare_Lista(bool tip);
};

void Lista::adaugare(Magazin* aux)
{
	Magazin* p = head;

	if (p)
	{
		if (aux->producator == p->producator)
		{
			aux->next = head;
			head = aux;
		}

		else {
			while (p->next && (p->next)->producator == aux->producator)
			{
				p = p->next;
			}

			aux->next = p->next;
			p->next = aux;
		}
	}

	else {
		head = aux;
	}
}

void Lista::afisare_Lista(bool tip)
{
	Magazin* p = head;

	if (!p)
	{
		cout << "Lista vida!" << endl;
	}

	else
	{
		while (p)
		{
			if (p->tip_aparat == tip)
			{
				p->afisare();
			}

			p = p->next;
		}
	}

}

void introducere(Lista& l, bool x)
{
	string producator;
	string tip_arzatoare;

	float pret;

	bool tip_aparat;

	unsigned short numar_programe;

	Magazin* mag;

	cout << "Producator: "; cin >> producator;
	cout << "Pret: "; cin >> pret;

	if (x == false)
	{
		Masina_Spalat* ms;
		cout << "Numar programe: "; cin >> numar_programe;

		ms = new Masina_Spalat(producator, pret, false, numar_programe);

		mag = ms;

		l.adaugare(mag);
	}

	else if (x == true)
	{
		Aragaz* ar;
		cout << "Tip arzatoare: "; cin >> tip_arzatoare;

		ar = new Aragaz(producator, pret, true, tip_arzatoare);

		mag = ar;

		l.adaugare(mag);
	}
}

int main()
{
	unsigned short optiune = 0;

	Lista l;
	l.head = NULL;

	ifstream fin("date.txt", ifstream::in);

	while (true)
	{
		cout << "1. Citire informatii dintr-un fisier." << endl;
		cout << "2. Adaugare masina spalat sau aragaz" << endl;
		cout << "3. Afisare electrocasnice." << endl;
		cout << "4. Cautare aragaz dupa tipul arzatoarei." << endl;
		cout << "5. Salvare carte de telefoane in fisier" << endl;
		cout << "6. Iesire." << endl;

		cout << "Optiunea dumneavoastra este: "; cin >> optiune;

		switch (optiune)
		{
		case 1: 
			while (!fin.eof())
			{
				fin >>
			}

		default:
			break;
		} 

	}
}