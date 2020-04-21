#include "Scientific.h"
#include<math.h>

using namespace std;

double Sin(float x)
{
    double val = 0;
    for(int i = 0; i < 100; i++)
    {
        val = val + ((power(-1, i) * power(x, 2*i + 1))/(fact(2*i + 1)));
    }
    return val;
}

double Cos(float x)
{
    double val = 0;
    for(int i = 0; i < 100; i++)
    {
        val = val + ((power(-1, i) * power(x, 2*i))/(fact(2*i)));
    }
    return val;
}


float Std_deviation(float * arr, int size)
{
    float mean = 0;
    float sum = 0;
    for(int i = 0; i < size; i++)
        mean = mean + arr[i];
    mean = mean / size;
    for(int i = 0; i < size; i++)
    {
        sum = sum + power(arr[i] - mean, 2);
    }
    sum = sum / size;
    sum = sqrt(sum);
    return sum;
}


double Poisson_pdf(int n, float parameter)
{
    return  (power(parameter, n) / (fact(n)*(power(2.71828, parameter))));
}

double Random(int Max)
{
    clock_t t;
    t = clock();
    return t % Max;
}

