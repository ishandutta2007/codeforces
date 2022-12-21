#include<stdio.h>
#include<algorithm>
using namespace std;
int ans=1000000,a[100005],i,n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;i++)
    scanf("%d",&a[i]);
    sort(a+1,a+1+m);
    for (i=1;i<=m;i++)
    {
        if (i+n-1>m)
        break;
        ans=min(ans,a[i+n-1]-a[i]);
    }
    printf("%d\n",ans);
}