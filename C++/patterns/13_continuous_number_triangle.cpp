#include<bits/stdc++.h>
using namespace std;

void print13(int n)
{
      int a=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cout<<a++<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    print13(n);
    return 0;
}