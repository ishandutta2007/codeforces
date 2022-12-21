#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    __int64 a[200005];
    __int64 t=0,i,j,k,l=0,s=0,m,n,mm=0,r=0;
    cin>>n;
    for (i=1;i<=n;i++)
     cin>>a[i];
    for (i=1;i<=n;i++)
     {
       if (a[i]==1)
      s++;
      else if (a[i]==0)
       t+=s;}
      cout<<t;
}