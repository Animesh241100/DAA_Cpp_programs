#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
//_______Learning how to use vectors___________
    vector <int>Test = { 1, 4, 12, 5, 7 };
    cout<<"Test.front(): "<<Test.front()<<endl;  //Notice the difference between .front(referrence to first element) and .begin(pointer or iterator to first element)
    cout<<"*Test.begin(): "<<*Test.begin()<<endl;

     
    cout<<"Test[3]: "<<Test[3]<<endl;  //accesing a particular position
    /*for(int i = 0; i < 5; i++)
    {
        cout<<"*Test.end(): "<<*Test.end()<<endl;  //returns a pointer to the last index(not 7 but 0)
        Test.pop_back();        //deletes an element from the end of the vector.
    }
    cout<<"*Test.end(): "<<*Test.end()<<endl;
    */
//__________Learning how to USE Heap STL data structure Algorithm___________

    
    for(int i = 0; i < 5; i++)
    {
        cout << " "<< Test[i];
    }
    
    make_heap(Test.begin(), Test.end()); //transforming the Test vector into corresponding heap vector of itself.
    cout<<"\nTest.front(): " << Test.front() << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << " " << Test[i];
    }
    Test.push_back(13);   //trying to insert into the heap.
    for(int i = 0; i < 6; i++)
    {
        cout << " " << Test[i];
    }
    push_heap(Test.begin(), Test.end());  //HEAPIFY
    cout<<"\nTest.front(): " << Test.front() << endl;
    pop_heap(Test.begin(), Test.end());
    cout<<"\n Extracted(Popped)MAX  " << *(Test.end() - 1);  //or use Test.back()(it is comparable to Test.front()
    //Test.end() returns address to the ending character 0(like \0 for strings), so for actual end character we have to subtract -1 from it.
    Test.pop_back();  //for the sake of completion because the popped one is still attached at the end of the transformed vector.
    cout<<"\nAfter extracting max,Test.front(): " << Test.front() << endl;


    return 0;
}
