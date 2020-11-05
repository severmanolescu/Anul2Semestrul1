#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int num)
{
    unsigned i = 0;
    unsigned rad = 0;

    printf("%d ", num);

    num = abs(num);
    rad = sqrt(num);

    if (num == 0 || num == 1)
        return false;

    for (i = 2; i < num/2; i++)
        if (num % i == 0)
            return false;

    return true;
}

int main()
{
	printf("%d", is_prime(247464361));
	return 0;
}