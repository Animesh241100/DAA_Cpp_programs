//The below document contains Experiments we did with string class.

#include<iostream>
//#include <bits/stdc++.h>
#include<string>

using namespace std;

int main()
{
    string str;
    int total = 0;
    cout<<"Enter the string"<<endl;
    getline(cin, str);

//Showing how to use push_back('character') and Pop_back() and str.back()
    cout<<"The index 3 element is "<<str[3]<<endl;
    str.push_back('@');
    cout<<"The last element after push_back @ is "<<str.back()<<endl;
    str.pop_back();
    cout<<"The last element after pop_back is "<<str.back()<<endl;
    cout<<"COUT ASCII:\t"<<(int)str[2] + 3<<endl;

    cout<<endl<<"Numerals"<<endl;
    for(int i = 0; i < str.length(); i++)
    {
        if((int)str[i]>=48 && (int)str[i]<=57)
        {
            total = total + (int)str[i] - 48;
            cout<<str[i]<<"\t"<<(int)str[i]<<endl;
        }
    } 

    cout<<"\nTotal of all the numerals Equals: "<<total<<endl;
    return 0;
}
