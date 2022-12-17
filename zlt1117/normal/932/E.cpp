//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define pb push_back
#define PII pair<int,int>
#define db double
#define ll long long
#define gc getchar()//(p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
#define poly vector<int>
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
const int maxn=5000+5,mod=1e9+7;
int pw[maxn],inv[maxn],fac[maxn];
int n,k;
inline int qpow(int x,int k)
{
	int ret=1;
	while(k)
	{
		if(k&1)ret=1ll*x*ret%mod;
		x=1ll*x*x%mod,k>>=1;
	}
	return ret;
}
vector<int>p;
bool vis[maxn];
inline void prepare(int n,int k)
{
	fac[0]=inv[0]=fac[1]=inv[1]=1;
	FOR(i,2,n)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,n)fac[i]=1ll*fac[i-1]*i%mod,inv[i]=1ll*inv[i-1]*inv[i]%mod; 
	pw[1]=vis[0]=vis[1]=1;
	FOR(i,2,n)
	{
		if(!vis[i])p.pb(i),pw[i]=qpow(i,k);
		for(auto x:p)
		{
			if(1ll*i*x>n)break;
			if(i%x)
			{
				vis[i*x]=1;
				pw[i*x]=1ll*pw[i]*pw[x]%mod;
			}
			else
			{
				vis[i*x]=1;
				pw[i*x]=1ll*pw[i]*pw[x]%mod;
				break;
			}
		}
	}
}
inline void init()
{
	
}
inline void input()
{
	n=gi(),k=gi();
	prepare(k+1,k);
}
inline int C(int n,int m){if(n<m)return 0;return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;}
inline void solve1()
{
	int ans=0;
	FOR(i,1,n)
	{
		int val=pw[i];
		val=1ll*val*C(n,i)%mod;
		ans=(ans+val)%mod;
	}
	printf("%d\n",ans);
}
int f[maxn];
inline void solve2()
{
	int ans=0;
	int val=1,p2=mod-(mod+1)/2,now=1,val2=1,val3;
	val3=1ll*qpow(2,n-k)%mod;
	f[1]=n;FOR(i,2,k)f[i]=1ll*f[i-1]*(n-i+1)%mod;
	FOR(i,1,k)f[i]=1ll*f[i]*inv[i]%mod;///(n,i)
	ans=1ll*f[k]*pw[k]%mod*val3%mod*val%mod;
	for(int i=k-1;i>=1;--i)
	{
		val=1ll*val*(mod+1)/2%mod;
		val2=1ll*val2*p2%mod;///(-1/2)^(k-i)
		now=1ll*now*(n-i-1)%mod*inv[k-i]%mod*fac[k-i-1]%mod;///(n-i-1,k-i)
		val=(val+1ll*now*val2%mod)%mod;
		val3=1ll*val3*2%mod;
		ans=(ans+1ll*f[i]*pw[i]%mod*val3%mod*val)%mod;
	}
	printf("%d\n",ans);
}
inline void solve()
{
	if(n<=k+1)solve1();
	else solve2();
}
int main()
{
//	freopen("kori.in","r",stdin);
//	freopen("kori.out","w",stdout);
	init();
	input();
	solve();
	return 0;
}