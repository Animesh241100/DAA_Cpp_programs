#include<iostream>
#include <bits/stdc++.h> 
using namespace std; 
void primeFactors(int n);
  
int main()  
{  
    int n; 
    printf("Enter the number: ");
    cin>>n;
    primeFactors(n);  
    return 0;  
} 

void primeFactors(int n)  
{  
    for(int j = 1; j <= n; j++)
    {
        // Print the number of 2s that divide n  
        while (j % 2 == 0)  
        {  
            cout <<"2 ";  
            j = j/2;  
        }  
    
        for (int i = 3; i <= sqrt(j); i = i + 2)  
        {  
            
            while (j % i == 0)  
            {  
                cout << i << " ";  
                j = j/i;  
            }  
        }  
  
        if (j > 2)  
            cout << j << " "; 
        printf("\n");
    } 
}  
