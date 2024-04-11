#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
    int ans=0,ss=0,ii,jj,i,j,k,l,s=0,m,n;
    int b[1000005],d[1000005];
    char c[505][505],e[1000005];
    int a[505][505];
void th(int i,int j,int u)
 {if (a[i][j]==100||a[i][j]==0)
  return ;
  else {a[i][j]=100;
   s++;
   e[s]='B';
   b[s]=i;d[s]=j;
   th(i-1,j,u+1);
   th(i+1,j,u+1);
   th(i,j-1,u+1);
   th(i,j+1,u+1);
if (u>0)
 {s++;
 e[s]='D';
 b[s]=i;d[s]=j;
 s++;
 e[s]='R';
 b[s]=i;d[s]=j;
}
return ;
}
}
int main()
{
    memset(a,0,sizeof(a));
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
     for (j=1;j<=m;j++)
      {cin>>c[i][j];
      if (c[i][j]=='#')
       a[i][j]=100;
       else a[i][j]=1;
    }
    s=0;

 for (ii=1;ii<=n;ii++)
  for (jj=1;jj<=m;jj++)
  if (a[ii][jj]!=100&&a[ii][jj]!=0)
    th(ii,jj,0);
    printf("%d\n",s);
    for (i=1;i<=s;i++)
     printf("%c %d %d\n",e[i],b[i],d[i]);
}