//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
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
const int maxn=2e6+5,mod=998244353;
int n,k,a[maxn],rk[maxn],fac[maxn],inv[maxn];
inline void init()
{
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	FOR(i,2,maxn-1)fac[i]=1ll*i*fac[i-1]%mod;
	FOR(i,2,maxn-1)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,maxn-1)inv[i]=1ll*inv[i-1]*inv[i]%mod;
}
inline int C(int x,int y)
{
	if(x<y||x<0||y<0)return 0;
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
inline void input()
{
	n=gi(),k=gi();
	FOR(i,0,n-1)a[i]=gi(),rk[a[i]]=i;
}
inline void solve()
{
	int cnt=0;
	rk[n]=-1;
	FOR(i,0,n-2)
	{
		int u=a[i],v=a[i+1];
		if(rk[u+1]>rk[v+1])cnt++;///must increase
	}
	cnt++;///the first one increase
	printf("%d\n",C(n-cnt+k,n));
}
int main()
{
	int T=1;
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}