//Implement Towers of Hanoi

#include<iostream>
using namespace std;
void Shift(int * S, int * D,  int l, int *M);
void init( int * arr, int n);
void Display();

int total = 0;
const int n = 4;
int flag = 0;
int S[n], M[n], D[n];      
int main()
{
    init(M, n);    //initializes all elements to 0.
    init(D, n);  
    for(int i = 0; i < n ; i++)
        S[i] = i+1;
    Shift(S, D, n - 1, M);
    printf("Total no of assignments is %d\n", total);
    return 0;
}

void Display()
{
    printf("State after exactly %d assignments\n", total);
    printf(" Source tower     Bottom=>  ");
    for(int i = n-1; i >= 0; i--)
    {
        printf("%d ", S[i]);
    }
    printf("            <= Top\n");
    printf(" Mediator tower             ");
    for(int i = n-1; i >= 0; i--)
    {
        printf("%d ", M[i]);
    }
    printf("\n");
    printf(" Destination tower          ");
    for(int i = n-1; i >= 0; i--)
    {
        printf("%d ", D[i]);
    }
    printf("\n");
}

void Shift(int * S, int * D,  int l, int *M) //Shift content of S to D using M as a medium. where l is the last index in the array. array index is zero at the top-most disc.
{
    if(l == 0)
    {
        D[0] = S[0]; //Since only one disc is there in the D array.
        S[0] = 0;
        total++;
        flag = 1; Display();
    }
    else
    {
         Shift(S, M, l - 1, D); //Shift all the l discs above the (l+1)th disc to the M array using D array as a mediator. 
         D[l] = S[l]; //After doing the above operation, directly shift the (l+1)th disc to the D array .
         S[l] = 0;
         total++; //so only 1 new assignment happened
         flag = 1;Display();
         Shift(M, D, l - 1, S); //Following a similar method as above, shift all those l discs to the D array from M array using S array as a mediator.
    }
}        
void init( int * arr, int n)
{
    for(int i = 0; i < n; i++)
        arr[i] = 0;
}

