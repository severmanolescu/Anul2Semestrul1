#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int i = 0;

	FILE* g;
	g = fopen("DATE.txt", "wb");

	for (i = 1; i <= 40; i++)
		fwrite(&i, 1, sizeof(int), g);

	return 0;
}
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define N 40
//
//unsigned int tab[N]; // variabilele globale sunt initializate automat pe zero
//
//
//// returneaza true sau false
//int cauta(unsigned int num) {
//	int i;
//	for (i = 0; i < N; i++) {
//		if (tab[i] == num) return 1; // true, gasit
//	}
//	return 0; // false, numar negasit
//}
//
//int main(void) {
//	FILE* fp;
//	int i;
//	unsigned int num;
//
//	fp = fopen("DATE.txt", "wb");
//	if (fp == NULL) {
//		perror("fopen()");
//		return -1;
//	}
//
//	srand(time(NULL)); // initializare generator de numere pseudo-random
//
//	for (i = 0; i < N; i++) {
//		num = rand() % 10000;
//		if (cauta(num)) { i--; continue; }
//		else tab[i] = num;
//	}
//
//	for (i = 0; i < N; i++) {
//		if (fwrite(&tab[i], sizeof(unsigned int), 1, fp) == 0) {
//			printf("Eroare la scriere\n");
//			return -1;
//		}
//	}
//
//	fclose(fp);
//
//}