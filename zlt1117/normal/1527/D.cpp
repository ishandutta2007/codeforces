//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define int ll
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
vector<int>e[maxn];
ll ans[maxn];
int dep[maxn];
int siz[maxn],fa[maxn];
int tp[maxn];
inline void init()
{
	FOR(i,0,n+1)e[i].clear(),ans[i]=0,dep[i]=0,fa[i]=0,tp[i]=0,siz[i]=0;
}
inline void input()
{
	n=gi();
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u);
	}
}
int f[maxn][20];
inline void dfs(int u,int topf)
{
	f[u][0]=fa[u];
	FOR(i,1,19)f[u][i]=f[f[u][i-1]][i-1];
	siz[u]=1;tp[u]=topf;
	for(int v:e[u])
	{
		if(v==fa[u])continue;
		dep[v]=dep[u]+1;fa[v]=u;
		dfs(v,topf);siz[u]+=siz[v];
	}
}
inline bool on_chain(int x,int y)
{
	if(dep[x]>dep[y])swap(x,y);
	for(int i=19;i>=0;--i)
	{
		if(dep[f[y][i]]>dep[x])y=f[y][i];
	}
	y=f[y][0];
	return x==y;
}
int nxt[maxn];
inline void solve()
{
	siz[0]=1;
	FOR(i,0,n)nxt[i]=-1;
	for(int v:e[0])dep[v]=1,dfs(v,v),siz[0]+=siz[v];
	for(int v:e[0])ans[0]+=1ll*siz[v]*(siz[v]-1)/2;
	int x=1;while(dep[x]!=1)x=fa[x];
	ans[1]=1ll*n*(n-1)/2-ans[0];
	map<int,int>mp;
	FOR(i,1,n-1)
	{
		int x=mp[tp[i]];
		mp[tp[i]]=dep[mp[tp[i]]]<dep[i]?i:mp[tp[i]];
		if(!on_chain(x,i))break;
		//printf("%d:%d\n",i,ok);
		if(sz(mp)==1)
		{
			int x=(*mp.begin()).first,y=(*mp.begin()).second;
			ans[i+1]=1ll*(siz[0]-siz[tp[x]])*siz[y];
			//cerr<<siz[tp[x]]<<':'<<siz[y]<<endl;
			//cerr<<i<<" "<<x<<endl;
		}
		else if(sz(mp)==2)
		{
			int x=(*mp.begin()).second;
			int y=(*--mp.end()).second;
			ans[i+1]=1ll*siz[x]*siz[y];
			//cerr<<i<<' '<<x<<' '<<y<<endl;
		}
		else break;
		//cerr<<i<<':'<<ans[i+1]<<'\n';
		ans[i]-=ans[i+1];
	}
	FOR(i,0,n)printf("%lld ",ans[i]);//,assert(ans[i]>=0);
	puts("");
}
signed main()
{
	//freopen("1.in","r",stdin);
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