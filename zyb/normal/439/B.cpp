#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,k,l,s,m,n;
    int a[100005];
    long long ans=0;
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
    scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for (i=1;i<=n;i++)
    {
        ans=ans+1ll*a[i]*m;
        m--;
        if (m<=0)
        m=1;
    }
   printf("%I64d",ans);
}