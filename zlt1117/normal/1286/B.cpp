#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxn=2005;
int fa[maxn],p[maxn],c[maxn],a[maxn],n,sz,rt,dep[maxn],cnt,sum;
bool vis[maxn];
struct edge
{
	int v,nxt;
	edge(){}
	edge(int vv,int nn)
	{
		v=vv,nxt=nn;
	}
}e[maxn<<1];
struct node
{
	int u,de;
	node(){}
	node(int uu,int dd)
	{
		u=uu,de=dd;
	}
	inline bool operator<(const node&b)const
	{
		return de>b.de;
	}
};
inline void add(int u,int v)
{
	e[++sz]=edge(v,p[u]);
	p[u]=sz;
}
inline void dfs(int u)
{
	dep[u]=dep[fa[u]]+1;
	for(int i=p[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa[u])continue;
		else
		{
			dfs(v);
		}
	}
}
inline void bfs()
{
	priority_queue<node>pq;
	for(int i=1;i<=n;++i)
	{
		if(c[i]==0)
		{
			pq.push(node(i,dep[i]));
			cnt--;
		}
	}
	while(!pq.empty())
	{
		int x=pq.top().u;
		pq.pop();
		vis[x]=true;
		a[x]=++sum;
		for(int i=x;i!=0;i=fa[i])
		{
			if(!vis[i])
			{
				c[i]--;
				if(c[i]==0)
				{
					pq.push(node(i,dep[i]));
					cnt--;
				}
			}
		}
	}
	if(cnt!=0)
	{
		printf("NO\n");
		exit(0);
	}
}
int main()
{
	memset(p,-1,sizeof(p));
	scanf("%d",&n);
	cnt=n;
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&fa[i],&c[i]);
		if(fa[i]==0)rt=i;
		add(i,fa[i]);
		add(fa[i],i);
	}
	dfs(rt);
	bfs();
	printf("YES\n");
	for(int i=1;i<=n;++i)
	{
		printf("%d ",a[i]);
	}
	return 0;
}