#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Unit
{
    public:
        int size;    //size of the array
        int arr[50]; //the array of sorted integers with default size 50.
        int pointer; //pointer to the first index which produces.
        Unit();
};

class Pair
{
    public:
        int Array_id;
        int value;
        Pair(int id, int val) 
        { 
            Array_id = id; 
            value = val; 
        } 
        
        int getARR() const { return Array_id; } 
        int getVAL() const { return value; }  
}; 
  
// To compare two Pairs 
class myComparator 
{ 
    public: 
        int operator() (const Pair& p1, const Pair& p2)
        { 
            return p1.getVAL() > p2.getVAL(); //keyed by values
        } 
}; 
vector<int> Sorter(Unit Unit_Array[], int k, int Final_Array_Size);

int main()
{
    int k;
    int Final_Array_Size = 0;
    cout << "Enter the no. of arrays: ";
    cin >> k;
    Unit Unit_Array[k];
    for(int i = 0; i < k; i++)
    {
        printf("Enter the size of %dth array:", i);
        cin >> Unit_Array[i].size;
        Final_Array_Size = Final_Array_Size + Unit_Array[i].size;
        printf("Enter the elements of %dth array:", i);
        for(int j = 0; j < Unit_Array[i].size; j++)
            cin >> Unit_Array[i].arr[j];
    }
    vector<int> Sorted_Array(Final_Array_Size);
    Sorted_Array = Sorter(Unit_Array, k, Final_Array_Size);
    cout << "The sorted Array is:\n";
    for(int i = 0; i < Final_Array_Size; i++)
    {
        cout << " " << Sorted_Array[i];
    }
    cout << endl;
    return 0;   
}

vector<int> Sorter(Unit Unit_Array[], int k, int Final_Array_Size)
{
    int j = 0;
    vector<int> Final_vector(Final_Array_Size);
    priority_queue<Pair, vector<Pair>, myComparator> Heap;
    for(int i = 0; i < k; i++)
    {
        Heap.push(Pair(i, Unit_Array[i].arr[Unit_Array[i].pointer]));
    } 
    
    while(j < Final_Array_Size)
    {
        Pair P = Heap.top(); 
        Heap.pop();
        Final_vector[j] = P.getVAL();
        j++; 
        if(Unit_Array[P.getARR()].pointer < Unit_Array[P.getARR()].size)
        {
            Unit_Array[P.getARR()].pointer = Unit_Array[P.getARR()].pointer + 1;
            P.Array_id = P.getARR();
            if(Unit_Array[P.getARR()].pointer < Unit_Array[P.getARR()].size)
            {
                P.value = Unit_Array[P.getARR()].arr[Unit_Array[P.getARR()].pointer];
                Heap.push(P);
            }
        } 
    }
    return Final_vector;    
}

Unit::Unit()
{
    pointer = 0;
}
