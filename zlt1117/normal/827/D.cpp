//#pragma GCC optimize("Ofast")
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
const int maxn=4e5+5;
struct DSU
{
	int fa[maxn];
	inline void init(int n){FOR(i,1,n)fa[i]=i;}
	inline int get(int x){if(x==fa[x])return x;return fa[x]=get(fa[x]);}
	inline void merge(int x,int y){fa[get(x)]=get(y);}
}dsu;
struct edge
{
	int u,v,w,idx;
	inline bool operator < (const edge&b)const{return w<b.w;}
}ne[maxn];
vector<int>e[maxn];
int ind[maxn],dp[maxn],fa[maxn][20],dep[maxn],Log[maxn],n,m,ans[maxn],id[maxn];
int maxv[maxn][20];
inline pair<int,int> LCA(int u,int v)
{
	int ret=0;
	if(dep[u]<dep[v])swap(u,v);
	for(int i=Log[dep[u]];i>=0;--i)if(dep[fa[u][i]]>=dep[v])ret=max(ret,maxv[u][i]),u=fa[u][i];
	if(u==v)return {u,ret};
	for(int i=Log[dep[u]];i>=0;--i)if(fa[u][i]!=fa[v][i])
	ret=max(maxv[u][i],max(ret,maxv[v][i])),u=fa[u][i],v=fa[v][i];
	return {fa[u][0],max(ret,max(maxv[u][0],maxv[v][0]))};
}
vector<int>del[maxn];
multiset<int>s[maxn];
inline void init()
{
	FOR(i,2,maxn-1)Log[i]=Log[i>>1]+1;
}
bool vis[maxn];
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,m)ne[i].u=gi(),ne[i].v=gi(),ne[i].w=gi(),ne[i].idx=i;
	sort(ne+1,ne+m+1);
}
int w[maxn];
inline void dfs(int u)
{
	dep[u]=dep[fa[u][0]]+1;
	FOR(i,1,Log[dep[u]])fa[u][i]=fa[fa[u][i-1]][i-1];
	if(!id[u])maxv[u][0]=0;else maxv[u][0]=w[u];
	FOR(i,1,Log[dep[u]])maxv[u][i]=max(maxv[u][i-1],maxv[fa[u][i-1]][i-1]);
	for(int v:e[u])
	{
		if(v==fa[u][0])continue;
		fa[v][0]=u;
		dfs(v);
	}
}
inline void merge(int u,int v)
{
	if(sz(s[v])>sz(s[u]))swap(s[u],s[v]);
	for(int x:s[v])s[u].insert(x);
}
inline void dfs2(int u)
{
//	printf("%d:",u);
//	for(int x:s[u])printf("%d ",x);
//	puts("");
	for(int v:e[u])
	{
		if(v==fa[u][0])continue;
		dfs2(v);
		merge(u,v);
	}
	for(int x:del[u])s[u].erase(s[u].find(x));
	if(s[u].size())ans[id[u]]=*s[u].begin()-1;
	else ans[id[u]]=-1;
//	printf("%d:",u);
//	for(int x:s[u])printf("%d ",x);
//	puts("");
}
inline void solve()
{
	dsu.init(2*n);
	FOR(i,1,m)
	{
		int u=dsu.get(ne[i].u),v=dsu.get(ne[i].v);
		if(u!=v)
		{
			vis[ne[i].idx]=1;
			dsu.merge(u,++n),dsu.merge(v,n);id[n]=ne[i].idx;
			e[ne[i].u].pb(n),e[n].pb(ne[i].u);
			e[ne[i].v].pb(n),e[n].pb(ne[i].v);
			w[n]=ne[i].w;
		}
	}
	dfs(1);
	FOR(i,1,m)
	{
		if(vis[ne[i].idx])continue;
		int lca=LCA(ne[i].u,ne[i].v).first;
		s[ne[i].u].insert(ne[i].w);
		s[ne[i].v].insert(ne[i].w);
		del[lca].pb(ne[i].w);
		del[fa[lca][0]].pb(ne[i].w);
		ans[ne[i].idx]=LCA(ne[i].u,ne[i].v).second-1;
	}
	dfs2(1);
	FOR(i,1,m)if(ans[i]>1000000000)ans[i]=-1;
	FOR(i,1,m)printf("%d ",ans[i]);
	puts("");
}
int main()
{
	int T=1;
	//T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}