#include <iostream>
#include <stdio.h>
#include <string>

#define ushort unsigned short

using namespace std;

class Lista;

class Articole
{
	ushort tip_articol;
	
	string producator;
	string denumire;

	Articole* next;

public:
	Articole(ushort tip_articol, string producator, string denumire)
	{
		this->tip_articol = tip_articol;
		this->producator = producator;
		this->denumire = denumire;
		this->next = NULL;
	}

	virtual void afisare()
	{
		cout << endl;
		cout << "Producator: " << producator << endl;
		cout << "Denumire: " << denumire << endl;
	}

	friend class Lista;
};

class Creioane : public Articole
{
	string tip_mina;

public:
	Creioane(ushort tip_articol, string producator, string denumire, string tip_mina) : Articole(tip_articol, producator, denumire)
	{
		this->tip_mina = tip_mina;
	}

	virtual void afisare()
	{
		Articole::afisare();
		cout << "Tip mina: " << tip_mina << endl;
	}

	friend class Lista;
};

class Pixuri : public Articole
{
	string culoare;

public:
	Pixuri(ushort tip_articol, string producator, string denumire, string culoare) : Articole(tip_articol, producator, denumire)
	{
		this->culoare = culoare;
	}

	virtual void afisare()
	{
		Articole::afisare();
		cout << "Culoare: " << culoare << endl;
	}

	friend class Lista;
};

class Lista
{
public:
	Articole* head;
	void adaugare(Articole* aux);
	void afisare(ushort tip);
};

void Lista::adaugare(Articole* aux)
{
	Articole* p = head;

	if (p)
	{
		if (aux->producator == p->producator)
		{
			aux->next = p;
			head = aux;
		}
		
		else
		{
			while (p->next && (p->next)->producator == aux->producator)
				p = p->next;

			aux->next = p->next;
			p->next = aux;
		}
	}
	else
	{
		head = aux;
	}
}

void Lista::afisare(ushort tip)
{
	Articole* p = head;

	if (p == NULL)
	{
		cout << "Lista vida!";
	}

	else while (p != NULL)
	{
		if (p->tip_articol == tip)
		{
			p->afisare();
		}
		p = p->next;
	}
}

class Supraincarcare
{
	string producator;
	string denumire;

public:
	friend ostream& operator<<(ostream& out, Supraincarcare& p);
	friend istream& operator>>(istream& in, Supraincarcare& p);

	string get_producator()
	{
		return producator;
	}

	string get_denumire()
	{
		return denumire;
	}
};

ostream& operator<<(ostream& out, Supraincarcare& p)
{
	cout << "Efectuare citire!" << endl;

	return out;
}

istream& operator>>(istream& in, Supraincarcare& p)
{
	cin.get();
	
	cout << "Dati producatorul: "; getline(cin, p.producator);
	cout << "Dati denumirea: "; getline(cin, p.denumire);

	return in;
}

void introducere(Lista& l, bool x)
{
	string tip_mina;
	string culoare;

	Articole* art;

	Supraincarcare supr;
	cout << supr;
	cin >> supr;

	if (x == false)
	{
		Creioane* creion;

		cout << "Tip mina: "; getline(cin, tip_mina);
		
		creion = new Creioane(1, supr.get_producator(), supr.get_denumire(), tip_mina);
		
		art = creion;
		
		l.adaugare(art);
	}

	else
	{
		Pixuri* pix;

		cout << "Culoare: "; getline(cin, culoare);

		pix = new Pixuri(2, supr.get_producator(), supr.get_denumire(), culoare);

		art = pix;

		l.adaugare(art);
	}

}

int main()
{
	ushort alegere;

	Lista l;
	l.head = NULL;

	while (true)
	{
		cout << endl;
		cout << "1. Adaugare creioane." << endl;
		cout << "2. Adaugare pixuri." << endl;
		cout << "3. Afisare creioane." << endl;
		cout << "4. Afisare pixuri." << endl;
		cout << "5. Iesire" << endl;

		cout << "Alegerea dumneavoastra este: "; cin >> alegere;

		switch (alegere)
		{
		case 1: introducere(l, false); break;
		case 2: introducere(l, true); break;
		case 3: l.afisare(1); break;
		case 4: l.afisare(2); break;
		case 5: exit(0);
		}
	}
}