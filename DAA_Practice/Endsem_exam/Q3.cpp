/*

Logic: We make a class ordered_pair which has two main members x and y, this class' object 
 represents an ordered pair (x, y).
    category 1: (a, a) for all a belongs to Set.
    category 2: (a, b) and (c, d)
 We make an 'Array' of ordered_pair objects and we already know that no. remaining ordered pairs which don't belong to above categories is size*size - size - 2 from Discrete maths class. So this 'Array' size is also size*size - size - 2.
    Two Functions are required:

    1. Enumerate: It fills the Array of ordered_pair objects with appropriate values.

    2. allPossibleSubset: It is the main function which was made to print all possible subsets of given Set, here the given set to this function is our ordered_pair 'Array' which contains all ordered_pairs enumerated by the 'Array' index(using the 'Enumerate' function we did it before calling this function.). This function 'artificially' adds all
     the category 1 and category 2 pairs at the starting of every Subset(or Relation here).


This gets our job done.

*/








#include<bits/stdc++.h>

using namespace std;

class ordered_pair
{
    public:
        char x;
        char y;
        ordered_pair()
        {
            x = 0;
            y = 0;
        }
};


int Enumerate(ordered_pair * Array, char * Set, int size);
void allPossibleSubset(ordered_pair * Array, int size_of_Array, char * Set, int set_size);

int main()
{

    int size;
    cout << "Enter the size of the set already containing 1, 2, 3 and 4: ";
    cin >> size;
    char Set[size];
    cout << "Enter the elements of the set, where a, b, c and d must be present among these elements as per the question's requirements: ";
    for(int i = 0; i < size; i++)
         cin >> Set[i];
    ordered_pair Array[size*size - size - 2];
    int n = Enumerate(Array, Set, size); //Enumerates all possible pairs which don't belong to category 1 or category 2.
    cout << endl << "Pairs generated: "<< n << endl;
    cout << "ENum  x  y" << endl;
        
    for(int i = 0; i < n; i++)
        cout << i << ": (" << Array[i].x << ", " << Array[i].y << ")\n";
    cout << "all" << endl;
    allPossibleSubset(Array, size*size - size - 2, Set, size);

    return 0;
}


 
int Enumerate(ordered_pair * Array, char * Set, int size)
{
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(Set[i] != Set[j])
            {
                if(Set[i] == 'a' && Set[j] ==  'b')
                    continue;
                if(Set[i] == 'c' && Set[j] == 'd')
                    continue;
                Array[count].x = Set[i];
                Array[count].y = Set[j];
                count++;
            }
        }
    }
    return count;
}

void allPossibleSubset(ordered_pair * Array, int size_of_Array, char * Set, int set_size)
{
    int c = 0;
	int  count = pow(2, size_of_Array);
    cout << "NULLL";
	for (int i = 0; i < count; i++)
	{
        cout << "{";
        for(int k = 0; k < set_size; k++)
            cout << "(" << Set[k] << "," << Set[k] << "), ";
        cout << "(a, b), (c, d), ";
		for (int j = 0; j < size_of_Array; j++)
		{
            
			if ((i & (1 << j)) > 0)
            {
                cout << "(" << Array[j].x << "," << Array[j].y << "), ";
            }
		}
		cout << "\b\b}\n";
        c++;
	}
    cout << "Total " << c << " reflexive relations printed.\n";
}
