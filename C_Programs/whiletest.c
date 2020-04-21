#include<stdio.h>

void main()
{
    int i = 0;
    int j = 0;
    while(i!=10)
    {
        while(j!=5)
        {
            printf("hi j\t");
            if(j%2 == 0)
                j++;
            else 
                i++;
        }

        printf("i = %d\n", i);
        i++;
    }
}