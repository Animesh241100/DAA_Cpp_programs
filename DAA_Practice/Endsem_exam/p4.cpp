#include <bits/stdc++.h>
using namespace std;

int allPossibleSubset(int arr[],int n)
{
    int c = 0;
	int  count = pow(2,n);
    cout << "NULLL";
	for (int i = 0; i < count; i++)
	{
        cout << "{";
		for (int j = 0; j < n; j++)
		{
            
			if ((i & (1 << j)) > 0)
				cout << arr[j] << ", ";
		}
		cout << "\b\b}\n";c++;
	}
    return c;
}

int main()
{
	int n;
	cout << "Enter size of the set\n";
	cin >> n;

	int arr[n];
	cout << "Enter Elements of the set\n";
	for(int i=0;i<n;i++)
		cin >> arr[i];

	cout << endl << allPossibleSubset(arr,n);
	
	return 0;
}
