#include <stdio.h>
#include <stdlib.h>

/**
 * @description:  计算n的阶乘
 * @param {type} 
 * @return {type} 
 */
int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

/**
 * @description: 斐波那契数列 
 * @param {type} 
 * @return {type} 
 */
int Fib(int n)
{
    if (n == 0) //边界条件
        return 0;
    else if (n == 1) //边界条件
        return 1;
    else
        return Fib(n - 1) + Fib(n - 2); //递归表达式
}

int main(int argc, char *argv[])
{
    int x = factorial(10);

    int y = Fib(4);
    printf("x=%d\n", x);
    printf("y=%d\n", y);

    return 0;
}
