#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define ll long long
#define pb push_back
//#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2))?EOF:*p1++;
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
inline pair<int,int> query(vector<int>v)
{
	printf("? %d ",sz(v));
	for(int x:v)printf("%d ",x);
	puts("");fflush(stdout);
	int x=gi(),d=gi();
	return pair<int,int>(x,d); 
}
inline void answer(int x,int y)
{
	printf("! %d %d\n",x,y);
	fflush(stdout);
	char s[100];scanf("%s",s+1);
	if(s[1]=='I')exit(0);
}
const int maxn=2005;
int n,dep[maxn],maxdepth;
vector<int>depth[maxn];
vector<int>e[maxn];
int fa[maxn];
bool vis[maxn];
inline void init()
{
	FOR(i,1,n)fa[i]=dep[i]=0,e[i].clear(),vis[i]=0;
	FOR(i,1,n)depth[i].clear();
}
inline void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;::fa[u]=fa;
	maxdepth=max(maxdepth,dep[u]);
	depth[dep[u]].pb(u);
	for(int v:e[u])
	{
		if(v==fa)continue;
		dfs(v,u); 
	}
}
inline void input()
{
	n=gi();maxdepth=0;
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u); 
	}
}
inline void solve()
{
	vector<int>v;FOR(i,1,n)v.pb(i);
	pair<int,int>now=query(v);
	dfs(now.first,0);
	int l=(now.second+1)/2,ret=now.first,d=now.second,r=min(maxdepth,d+1);
	while(l<=r)
	{
		int mid=(l+r)>>1;
		now=query(depth[mid]);
		if(now.second==d)l=mid+1,ret=now.first;
		else r=mid-1; 
	}
	int x=ret;
	while(dep[x]!=1)vis[x]=1,x=fa[x];
	int ansl=ret,ansr=0,resd=d-dep[ansl]+2;
	v.clear();for(int x:depth[resd])if(!vis[x])v.pb(x);
	ansr=query(v).first;
	answer(ansl,ansr);
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
}