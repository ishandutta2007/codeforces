#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=gc;}
	return (f==1)?x:-x;
}
inline void init(){}
const int maxn=2e5+5;
const int M=30;
struct Trie
{
	static const int maxn=64e5+5;///32times
	int son[maxn][2],tot;
	queue<int>q;
	inline int newnode()
	{
		if(!q.empty()){int u=q.front();q.pop();return u;}
		else return ++tot;
	}
	inline void insert(int &u,int x,int step)
	{
		if(!u)u=newnode();
		if(step==-1)return ;
		insert(son[u][x>>step&1],x,step-1);
	}
	inline int query(int u,int x,int step)
	{
		if(step==-1)return 0;
		if(son[u][x>>step&1])return query(son[u][x>>step&1],x,step-1);
		else return (1<<step)+query(son[u][(x>>step&1)^1],x,step-1);
	}
	inline void remove(int &u)
	{
		if(u==0)return ;
		q.push(u);
		remove(son[u][0]);
		remove(son[u][1]);
		son[u][0]=son[u][1]=0;
	}
	inline void find(int u,vector<int>&vec,int sum,int step)
	{
		if(step==-1)return vec.pb(sum);
		if(son[u][0])find(son[u][0],vec,sum,step-1);
		if(son[u][1])find(son[u][1],vec,sum+(1<<step),step-1);
	}
}trie;
int rt[maxn*32],tot;
int son[maxn*32][2];
inline void build(int u,vector<int>&vec,int step)
{
	if(step==-1)
	{
		for(int x:vec)trie.insert(rt[u],x,M);
		return ; 
	}
	vector<int>ls,rs;
	for(int x:vec)
	{
		if(x>>step&1)rs.pb(x);
		else ls.pb(x); 
	}
	if(!ls.empty())
	son[u][0]=++tot,build(tot,ls,step-1);
	if(!rs.empty())
	son[u][1]=++tot,build(tot,rs,step-1);
}
int a[maxn],n;
ll ans;
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
}
inline void dfs(int u)
{
	if(!son[u][0]&&!son[u][1])return ;
	if(!son[u][1])
	{
		dfs(son[u][0]);
		rt[u]=rt[son[u][0]];
		return ;
	}
	if(!son[u][0])
	{
		dfs(son[u][1]);
		rt[u]=rt[son[u][1]];
		return ;
	}
	dfs(son[u][0]);
	rt[u]=rt[son[u][0]];
	dfs(son[u][1]);
	int now=2e9;
	vector<int>vec;
	trie.find(rt[son[u][1]],vec,0,M);
	for(int x:vec)now=min(now,trie.query(rt[u],x,M));
	for(int x:vec)trie.insert(rt[u],x,M);
	trie.remove(rt[son[u][1]]);
	ans+=now;
}
inline void solve()
{
	vector<int>now;
	FOR(i,1,n)now.pb(a[i]);
	build(0,now,M);
	dfs(0);
	printf("%lld\n",ans);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}