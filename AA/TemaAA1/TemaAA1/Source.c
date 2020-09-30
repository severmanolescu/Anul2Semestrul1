//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	float epsilon;
//	int* sir[10];
//
//	int n = 0;
//	unsigned short i = 0;
//
//	FILE* f;
//	if ((f = fopen("INPUT.DAT", "r")) == NULL)
//	{
//		printf("Fisierul nu exista sau a aparut o eroare la deschidere!");
//		return -1;
//	}
//
//	fscanf(f, "%d", &n);
//	/*if ((sir = (int*)malloc(n * sizeof(int)) == NULL))
//	{
//		printf("Eroare la alocarea memoriei!");
//		return -1;
//	}*/
//
//	printf("%d\n", n);
//
//	for (i = 0; i < n; i++)
//		fscanf(f, "%d", &sir[i]);
//
//	for (i = 0; i < n; i++)
//		printf("%d  ", sir[i]);
//
//	getchar();
//	return 0;
//}