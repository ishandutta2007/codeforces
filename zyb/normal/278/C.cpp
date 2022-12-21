#include<iostream>
#include<stdio.h>
#include<cstring>
int fa[105],a[105][105],k[105],e[105];
inline int get(int p)
{
    if(fa[p]==p)return p;
    fa[p]=get(fa[p]);
    return fa[p];
}
int main()
{
  bool bb[105];
  memset(bb,false,sizeof(bb));
    int q,i,j,l,s,m,n,z,x,y;
      s=0;
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
     {scanf("%d",&k[i]);
     
     if (k[i]==0)
      {s++;
      e[s]=0;
      bb[i]=true;
      fa[i]=i;
    }
    else fa[i]=i;
     for (j=1;j<=k[i];j++)
      scanf("%d",&a[i][j]);
}
if (s==n)
 {printf("%d",n);
 return 0;
}
bool b=false;
for (i=1;i<n;i++)
 for (j=i+1;j<=n;j++)
  {
        if (bb[i]!=true&&bb[j]!=true)
  {
        b=false;
        for (q=1;q<=k[i];q++)
   for (l=1;l<=k[j];l++)
    if (a[i][q]==a[j][l])
     {z=get(i);
     y=get(j);
     fa[z]=y;
     b=true;
     break;
    }
}
}
for (i=1;i<=n;i++)
 {if (bb[i]!=true)
 {
        j=get(i);
 for (l=1;l<=s;l++)
  if (e[l]==j)
   break;
if (l>s)
 {s++;
 e[s]=j;
}
}
}
printf("%d",s-1);
}