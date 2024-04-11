#include<stdio.h>
using namespace std;
 int ans=0,i,j,k,l,s,m,n;
 int a[6][6];
inline int  check(int o,int p,int q,int u,int w)
{
 if (o==p)
 return 0;
 if (o==q)
 return 0;
 if (o==u)
 return 0;
 if (o==w)
 return 0;
 if (p==q)
 return 0;
 if (p==u)
 return 0;
 if (p==w)
 return 0;
 if (q==u)
 return 0;
 if (q==w)
 return 0;
 if (u==w)
 return 0;
 int now=0;
 now=a[p][q]+a[q][p]+a[u][w]+a[w][u]+a[q][u]+a[u][q]+a[u][w]+a[w][u]+a[o][p]+a[p][o]+a[q][u]+a[u][q];
 return now;
}
int main()
{

 for (i=1;i<=5;i++)
 for (j=1;j<=5;j++)
 scanf("%d",&a[i][j]);
 s=0;
 for (i=1;i<=5;i++)
 for (j=1;j<=5;j++)
 for (k=1;k<=5;k++)
 for (l=1;l<=5;l++)
 for (m=1;m<=5;m++)
 {
  s=check(i,j,k,l,m);
  if (s>ans)
  ans=s;
}
printf("%d",ans);
}