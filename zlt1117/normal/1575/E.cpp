#pragma GCC optimize("Ofast")
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
const int maxn=2e5+5,inf=1e9,mod=1e9+7;
int n,k,a[maxn];
vector<pair<int,int>>e[maxn];
int siz[maxn],maxv[maxn],rt,dis[maxn];
ll val[maxn],ans;
vector<int>now;
struct segmentree
{
	#define ls u<<1
	#define rs u<<1|1
	static const int maxn=8e5+5;
	ll sum[maxn];
	inline void pushup(int u){sum[u]=sum[ls]+sum[rs];}
	inline void update(int u,int l,int r,int x,ll v)
	{
		if(l==r)return sum[u]+=v,void();
		int mid=(l+r)>>1;
		if(x<=mid)update(ls,l,mid,x,v);
		else update(rs,mid+1,r,x,v);
		pushup(u);
	}
	inline ll query(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)return sum[u];
		int mid=(l+r)>>1;ll ret=0;
		if(x<=mid)ret=query(ls,l,mid,x,y);
		if(y>mid)ret+=query(rs,mid+1,r,x,y);
		return ret;
	}
}tree[2],T[2];
inline void init()
{

}
inline void input()
{
	n=gi(),k=gi();
	FOR(i,1,n)a[i]=gi();
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi(),w=gi();
		e[u].pb({v,w});e[v].pb({u,w});
	}
}
bool vis[maxn];
int sum;
inline void getrt(int u,int fa)
{
	now.pb(u);
	siz[u]=1;maxv[u]=0;
	for(auto x:e[u])
	{
		int v=x.first;
		if(v==fa||vis[v])continue;
		getrt(v,u);
		siz[u]+=siz[v];
		maxv[u]=max(maxv[u],siz[v]);
	}
	maxv[u]=max(maxv[u],sum-siz[u]);
	if(maxv[u]<maxv[rt])rt=u;
}
inline void getdis(int u,int fa,int nowc)
{
	now.pb(u);
	for(auto x:e[u])
	{
		int v=x.first,w=x.second;
		if(v==fa||vis[v])continue;
		val[v]=val[u]+a[v],dis[v]=dis[u]+(nowc!=w);
		getdis(v,u,w);
	}
}
inline void count(int u)
{
	vector<pair<int,int>>temp;
	dis[u]=0,val[u]=0;
	ans=(ans+a[u])%mod;
	for(auto x:e[u])
	{
		now.clear();
		int v=x.first,w=x.second;
		if(vis[v])continue;
		dis[v]=0,val[v]=a[v];
		getdis(v,u,w);
		for(int x:now)temp.pb({w,x});
		for(int x:now)if(dis[x]<=k)ans=(ans+val[x]+a[u])%mod;
		for(int x:now)
		{
			if(dis[x]>k)continue;
			ll sum=tree[w].query(1,0,n,0,k-dis[x])+1ll*T[w].query(1,0,n,0,k-dis[x])*val[x];
			if(dis[x]<k)sum+=tree[w^1].query(1,0,n,0,k-dis[x]-1)+1ll*T[w^1].query(1,0,n,0,k-dis[x]-1)*val[x];
			ans=(ans+sum)%mod;
		}
		for(int x:now)if(dis[x]<=k)tree[w].update(1,0,n,dis[x],val[x]+a[u]),T[w].update(1,0,n,dis[x],1);
	}
	for(auto x:temp)
	{
		int w=x.first,v=x.second;
		if(dis[v]>k)continue;
		tree[w].update(1,0,n,dis[v],-val[v]-a[u]);
		T[w].update(1,0,n,dis[v],-1);
	}
//	cerr<<u<<' '<<ans<<endl;
}
inline void Divide(int u)
{
//	cerr<<u<<endl;
	vis[u]=1;
	count(u);
	for(auto x:e[u])
	{
		int v=x.first;
		if(vis[v])continue;
		maxv[rt=0]=inf;sum=siz[v];
		getrt(v,u);
		Divide(rt);
	}
}
inline void solve()
{
	maxv[rt=0]=inf;sum=n;
	getrt(1,0);
	Divide(rt);
	printf("%lld\n",ans);
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