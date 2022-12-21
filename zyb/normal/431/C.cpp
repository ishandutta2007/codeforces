#include<stdio.h>
#include<cstring>
#include<iostream>
#define P 1000000007
using namespace std;
int main()
{
 int i,j,k,l,s,m,n;
 long long ans;
 int f[105];
 memset(f,0,sizeof(f));
 scanf("%d%d%d",&n,&m,&k);
 k--;
 f[0]=1;
 for (i=1;i<=n;i++)
 for (j=1;j<=min(i,m);j++)
 f[i]=(f[i]+f[i-j])%P;
 /*for (i=1;i<=n;i++)
 f[i]=f[i]*2;*/
 ans=0;
 ans=f[n]%P;
 memset(f,0,sizeof(f));
 f[0]=1;
 for (i=1;i<=n;i++)
 for (j=1;j<=min(i,k);j++)
 f[i]=(f[i]+f[i-j])%P;
 ans-=f[n];
 while (ans<0)
 ans=ans+P;
 printf("%I64d",ans);
}