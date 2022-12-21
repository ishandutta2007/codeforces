#include<stdio.h>
using namespace std;
int main()
{
    int i,j,k,l,s,m,n,ans=0;
    int a[10005];
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
    scanf("%d",&a[i]);
    i=1;
    while (i<=n)
    {
        s=0;
        ans++;
        while (s<=m&&i<=n)
        {
            if (s+a[i]<=m)
            {
                s+=a[i];
                i++;
            }
            else
            break;
        }
    }
    printf("%d",ans);
}