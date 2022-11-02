#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define INF 0x3f3f3f3f
#define N 400100
using namespace std;

int n,m,Q,first[N],dfn[N],low[N],sta[N],bj[N],top[N],sn[N],fa[N],deep[N],dep[N],tp,bb=1,tt,yn;
bool vis[1001000];
struct Bn
{
	int to,next;
} bn[1001000];
vector<int>son[N];

inline void add(int u,int v)
{
	bb++;
	bn[bb].to=v;
	bn[bb].next=first[u];
	first[u]=bb;
}

void dfs(int now)
{
	int p,q,t;
	low[now]=dfn[now]=++tt;
	for(p=first[now]; p!=-1; p=bn[p].next)
	{
		q=p>>1;
		if(vis[q]) continue;
		vis[q]=1;
		sta[++tp]=q;
		if(dfn[bn[p].to]) low[now]=min(low[now],dfn[bn[p].to]);
		else
		{
			dfs(bn[p].to);
			low[now]=min(low[now],low[bn[p].to]);
			if(low[bn[p].to]>=dfn[now])
			{
				++n;
				for(;; tp--)
				{
					t=bn[sta[tp]<<1].to;
					if(bj[t]!=n)
					{
						son[n].push_back(t);
						son[t].push_back(n);
						bj[t]=n;
					}
					t=bn[(sta[tp]<<1)+1].to;
					if(bj[t]!=n)
					{
						son[n].push_back(t);
						son[t].push_back(n);
						bj[t]=n;
					}
					if(sta[tp]==q) break;
				}
				tp--;
			}
		}
	}
}

int Dfs(int now,int last)
{
	int i,j,res=1,mx=0,t;
	for(i=0; i<son[now].size(); i++)
	{
		if(son[now][i]==last) continue;
		deep[son[now][i]]=deep[now]+(son[now][i]>yn);
		dep[son[now][i]]=dep[now]+1;
		fa[son[now][i]]=now;
		res+=t=Dfs(son[now][i],now);
		if(t>mx)
		{
			mx=t;
			sn[now]=son[now][i];
		}
	}
	return res;
}

void D2(int now,int last)
{
	int i,j;
	if(sn[now])
	{
		top[sn[now]]=top[now];
		D2(sn[now],now);
	}
	else return;
	for(i=0; i<son[now].size(); i++)
	{
		if(son[now][i]==last || son[now][i]==sn[now]) continue;
		top[son[now][i]]=son[now][i];
		D2(son[now][i],now);
	}
}

inline int lca(int u,int v)
{
	for(;top[u]!=top[v];)
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}

int main()
{
	memset(first,-1,sizeof(first));
	int i,j,p,q,t;
	cin>>n>>m>>Q;
	yn=n;
	for(i=1; i<=m; i++)
	{
		scanf("%d%d",&p,&q);
		add(p,q),add(q,p);
	}
	dep[1]=top[1]=1;
	deep[1]=0;
	dfs(1);
	tt=0;
	Dfs(1,-1);
	D2(1,-1);
	
//	for(i=1;i<=n;i++) cout<<deep[i]<<" ";return 0;
	
	for(i=1;i<=Q;i++)
	{
		scanf("%d%d",&p,&q);
		t=lca(p,q);
		printf("%d\n",deep[p]+deep[q]-deep[t]*2+(t>yn));
	}
}