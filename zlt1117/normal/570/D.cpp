#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
using namespace std;
template<typename T>
inline T max(T a,T b){return a>b?a:b;}
template<typename T>
inline T min(T a,T b){return a<b?a:b;}
const int maxn=5e5+5;
inline int getint()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')ch=getchar();
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f==1)?x:-x;
}
char s[maxn];
int p[maxn],sz,n,m;
vector<pair<int,int> >v[maxn];
bool ans[maxn];
int d[maxn][27];
int dep[maxn],son[maxn],siz[maxn];
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
inline void dfs1(int u,int fa)
{
	dep[u]=dep[fa]+1;
	siz[u]=1;
	REP(u)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
	}
}
inline void update(int u,int fa,int val,int hvy)
{
	d[dep[u]][s[u]-'a']+=val;
	REP(u)
	{
		int v=e[i].v;
		if(v==fa||v==hvy)continue;
		update(v,u,val,hvy);	
	}
}
inline void dfs2(int u,int fa,int opt)
{
	REP(u)
	{
		int v=e[i].v;
		if(v==fa||v==son[u])continue;
		dfs2(v,u,0);
	}
	if(son[u])dfs2(son[u],u,1);
	update(u,fa,1,son[u]);
	FOR(i,0,(int)v[u].size()-1)
	{
		int id=v[u][i].first;
		int depth=v[u][i].second;
		int cnt=0;
		for(int j=0;j<=25;++j)
		{
			if(d[depth][j]%2==1)cnt++;
		}
		if(cnt>=2)ans[id]=false;
		else ans[id]=true;
	}
	if(opt==0)update(u,fa,-1,0);
}
int main()
{
	memset(p,-1,sizeof(p));
	n=getint(),m=getint();
	FOR(i,2,n)
	{
		int fa=getint();
		add(i,fa);
		add(fa,i);
	}
	scanf("%s",s+1);
	for(int i=1;i<=m;++i)
	{
		int u=getint(),x=getint();
		v[u].push_back(PII(i,x));
	}
	dfs1(1,0);
	dfs2(1,0,1);
	for(int i=1;i<=m;++i)printf((ans[i]==1)?"Yes\n":"No\n");
	return 0;
}
///