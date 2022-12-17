#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()
#define mk make_pair
#define iter set<int>::iterator
//#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=2e5+5,mod=998244353;
int n;
vector<pair<int,pair<int,int>>>e[maxn];
map<int,int>mp[maxn];
inline void init()
{
	FOR(i,1,n)e[i].clear(),mp[i].clear();
}
inline void input()
{
	n=gi();
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi(),x=gi(),y=gi();
		int g=__gcd(x,y);x/=g,y/=g;
		e[u].pb({v,{x,y}});e[v].pb({u,{y,x}});
	}
}
inline int qpow(int x,int k)
{
	int ret=1;
	while(k)
	{
		if(k&1)ret=1ll*ret*x%mod;
		k>>=1,x=1ll*x*x%mod;
	}
	return ret;
}
inline vector<int> factor(int x)
{
	int y=x;vector<int>v;
	for(int i=2;i*i<=y;++i)
	{
		while(y%i==0)
		{
			y/=i;
			v.pb(i);
		}
	}
	if(y!=1)v.pb(y);
	return v;
}
inline void dfs(int u,int fa)
{
	for(auto x:e[u])
	{
		int v=x.first,a=x.second.first,b=x.second.second;
		if(v==fa)continue;
		dfs(v,u);
		vector<int>vec=factor(b);
		for(int b:vec)if(mp[v].count(b))mp[v][b]=max(mp[v][b]-1,0);
		vec=factor(a);
		for(int a:vec)mp[v][a]++;
		if(sz(mp[u])<sz(mp[v]))swap(mp[u],mp[v]);
		for(auto x:mp[v])mp[u][x.first]=max(mp[u][x.first],x.second);
	}
}
int answer=0;
inline void dfs2(int u,int fa,int ans)
{
	answer=(answer+ans)%mod;
	int t=ans;
	for(auto x:e[u])
	{
		int v=x.first,a=x.second.first,b=x.second.second;
		if(v==fa)continue;
		ans=1ll*t*qpow(a,mod-2)%mod*b%mod;
		dfs2(v,u,ans);
	}
}
inline void solve()
{
	answer=0;
	dfs(1,0);
	int ans=1;
	for(auto x:mp[1])ans=1ll*ans*qpow(x.first,x.second)%mod;
	dfs2(1,0,ans);
	printf("%d\n",answer);
}
int main()
{
	int T=1;
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}