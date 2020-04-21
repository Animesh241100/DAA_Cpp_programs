#include "Scientific.h"

using namespace std;

int main()
{
    float x, y, parameter;
    int n, size, Max;
    cout << "enter x for ratios: ";
    cin >> x;
    cout << "sin(x) = " << Sin(x) << endl;
    cout << "cos(x) = " << Cos(x) << endl;
    cout << "enter X(integer) and parameter for pdf calculation: ";
    cin >> n >> parameter;
    cout << "Poisson_pdf = " << Poisson_pdf(n, parameter);
    cout << "Enter the size of the data you want to calculate std deviation: ";
    cin >> size;
    float arr[size];
    cout << "size " << size;
    cout << "Enter the array of numbers: " << endl;
    for(int i = 0; i < size; i++)
        cin >> arr[i];
    cout << "The Std_deviation of given data is: " << Std_deviation(arr, size) << endl;
    cout << "Enter the n in the range 0...n from which you want to get random number from: ";
    cin >> Max;
    cout << "Random no. : " << Random(Max) << endl;
    return 0;
}
