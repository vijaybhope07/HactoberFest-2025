#include<bits/stdc++.h>
using namespace std;

void print17(int n)
{
    char ch='A';
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n-i; j++)
        {
            cout<<"  ";
        }
        for(int j=1; j<=2*i-1; j++)
        {
            if (j <= (2 * i - 1) / 2) 
            {
              cout << ch++ << " ";
            }
            else
            {
                cout<<ch--<<" ";
            }
        }
         for(int j=1; j<=n-i; j++)
        {
            cout<<"  ";
        }
        cout<<endl;
        ch='A';
    }
}

int main()
{
    int n;
    cin>>n;
    print17(n);
    return 0;
}