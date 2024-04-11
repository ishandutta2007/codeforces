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
#define db double
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
const int maxn=1e5+5;
int n,a[maxn],now,last,k;
ll dp[2][maxn];
inline void init()
{

}
inline void input()
{
	n=gi();k=gi();
	FOR(i,1,n)a[i]=gi();
}
ll ans;
int cnt[maxn],l=1,r=0;
inline void update1(int x){x=a[x],ans-=1ll*cnt[x]*(cnt[x]-1)/2,cnt[x]++,ans+=1ll*cnt[x]*(cnt[x]-1)/2;}
inline void update2(int x){x=a[x],ans-=1ll*cnt[x]*(cnt[x]-1)/2,cnt[x]--,ans+=1ll*cnt[x]*(cnt[x]-1)/2;}
inline ll calc(int i,int j)
{
	while(r<j)update1(++r);
	while(r>j)update2(r--);
	while(l<i)update2(l++);
	while(l>i)update1(--l);
	return ans;
}
inline void work(int l,int r,int L,int R)
{
	if(l>r)return ;
	int mid=(l+r)>>1;
	int best=-1;ll minv=1e18;
	FOR(i,L,min(R,mid-1))
	{
		ll now=calc(i+1,mid)+dp[last][i];
		if(now<=minv)minv=now,best=i; 
	}
	dp[now][mid]=minv;
	work(l,mid-1,L,best);
	work(mid+1,r,best,R);
}
inline void solve()
{
	memset(dp[now],0x3f,sizeof(dp[now]));
	dp[now][0]=0;
	FOR(i,1,k)
	{
		now=now^1,last=now^1;
		memset(dp[now],0x3f,sizeof(dp[now]));
		work(0,n,0,n);
	}
	printf("%lld\n",dp[now][n]);
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