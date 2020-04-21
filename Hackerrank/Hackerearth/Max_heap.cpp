#include<bits/stdc++.h>

using namespace std;

 
class heap
{
    public:
        int arr[100];  //remember that the arr[0] is reserved for nothing and shall not be used.
        int size;
        heap()
        {
            size = 0;
            for(int i = 0; i < 100; i++)
                arr[i] = -100;
        }
};

void push_heap(heap &H, int c);
int pop_heap(heap &H);
void Swap(int * a, int * b);
void Print_heap(heap &H);   
vector<int> Heapsort(heap &H);

int main()
{
    heap H;
    int n, c;
    vector<int> Sorted_Array(100);
   cout << "Enter the no. of elements to be inserted: ";
   cin >> n;
   //  srand(time(0));
    // n = rand() % (21);
    while(n != 0)
    {
        cin >> c;
        //c = rand() % (3000);
        push_heap(H, c);
        n--;
    }
    Print_heap(H);
    cout << "\npopped element is: " << pop_heap(H) << endl;
    Print_heap(H);
    int size = H.size;
    Sorted_Array = Heapsort(H);
    cout << endl << "Sorting using Heapsort: " << endl;
    for(int i = 0; i < size; i++)
        cout << " " << Sorted_Array[i];/**/
    return 0;
}

void push_heap(heap &H, int c)
{
    H.size++;
    H.arr[H.size] = c;
    if(H.size > 1)  //For all of the non-first-most insertions.
    {
        int it = H.size;
        while(it != 1)
        {
            if(H.arr[it] > H.arr[it / 2])
            {
                Swap(&H.arr[it], &H.arr[it/2]);
                it = it / 2;
            }
            else 
                break;
        }
    }
}

int pop_heap(heap &H)
{
    if(H.size > 0)
    {
        Swap(&H.arr[1], &H.arr[H.size]);
        int temp = H.arr[H.size];
        H.size--;
        int it = 1;
        //while(/*(2*it <= H.size - 1) ||*/ (2*it + 1 <= H.size))
        while(it <= H.size)
        {
            if(2*it + 1 <= H.size)
            { 
                if(H.arr[it] < H.arr[2*it] || H.arr[it] < H.arr[2*it + 1])
                {
                    if(H.arr[2*it] > H.arr[2*it + 1])
                    {
                        Swap(&H.arr[it], &H.arr[2*it]);
                        it = 2*it;
                    }
                    else
                    {
                        Swap(&H.arr[it], &H.arr[2*it + 1]);
                        it = 2*it + 1;
                    }
                }
            }
            else if(2*it <= H.size)
            {
                if(H.arr[it] < H.arr[2*it])
                {
                    Swap(&H.arr[it], &H.arr[2*it]);
                    it = 2*it;
                }
            }
        }
        return temp;
    }
    else
    {
        return INFINITY; //represents the Heap can no more be popped out 
    }
}

void Swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Print_heap(heap &H)
{
    int i = 1;
    while(i <= H.size)
    {
        cout << H.arr[i] << " " ;
        i++;
    }
}

vector<int> Heapsort(heap &H)
{
    vector <int>vec(100);
    int i = 0;
    int size = H.size;
   // while(i != H.size - 1)
    while(i < size)
    {
        //vec.push_back(pop_heap(H));
        vec[i] = pop_heap(H);
       // cout << " " << pop_heap(H);
        i++;
    }
    return vec;
}



