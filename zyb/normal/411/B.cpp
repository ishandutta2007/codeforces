#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int a[105][105],b[105],c[105];
    bool bb[105];
    int i,j,k,l,s,m,n;
    scanf("%d%d%d",&n,&m,&k);
    for (i=1;i<=n;i++)
     for (j=1;j<=m;j++)
      scanf("%d",&a[i][j]);
      for (i=1;i<=n;i++)
      c[j]=0;
      for (j=0;j<=k;j++)
      bb[j]=false;
     
    for (i=1;i<=m;i++)
     { for (j=0;j<=k;j++)
      b[j]=0;
            for (j=1;j<=n;j++)
            if (a[j][i]!=0)
            {
            if (c[j]==0)
            {
     if (b[a[j][i]]==0&&bb[a[j][i]]==false)
      b[a[j][i]]=j;
      else {
       c[j]=i;
      c[b[a[j][i]]]=i;
      bb[a[j][i]]=true;
    }
}
}
}
for (i=1;i<=n;i++)
 printf("%d\n",c[i]);
}