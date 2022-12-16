#include<stdio.h>
using namespace std;
int main()
{
    int a[100005];
    int s=0,i,j,k,l,n,m;
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
    scanf("%d",&a[i]);
    for (i=1;i<=m;i++)
    {
        scanf("%d%d",&j,&k);
        if (a[j]<a[k])
        s+=a[j];
        else
        s+=a[k];
    }
    printf("%d",s);
}