// https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/tutorial/

#include<bits/stdc++.h>

using namespace std;

//void Sort(int * arr, int N);
int Max_BOT(int * arr, int X, int N);

int main()
{
    int T, N, X, max_count;
    cin >> T;
    int arr[10000];
    for(int c = 0; c < T; c++)
    {
        cin >> N >> X;
        for(int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr+N); 
        max_count = Max_BOT(arr, X, N);
        printf("%d\n", max_count);
    }
    return 0;
}


 

int Max_BOT(int * arr, int X, int N)
{
    int count = 0;
    int i = 0;
   /* while (count <= X && i < N)
    {
        count = count + arr[i];
        i++;
    }
    return i - 1;*/
    while(1)
    {
        if(count + arr[i] < X && i < N)
        {
            count = count + arr[i];
            i++;
        }
        else
            break;
    }
    return i;
}
    

