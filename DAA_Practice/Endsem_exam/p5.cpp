

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


int Enumerate2(ordered_pair * Array, char * Set, int size);
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
    int n = Enumerate2(Array, Set, size); //Enumerates all possible pairs which don't belong to (a, a) for all a belongs to Set and (a, b) and (c, d)
    cout << endl << "Pairs generated: "<< n << endl;
    cout << "ENum  x  y" << endl;
        
    for(int i = 0; i < n; i++)
        cout << i << ": (" << Array[i].x << ", " << Array[i].y << ")\n";
    cout << "all" << endl;
    allPossibleSubset(Array, size*size - size - 2, Set, size);

    return 0;
}


 
int Enumerate2(ordered_pair * Array, char * Set, int size)
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
    cout << "Total " << c << "reflexive relations printed.\n";
}
