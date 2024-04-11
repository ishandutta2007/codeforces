#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define gc getchar()//(p1==p2&&(p2=((p1=buf)+fread(buf,1,100000,stdin)),p1==p2)?EOF:*p1++)
char buf[100000],*p1=buf,*p2=buf;
using namespace std;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=1e6+5,mod=1e9+7;
int fac[maxn],inv[maxn],n,k;
inline int qpow(int x,ll k)
{
	int ret=1;
	while(k)
	{
		if(k&1)ret=1ll*ret*x%mod;
		k>>=1,x=1ll*x*x%mod;
	}
	return ret;
}
inline void init()
{
	fac[0]=inv[0]=fac[1]=inv[1]=1;
	FOR(i,2,maxn-1)fac[i]=1ll*fac[i-1]*i%mod;
	FOR(i,2,maxn-1)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,maxn-1)inv[i]=1ll*inv[i-1]*inv[i]%mod;
}
inline int C(int x,int y){if(x<y)return 0;return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;}
inline void input()
{
	n=gi(),k=gi();
}
int f[maxn],g[maxn];
inline void solve()
{
	int ans=0;
	FOR(i,0,n)f[i]=qpow(k-1,1ll*i*(n-1));
	FOR(i,0,n)g[i]=qpow(k,n-i);
	FOR(i,0,n)
	{
		FOR(j,0,n)
		{
			int sum=(i+j)&1?mod-1:1;
			sum=1ll*sum*C(n,i)%mod;
			sum=1ll*sum*C(n,j)%mod;
			int now=qpow(k-1,(1ll*(i+j)*n-i*j)%(mod-1));
			now=1ll*now*qpow(k,(1ll*(n-i)*(n-j))%(mod-1))%mod;
			ans=(ans+1ll*sum*now%mod)%mod;
		}
	}
	printf("%d\n",ans);
}
int main()
{
//	freopen("flow.in","r",stdin);
//	freopen("flow.out","w",stdout);
	init();
	input();
	solve();
	return 0;
}