#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int i = 0;

	FILE* g;
	g = fopen("Yes.txt", "wb");

	for (i = 1; i <= 40; i++)
		fwrite(&i, 1, sizeof(int), g);

	return 0;
}