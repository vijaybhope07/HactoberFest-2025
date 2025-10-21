#include<bits/stdc++.h>
using namespace std;

void print14(int n)
{
   char ch='A';
    for(int i=1; i<=n; i++)
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
    print14(n);
    return 0;
}