//#pragma GCC optimize("Ofast")
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
int n;
bool vis[maxn];
vector<pair<int,int> >e[maxn];
int siz[maxn],d[maxn],now,fib[maxn],tot;
map<int,int>mp;
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi();
		e[u].pb({i,v}),e[v].pb({i,u});
		d[u]++,d[v]++;
	}
	FOR(i,1,n)if(d[i]==1)now=i;
	int x=1,y=1;
	fib[1]=tot=1;mp[1]=1;fib[0]=1;
	while(x<=n)
	{
		y=x+y;
		fib[++tot]=y;
		mp[y]=tot;
		swap(x,y);
	}
}
vector<int>temp;
int fa[maxn];
inline void getdis(int u,int f)
{
	siz[u]=1;
	temp.pb(u);
	for(auto x:e[u])
	{
		int v=x.second,i=x.first;
		if(v==f||vis[i])continue;
		fa[v]=u;
		getdis(v,u);
		siz[u]+=siz[v];
	}
}
inline void getd(int u,int f)
{
	d[u]=0;
	for(auto x:e[u])
	{
		int v=x.second;
		if(vis[x.first]||v==f)continue;
		getd(v,u);
		d[u]++;
	}
	if(d[u]<=1)now=u;
}
inline bool dfs(int u)
{
	temp.clear();
	getdis(u,0);
	if(sz(temp)==1)return true;
	bool ok=0;
	for(auto x:temp)
	{
		if(x!=u&&(siz[x]==fib[mp[siz[u]]-2]||siz[x]==fib[mp[siz[u]]-1]))
		{
			for(auto y:e[x])
			{
				now=x;
				if(y.second==fa[x])
				{
					vis[y.first]=1;
					break;
				}
			}
			ok=1;
			break;
		}
	}
	if(ok==0)return false;
	int now1=now,now2=fa[now];
	for(auto x:temp)d[x]=fa[x]=siz[x]=0;
	getd(now1,0);
	if(!dfs(now))return false;
	getd(now2,0);
	return dfs(now);
}
inline void solve()
{
	if(!mp.count(n))printf("no\n");
	else printf(dfs(now)?"yes\n":"no\n");
}
int main()
{
	int T=1;
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}
/*
8
1 2
1 3
2 4
2 5
3 6
3 7
1 8
*/