#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,k,l,s,m,n;
    int c[105],a[105][105],b[105];
    scanf("%d",&n);
    for (i=1;i<=n;i++)
     scanf("%d",&b[i]);
    for (i=1;i<=n;i++)
     for (j=1;j<=b[i];j++)
      scanf("%d",&a[i][j]);
    for (i=1;i<=n;i++)
     {c[i]=b[i]*15;
     for (j=1;j<=b[i];j++)
      c[i]+=a[i][j]*5;}
      sort(c+1,c+1+n);
      printf("%d",c[1]);
    }