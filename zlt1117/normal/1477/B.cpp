//#pragma GCC optimize(4)
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
char s[maxn],t[maxn];
int l[maxn],r[maxn],n,q,sum[maxn];
struct segmentree
{
	static const int maxn=8e5+5;
	#define ls u<<1
	#define rs u<<1|1
	int rev[maxn],sum[maxn];
	inline void clear()
	{
		FOR(i,1,4*n)rev[i]=sum[i]=0;
	}
	inline void pushup(int u)
	{
		sum[u]=sum[ls]+sum[rs];
	}
	inline void build(int u,int l,int r)
	{
		if(l==r)return sum[u]=(t[l]=='1'),void();
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		pushup(u);
	}
	inline void pushdown(int u,int l,int r)
	{
		if(rev[u]!=0)
		{
			int mid=(l+r)>>1;
			rev[ls]=rev[rs]=rev[u];
			if(rev[u]==1)
			{
				sum[ls]=mid-l+1;
				sum[rs]=r-mid;
			}
			else sum[ls]=sum[rs]=0;
			rev[u]=0;
		}
	}
	inline void update(int u,int l,int r,int x,int y,int v)
	{
		if(x<=l&&y>=r)return rev[u]=v,sum[u]=(v==1)?r-l+1:0,void();
		int mid=(l+r)>>1;
		pushdown(u,l,r);
		if(x<=mid)update(ls,l,mid,x,y,v);
		if(y>mid)update(rs,mid+1,r,x,y,v);
		pushup(u);
	}
	inline int query(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)return sum[u];
		pushdown(u,l,r);
		int ret=0;
		int mid=(l+r)>>1;
		if(x<=mid)ret=query(ls,l,mid,x,y);
		if(y>mid)ret+=query(rs,mid+1,r,x,y);
		return ret;
	}
}tree;
inline void init()
{
	tree.clear();
	FOR(i,1,q)sum[i]=0;
}
inline void input()
{
	n=gi(),q=gi();
	scanf("%s",s+1);scanf("%s",t+1);
	FOR(i,1,q)l[i]=gi(),r[i]=gi();
}
inline void solve()
{
	tree.build(1,1,n);
	for(int i=q;i>=1;--i)
	{
		int cnt=tree.query(1,1,n,l[i],r[i]),res=r[i]-l[i]+1-cnt;
		if(cnt==res)return printf("NO\n"),void();
		if(res<(r[i]-l[i]+2)/2)tree.update(1,1,n,l[i],r[i],1);
		else tree.update(1,1,n,l[i],r[i],-1);
	}
	FOR(i,1,n)if(s[i]-'0'!=tree.query(1,1,n,i,i))return printf("NO\n"),void();
	printf("YES\n");
}
int main()
{
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