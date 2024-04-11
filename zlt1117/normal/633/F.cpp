#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long 
using namespace std;
const int maxn=1e5+5;
int p[maxn],a[maxn],f[maxn][5],n,sz;
///0==>1==> 2==>2 3==>24 
struct edge
{
	int v,nxt;
	edge(){}
	edge(int vv,int nn)
	{
		v=vv,nxt=nn;
	}
}e[maxn<<1];
inline void add(int u,int v)
{
	e[++sz]=edge(v,p[u]);
	p[u]=sz;
}
inline int max(int a,int b)
{
	return a<b?b:a;
}
inline void dfs(int u,int fa)
{
	f[u][0]=f[u][1]=a[u];///
	f[u][2]=f[u][3]=f[u][4]=-100000;
	for(int i=p[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa)continue;
		else
		{
			dfs(v,u);
			f[u][3]=max(f[u][3],max(f[u][2]+f[v][0],max(f[u][1]+f[v][1],max(f[u][0]+f[v][2],f[v][3]))));
			f[u][2]=max(f[u][2],max(f[u][0]+f[v][1],max(f[u][4]+f[v][0]+a[u],f[v][2]+a[u])));
			f[u][4]=max(f[u][4],f[v][1]);
			f[u][1]=max(f[u][1],max(f[v][1],f[u][0]+f[v][0]));
			f[u][0]=max(f[u][0],f[v][0]+a[u]);
		}
	} 
}
signed main()
{
	memset(p,-1,sizeof(p));
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n-1;++i)
	{
		int aa,b;
		scanf("%lld%lld",&aa,&b);
		add(aa,b);
		add(b,aa);
	}
	dfs(1,-1);
	printf("%lld\n",f[1][3]);
	return 0;
}