#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;
int main()
{string a[1005];
    int i,j,k,l,s=0,m,n;
    cin>>n;
    for (i=1;i<=n;i++)
     {for (j=1;j<=n;j++)
      {if (i % 2==1&&j % 2==1)
       {a[i]+='C';
       s++;}
       else if (i % 2==0&&j % 2==0)
        {a[i]+='C';
        s++;}
        else a[i]+='.';}
    }
    cout<<s<<endl;
    for (i=1;i<=n;i++)
     {for (j=0;j<=n-1;j++)
      cout<<a[i][j];
      cout<<endl;}
    }