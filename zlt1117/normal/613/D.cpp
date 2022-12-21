//#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define gc getchar()
using namespace std;
inline int getint()
{
	char ch=gc;int x=0,f=1;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=1e5+5;
int n,q,u,v,k,a[maxn],p[maxn],ans,tim,dfn[maxn],sta[maxn],de,siz[maxn],pre[maxn],sz,dep[maxn],fa[maxn][20];
struct edge
{
	int v,nxt;
	edge(int vv=0,int nn=0){v=vv,nxt=nn;}
}e[maxn<<1];
inline void add(int u,int v)
{
	e[++sz]=edge(v,p[u]);
	p[u]=sz;
}
inline void dfs(int u)
{
	dfn[u]=++tim;
	dep[u]=dep[fa[u][0]]+1;
	FOR(i,1,pre[dep[u]])fa[u][i]=fa[fa[u][i-1]][i-1];
	REP(u)
	{
		int v=e[i].v;
		if(v==fa[u][0])continue;
		fa[v][0]=u;
		dfs(v);
	}
}
inline bool cmp(int x,int y){return dfn[x]<dfn[y];}
inline int lca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int i=pre[dep[u]];i>=0;--i)
		if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
	if(u==v)return u;
	for(int i=pre[dep[u]];i>=0;--i)
		if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
inline void insert(int x)/// 
{
	if(de==0)///
	{
		sta[++de]=x;
		return ;
	}
	int ance=lca(x,sta[de]);
	while((de>1)&&(dep[ance]<dep[sta[de-1]]))
	{
		add(sta[de-1],sta[de]);
		de--;
	}
	if((dep[ance]<dep[sta[de]]))add(ance,sta[de--]);
	if((de==0)||(ance!=sta[de]))sta[++de]=ance;
	sta[++de]=x;
}
inline void dfs1(int u)
{
	if(siz[u])
	{
		REP(u)
		{
			int v=e[i].v;
			dfs1(v);/// 
			if(siz[v])
			{
				siz[v]=0;
				++ans;
			}
		}
	}
	else
	{
		REP(u)
		{
			int v=e[i].v;
			dfs1(v);
			siz[u]+=siz[v];
			siz[v]=0;
		}
		if(siz[u]>1)/// 
		{
			++ans,siz[u]=0;
		}
	}
	p[u]=-1;
}
int main()
{
	memset(p,-1,sizeof(p));
	n=getint();
	FOR(i,1,n-1)
	{
		u=getint(),v=getint();
		add(u,v);add(v,u);
	}
	FOR(i,2,n)pre[i]=pre[i>>1]+1;
	sz=0;
	dfs(1);
	memset(p,-1,sizeof(p));
	memset(siz,0,sizeof(siz));
	q=getint();
	while(q--)
	{
		bool ok=1;
		k=getint();
		FOR(i,1,k)a[i]=getint(),siz[a[i]]=1;
		FOR(i,1,k)
		{
			if(siz[fa[a[i]][0]])
			{
				ok=false;
				break;
			}
		}
		if(!ok)
		{
			printf("-1\n");
			while(k)siz[a[k]]=0,k--;
			continue;
		}
		ans=0;
		sort(a+1,a+k+1,cmp);
		if(a[1]!=1)sta[de=1]=1;/// 
		FOR(i,1,k)insert(a[i]);///0 
		/// 
		while(de>=2)add(sta[de-1],sta[de]),/*add(sta[de],sta[de-1]),*/de--;
		dfs1(1);///lca 
		siz[1]=0;///!!!()
		sz=de=0;
		printf("%d\n",ans);
	}
	return 0;
}