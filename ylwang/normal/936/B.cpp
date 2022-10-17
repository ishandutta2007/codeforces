#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define ll long long
#define il inline
#define re register
#define fp(i,a,b) for(re int i=a;i<=b;i++)
#define fq(i,a,b) for(re int i=a;i>=b;i--)
using namespace std;
const int N=1e5+100;
int n,h[N],cnt,m,vis[N][2],st,len[N],f=0,top,chu[N],dfn[N],low[N],tim,inq[N],scc,Stack[N],t[N],mx;
struct Edge
{
    int to,next;
}e[N<<1];
il void add(re int u,re int v)
{
  e[++cnt]=(Edge){v,h[u]};h[u]=cnt;
}
il void Tarjan(re int u)//
{
  dfn[u]=low[u]=++tim;
  Stack[++top]=u;
  inq[u]=1;
  for(re int i=h[u];i;i=e[i].next)
    {
      re int v=e[i].to;
      if(!dfn[v]) Tarjan(v),low[u]=min(low[u],low[v]);
      else if(inq[v]) low[u]=min(low[u],dfn[v]);
    }
  if(low[u]==dfn[u])
    {
      ++scc;
      while(Stack[top]^u)
    {
      inq[Stack[top]]=0;
      t[scc]++;--top;
    }
      inq[u]=0;--top;
      t[scc]++;mx=max(mx,t[scc]);
    }
}
il void dfs(re int u,re int mk)//mk
{
    for(re int i=h[u];i;i=e[i].next)
    {
      re int v=e[i].to;
      if(vis[v][mk^1]) continue;//
      vis[v][mk^1]=1;
      len[++top]=v;//
      if(!mk&&!chu[v]){printf("Win\n");fp(i,0,top) printf("%d ",len[i]);exit(0);}//
      dfs(v,mk^1);
      --top;
    }
}
il int gi()
{
    re int x=0,t=1;
    re char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') t=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
    return x*t;
}
int main()
{
    n=gi();m=gi();
    fp(i,1,n)
    {
        chu[i]=gi();
        fp(j,1,chu[i]) add(i,gi());
    }
    len[0]=gi();
    dfs(len[0],0);top=0;
    Tarjan(len[0]);//
    if(mx>1) {puts("Draw");return 0;}
    puts("Lose");
    return 0;
}