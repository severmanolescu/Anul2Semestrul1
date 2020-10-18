#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct arbore {
	unsigned int parinte;
    long cheie;
	bool radacina; // Variabila folosita pentru indentidicarea radacii
}arbore;

unsigned long contor = 1;
unsigned long numere;
unsigned long au1; // numar folost pe post de auxiliar pentru suprimare

FILE* out; // Fisierul unde o sa se execute scrierea pentru functiile recursive

unsigned short* afisate; // pointer-ul o sa fie initializat intr-un vector pentru a tine seama nodurilor afisate

unsigned Tata(arbore arb[], unsigned long n)
{
	unsigned long index = 0;

	for (index = 1; index < numere; index++)
	{
		if (arb[index].cheie == n)
		{
			return arb[index].parinte; // Returneaza numarul nodului al tatului nodului dat ca parametru
		}
	}

	return 0; // Returneaza 0 daca nodul nu are un parinte, daca acesta este radacina
}

unsigned long PrimulFiu(arbore arb[], unsigned long n)
{
	unsigned long index = 0;

	for (index = 2; index <= numere; index++)
	{
		if (arb[index].parinte == n && arb[index].cheie != -1) // Verifica daca nodul curent are tatal egal cu valoarea data, 
		{													   //dar si daca acest nod a fost sters din arbore sau nu
			return index;
		}
	}

	return 0; // Returneaza 0 daca nodul nu are un fiu, adica acesta este o frunza
}

unsigned long FrateDreapta(arbore arb[], unsigned long n)
{
	unsigned long index = 0;
	unsigned long index1 = 0;

	for (index = 2; index < numere; index++) // parcuge arborele pana gaseste pozitia cheii in arbore
	{
		if (arb[index].cheie == n)
		{
			break;
		}
	}

	for (index1 = index + 1; index1 < numere; index1++)
	{
		if (arb[index1].parinte == arb[index].parinte && arb[index].cheie != -1) // Verifica daca cele noua noduri au acelasi tata
		{																		 //si daca nodul este sters sau nu din arbore 
			return index1;
		}
	}

	return 0; // Returneaza 0 daca nodul nu are un frate
}

unsigned long Cheie(arbore arb[], unsigned long n)
{
	return arb[n].cheie; // Returneaza cheia nodului dat ca parametru
}

long Radacina(arbore arb[])
{
	unsigned long index = 0;
	unsigned short nod = 0; // Variabila in care se vor stoca numarul nodurilor sunt "radacini"

	bool ok = true;

	for (index = 1; index < numere; index++)
	{
		if (arb[index].radacina == true)
		{
			nod++;
		}
	}

	if (nod == 1) // Daca exista doar o radacina returneaza cheia acesteia
		return arb[1].cheie;

	return -1; // Daca cumva exista mai multe multe noduri "radacina" sau daca nu exista inca o radacina retuneaza valoare 0
}

void initializeaza(arbore arb[])
{
	unsigned long index = 0;

	for (index = 0; index < numere; index++) // Parcurgerea fiecarui nod din arbore si initializarea lor cu valoarile implicite
	{
		arb[index].cheie = 0;
		arb[index].parinte = 0;
		arb[index].radacina = false;

		afisate[index] = 0;
	}
}

void insereaza(arbore arb[], unsigned long cheie, int tata)
{
	unsigned long index = 0;

	for (index = 0; index < numere; index++) // Parcurge nod pana la intalnirea nodului care ii este dat ca tata
	{
		if (arb[index].cheie == tata)
		{
			break;
		}
	}

	if (tata == -1) // Daca valoare data prin parametrul tata este -1, se considera ca nodule ste radacina
	{
		arb[contor].radacina = true; 
	}

	arb[contor].cheie = cheie;  // Inserarea nodului la finalul arborelui 
	arb[contor].parinte = index;//cu tatal gasit prin valoarea index
	contor++; // Indexarea valorii contor pentru a stii mereu pozitia la care ne aflam la inserarea nodurilor in arbore
}

void inordine(arbore arb[], unsigned long n) // Functie recursiva pentru afisarea arborelui in inordine
{
	unsigned aux1 = 0;
	unsigned aux2 = 0;

	if (n > 0) // Cat timp valaore n este mai amre decat 0, adica cat timp n poate reprezenta un nod din arbore
	{
		inordine(arb, PrimulFiu(arb, n)); // Apelam functia pentru primul fiu al nodului curent 
		
		if (!afisate[n] && Cheie(arb, n) != -1) // Verificare daca nodul nu a fost sters sau daca acesta nu a fost deja afisat
		{
			fprintf(out, "%lu ", Cheie(arb, n));
			afisate[n] = 1;
		}

		aux1 = FrateDreapta(arb, Cheie(arb, PrimulFiu(arb, n))); // Initializam pe aux1 cu fratele de dreapta
		aux2 = FrateDreapta(arb, Cheie(arb, aux1));				 //al primului fiu al nodului curent, iar pe aux2
																 //cu fratele de dreapta al nodului aux1

		while (aux1 || aux2) // Cat timp cele doua noduri corespunzatoare valorilor aux1 si aux2 mai au descendenti sau mostenitori
		{
			if (aux1)
				inordine(arb, aux1);

			if (aux2)
				inordine(arb, aux2);

			aux1 = PrimulFiu(arb, aux1);
			aux2 = FrateDreapta(arb, Cheie(arb,aux2));
		}

	}
}

void preordine(arbore arb[], unsigned long n) // Functie recursiva pentru afisarea arborelui in preorine
{
	unsigned aux1 = 0; // Variabile auxilaire pentru usurarea muncii
	unsigned aux2 = 0;

	if (n > 0) // Cat timp valaore n este mai amre decat 0, adica cat timp n poate reprezenta un nod din arbore
	{
		if (!afisate[n] && Cheie(arb, n) != -1) // Verificare daca nodul nu a fost sters sau daca acesta nu a fost deja afisat
		{
			fprintf(out, "%lu ", Cheie(arb, n));
			afisate[n] = 1;
		}

		preordine(arb, PrimulFiu(arb, n)); // Apelam functia pentru primul fiu al nodului curent 

		aux1 = FrateDreapta(arb, Cheie(arb, PrimulFiu(arb, n))); // Initializam pe aux1 cu fratele de dreapta 
		aux2 = FrateDreapta(arb, Cheie(arb, aux1));				 //al primului fiu al nodului curent, iar pe aux2 
		                                                         //cu fratele de dreapta al nodului aux1

		while (aux1 || aux2) // Cat timp cele doua noduri corespunzatoare valorilor aux1 si aux2 mai au descendenti sau mostenitori
		{
			if (aux1)
				preordine(arb, aux1);

			if (aux2)
				preordine(arb, aux2);

			aux1 = PrimulFiu(arb, aux1);
			aux2 = FrateDreapta(arb, Cheie(arb, aux2));
		}

	}
}

void postordine(arbore arb[], unsigned long n) // Functie recursiva pentru afisarea arborelui in postordine
{
	unsigned aux1 = 0;
	unsigned aux2 = 0;

	if (n > 0) // Cat timp valaore n este mai amre decat 0, adica cat timp n poate reprezenta un nod din arbore
	{
		postordine(arb, PrimulFiu(arb, n)); // Apelam functia pentru primul fiu al nodului curent 

		aux1 = FrateDreapta(arb, Cheie(arb, PrimulFiu(arb, n))); // Initializam pe aux1 cu fratele de dreapta
		aux2 = FrateDreapta(arb, Cheie(arb, aux1));			     //al primului fiu al nodului curent, iar pe aux2
															     //cu fratele de dreapta al nodului aux1

		while (aux1 || aux2) // Cat timp cele doua noduri corespunzatoare valorilor aux1 si aux2 mai au descendenti sau mostenitori
		{
			if (aux1)
				postordine(arb, aux1);

			if (aux2)
				postordine(arb, aux2);

			aux1 = PrimulFiu(arb, aux1);
			aux2 = FrateDreapta(arb, Cheie(arb, aux2));
		}

		if (!afisate[n] && Cheie(arb, n) != -1) // Verificare daca nodul nu a fost sters sau daca acesta nu a fost deja afisat
		{
			fprintf(out, "%lu ", Cheie(arb, n));
			afisate[n] = 1;
		}

	}
}

void suprimare(arbore arb[], unsigned long n)
{
	if (n > 0) // Cat timp valaore n este mai amre decat 0, adica cat timp n poate reprezenta un nod din arbore
    {
		suprimare(arb, PrimulFiu(arb, n)); // Apelam functia pentru primul fiu al nodului n

		if (n != au1) // Daca n este egal cu valoare nodului dat pentru suprimare, codul nu va trece la fratele lui de dreapta
		{			  //pentru nu a sterge si alte noduri care nu sunt necesare
			suprimare(arb, FrateDreapta(arb, Cheie(arb, n)));
		}

		arb[n].cheie = -1; // Valoarea -1 corespunzatoare nodurilor sterse
	}
}

int main()
{
	unsigned long auxiliar = 0; // Nod auxiliar folosti atat pentru citirea din fisier atat si pentru citirea valoarilor pentur meniul interactiv
	unsigned long index = 0;
	unsigned long tata = 1; // Variabila care va seta tatal fiecarui nod

	unsigned short s = 1; // Variabila care va oferii fiecarui nod cate 5 fii

	int alegere = 1; // Variabila folosita pentru meniul interactiv
	int rad = 0; // Variabila folosita pentru afisarea radacinii arborelui

	double procent = 0;  // Variabila folosita pentru afisare procentului la care a ajuns citirea 
	double procent1 = 1; // Vabila folosita drept auxiliar pentru procent, deoarece nu dorim sa afiseze foarte des la ce procent a ajuns

	char c = '%';    // Variabila folosita pentru afisarea procentuli
	char fisier[20]; // Variabila folosita pentru stocarea numelui fisierului de unde o sa se execute citirea

	bool radacina = false; // Variabila folosita pentru a identifica daca radacina a fost initializata sau nu

	struct arbore* arb;

	FILE* input;

	printf("Dati numele fisieului de unde doriti sa se faca citirea: ");
	if (scanf("%s", fisier) != 1) // Verificare daca citirea numelui fisierului a avut loc cu succes
	{
		perror("scanf"); // Afisare un mesaj in caz de esec
		return -1;
	}

	fisier[strlen(fisier)] = 0;

	if ((input = fopen(fisier, "rb")) == NULL) // Deschiderea fisierului binar pentru citire
	{
		perror("fopen"); // Afisare un mesja de eroare in cazul in care nu s-a putut efectua deschiderea
		return -1;
	}

	if ((out = fopen("DATA.OUT", "w")) == NULL) // Deschiderea fisierului pentru scriere
	{
		perror("fopen"); // Afisare un mesja de eroare in cazul in care nu s-a putut efectua deschiderea
		exit(-1);
	}

	fseek(input, 0, SEEK_END);
	numere = ftell(input) / sizeof(unsigned); // Identificarea nuamrului de variabile de tip unsigned din fisier
	fseek(input, 0, SEEK_SET); // SEtam pointerul din fisier la inceput

	numere++;

	if ((arb = (arbore*)malloc(sizeof(struct arbore) * (numere + 2))) == NULL)
	{
		perror("malloc");
		return -1;
	}

	if ((afisate = (unsigned short*)malloc(sizeof(unsigned short) * (numere + 2))) == NULL)
	{
		perror("malloc");
		return -1;
	}

	initializeaza(arb); // Apelare functiei de afisare

	for (index = 0; index < numere; index++)
	{
		fread(&auxiliar, sizeof(unsigned long), 1, input); // Citirea numarului din fisierul binar

		alegere = index + 1;

		procent = (float)(alegere) / (numere * 1.0) * 100.0; // Indentificarea procentului

		if (procent != procent1)
		{
			printf("Citire si initializare: %.2f %c \n", procent, c);

			procent1 = procent;
		}

		if (radacina == false) // Daca radacina nu a fost inca initializata
		{
			arb[1].cheie = auxiliar;
			arb[1].parinte = 0;
			arb[1].radacina = true;
			contor++;
			radacina = true;
		}

		else if (s < 5) // Daca nodul salvat in variabila tata are mai putin de 5 fii
		{
			insereaza(arb, auxiliar, arb[tata].cheie);
			s++; // Incrementam numarul de fii ai nodului tata
		}

		else // Daca tata are 5 fii
		{
			insereaza(arb, auxiliar, arb[tata].cheie);
			s = 1;
			tata++;
		}
	}

	printf("\nCitirea si initializarea a avut loc cu succes! \n\n");

	while (alegere)
	{
		printf("1. Scrierea in fisier in inordine.\n");
		printf("2. Scrierea in fisier in preordine.\n");
		printf("3. Scrierea in fisier in postordine.\n");
		printf("4. Afisarea tatalui unui nod.\n");
		printf("5. Afisarea primului fiu al unui nod.\n");
		printf("6. Afisarea frate de dreapta al unui nod.\n");
		printf("7. Afisarea cheii unui nod.\n");
		printf("8. Afisarea nodului care este radacina.\n");
		printf("9. Suprimarea unui nod.\n");
		printf("0. Iesire.\n");

		printf("Alegerea dumneavoastra este: ");
		if (scanf("%d", &alegere) != 1)
		{
			perror("scanf");
		}

		switch (alegere)
		{
		case 1: printf("\nScriere in fisierul DATA.OUT parcurgerea in inordine...");

			inordine(arb, 1);

			printf("\nScriere in fisierul DATA.OUT parcurgerea in inordine executata cu succes\n\n");

			fprintf(out, "\n");
			break;

		case 2: printf("\nScriere in fisierul DATA.OUT parcurgerea in preordine...");

			preordine(arb, 1);

			printf("\nScriere in fisierul DATA.OUT parcurgerea in preordine executata cu succes\n\n");

			fprintf(out, "\n");
			break;

		case 3: printf("\nScriere in fisierul DATA.OUT parcurgerea in postordine...");

			postordine(arb, 1);

			printf("\nScriere in fisierul DATA.OUT parcurgerea in postordine executata cu succes\n\n");

			fprintf(out, "\n");
			break;

		case 4: printf("\nDati cheia nodul: ");

			if (scanf("%lu", &auxiliar) != 1)
			{
				perror("scanf");
			}

			if (auxiliar > numere)
			{
				printf("Nodul nu apartine arborelui!\n\n");
			}

			index = Tata(arb, Cheie(arb, auxiliar));
			if (index > 0)
			{
				printf("Tatal nodului cu cheia %lu este nodul %lu cu cheia %lu.\n\n", auxiliar, index, Cheie(arb, index));
			}

			else if (index == -1)
			{
				printf("Nodul a fost sters din arbore!\n\n");
			}

			else
			{
				printf("Nodul este radacina sau arborele nu a fost initializat!\n\n");
			}
			break;

		case 5:printf("\nDati nodul: ");

			if (scanf("%lu", &auxiliar) != 1)
			{
				perror("scanf");
			}

			if (auxiliar > numere)
			{
				printf("Nodul nu apartine arborelui!\n\n");
			}

			index = PrimulFiu(arb, auxiliar);

			if (index > 0)
			{
				printf("Primul fiu al nodului %lu este  nodul %lu cu cheia %lu.\n\n", auxiliar, index, Cheie(arb, index));
			}

			else if (index == -1)
			{
				printf("Nodul a fost sters din arbore!\n\n");
			}

			else
			{
				printf("Nodul este o frunza!\n\n");
			}
			break;

		case 6: printf("\nDati nodul: ");

				if (scanf("%lu", &auxiliar) != 1)
				{
					perror("scanf");
				}

				if (auxiliar > numere)
				{
					printf("Nodul nu apartine arborelui!\n\n");
				}

				index = FrateDreapta(arb, Cheie(arb, auxiliar));

				if (index > 0)
				{
					printf("Fratele de drapta al nodului %lu este  nodul %lu cu cheia %lu.\n\n", auxiliar, index, Cheie(arb, index));
				}

				else if (index == -1)
				{
					printf("Nodul a fost sters din arbore!\n\n");
				}

				else
				{
					printf("Nodul nu are un frate de dreapta!\n\n");
				}
				break;

		case 7: printf("\nDati nodul: ");
				if (scanf("%lu", &auxiliar) != 1)
				{
					perror("scanf");
				}
	
				if (auxiliar > numere)
				{
					printf("Nodul nu apartine arborelui!\n\n");
				}

				else if (Cheie(arb, auxiliar) == -1)
				{
					printf("Nodul a fost sters din arbore!\n\n");
				}

				else
				{
					printf("Cheia nodului %lu este %lu.\n\n", auxiliar, Cheie(arb, auxiliar));
				}

				break;
				
		case 8: if ((rad = Radacina(arb)) == -1)
				{
					printf("\nArborele nu a fost initializat!\n\n");
				}
				
			    else
				{
					printf("\nRdacina arborelul este: %d\n\n", rad);
				}
			  break;

		case 9: printf("\nDati nodul: ");
				if (scanf("%lu", &au1) != 1)
				{
					perror("scanf");
				}
				
				if (au1 > numere)
				{
					printf("Nodul nu apartine arborelui!\n\n");
				}
				
				else
				{
					suprimare(arb, au1);
				}
				break;

		case 0: break;

		default: printf("\nAlegere gresita!\n\n");
		}

		for (index = 0; index < numere; index++) // Reinitializam vectorul afisate
			afisate[index] = 0;
	}

	free(arb); // Eliberam memoria ocupata de arbore
	free(afisate); // Eliberam memoria ocupata de vectorul pentru valorile afisate

	fclose(out); // Inchiderea fisierului de iesire
	fclose(input); // Inchiderea fisierului de intrare

	return 0;
}