//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define se second
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=2e5+5;
int n,a[maxn];
vector<int>e[maxn];
map<int,int>mp[maxn];
int vis[maxn],nvis[maxn],ok[maxn],counter;
int dep[maxn];
inline void merge(int u,int v)
{
	if(sz(mp[u])>sz(mp[v]))swap(mp[u],mp[v]);
	for(auto x:mp[u])
	{
		if(!mp[v].count(x.first))mp[v][x.first]=x.second;
		else 
		{
			nvis[x.second]=nvis[mp[v][x.first]]=1;
			mp[v][x.first]=dep[mp[v][x.first]]<dep[x.second]?mp[v][x.first]:x.second;
		}
	}
	map<int,int>temp;
	swap(temp,mp[u]);
}
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u);
	}
}
inline void dfs(int u,int f)
{
	for(auto v:e[u])
	{
		if(v==f)continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}
inline void dfs1(int u,int f)
{
	for(auto v:e[u])
	{
		if(v==f)continue;
		dfs1(v,u);
		if(mp[v].count(a[u]))vis[v]=1,nvis[mp[v][a[u]]]=1,counter++;
		merge(v,u);
	}
	mp[u][a[u]]=u;
}
int ans;
inline void dfs2(int u,int f)
{
	if(!nvis[u]&&vis[u]==counter)ans++;
	for(auto v:e[u])
	{
		if(v==f)continue;
		vis[v]+=vis[u];
		nvis[v]|=nvis[u];
		dfs2(v,u);
	}
}
inline void solve()
{
	dfs(1,0);
	dfs1(1,0);
	dfs2(1,0);
	printf("%d\n",ans);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}
/*
3
1 3 2
1 2
2 3
*/