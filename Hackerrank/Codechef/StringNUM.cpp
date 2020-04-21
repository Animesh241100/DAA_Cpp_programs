//Application of string Class

#include<iostream>
#include<string>
using namespace std;
int sumnum(string str);

int main()
{
    int n;  //#test cases
    //cout<<"Enter #test cases"<<endl;
    cin>>n;
    string str;
    int total[n];
    //cout<<"Enter strings:"<<endl;
    for(int i = 0; i <= n; i++)
    {
        getline(cin,str);
        total[i] = sumnum(str);
    }
     for(int i = 1; i <= n; i++)
    {
       cout<<total[i]<<endl;
    }
    return 0;
}

int sumnum(string str)
{
    int total = 0;
    for(int i = 0; i < str.length(); i++)
    {
        if((int)str[i]>=48 && (int)str[i]<=57)
        {
            total = total + (int)str[i] - 48;
        }
    } 
    return total;
}
        
