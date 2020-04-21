//the below code doesn't work some more work is needed, you have switched to vector-pair and stuff like that to implement elementary graph algorithms.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    
//_____________________HEAPSORT_____________________________
    vector <int>Test = { 1, 4, 12, 5, 7 };
    int size = Test.size();
    vector <int>HeapSort(size);
    make_heap(Test.begin(), Test.end());
    //pop_heap(Test.begin(), Test.end());
    for(int i = 0; i < size; i++)
    {
        pop_heap(Test.begin(), Test.end());
        HeapSort.push_back(Test.back());
        Test.pop_back();
    }
    cout << "The Sorted Sequence due to HeapSort :\n";
    for(int i = 0; i < size; i++)
    {
        cout << " " << HeapSort[i];
    }
    cout<<"Heap Input\n";
    for(int i = 0; i < size; i++)
    {
        cout << " " << Test[i];
    }
    

    for(int i = 0; i < Test.size(); i++)
        cout << " " << Test[i]; 
    
    return 0;
}