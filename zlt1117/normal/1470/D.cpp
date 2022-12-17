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
#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=3e5+5;
int n,m;
vector<int>e[maxn];
int col[maxn];
bool vis[maxn];
inline void init()
{
	FOR(i,1,n)col[i]=0,vis[i]=0,e[i].clear();
}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,m)
	{
		int u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u);
	}
}
inline void dfs(int u,int f)
{
	vis[u]=1;
	for(auto x:e[u])
	{
		if(!vis[x])dfs(x,u);
	}
}
int fa[maxn];
inline int get(int x)
{
	if(x==fa[x])return x;
	else return fa[x]=get(fa[x]);
}
inline void solve()
{
	dfs(1,0);
	FOR(i,1,n)if(!vis[i]){printf("NO\n");return ;}
	FOR(i,1,n)fa[i]=i,vis[i]=0;
	printf("YES\n");
	vector<int>vec;
	set<int>s;s.insert(1); 
	while(!s.empty())
	{
		int x=*s.begin();
		s.erase(s.begin());
		if(vis[x])continue;
		vec.pb(x);
		vis[x]=1;
		for(auto v:e[x])
		{
			if(vis[v])continue;
			vis[v]=1;
			for(auto z:e[v])
			{
				if(!vis[z])s.insert(z);
			}
		}
	}
	printf("%d\n",sz(vec));
	for(auto x:vec)printf("%d ",x);
	printf("\n");
}
int main()
{
	int T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}///