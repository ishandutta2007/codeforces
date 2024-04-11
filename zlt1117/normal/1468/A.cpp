#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define se second
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=1e6+5;
int n,a[maxn];
int temp[maxn],dp[maxn],val[maxn][22],pre[maxn],t[maxn]; 
int tot=0;
int rt[maxn];
struct segmentree
{
	static const int maxn=2e7+5;
	int maxv[maxn],ls[maxn],rs[maxn],tot1;
	inline void clear()
	{
		FOR(i,0,tot1)maxv[i]=ls[i]=rs[i]=0;
		tot1=0;
	}
	inline void pushup(int u)
	{
		maxv[u]=max(maxv[ls[u]],maxv[rs[u]]);
	}
	inline void update(int &u,int pre,int l,int r,int x,int v)
	{
		u=++tot1;
		if(l==r)return maxv[u]=max(maxv[u],v),void();
		int mid=(l+r)>>1;
		ls[u]=ls[pre],rs[u]=rs[pre];
		if(x<=mid)update(ls[u],ls[pre],l,mid,x,v);
		else update(rs[u],rs[pre],mid+1,r,x,v);
		pushup(u);
	}
	inline int query(int u,int l,int r,int x,int y)
	{
		if(u==0)return 0;
		if(x<=l&&y>=r)return maxv[u];
		int mid=(l+r)>>1;
		int ret=0;
		if(x<=mid)ret=query(ls[u],l,mid,x,y);
		if(y>mid)ret=max(ret,query(rs[u],mid+1,r,x,y));
		return ret;
	}
}tree;
inline void init()
{
	tot=0; 
	FOR(i,1,n)temp[i]=t[i]=rt[i]=dp[i]=pre[i]=0;
	FOR(i,1,n)memset(val[i],0,sizeof(val[i]));
	tree.clear();
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
	FOR(i,2,n)pre[i]=pre[i>>1]+1;
	FOR(i,1,n)
	{
		val[i][0]=a[i];
		FOR(j,1,pre[i])val[i][j]=max(val[i][j-1],val[i-(1<<(j-1))][j-1]);
	}
}
inline void solve()
{
	FOR(i,1,n)
	{
		int now=upper_bound(temp+1,temp+tot+1,a[i])-temp;
		if(now==tot+1)temp[++tot]=a[i];
		else temp[now]=a[i];
		dp[i]=now;
	}
	int ans=0;
	a[n+1]=n; 
	FOR(i,1,n+1)
	{
		rt[i]=rt[i-1];
		t[i]=tree.query(rt[i-1],0,n,0,a[i])+1;
		int now=i-1;
		for(int j=pre[i-1];j>=0;--j)if(val[now][j]<a[i]&&now-(1<<j)>=0)now-=(1<<j);
		if(now>=1)t[i]=max(t[i],tree.query(rt[now-1],0,n,0,a[i])+2);
		tree.update(rt[i],rt[i],0,n,a[i],t[i]);
		ans=max(ans,t[i]);
	}
	printf("%d\n",ans-1);
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
}///