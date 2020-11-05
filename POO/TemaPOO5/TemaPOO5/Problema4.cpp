#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Lista;

class Magazin
{
	string producator;

	float pret;
	float rezolutie;

	bool tip_aparat;

	Magazin* next;

public:
	Magazin(string producator, float pret, float rezolutie, bool tip_aparat)
	{
		this->pret = pret;
		this->producator = producator;
		this->rezolutie = rezolutie;
		this->tip_aparat = tip_aparat;
		next = NULL;
	}

	virtual void afisare()
	{
		cout << endl;
		cout << "Pretul: " << pret << endl;
		cout << "Producatorul: " << producator << endl;
		cout << "Diagonala: " << rezolutie << endl;
	}

	friend class Lista;
};

class Rama_Foto : public Magazin
{
	string format;

	float diagonala;

public:
	Rama_Foto(string producator, float pret, float rezolutie, bool tip_aparat,
			  string format, float diagonala) : Magazin(producator, pret, rezolutie, tip_aparat)
	{
		this->diagonala = diagonala;
		this->format = format;
	}

	virtual void afisare()
	{
		Magazin::afisare();
		cout << "Format: " << format << endl;
		cout << "Diagonala: " << diagonala << endl;
	}
	
	friend class Lista;
};

class Aparat_Foto : public Magazin
{
	string tip_senzor;

	bool tip;

public:
	Aparat_Foto(string producator, float pret, float rezolutie, bool tip_aparat,
		string tip_senzor, float tip) : Magazin(producator, pret, rezolutie, tip_aparat)
	{
		this->tip_senzor = tip_senzor;
		this->tip = tip;
	}

	virtual void afisare()
	{
		Magazin::afisare();
		cout << "Tip Senzor: " << tip_senzor << endl;
		cout << "Tip aparat: ";

		if (tip == false)
		{
			cout << "compact" << endl;
		}
		else
		{
			cout << "D-SLR" << endl;
		}
	}

	friend class Lista;
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

		else{
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
	string format_afisare;
	string tip_senzor;

	float diagonala;
	float rezolutie;
	float pret;

	bool tip_aparat;

	Magazin* mag;

	cout << "Producator: "; cin >> producator;
	cout << "Pret: "; cin >> pret;
	cout << "Rezolutie: "; cin >> rezolutie;

	if (x == false)
	{
		Rama_Foto* Rf;
		cout << "Diagonala: "; cin >> diagonala;
		cout << "Format afisare: "; cin >> format_afisare;

		Rf = new Rama_Foto(producator, pret, rezolutie, false, format_afisare, diagonala);
		mag = Rf;
		l.adaugare(mag);
	}

	else if (x == true)
	{
		Aparat_Foto* Af;
		cout << "Tip aparat(0 - compact; 1 - D-SLR): "; cin >> tip_aparat;
		cout << "Tip senzor: "; cin >> tip_senzor;

		Af = new Aparat_Foto(producator, pret, rezolutie, true, tip_senzor, tip_aparat);
		mag = Af;
		l.adaugare(mag);
	}
}

void main()
{
	unsigned short optiune = 0;

	Lista l;
	l.head = NULL;

	do
	{
		system("CLS");

		cout << "1. Adaugare rama foto." << endl;
		cout << "2. Adaugare aparat foto." << endl;
		cout << "3. Afisare rame foto." << endl;
		cout << "4. Afisare aparat foto." << endl;
		cout << "5. Iesire." << endl;

		cout << " Optiunea dumneavosatra este: "; cin >> optiune;

		switch (optiune)
		{
		case 1: introducere(l, false); break;
		case 2: introducere(l, true); break;
		case 3: l.afisare_Lista(false); _getch(); break;
		case 4: l.afisare_Lista(true); _getch(); break;
		case 5: exit(0);
		}
	} while (true);
}