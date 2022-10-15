#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e7+5,mod=998244353;
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
int n,m,lim;
class mint
{
	public:
	int v;
	mint()=default;
	mint(int _v):v(_v){}
	mint& operator +=(const mint&rhs){v+=rhs.v;if(v>=mod)v-=mod;return *this;}
	mint& operator -=(const mint&rhs){v-=rhs.v;if(v<0)v+=mod;return *this;}
	mint& operator *=(const mint&rhs){v=(ll)v*rhs.v%mod;return *this;}
	mint& operator /=(const mint&rhs){v=(ll)v*rhs.inv().v%mod;return *this;}
	mint operator -(){return v?mod-v:0;}
	friend mint operator +(const mint&lhs,const mint&rhs){return (mint)lhs+=rhs;}
	friend mint operator -(const mint&lhs,const mint&rhs){return (mint)lhs-=rhs;}
	friend mint operator *(const mint&lhs,const mint&rhs){return (mint)lhs*=rhs;}
	friend mint operator /(const mint&lhs,const mint&rhs){return (mint)lhs/=rhs;}
	friend bool operator ==(const mint &lhs,const mint &rhs){return lhs.v==rhs.v;}
	mint inv()const{return qpow(v,mod-2);}
};
mint fac[maxn<<1],ifac[maxn<<1],ans;
mint C(int n,int m){return fac[n]*ifac[m]*ifac[n-m];}
int main()
{
	n=read();m=read();lim=read();
	fac[0]=1;for(int i=1;i<=n+m;i++)fac[i]=fac[i-1]*i;
	ifac[n+m]=fac[n+m].inv();
	for(int i=n+m-1;i>=0;i--)ifac[i]=ifac[i+1]*(i+1);
	int to=n;if(lim)to=min(to,m/lim);
	for(int i=1;i<=to;i++)
	{
		mint val=ifac[n-i]*fac[m-lim*i+n-1]*ifac[m-lim*i]*ifac[i];
		ans+=(i&1)?val:-val;
	}
	ans/=C(m-lim+n-1,n-1);
	printf("%d\n",ans.v);
	return 0;
}