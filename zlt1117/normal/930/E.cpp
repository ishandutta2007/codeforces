#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define sz(x) (int)(x.size())
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
const int maxn=2e6+5,mod=1e9+7;
struct line
{
	int l,r;
	inline bool operator<(const line &b)const
	{
		if(l!=b.l)return l<b.l;
		else return r-l>b.r-b.l;
	}
}a[2][maxn];
int temp[maxn],tot,m,n1,n2,sum[2];
vector<PII>vec[maxn];
inline int min(int a,int b){return a<b?a:b;}
inline ll qpow(ll x,ll k)
{
	ll ret=1;
	while(k)
	{
		if(k&1)ret=(ret*x)%mod;
		k>>=1,x=(x*x)%mod;
	}
	return ret;
}
struct segmentree
{
	#define ls u<<1
	#define rs u<<1|1
	static const int maxn=4e6+5;
	ll sum[maxn],tag[maxn];///recover
	inline void pushup(int u){sum[u]=sum[ls]+sum[rs];}
	segmentree(){memset(tag,-1,sizeof(tag));}
	inline void pushdown(int u,int l,int r)
	{
		if(tag[u]!=-1)
		{
			int mid=(l+r)>>1;
			sum[ls]=tag[u]*(mid-l+1)%mod;
			sum[rs]=tag[u]*(r-mid)%mod;
			tag[ls]=tag[u],tag[rs]=tag[u];
			tag[u]=-1;
		}
	}
	inline void update(int u,int l,int r,int x,int y,ll v)
	{
		if(x<=l&&y>=r)
		{
			sum[u]=v;
			tag[u]=v;
			return ;
		}
		else 
		{
			pushdown(u,l,r);
			int mid=(l+r)>>1;
			if(x<=mid)update(ls,l,mid,x,y,v);
			if(y>mid)update(rs,mid+1,r,x,y,v);
			pushup(u);
		}
	}
	inline ll query(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)return sum[u];
		else
		{
			ll ret=0;
			int mid=(l+r)>>1;
			if(x<=mid)ret+=query(ls,l,mid,x,y)%mod;
			if(y>mid)ret+=query(rs,mid+1,r,x,y)%mod;
			ret%=mod;
			return ret;
		}
	}
}T0,T1;
int main()
{
//	freopen("street.in","r",stdin);
//	freopen("street.out","w",stdout);
	m=gi(),n1=gi(),n2=gi();
	FOR(i,1,n1)
	{
		int l=gi(),r=gi();
		temp[++tot]=l,temp[++tot]=r;if(l>1)temp[++tot]=l-1;
		a[0][++sum[0]].l=l;
		a[0][sum[0]].r=r;
	}
	FOR(i,1,n2)
	{
		int l=gi(),r=gi();
		temp[++tot]=l,temp[++tot]=r;if(l>1)temp[++tot]=l-1;
		a[1][++sum[1]].l=l;
		a[1][sum[1]].r=r;
	}
	sort(temp+1,temp+tot+1);
	temp[++tot]=m;
	tot=unique(temp+1,temp+tot+1)-temp-1;
	FOR(i,0,1)
	{
		FOR(j,1,sum[i])
		{
			a[i][j].l=lower_bound(temp+1,temp+tot+1,a[i][j].l)-temp;
			a[i][j].r=lower_bound(temp+1,temp+tot+1,a[i][j].r)-temp;
			vec[a[i][j].r].push_back(PII(i,a[i][j].l));
		}
	}
	int n=tot;
	T0.update(1,0,n,0,0,1);
	FOR(i,1,tot)
	{
		ll delta=temp[i]-temp[i-1]-1;
		delta=qpow(2,delta)-1;
		///0
		///
		/// 
		///01 
		ll x=T0.query(1,0,n,0,i-1);
		ll y=T1.query(1,0,n,0,i-1);
		T1.update(1,0,n,i-1,i-1,T1.query(1,0,n,i-1,i-1)+x);
		T0.update(1,0,n,i-1,i-1,T0.query(1,0,n,i-1,i-1)+y);
		x+=y;x%=mod;x=(x*delta)%mod;
		T0.update(1,0,n,i,i,x);T1.update(1,0,n,i,i,x);
		for(auto z:vec[i])
		{
			if(z.first==0)T1.update(1,0,n,0,z.second-1,0);
			if(z.first==1)T0.update(1,0,n,0,z.second-1,0);
		}
	}
	ll ans=0;
	ans+=T0.query(1,0,n,0,n)+T1.query(1,0,n,0,n);
	printf("%lld\n",ans%mod);
	return 0;
}