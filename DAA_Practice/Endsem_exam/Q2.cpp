//Solution to Q.2 of Set 5 by CED18I065.

/*
 Logic:
The Dynamic Programming solution creates a Matrix of n + 1 rows and t + 1 columns. In the 
Matrix, Matrix[i][j] is filled as true if there exists a subset of the set A, which sums up
 to the value j. where j = 0, 1, 2, ... , t.

Below is the Matrix filling Scheme:

Step 1: Initialise all the elements of the first row as "FALSE". Since having taking 0 
elements from the set doesn't contribute in the solution.

Step 2: Initialise all the elements of the first column as "TRUE". We take it for granted
that t = 0 case doesn't require any element from the set because the null set is subset of
all sets.

Step 3: Now taking above cases as base cases we generate the solution by filling the matrix 
in a Bottom-up fashion-
        if current column value(current_sum j) is smaller than the element A[i - 1].
        then that means the A[i - 1] was not used to create the solution, 
        therefore such a subset exists or not(value to be filled in Matrix[i][j]) solely
        depends upon the truth value in just above row Matrix[i - 1][j].(line: 87, 88 )

        if current column value(current_sum j) is greater than the element A[i - 1].
         then that means the A[i - 1] had may or may not been used to create the solution.
         therefore this can be true if any of the below statements are true:(line: 89, 90)

            S1: current_sum is constructed excluding A[i - 1], which solely depends upon
             whether Matrix[i - 1, j] is true.

            S2: current_sum is constructed excluding A[i - 1], which means we keep the row
             i - 1 as fixed and jump A[i - 1] steps towards left and checking whether this 
             cell i.e. Matrix[i - 1][j - A[i - 1]] is true.
            Simply ORing the S1 and S2 does our job, THIS IS THE ONLY REASON WE HAVE TAKEN A
            BOOLEAN TWO-DIMENSIONAL MATRIX. 
            
Step 4: At last, the value present in the Matrix[n][t] represents whether the sum t can be 
created using elements A[i], i = 1 ... n , which is our final answer.
*/

#include <iostream> 
 
using namespace std;

bool Find_subset(int A[], int n, int t); 

int main() 
{ 
    int size, t;
    cout << "Enter the set size: ";
    cin >> size;
    int A[size];
    cout << "Enter the positive integers A[i]: ";
    for(int i = 0; i < size; i++)
        cin >> A[i]; 
    cout << "Enter another positive integer t: ";
    cin >> t;
    if (Find_subset(A, size, t) == true) 
        cout << "There exists a subset of the set A which adds up to t." << endl; 
    else
        cout << "There does not exist a subset of the set A which adds up to t." << endl; 
    return 0; 
} 



bool Find_subset(int A[], int n, int t) 
{ 
	bool Matrix[n + 1][t + 1]; //create a matrix with n + 1 rows and t + 1 columns

 //Filling the Matrix as per the above method.

 //Step: 1
    for (int i = 0; i <= n; i++) 
	    Matrix[i][0] = true; 

 //Step: 2
	for (int i = 1; i <= t; i++) 
	    Matrix[0][i] = false; 
 
 //Step: 3
	for (int i = 1; i <= n; i++) 
	{ 
        for (int j = 1; j <= t; j++) 
        { 
            if(j < A[i - 1])  
                Matrix[i][j] = Matrix[i-1][j]; 
            else    
                Matrix[i][j] = Matrix[i - 1][j] || Matrix[i - 1][j - A[i - 1]]; 
        } 
	} 

 //Step: 4
    return Matrix[n][t]; //return the value of last(bottom-right) cell.
} 
