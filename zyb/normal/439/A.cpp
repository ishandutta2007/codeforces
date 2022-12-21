#include<stdio.h>
using namespace std;
int main()
{
    int ans,i,j,k,l,s=0,m,n;
    int a[10005];
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s=s+a[i]+10;
    }
    s-=10;
    ans=0;
    if (s<=m)
    ans=ans+(n-1)*2;
    else
    {
        printf("-1");
        return 0;
    }
    s=m-s;
    while (s>0)
    {
        s=s-5;
        ans++;
    }
    if (s<0)
    ans--;
    printf("%d",ans);
}