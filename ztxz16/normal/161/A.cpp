#include <stdio.h>
#include <stdlib.h>

int n,m,x,y,i,j,sum,ans[100005];
int a[100005],b[100005];

int main()
{
    scanf("%d %d %d %d",&n,&m,&x,&y);
    for(i=1;i<=n;i++)
       scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
       scanf("%d",&b[i]);
    j=1;
    for(i=1;i<=n;i++)
    {
       while (b[j]<a[i]-x && j<=m) j++;
       if (j<=m && b[j]<=a[i]+y) sum++,ans[i]=j,j++;
    }
    printf("%d\n",sum);
    for(i=1;i<=n;i++)
       if (ans[i]!=0) printf("%d %d\n",i,ans[i]);
    return 0;
}