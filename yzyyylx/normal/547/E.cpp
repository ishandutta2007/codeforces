#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define N 200100
#define M 500100
using namespace std;

int n,m,Q,tt,ttt,sz[N],first[N],bb,in[N],out[N],ans[M],sp[N];
string str[N];
struct Node
{
	int son[26],fail;
}node[N];
struct Bn
{
	int to,next;
}bn[N];
struct Qu
{
	int pos,k,id,type;
	bool operator < (const Qu &u) const
	{
		return pos<u.pos;
	}
}qu[M<<1];
queue<int>que;

inline void ade(int u,int v)
{
	bb++;
	bn[bb].to=v;
	bn[bb].next=first[u];
	first[u]=bb;
}

inline void add(int v)
{
	int i,j,u,now=0;
	for(i=0;i<str[v].size();i++)
	{
		u=str[v][i]-'a';
		if(!node[now].son[u])
		{
			node[now].son[u]=++tt;
		}
		now=node[now].son[u];
	}
	sp[v]=now;
}

inline void build()
{
	int p,q,i,j,k;
	for(i=0;i<26;i++)
	{
		if(node[0].son[i])
		{
			node[node[0].son[i]].fail=0;
			ade(0,node[0].son[i]);
			que.push(node[0].son[i]);
		}
	}
	for(;!que.empty();)
	{
		p=que.front();
		que.pop();
		for(i=0;i<26;i++)
		{
			if(node[p].son[i])
			{
				for(k=node[p].fail;k&&!node[k].son[i];k=node[k].fail);
				node[node[p].son[i]].fail=node[k].son[i];
				ade(node[k].son[i],node[p].son[i]);
				que.push(node[p].son[i]);
			}
		}
	}
}

inline int lb(int u){return u&(-u);}
inline void ad(int u,int v){for(;u<=ttt;u+=lb(u)) sz[u]+=v;}
inline int ask(int u){int res=0;for(;u;u-=lb(u)) res+=sz[u];return res;}

inline void ads(int v)
{
	int i,now=0;
	for(i=0;i<str[v].size();i++)
	{
		now=node[now].son[str[v][i]-'a'];
		ad(in[now],1);
	}
}

void dfs(int now)
{
	int i,j,p,q;
	in[now]=++ttt;
	for(p=first[now];p!=-1;p=bn[p].next)
	{
		dfs(bn[p].to);
	}
	out[now]=ttt;
}

int main()
{
	ios::sync_with_stdio(0);
	bb=0;
	memset(first,-1,sizeof(first));
	int i,j,k,p,q,o;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>str[i];
		add(i);
	}
	build();
	dfs(0);
//	p=node[o].son[1];
//	cout<<in[p]<<" "<<out[p];return 0;
//	for(i=0;i<=ttt;i++) cout<<in[i]<<" "<<out[i]<<endl;
	for(i=1;i<=m;i++)
	{
		cin>>p>>q>>o;
		qu[++Q].id=i;
		qu[Q].pos=p-1;
		qu[Q].type=-1;
		qu[Q].k=sp[o];
		
		qu[++Q].id=i;
		qu[Q].pos=q;
		qu[Q].type=1;
		qu[Q].k=sp[o];
	}
	sort(qu+1,qu+Q+1);
	for(i=1,j=1;i<=Q;i++)
	{
//		if(!qu[i].pos) continue;
		for(;j<=qu[i].pos&&j<=n;j++) ads(j);
		ans[qu[i].id]+=qu[i].type*(ask(out[qu[i].k])-ask(in[qu[i].k]-1));
//		if(qu[i].id==5) cout<<qu[i].k<<" "<<in[qu[i].k]<<" "<<out[qu[i].k]<<endl;
	}
	for(i=1;i<=m;i++) cout<<ans[i]<<endl;
}