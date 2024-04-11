#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
struct node{
double xx;
int z;
}c[1005];
inline bool cmp(node x,node y)
 {return x.xx<y.xx;
}
int main()
{
    int i,j,k,l,s,m,n;
    int a[1005],b[1005],d[1005];
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
     scanf("%d%d%d",&a[i],&b[i],&c[i].z);
     for (i=1;i<=n;i++)
      c[i].xx=sqrt(a[i]*a[i]+b[i]*b[i]);
    sort(c+1,c+1+n,cmp);
    for (i=1;i<=n;i++)
     if (c[i].z+m>=1000000)
      {printf("%.7lf",c[i].xx);
      return 0;
    }
    else m+=c[i].z;
    printf("%d",-1);   
    }