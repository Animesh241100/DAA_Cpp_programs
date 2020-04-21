#include<bits/stdc++.h>

using namespace std;

class ordered_pair
{
    public:
        int x;
        int y;
        ordered_pair()
        {
            x = 0;
            y = 0;
        }
};


int Enumerate2(ordered_pair * Array, int * Set, int size);
int Enumerate(int Matrix[][3], int * Set, int size);
int allPossibleSubset(ordered_pair * Array, int size_of_Array);
void Print_pair(ordered_pair P);

int main()
{

    int size;
    cout << "Enter the size of the set already containing 1, 2, 3 and 4: ";
    cin >> size;
    int Set[size];
   // cout << "Enter the elements of the set: ";
    for(int i = 0; i < size; i++)
         Set[i] = i;
    ordered_pair Array[size*size - size - 2];
    
    int Matrix[size*size - size - 2][3];
   //int n = Enumerate(Matrix, Set, size);
   int n = Enumerate2(Array, Set, size);
    cout << endl << "Pairs generated: "<< n << endl;
    cout << "ENum  x  y" << endl;
    //for(int i = 0; i < n; i++)
        //cout << Matrix[i][0] << ": (" << Matrix[i][1] << ", " << Matrix[i][2] << ")\n";

        
    for(int i = 0; i < n; i++)
        cout << i << ": (" << Array[i].x << ", " << Array[i].y << ")\n";
    cout << "all" << endl;
    cout << allPossibleSubset(Array, size*size - size - 2);

    return 0;
}


int Enumerate(int Matrix[][3], int * Set, int size)
{
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(Set[i] != Set[j])
            {
                if(Set[i] == 1 && Set[j] == 2)
                    continue;
                if(Set[i] == 3 && Set[j] == 4)
                    continue;
                
               // cout << "(" << Set[i] << ", " << Set[j] << "), ";
                Matrix[count][0] = count;
                Matrix[count][1] = Set[i];
                Matrix[count][2] = Set[j];
                count++;
            }
        }
    }
    return count;
}


int Enumerate2(ordered_pair * Array, int * Set, int size)
{
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(Set[i] != Set[j])
            {
                if(Set[i] == 1 && Set[j] == 2)
                    continue;
                if(Set[i] == 3 && Set[j] == 4)
                    continue;
                
               // cout << "(" << Set[i] << ", " << Set[j] << "), ";
                Array[count].x = Set[i];
                Array[count].y = Set[j];
                count++;
            }
        }
    }
    return count;
}

int allPossibleSubset(ordered_pair * Array, int size_of_Array)
{
    int c = 0;
	int  count = pow(2, size_of_Array);
    cout << "NULLL";
	for (int i = 0; i < count; i++)
	{
        cout << "{";
		for (int j = 0; j < size_of_Array; j++)
		{
            
			if ((i & (1 << j)) > 0)
            {
               // Print_pair(Array[i]);
                cout << "(" << Array[j].x << "," << Array[j].y << "), ";
				//cout << ", ";
            }
		}
		cout << "\b\b}\n";c++;
	}
    return c;
}

void Print_pair(ordered_pair P)
{
    cout << "(" << P.x << "," << P.y << "), ";
}