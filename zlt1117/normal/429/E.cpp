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
const int maxn=2e5+5;
int l[maxn],r[maxn],temp[maxn],tot,n,cnt;
vector<pair<int,int>>e[maxn];
int vis[maxn],d[maxn];
inline void input()
{
	n=gi();
	FOR(i,1,n)l[i]=gi(),r[i]=gi(),temp[++tot]=l[i],temp[++tot]=r[i]+1;
	sort(temp+1,temp+tot+1),tot=unique(temp+1,temp+tot+1)-temp-1;
	FOR(i,1,n)l[i]=lower_bound(temp+1,temp+tot+1,l[i])-temp,\
	r[i]=lower_bound(temp+1,temp+tot+1,r[i]+1)-temp;
}
int cur[maxn];
inline void dfs(int u)
{
	for(int &i=cur[u];i<sz(e[u]);i++)
	{
		int id=e[u][i].first,v=e[u][i].second;
		if(vis[id])continue;
		vis[id]=v>u?2:1;
		dfs(v);
	}
}
inline void solve()
{
	vector<int>v;
	FOR(i,1,n)e[l[i]].pb({i,r[i]}),e[r[i]].pb({i,l[i]}),d[l[i]]++,d[r[i]]++;
	FOR(i,1,tot)if(d[i]&1)v.pb(i);
	cnt=n;
	for(int i=0;i<sz(v);i+=2)
	{
		++cnt;
		e[v[i]].pb({cnt,v[i+1]});
		e[v[i+1]].pb({cnt,v[i]});
	}
	FOR(i,1,tot)dfs(i);
	FOR(i,1,n)printf("%d ",vis[i]-1);
}
int main()
{
	input();
	solve();
	return 0;
}