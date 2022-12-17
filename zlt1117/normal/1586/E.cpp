#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define sz(x) (int)(x.size())
#define pb push_back
#define PII pair<int,int>
#define ll long long
#define gc getchar()
//#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
using namespace std;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=3e5+5;
int n,m,Q;
vector<int>e[maxn];
bool vis[maxn];
vector<int>tmp[maxn];
int cnt[maxn],dep[maxn]; 
int u[maxn],v[maxn],fa[maxn];
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,m)
	{
		int u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u);
	}
}
inline void dfs(int u)
{
	dep[u]=dep[fa[u]]+1;
	vis[u]=1;
	for(int v:e[u])
	{
		if(v==fa[u]||vis[v])continue;
		fa[v]=u,dfs(v);
	}
}
inline vector<int> get_path(int u,int v)
{
	vector<int>v1,v2;
	while(dep[v]>dep[u])v2.pb(v),v=fa[v];
	while(dep[u]>dep[v])v1.pb(u),u=fa[u];
	while(u!=v)v1.pb(u),v2.pb(v),u=fa[u],v=fa[v];
	v1.pb(u);
	reverse(v2.begin(),v2.end());
	for(int x:v2)v1.pb(x);
	return v1;
}
inline void solve()
{
	dfs(1);
	Q=gi();
	FOR(i,1,Q)
	{
		u[i]=gi(),v[i]=gi();
		cnt[u[i]]++,cnt[v[i]]++;
	}
	int ans=0;
	FOR(i,1,n)if(cnt[i]&1)ans++;
	if(ans>0)printf("NO\n%d\n",ans/2);
	else
	{
		puts("YES");
		FOR(i,1,Q)
		{
			vector<int>path=get_path(u[i],v[i]);
			printf("%d\n",sz(path));
			for(int x:path)printf("%d ",x);
			puts("");
		}
	}
}
int main()
{
	input();
	solve();
	return 0;
}