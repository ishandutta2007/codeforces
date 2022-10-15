// ubsan: undefined
// accoders
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
const int maxn=2.5e3+5,maxm=1e5+5,mod=1e9+7;
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
class mint
{
	public:
	int v;
	mint()=default;
	mint(int _v):v(_v){}
	mint& operator +=(const mint &rhs){v+=rhs.v;if(v>=mod)v-=mod;return *this;}
	mint& operator -=(const mint &rhs){v-=rhs.v;if(v<0)v+=mod;return *this;}
	mint& operator *=(const mint &rhs){v=(ll)v*rhs.v%mod;return *this;}
	mint& operator /=(const mint &rhs){v=(ll)v*rhs.inv().v%mod;return *this;}
	mint operator -()const{return v?mod-v:0;}
	friend mint operator +(const mint &lhs,const mint &rhs){return (mint)lhs+=rhs;}
	friend mint operator -(const mint &lhs,const mint &rhs){return (mint)lhs-=rhs;}
	friend mint operator *(const mint &lhs,const mint &rhs){return (mint)lhs*=rhs;}
	friend mint operator /(const mint &lhs,const mint &rhs){return (mint)lhs/=rhs;}
	static mint qpow(mint a,int b){mint ret=1;for(;b;b>>=1,a*=a)if(b&1)ret*=a;return ret;}
	mint inv()const{return qpow(v,mod-2);}
};
int n,a[maxn],s,mx;
mint f[maxm],ans;
int main()
{
	generate_n(a+1,n=read(),read);
	s=accumulate(a+1,a+n+1,0);
	mx=*max_element(a+1,a+n+1);
	for(int i=1;i<mx;i++)f[i+1]=-f[i-1]+2*f[i]-mint(1)/(s-i);
	for(int i=1;i<=n;i++)ans+=f[a[i]];
	ans+=s-1;
	ans*=s-1;
	printf("%d\n",ans.v);
	return 0;
}