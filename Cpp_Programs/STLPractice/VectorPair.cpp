//Here we'll learn 3 ways of insertion in vector pair and accessing its elements.

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    vector <int> test = { 12, 5, 23, 45 };
    vector <pair<int, int>> Pair_vector(4);

    //Accessing the elements of the vectorPAIR and INSERTION
    Pair_vector[3].first =  10;
    Pair_vector[3].second =  140;

    //Another way of INSERTION
    Pair_vector[2] = make_pair(34, 56);

    //Appending a pair-node at the end of the vectorPAIR
    Pair_vector.push_back(make_pair(23, 45)); //pushes a new node at the back of Pair_vector.

    for(int i = 0; i < Pair_vector.size(); i++)
    {
        cout << Pair_vector[i].first<<"\t";
        cout << Pair_vector[i].second<<endl;
    }

//_______Experimenting with 2 dimensional vectors and extending it to pairs______

    vector <vector <int>> Matrix = { {1, 2, 3}, {4, 5, 6} };
    Matrix.push_back(test);

    cout << "Printing the matrix vector\n" ;
    for(int i = 0; i < Matrix.size(); i++)
    {
        for(int j = 0; j < Matrix[i].size(); j++)
        {
            cout << " " << Matrix[i][j];
        }
        cout << endl;
    }

//__________Now we learn how to create a vector-matrix with a specific size______

    vector <vector <int>> Matrix2(10);    //same as:   vector <int> Test(20);
    for(int i = 0; i < Matrix2.size(); i++)
    {
        Matrix2[i].resize(4); //resizes all component vectors to size 4
    }

    //Above lines declare a vector of 10 vectors of size 4 initialized with 0
    //Lets print them to verify.

    for(int i = 0; i < Matrix2.size(); i++)
    {
        Matrix2[i][3] = 4;
        for(int j = 0; j < Matrix2[i].size(); j++)
        {
            cout << " " << Matrix2[i][j];
        }
        cout << endl;
    }




    return 0;
}