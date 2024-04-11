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
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
inline ll calc(ll k,ll b,ll x){return k*x+b;}
const int inf=1e9,maxn=1.5e5+5;
int root;
struct segmentree
{
	static const int maxn=6e5+5;
	ll k[maxn],b[maxn];int tot,ls[maxn],rs[maxn];
	inline void clear(){FOR(i,1,tot)k[i]=b[i]=ls[i]=rs[i]=0;tot=0;}
	inline void update(int &u,int l,int r,int x,int y,ll kk,ll bb)
	{
		if(!u)u=++tot;
		int mid=(l+r)>>1;
		if(x<=l&&y>=r)
		{
			if((k[u]==0)||(calc(k[u],b[u],l)<=calc(kk,bb,l)&&calc(k[u],b[u],r)<=calc(kk,bb,r)))return k[u]=kk,b[u]=bb,void();
			else if(calc(k[u],b[u],l)>=calc(kk,bb,l)&&calc(k[u],b[u],r)>=calc(kk,bb,r))return ;
			if(calc(k[u],b[u],mid)<=calc(kk,bb,mid))swap(k[u],kk),swap(b[u],bb);
			if(calc(kk,bb,l)>=calc(k[u],b[u],l))update(ls[u],l,mid,x,y,kk,bb);
			if(calc(kk,bb,r)>=calc(k[u],b[u],r))update(rs[u],mid+1,r,x,y,kk,bb);
			return ;
		}
		if(x<=mid)update(ls[u],l,mid,x,y,kk,bb);
		if(y>mid)update(rs[u],mid+1,r,x,y,kk,bb);
	}
	inline ll query(int u,int l,int r,int x)
	{
		if(!u)return 0;
		ll ret=0;
		if(k[u])ret=calc(k[u],b[u],x);
		if(l==r)return ret;
		int mid=(l+r)>>1;
		if(x<=mid)ret=max(ret,query(ls[u],l,mid,x));
		else ret=max(ret,query(rs[u],mid+1,r,x));
		return ret;
	}
}tree;
vector<int>e[maxn];
int a[maxn];
int siz[maxn],rt,maxv[maxn],ssum,n;
bool vis[maxn];
ll ans;
inline void getrt(int u,int fa)
{
	maxv[u]=0,siz[u]=1;
	FOR(t,0,sz(e[u])-1)
	{
		int v=e[u][t];
		if(v==fa||vis[v])continue;
		getrt(v,u);
		siz[u]+=siz[v],maxv[u]=max(maxv[u],siz[v]);
	}
	maxv[u]=max(maxv[u],ssum-siz[u]);
	if(maxv[u]<maxv[rt])rt=u;
}
vector<int>points[maxn],now;
ll pre[maxn],suf[maxn],sum[maxn];
int cnt[maxn];
inline void getdis(int u,int fa)
{
	cnt[u]=cnt[fa]+1;
	sum[u]=sum[fa]+a[u];
	suf[u]=suf[fa]+sum[fa]+a[u];
	pre[u]=pre[fa]+1ll*(cnt[u]-1)*a[u];
	now.pb(u);
	FOR(t,0,sz(e[u])-1)
	{
		int v=e[u][t];
		if(vis[v]||v==fa)continue;
		getdis(v,u);
	}
}
inline void count(int u)
{
	pre[u]=suf[u]=0,cnt[u]=1,suf[u]=a[u],sum[u]=a[u];
	FOR(t,0,sz(e[u])-1)
	{
		int v=e[u][t];
		if(vis[v])continue;
		now.clear(),getdis(v,u);
		points[v]=now;
	}
	//FOR(i,1,n)printf("pre[%d]=%lld,suf[%d]=%lld,cnt[%d]=%d,sum[%d]=%lld\n",i,pre[i],i,suf[i],i,cnt[i],i,sum[i]);
	root=0;
	FOR(t,0,sz(e[u])-1)
	{
		int v=e[u][t];
		if(vis[v])continue;
		FOR(i,0,sz(points[v])-1)
		{
			int p=points[v][i];
			ans=max(ans,max(pre[p]+sum[p],suf[p]));
			ans=max(ans,tree.query(1,1,n,cnt[p])+suf[p]);
			//puts("tree");
			//FOR(i,1,tree.tot)printf("k[%d]=%lld,b[%d]=%lld\n",i,tree.k[i],i,tree.b[i]);
			//puts("tree");
			//cerr<<":"<<p<<' '<<suf[p]<<' '<<tree.query(1,1,n,cnt[p])+suf[p]<<endl;
		}
		FOR(i,0,sz(points[v])-1)
		{
			int p=points[v][i];
			tree.update(root,1,n,1,n,sum[p]-a[u],pre[p]);
		}
	}
	root=0;tree.clear();
	for(int t=sz(e[u])-1;t>=0;--t)
	{
		int v=e[u][t];
		if(vis[v])continue;
		FOR(i,0,sz(points[v])-1)
		{
			int p=points[v][i];
			ans=max(ans,max(pre[p]+sum[p],suf[p]));
			ans=max(ans,tree.query(1,1,n,cnt[p])+suf[p]);
			//puts("tree");
			//FOR(i,1,tree.tot)printf("k[%d]=%lld,b[%d]=%lld\n",i,tree.k[i],i,tree.b[i]);
			//puts("tree");
			//cerr<<":"<<p<<' '<<suf[p]<<' '<<tree.query(1,1,n,cnt[p])+suf[p]<<endl;
		}
		FOR(i,0,sz(points[v])-1)
		{
			int p=points[v][i];
			tree.update(root,1,n,1,n,sum[p]-a[u],pre[p]);
		}
	}
	root=0;tree.clear();
	FOR(t,0,sz(e[u])-1)
	{
		int v=e[u][t];
		if(vis[v])continue;
		points[v].clear();
	}
}
int depth[maxn];
inline void Divide(int u)
{
	//cerr<<depth[u]<<endl;
	vis[u]=1;
	//printf("start %d\n",u);
	count(u);
	//printf("end %d\n",u);
	FOR(t,0,sz(e[u])-1)
	{
		int v=e[u][t];
		if(vis[v])continue;
		maxv[rt=0]=inf,ssum=siz[v];
		getrt(v,u);
		depth[rt]=depth[u]+1;
		Divide(rt);
	}
}
inline void input()
{
	n=gi();
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u);
	}
	FOR(i,1,n)a[i]=gi();
}
inline void solve()
{
	maxv[rt=0]=inf,ssum=n;
	getrt(1,0);//cerr<<rt<<endl;
	//FOR(i,1,n)printf("%d %d %d\n",i,siz[i],maxv[i]);
	Divide(rt);
	printf("%lld\n",ans);
}
int main()
{
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
	input();
	solve();
	return 0;
}