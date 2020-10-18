#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct arbore {
	unsigned int parinte;
	unsigned long cheie;
	bool radacina;
}arbore;

unsigned long contor = 1;
unsigned long numere;

FILE* out;

unsigned short *afisate;

unsigned Tata(arbore arb[], unsigned long n)
{
	unsigned long index = 0;

	for (index = 0; index < numere; index++)
	{
		if (arb[index].cheie == n)
		{
			return arb[index].parinte;
		}
	}

	return 0;
}

unsigned long PrimulFiu(arbore arb[], unsigned long n)
{
	unsigned long index = 0;

	for (index = 2; index <= numere; index++)
	{
		if (arb[index].parinte == n)
		{
			return arb[index].cheie;
		}
	}

	return 0;
}

unsigned long FrateDreapta(arbore arb[], unsigned long n)
{
	unsigned long index = 0;

	for (index = 2; index < numere; index++)
	{
		if (arb[index].cheie == n)
		{
			if (arb[index + 1].parinte == arb[index].parinte)
			{
				return index + 1;
			}
		}
	}

	return 0;
}

unsigned long Cheie(arbore arb[], unsigned long n)
{
	unsigned long index = 0;

	for (index = 0; index < numere; index++)
	{
		if (arb[index].cheie == n)
		{
			return index;
		}
	}
	return 0;
}

long Radacina(arbore arb[])
{
	unsigned long index = 0;
	unsigned short nod = 0;

	bool ok = true;

	for (index = 1; index < numere; index++)
	{
		if (arb[index].radacina == true)
		{
			nod++;
		}
	}

	if (nod == 1)
		return arb[1].cheie;

	return -1;
}

void initializeaza(arbore arb[])
{
	unsigned long index = 0;

	for (index = 0; index < numere; index++)
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

	for (index = 0; index < numere; index++)
	{
		if (arb[index].cheie == tata)
			break;
	}

	if (tata == -1)
		arb[contor].radacina = true;

	arb[contor].cheie = cheie;
	arb[contor].parinte = index;
	contor++;
}

void inordine(arbore arb[], unsigned long n)
{
	unsigned aux1;
	unsigned aux2;

	if (n > 0)
	{
		inordine(arb, PrimulFiu(arb, n));

		if (!afisate[Cheie(arb, n)])
		{
			fprintf(out, "%lu ", n);
			afisate[Cheie(arb, n)] = 1;
		}

		aux1 = FrateDreapta(arb, PrimulFiu(arb, n));
		aux2 = FrateDreapta(arb, aux1);

		while (aux1 || aux2)
		{
			if (aux1)
				inordine(arb, aux1);

			if (aux2)
				inordine(arb, aux2);

			aux1 = PrimulFiu(arb, aux1);
			aux2 = FrateDreapta(arb, aux2);
		}
		
	}
}

void postordine(arbore arb[], unsigned long n)
{
	unsigned aux1;
	unsigned aux2;

	if (n > 0)
	{
		postordine(arb, PrimulFiu(arb, n));

		aux1 = FrateDreapta(arb, PrimulFiu(arb, n));
		aux2 = FrateDreapta(arb, aux1);

		while (aux1 || aux2)
		{
			if (aux1)
				postordine(arb, aux1);

			if (aux2)
				postordine(arb, aux2);

			aux1 = PrimulFiu(arb, aux1);
			aux2 = FrateDreapta(arb, aux2);
		}

		if (!afisate[Cheie(arb, n)])
		{
			fprintf(out, "%lu ", n);
			afisate[Cheie(arb, n)] = 1;
		}

	}
}

void preordine(arbore arb[], unsigned long n)
{
	unsigned aux1;
	unsigned aux2;

	if (n > 0)
	{
		if (!afisate[Cheie(arb, n)])
		{
			fprintf(out, "%lu ", n);
			afisate[Cheie(arb, n)] = 1;
		}

		preordine(arb, PrimulFiu(arb, n));

		aux1 = FrateDreapta(arb, PrimulFiu(arb, n));
		aux2 = FrateDreapta(arb, aux1);

		while (aux1 || aux2)
		{
			if (aux1)
				preordine(arb, aux1);

			if (aux2)
				preordine(arb, aux2);

			aux1 = PrimulFiu(arb, aux1);
			aux2 = FrateDreapta(arb, aux2);
		}

	}
}

int main()
{
	unsigned long auxiliar = 0;
	unsigned long index = 0;
	unsigned long tata = 1;
	unsigned short s = 1;

	int alegere = 1;

	double procent = 0;
	double procent1 = 1;

	char c = '%';

	bool radacina = false;

	struct arbore* arb;

	FILE* f;
	if (( f = fopen("Yes.txt", "rb" )) == NULL)
	{
		perror("fopen");
		return -1;
	}

	if ((out = fopen("DATA.OUT", "w")) == NULL)
	{
		perror("fopen");
		exit(-1);
	}

	fseek(f, 0, SEEK_END);
	numere = ftell(f) / sizeof(unsigned);
	fseek(f, 0, SEEK_SET);

	numere++;

	if (( arb = (arbore*)malloc(sizeof(struct arbore) * (numere + 2) )) == NULL )
	{
		perror("malloc");
		return -1;
	}

	if ((afisate = (unsigned short*)malloc(sizeof(unsigned short) * (numere + 2))) == NULL)
	{
		perror("malloc");
		return -1;
	}

	initializeaza(arb);

	for (index = 0; index < numere; index++)
	{
		fread(&auxiliar, sizeof(unsigned long), 1, f);

		procent = (float)(index) / (numere * 1.0) * 100.0;

		if (procent != procent1)
		{
			printf("Citire si initializare: %.2f %c \n", procent, c);

			procent1 = procent;
		}
		
		if (radacina == false)
		{
			arb[1].cheie = auxiliar;
			arb[1].parinte = 0;
			arb[1].radacina = true;
			contor++;
			radacina = true;
		}
		else if (s < 5)
		{
			insereaza(arb, auxiliar, arb[tata].cheie);
			s++;
		}
		else
		{
			insereaza(arb, auxiliar, arb[tata].cheie);
			s = 1;
			tata++;
		}
	}

	printf("\nCitirea si initializarea a avut loc cu succes!\n\n");

	while (alegere)
	{
		printf("1. Scrierea in fisier in inordine.\n");
		printf("2. Scrierea in fisier in preordine.\n");
		printf("3. Scrierea in fisier in postordine.\n");
		printf("0. Iesire.\n");

		printf("Alegerea dumneavoastra este: "); 
		if (scanf("%d", &alegere) != 1)
		{
			perror("scanf");
		}

		switch (alegere)
		{
		case 1: printf("\nScriere in fisierul DATA.OUT parcurgerea in inordine...");
				fprintf(out, "\nScriere in inordine: \n");
				inordine(arb, Radacina(arb));
				printf("\nScriere in fisierul DATA.OUT parcurgerea in inordine executata cu succes\n\n");
				break;

		case 2: printf("\nScriere in fisierul DATA.OUT parcurgerea in preordine...");
				fprintf(out, "\nScriere in preordine: \n");
				preordine(arb, Radacina(arb));
				printf("\nScriere in fisierul DATA.OUT parcurgerea in preordine executata cu succes\n\n");
				break;

		case 3: printf("\nScriere in fisierul DATA.OUT parcurgerea in postordine...");
				fprintf(out, "\nScriere in postordine: \n");
				postordine(arb, Radacina(arb));
				printf("\nScriere in fisierul DATA.OUT parcurgerea in postordine executata cu succes\n\n");
				break;

		}
		for (index = 0; index < numere; index++)
			afisate[index] = 0;

		fprintf(out, "\n");
	}

	free(arb);
	free(afisate);
	fclose(out);
	fclose(f);

	return 0;
}