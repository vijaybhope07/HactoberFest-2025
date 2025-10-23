#include<bits/stdc++.h>
using namespace std;

void print18(int n)
{
    char ch;
  for (int i = 1; i <= n; i++)
  {
      ch = 'A' + n - 1;
      for(int j=1; j<=i; j++)
      {
          cout<<ch--<<" ";
      }
      cout<<endl;
  }
}

int main()
{
    int n;
    cin>>n;
    print18(n);
    return 0;
}