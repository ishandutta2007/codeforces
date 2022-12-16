#include<stdio.h>
using namespace std;
int x[200005],y[200005],i,j,k,l,s,m,n,gt,gg,st,gtw;
int main()
{
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        if (y[i]>gt)
        {
            gg=gt;
            gt=y[i];
            st=i;
        }
        else
        if (y[i]>gg)
        gg=y[i];
        gtw+=x[i];
    }
    for (i=1;i<=n;i++)
    {
        if (i!=st)
        printf("%d ",gt*(gtw-x[i]));
        else
        printf("%d ",gg*(gtw-x[i]));
    }
}