#pragma GCC optimize("Ofast")
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
#define db double
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
const int mod=998244353,maxn=1e5+5;
int x[maxn],v[maxn],p[maxn],n;
struct Matrix 
{
	int a[2][2];
	Matrix(int b=0,int c=0,int d=0,int e=0){a[0][0]=b,a[0][1]=c,a[1][0]=d,a[1][1]=e;}
	inline void clear(){memset(a,0,sizeof(a));}
	inline Matrix operator * (const Matrix &b)
	{
		Matrix c;c.clear();
		FOR(k,0,1)FOR(i,0,1)FOR(j,0,1)c.a[i][j]=(c.a[i][j]+1ll*a[i][k]*b.a[k][j]%mod)%mod;
		return c;
	}
}a[maxn];
struct segmentree
{
	#define ls u<<1
	#define rs u<<1|1
	static const int maxn=4e5+5;
	Matrix sum[maxn];
	inline void pushup(int u){sum[u]=sum[ls]*sum[rs];}
	inline void update(int u,int l,int r,int x)
	{
		if(l==r)return sum[u]=a[l],void();
		int mid=(l+r)>>1;
		if(x<=mid)update(ls,l,mid,x);
		else update(rs,mid+1,r,x);
		pushup(u);
	}
	inline void build(int u,int l,int r)
	{
		if(l==r)return sum[u]=a[l],void();
		int mid=(l+r)>>1;
		build(ls,l,mid),build(rs,mid+1,r);
		pushup(u);
	}
}tree;
struct state
{
	int x,i,j;ll val;
	double nval;
	///x-1-->the first x-->the second
	///i-->the direction of x-1 j-->the direction of x
	inline bool operator < (const state &b)const{return nval<b.nval;}
}q[maxn*2];
int tot;
inline int qpow(int x,int k)
{
	int ret=1;
	while(k)
	{
		if(k&1)ret=1ll*x*ret%mod;
		k>>=1,x=1ll*x*x%mod;
	}
	return ret;
}
inline void init()
{

}
inline void input()
{
	n=gi();
	int inv=qpow(100,mod-2);
	FOR(i,1,n)x[i]=gi(),v[i]=gi(),p[i]=gi(),p[i]=1ll*p[i]*inv%mod;
}
inline void solve()
{
	a[1]=Matrix(mod+1-p[1],p[1],0,0);
	FOR(i,2,n)///i-1->i
	{
		a[i]=Matrix(mod+1-p[i],p[i],mod+1-p[i],p[i]);
		q[++tot]={i,1,0,1ll*(x[i]-x[i-1])*qpow(v[i]+v[i-1],mod-2)%mod,(double)(x[i]-x[i-1])/(v[i]+v[i-1])};
		if(v[i]>v[i-1])q[++tot]={i,0,0,1ll*(x[i]-x[i-1])*qpow(v[i]-v[i-1],mod-2)%mod,(double)(x[i]-x[i-1])/(v[i]-v[i-1])};
		if(v[i]<v[i-1])q[++tot]={i,1,1,1ll*(x[i]-x[i-1])*qpow(v[i-1]-v[i],mod-2)%mod,(double)(x[i]-x[i-1])/(v[i-1]-v[i])};
	}
	tree.build(1,1,n);
	sort(q+1,q+tot+1);
	int ans=0;
	FOR(j,1,tot)
	{
		int i=q[j].x;
		Matrix temp=a[i];
		a[i].clear();
		int val1=q[j].i,val2=q[j].j;
		a[i].a[val1][val2]=val2?p[i]:mod+1-p[i];
		tree.update(1,1,n,i);
		ans=(ans+1ll*q[j].val*(tree.sum[1].a[0][0]+tree.sum[1].a[0][1])%mod)%mod;
		a[i]=temp;
		a[i].a[val1][val2]=0;
		tree.update(1,1,n,i);
	}
	printf("%d\n",ans);
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