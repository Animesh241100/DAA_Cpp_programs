#include"Basic.h"

double add(double a, double b)
{
    return (a + b);
}
double prod(double a, double b)
{
    return (a * b);
}
int fact(int a)
{
    if(a > 0)
        return (a * fact(a - 1));
    else
        return 1;
}

double power(float x, int n)
{
    if(n == 0)
        return 1;
    else if(n > 0)
        return (x * power(x, n - 1));
    else
        return (1 / power(x, n));
}
