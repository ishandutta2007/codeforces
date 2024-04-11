//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
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
const int maxn=2e5+5,mod=998244353;
int n;
ll pre[2][maxn];
inline void init()
{

}
inline void input()
{
	n=gi();
	pre[1][1]=1;
}
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
inline void solve()
{
	FOR(i,2,n)
	{
		pre[0][i]=pre[0][i-1];
		pre[1][i]=pre[1][i-1];
		pre[i&1][i]+=pre[(i&1)^1][i-1];
		pre[i&1][i]%=mod;
	}
	pre[n&1][n]=(pre[n&1][n]*qpow(qpow(2,n),mod-2))%mod;
	printf("%lld\n",pre[n&1][n]);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}///