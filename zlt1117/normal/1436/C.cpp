//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
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
const int mod=1e9+7,maxn=1005;
ll ans;
int x,n,m;
ll inv[maxn],fac[maxn];
inline void init()
{

}
inline void input()
{
	n=gi(),x=gi(),m=gi();
	inv[1]=inv[0]=fac[0]=fac[1]=1;
	FOR(i,2,n)fac[i]=fac[i-1]*i%mod,inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,n)inv[i]=inv[i-1]*inv[i]%mod;
}
inline ll C(int n,int m){if(m>n)return 0;else return (fac[n]*inv[n-m])%mod*inv[m]%mod;}
inline void solve()
{
	int left=0,right=n;
	int bigger=0,lower=0;
	while(left<right)
	{
		int middle=(left+right)/2;
		if(middle<=m)lower++,left=middle+1;
		else bigger++,right=middle;
	}
	lower--;
	ans=C(n-x,bigger)*fac[bigger]%mod;
	ans=(ans*C(x-1,lower)%mod)*fac[lower]%mod;
	ans=(ans*fac[n-lower-bigger-1])%mod;
	printf("%lld\n",ans);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}