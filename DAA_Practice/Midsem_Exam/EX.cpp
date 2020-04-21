
 
#include <bits/stdc++.h> 
using namespace std; 
  
void primeFactors(int n); 
int main()  
{  
    int n = 4;
    int k,i; 
    k = n;
    while(k!=2*n + 1)
    {
        i = k;
        printf("For %d", k);
        primeFactors(i); 
        printf("\n");
        k++;
    }
    return 0;  
}  

void primeFactors(int n)  
{  
    
    while (n % 2 == 0)  
    {  
        cout << 2 << " ";  
        n = n/2;  
    }  
  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        
        while (n % i == 0)  
        {  
            cout << i << " ";  
            n = n/i;  
        }  
    }   
    if (n > 2)  
        cout << n << " ";  
}  
  