#include <stdio.h>
#include <stdlib.h>

int akm(int m, int n)
{
    if (m == 0)
    {
        printf("return(%d)\n", n + 1);
        return (n + 1);
    }
    else if (n == 0)
    {
        printf("akm(%d,%d)\n", m - 1, 1);
        return (akm(m - 1, 1));
    }
    else
    {
		printf("akm(%d,akm(%d,%d))\n", m - 1, m, n - 1);
        return (akm(m - 1, akm(m, n - 1)));
    }
}

int main(int argc, char const *argv[])
{
    printf("akm(%d,%d)\n", 2, 1);
    akm(2, 1);
    return 0;
}
