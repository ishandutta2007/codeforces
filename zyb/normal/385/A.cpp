#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int ans,i,j,k,l,s,m,n;
    int a[105];
    int b[105];
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
     scanf("%d",&a[i]);
    for (i=1;i<n;i++)
     b[i]=a[i]-a[i+1];
    sort(b+1,b+n);
    ans=b[n-1]-m;
    if (ans<0)
     ans=0;
     printf("%d",ans);
}