#include<stdio.h>
#include<cstring> 
using namespace std;
int main()
{
 int i,j,k,l,s,m,n,a[5];
 long long ans;
 char c[100005];
 scanf("%d%d%d%d",&a[1],&a[2],&a[3],&a[4]);
 scanf("%s",c); 
 j=strlen(c);
 ans=0;
 for (i=0;i<j;i++)
 ans=ans+a[int(c[i])-48];
 printf("%I64d",ans);
}