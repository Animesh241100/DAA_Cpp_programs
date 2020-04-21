#include<iostream>
#include"Basic.h"
using namespace std;

int main()
{
    int a = 4;
    int b = 6;
    Basic object;
    printf("add :%d\n", object.addition(a,b));
    printf("mul :%d\n", object.multiply(a,b));
    printf("fact :%d\n", object.factorial(a));
}