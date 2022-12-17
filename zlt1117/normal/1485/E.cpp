#pragma GCC optimize(4)
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
#define db double
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
int fa[maxn],a[maxn],dep[maxn],n,d;
ll temp[maxn];
vector<int>vec[maxn],e[maxn];
ll dp[maxn];
inline void init()
{
	FOR(i,0,n)vec[i].clear(),e[i].clear(),temp[i]=dp[i]=fa[i]=a[i]=dep[i]=0;
}
inline void dfs(int u)
{
	if(u==1)return ;
	else if(dep[u])return ;
	dfs(fa[u]);
	dep[u]=dep[fa[u]]+1;
}
inline void input()
{
	n=gi();
	FOR(i,2,n)fa[i]=gi(),e[fa[i]].pb(i);
	FOR(i,2,n)a[i]=gi();vec[0].pb(1);
	FOR(i,2,n)dfs(i),d=max(d,dep[i]),vec[dep[i]].pb(i);
}
inline bool cmp(const int &x,const int &y){return a[x]<a[y];}
inline void solve()
{
	int minv=1e9,maxv=-1e9;
	for(auto x:vec[d])minv=min(minv,a[x]),maxv=max(maxv,a[x]);
	for(auto x:vec[d])dp[x]=max(a[x]-minv,maxv-a[x]);
	for(int i=d-1;i>=0;--i)
	{
		minv=1e9,maxv=-1e9;
		for(auto x:vec[i])minv=min(minv,a[x]),maxv=max(maxv,a[x]);
		for(auto x:vec[i])
		{
			for(auto y:e[x])temp[x]=max(temp[x],dp[y]);
			dp[x]=max(dp[x],temp[x]+max(a[x]-minv,maxv-a[x]));
		}
		sort(vec[i].begin(),vec[i].end(),cmp);
		set<ll>s1,s2;
		for(auto x:vec[i])s1.insert(temp[x]+a[x]);
		for(auto x:vec[i])
		{
			if(s1.size())
			{
				auto it=s1.end();--it;
				dp[x]=max(dp[x],(*it)-a[x]);
			}
			if(s2.size())
			{
				auto it=s2.end();--it;
				dp[x]=max(dp[x],(*it)+a[x]);
			}
			s1.erase(temp[x]+a[x]);
			s2.insert(temp[x]-a[x]);
		}
	}
	printf("%lld\n",dp[1]);
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
/*
1
3 
1 1
2 1000
*/