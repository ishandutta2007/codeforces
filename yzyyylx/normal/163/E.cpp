#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#define ll long long
#define N 100100
#define M 1001000
using namespace std;

int n,m,tt,pos[N],in[M],out[M];
ll sz[M],ans;
bool zt[N];
string str;
struct Node
{
	int fail,to[26];
}node[M];
vector<int>son[M];
queue<int>que;

inline void add(int v)
{
	int i,now=0,u;
	for(i=0;i<str.size();i++)
	{
		u=str[i]-'a';
		if(!node[now].to[u])
		{
			node[now].to[u]=++tt;
		}
		now=node[now].to[u];
	}
	pos[v]=now;
}

inline void build()
{
	int i,j,k,p,q;
	for(i=0;i<26;i++)
	{
		if(node[0].to[i])
		{
			que.push(node[0].to[i]);
		}
	}
	for(;!que.empty();)
	{
		p=que.front();
		que.pop();
		for(i=0;i<26;i++)
		{
			if(node[p].to[i])
			{
				for(k=node[p].fail;k&&!node[k].to[i];k=node[k].fail);
				node[node[p].to[i]].fail=node[k].to[i];
				que.push(node[p].to[i]);
			}
		}
	}
	for(i=1;i<=tt;i++) son[node[i].fail].push_back(i);
}

void dfs(int now)
{
	ll i;
	in[now]=++tt;
	for(i=0;i<son[now].size();i++)
	{
		dfs(son[now][i]);
	}
	out[now]=tt;
}

inline int lb(int u){return u&(-u);}
inline void ad(int u,ll v){for(;u<=tt;u+=lb(u)) sz[u]+=v;}
inline ll ask(int u){ll res=0;for(;u;u-=lb(u)) res+=sz[u];return res;}

inline void find()
{
	int i,now=0,u;
	for(i=1;i<str.size();i++)
	{
		u=str[i]-'a';
		for(;now&&!node[now].to[u];now=node[now].fail);
		now=node[now].to[u];
		ans+=ask(in[now]);
	}
}

int main()
{
	int i,j,p,q;
	cin>>m>>n;
	for(i=1;i<=n;i++)
	{
		cin>>str;
		add(i);
	}
	build();
	tt=0;
	dfs(0);
	for(i=1;i<=n;i++)
	{
		p=pos[i];
		ad(in[p],1);
		ad(out[p]+1,-1);
	}
	for(i=1;i<=m;i++)
	{
		cin>>str;
		if(str[0]=='?')
		{
			ans=0;
			find();
			printf("%lld\n",ans);
		}
		else
		{
			if(str[0]=='+')
			{
				p=0;
				for(j=1;j<str.size();j++) p=p*10+str[j]-'0';
				if(!zt[p]) continue;
				zt[p]=0;
				p=pos[p];
				ad(in[p],1),ad(out[p]+1,-1);
			}
			else
			{
				p=0;
				for(j=1;j<str.size();j++) p=p*10+str[j]-'0';
				if(zt[p]) continue;
				zt[p]=1;
				p=pos[p];
				ad(in[p],-1),ad(out[p]+1,1);
			}
		}
	}
}