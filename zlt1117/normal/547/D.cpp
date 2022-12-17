#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define ll long long
#define pb push_back
//#define gc ((p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2))?EOF:*p1++)
#define gc getchar()
#define iter set<int>::iterator
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=4e5+5,M=2e5;
int n,x[maxn],y[maxn];
vector<pair<int,int>>e[maxn]; 
int ans[maxn],cur[maxn],d[maxn];
bool vis[maxn];
inline void dfs(int u)
{
	for(int &i=cur[u];i<sz(e[u]);++i)
	{
		int id=e[u][i].first,v=e[u][i].second;
		if(vis[abs(id)])continue;
		ans[abs(id)]=id>0?1:-1;
		vis[abs(id)]=1,dfs(v);
	}
}
inline void input()
{
	n=gi();
	FOR(i,1,n)x[i]=gi(),y[i]=gi();
	FOR(i,1,n)
	{
		e[x[i]].pb({i,y[i]+M});
		e[y[i]+M].pb({-i,x[i]});
		d[x[i]]++,d[y[i]+M]++;
	}
	vector<int>v;
	FOR(i,1,2*M)if(d[i]&1)v.pb(i);
	int cnt=n;
	for(int i=0;i<sz(v);i+=2)
	{
		e[v[i]].pb({++cnt,v[i+1]});
		e[v[i+1]].pb({-cnt,v[i]});	
	} 
}
inline void solve()
{
	FOR(i,1,2*M)dfs(i);
	FOR(i,1,n)ans[i]==1?putchar('b'):putchar('r');
	puts("");
}
int main()
{
	input();
	solve();
	return 0;
}