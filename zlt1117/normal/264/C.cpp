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
const int maxn=1e5+5;
int n,q,a[maxn],b[maxn],c[maxn],v[maxn];
ll dp[maxn],now[maxn];
pair<ll,ll>max1,max2;
inline void init()
{

}
inline void input()
{
	n=gi(),q=gi();
	FOR(i,1,n)v[i]=gi();
	FOR(i,1,n)c[i]=gi();
}
inline void answer(int a,int b)
{
	max1=max2={0,0};
	ll ans=0;
	FOR(i,1,n)dp[i]=-1e18,now[i]=-1e18;
	FOR(i,1,n)
	{
		if(max1.second==c[i])dp[i]=max2.first+1ll*b*v[i];
		else dp[i]=max1.first+1ll*b*v[i];
		dp[i]=max(dp[i],now[c[i]]+1ll*a*v[i]);
		now[c[i]]=max(now[c[i]],dp[i]);
		pair<ll,ll>t={now[c[i]],c[i]};
		if(t.first>=max1.first)
		{
			if(max1.second==c[i])max1=t;
			else max2=max1,max1=t;
		}
		else if(t.first>=max2.first)max2=t;
	}
	FOR(i,1,n)ans=max(ans,dp[i]);
//	FOR(i,1,n)printf("dp[%d]=%lld\n",i,dp[i]);
	printf("%lld\n",ans);
}
inline void solve()
{
	FOR(i,1,q)
	{
		a[i]=gi(),b[i]=gi();
		answer(a[i],b[i]);
	}
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