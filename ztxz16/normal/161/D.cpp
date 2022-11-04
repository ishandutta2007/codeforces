#include <stdio.h>
#include <stdlib.h>
#define ll long long

ll n,k,a,b,ans,i,h,t,zl[100005];
ll e[100005],succ[100005],last[100005],sum;
ll father[100005],now;
ll f[50005][505],x,j;

int main()
{
    scanf("%I64d %I64d",&n,&k);
    for(i=1;i<n;i++)
    {
       scanf("%I64d %I64d",&a,&b);
       e[++sum]=b,succ[sum]=last[a],last[a]=sum;
       e[++sum]=a,succ[sum]=last[b],last[b]=sum;
    }
    zl[1]=1;
    father[1]=0;
    for(h=t=1;h<=t;h++)
    {
       now=zl[h];
       f[now][0]=1;
       for(x=last[now];x!=0;x=succ[x])
       {
          if (e[x]==father[now]) continue;
          father[e[x]]=now;
          zl[++t]=e[x];
       }
    }
    for(i=t;i>=2;i--)
    {
       now=zl[i];
       for(j=0;j<k;j++)
          f[father[now]][j+1]+=f[now][j];
    }
    for(i=1;i<=t;i++)
    {
       now=zl[i];
       ans+=f[now][k];
       for(x=last[now];x!=0;x=succ[x])
       {
          if (e[x]==father[now]) continue;
          for(j=k-1;j>=0;j--)
          {
             f[e[x]][j+1]+=f[now][j];
             if (j>0) f[e[x]][j+1]-=f[e[x]][j-1];
          }
       }
    }
    printf("%I64d\n",ans/2);
    return 0;
}