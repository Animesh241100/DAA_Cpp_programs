//Solution to Q.1 of Set 5 by CED18I065.

/*
Logic: Split the array from half using 'Function' and recursively call the 'Function' for
 both halves of the array until you reach the Base-case 1 or 2.
1. If you reach Base-case 1: there is nothing to do, all min and max values are identical
 in this case. 
2. If you reach Base-case 2: compare those two elements with each other and assign max1,
 max2, min1 and min2 values accordingly.
Conquer_Step: We have got all the max and min values for both halves. Now, follow the steps 
 given in the code from line 82 to line 114 to frame the final answer. These steps are self
expalanatory.

Note: This algorithm is designed in such a way that for example: 5, 5, 1, 1:
the Output is min1 = 1 and min2 = 5 and max1 = 5 and max2 = 1
*/
#include<bits/stdc++.h>

using namespace std;


class Final
{
public:
    int max1;
    int max2;
    int min1;
    int min2;
    Final()
    {
        min1 = 0;
        max1 = 0;
        min2 = 0;
        max2 = 0;
    }
};

Final Function(int * arr, int l, int h);

int main()
{
    int size;
    cout << "Enter the array size: ";
    cin >> size;
    int arr[size];
    cout << "Enter the array elements: ";
    for(int i = 0; i < size; i++)
        cin >> arr[i];
    Final F;
    F = Function(arr, 0, size - 1);
    cout << "First-max = " << F.max1 << endl;
    cout << "Second-max = " << F.max2 << endl;
    cout << "First-min = " << F.min1 << endl;
    cout << "Second-min = " << F.min2 << endl;
    return 0;
}


Final Function(int * arr, int l, int h)
{
    Final F;
    if(l == h)  //Base case 1(when only one element exists)
    {
        F.max1 = arr[l]; //all values are same
        F.max2 = arr[l];
        F.min1 = arr[l];
        F.min2 = arr[l];
        return F; //return the final object.
    }
    else if(h - l == 1) //Base case 2(when only two elements exist)
    {
        F.max1 = max(arr[l], arr[h]); //pick max out of them and assign to max1
        F.max2 = min(arr[l], arr[h]); //pick min out of them and assign to max2
        F.min1 = F.max2; //self explanatory
        F.min2 = F.max1; //self explanatory
        return F; //return the final object.
    }

    int mid = (l + h) / 2;  //Find the mid of the array
    Final Left = Function(arr, l, mid); //Recursively call the 'Function' for Left-half
    Final Right = Function(arr, mid + 1, h); //Recursively call the 'Function' for Right-half
    if(Right.max1 > Left.max1)
    {
        F.max1 = Right.max1; //Max of both sides is assigned as final max1
        if((Right.max2 != Right.max1) && (Right.max2 > Left.max1)) //self explanatory
            F.max2 = Right.max2;
        else
            F.max2 = Left.max1;
    }
    else //self explanatory
    {
        F.max1 = Left.max1;
        if((Left.max2 != Left.max1) && (Left.max2 > Right.max1))
            F.max2 = Left.max2;
        else
            F.max2 = Right.max1;
    }

    if(Right.min1 < Left.min1) //Similar process is done to find First and Second Min
    {
        F.min1 = Right.min1;
        if((Right.min2 != Right.min1) && (Right.min2 < Left.min1)) //self explanatory
            F.min2 = Right.min2;
        else
            F.min2 = Left.min1;
    }
    else //self explanatory
    {
        F.min1 = Left.min1;
        if((Left.min2 != Left.min1) && (Left.min2 < Right.min1))
            F.min2 = Left.min2;
        else
            F.min2 = Right.min1;
    }
    return F; //return the final object.
}
    
        
