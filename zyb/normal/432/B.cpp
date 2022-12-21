#include<stdio.h>
using namespace std;
int a[100005],b[100005],d[100005],f[100005],e[100005];
int main()
{
    int i,j,k,l,s,m,n;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d%d",&d[i],&b[i]);
        a[d[i]]++;
    }
    for (i=1;i<=n;i++)
    {
        f[i]=n-1;
        f[i]+=a[b[i]];
        e[i]=n-1;
        e[i]-=a[b[i]];
        printf("%d %d\n",f[i],e[i]);
    }
}