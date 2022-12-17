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
const int maxn=5e5+5,inf=1e9+3;
int n,q,a[maxn],b[maxn],c[maxn];
ll prea[maxn],preb[maxn],prec[maxn];
ll dp[maxn];
struct node
{
	int l,r,k;
};
vector<node>now;
inline void input()
{
	n=gi(),q=gi();
	FOR(i,1,n)a[i]=gi(),prea[i]=prea[i-1]+a[i];
	FOR(i,1,n)b[i]=gi(),preb[i]=preb[i-1]+b[i];
	FOR(i,1,n)c[i]=gi(),prec[i]=prec[i-1]+c[i];
	FOR(i,1,q)
	{
		int l=gi(),r=gi(),k=gi();l--;
		now.pb({l,r,k});
	}
}
ll suf[maxn];
ll tag[maxn];
inline void cdq(int l,int r,vector<node>&now,int val)
{
	if(l==r)return ;
	int mid=(l+r)>>1;
	vector<node>now1,now2;
	for(auto &x:now)
	{
		x.l=max(x.l,l),x.r=min(x.r,r);
		if(x.l==l&&x.r==r){val=min(val,x.k);continue;}
		if(x.l<=mid)now1.pb(x);
		if(x.r>mid)now2.pb(x);
	}
	cdq(l,mid,now1,val);
	for(int i=l;i<=mid;++i)suf[i]=-1e18;
	for(int i=mid;i>=l;--i)
	{
		if(i!=mid)suf[i]=suf[i+1];
		suf[i]=max(suf[i],max(dp[i],prea[i+1])-preb[i]);
	}
	FOR(i,l,r)tag[i]=-1e18;
	if(val!=inf)tag[r]=suf[l]-val;
	for(auto x:now)
	{
		if(x.l<=mid&&x.r>mid)tag[x.r]=max(tag[x.r],suf[x.l]-x.k);
	}
	ll nowans=-1e18;
	for(int i=r;i>=mid+1;--i)
	{
		nowans=max(nowans,tag[i]);
		dp[i]=max(dp[i],nowans+preb[i]);
	}
	cdq(mid+1,r,now2,val);
}
inline void solve()
{
	memset(dp,0xcf,sizeof(dp));
	cdq(0,n,now,inf);
	//FOR(i,1,n)printf("dp[%d]=%lld\n",i,dp[i]);
	ll ans=-1e18;
	FOR(i,1,n)ans=max(ans,dp[i]+prec[n]-prec[i-1]);
	printf("%lld\n",ans);
}
int main()
{
	input();
	solve();
	return 0;
}