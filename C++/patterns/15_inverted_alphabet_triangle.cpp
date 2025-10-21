#include<bits/stdc++.h>
using namespace std;

void print15(int n)
{
     char ch='A';
    for(int i=n; i>=1; i--)
    {  
        for(int j=1; j<=i; j++)
       {
           cout<<ch<<" ";
             ch++;
       }
       cout<<endl;
       ch='A';
    }
}

int main()
{
    int n;
    cin>>n;
    print15(n);
    return 0;
}