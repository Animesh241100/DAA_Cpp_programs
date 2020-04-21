#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> heap = {3, 5, 12, 2, 10};
    make_heap(heap.begin(), heap.end());  //Heapify
    for(auto it = heap.begin(); it != heap.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
//-------------------------------------------------------------------------------------
    heap.push_back(11);
    for(auto it = heap.begin(); it != heap.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
//-------------------------------------------------------------------------------------
    push_heap(heap.begin(), heap.end());  //Heapify
    for(auto it = heap.begin(); it != heap.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
//-------------------------------------------------------------------------------------
    cout << "extracted max " << heap.front() << endl;
    pop_heap(heap.begin(), heap.end()); //deletion procedure step-1
    for(auto it = heap.begin(); it != heap.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
//-------------------------------------------------------------------------------------
    heap.pop_back();  //deletion procedure step-2(clearing the remains of the extracted max)
    for(auto it = heap.begin(); it != heap.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
//-------------------------------------------------------------------------------------
    heap.push_back(30);
    for(auto it = heap.begin(); it != heap.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
//-------------------------------------------------------------------------------------
    push_heap(heap.begin(), heap.end());  //Heapify
    for(auto it = heap.begin(); it != heap.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
//-------------------------------------------------------------------------------------
    return 0;
}

