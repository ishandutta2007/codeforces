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
inline void chkmax(int &x,int y){if(x<y)x=y;}
inline void chkmin(int &x,int y){if(x>y)x=y;}
const int maxn=1e5+5;
int fac[maxn],inv[maxn],invf[maxn],n,m,mod;
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
int fa[maxn],siz[maxn];
inline int get(int x){if(x==fa[x])return x;return fa[x]=get(fa[x]);}
inline void init()
{

}
inline void input()
{
	n=gi(),m=gi(),mod=gi();
	fac[0]=fac[1]=inv[0]=inv[1]=invf[0]=invf[1]=1;
	FOR(i,2,n)fac[i]=1ll*i*fac[i-1]%mod;
	FOR(i,2,n)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,n)invf[i]=1ll*invf[i-1]*inv[i]%mod;
	FOR(i,1,n)fa[i]=i,siz[i]=1;
	FOR(i,1,m)
	{
		int u=gi(),v=gi();
		if(get(u)==get(v))continue;
		siz[get(v)]+=siz[get(u)];
		fa[get(u)]=get(v);
	}
}
inline void solve()
{
	int ans=1;int cnt=0;
	FOR(i,1,n)
	{
		if(get(i)==i)
		{
			cnt++;
			if(cnt>=3)ans=1ll*ans*n%mod;
			ans=1ll*ans*siz[i]%mod;
		}
	}
	if(cnt==1)return printf("%d\n",1%mod),void();
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