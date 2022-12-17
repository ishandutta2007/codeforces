//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define gc getchar()
#define mk make_pair
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
const int maxn=1e5+5;
int Log[maxn];
vector<pair<int,int>>e[maxn];
int dis[maxn],n,q,rt;
inline void getdis(int u,int fa)
{
	if(dis[u]>dis[rt])rt=u;
	for(auto x:e[u])
	{
		int v=x.first,w=x.second;
		if(v==fa)continue;
		dis[v]=dis[u]+w;
		getdis(v,u);
	}
}
struct Tree
{
	int rt,fa[maxn][20],dep[maxn],rk[maxn],ans[maxn],son[maxn],len[maxn],tp[maxn],bot[maxn],id[maxn],cnt,dis[maxn];
	inline void dfs(int u)
	{
		dep[u]=dep[fa[u][0]]+1;
		FOR(i,1,Log[dep[u]])fa[u][i]=fa[fa[u][i-1]][i-1];
		for(auto x:e[u])
		{
			int v=x.first,w=x.second;
			if(v==fa[u][0])continue;
			fa[v][0]=u;dis[v]=dis[u]+w,dfs(v);
			len[v]+=w;
			if(len[v]>len[u])
			{
				len[u]=len[v];
				son[u]=v;
			}
		}
	}
	inline void dfs2(int u,int topf)
	{
		tp[u]=topf;
		if(son[u])dfs2(son[u],topf),bot[u]=bot[son[u]];
		else bot[u]=u;
		for(auto x:e[u])
		{
			int v=x.first;
			if(v==fa[u][0]||v==son[u])continue;
			dfs2(v,v);
		}
	}
	inline void init()
	{
		dfs(rt),dfs2(rt,rt);
		cnt=0;
		FOR(i,1,n)if(tp[i]==i)id[++cnt]=i;
		sort(id+1,id+cnt+1,[&](int x,int y){return len[x]>len[y];});
		FOR(i,1,cnt)
		{
			int x=bot[id[i]];
			while(!rk[x])
			{
				rk[x]=i;
				x=fa[x][0];
			}
			ans[i]=ans[i-1]+len[id[i]];
		}
	}
	inline int query(int x,int y)
	{
		y=y*2-1;
		if(y>=cnt)return ans[cnt];
		if(rk[x]<=y)return ans[y];
		int ret1=0,ret2=0;
		ret1=ans[y-1];int t=x;
		for(int i=Log[dep[x]];i>=0;--i)if(rk[fa[t][i]]>y-1)t=fa[t][i];
		ret1+=dis[bot[x]]-dis[fa[t][0]];
		ret2=ans[y];t=x;
		for(int i=Log[dep[x]];i>=0;--i)if(rk[fa[t][i]]>y)t=fa[t][i];
		t=fa[t][0];
		ret2+=dis[bot[x]]-dis[t]-len[son[t]];
		return max(ret1,ret2);
	}
}T1,T2;
inline void input()
{
	n=gi(),q=gi();
	FOR(i,2,n)Log[i]=Log[i>>1]+1;
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi(),w=gi();
		e[u].pb({v,w}),e[v].pb({u,w});
	}
	getdis(1,0);T1.rt=rt;dis[rt]=0;getdis(rt,0);T2.rt=rt;
	T1.init(),T2.init();
}
inline void solve()
{
	int ans=0;
	while(q--)
	{
		int x=gi(),y=gi();
		x=(x+ans-1)%n+1,y=(y+ans-1)%n+1;
		//cerr<<x<<' '<<y<<endl;
		printf("%d\n",ans=max(T1.query(x,y),T2.query(x,y)));
	}
}
int main()
{
	input();
	solve();
	return 0;
}