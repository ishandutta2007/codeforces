#include<stdio.h>
using namespace std;
int main()
{
    int ans=0,i,j,k,l,s,m,n;
    int d[55];
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
    {
        bool b=false;
        scanf("%d",&k);
        for (j=1;j<=k;j++)
        {
        scanf("%d",&l);
        if (m>l)
        if (!b)
        {
            ans++;
            d[ans]=i;
            b=true;
        }
        }
    }
    printf("%d\n",ans);
    for (i=1;i<=ans;i++)
    printf("%d ",d[i]);
}