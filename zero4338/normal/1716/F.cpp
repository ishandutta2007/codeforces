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
const int maxn=2e3+5,mod=998244353;
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
	friend mint qpow(mint a,int b){mint ret=1;for(;b;b>>=1,a*=a)if(b&1)ret*=a;return ret;}
	mint inv()const{return qpow(v,mod-2);}
};
mint s[maxn][maxn];
int T,n,m,k;
int main()
{
	s[0][0]=1;
	for(int i=1;i<=2000;i++)
		for(int j=1;j<=i;j++)s[i][j]=s[i-1][j-1]+s[i-1][j]*j;
	T=read();
	while(T--)
	{
		n=read();m=read();k=read();
		mint ans=0,down=1,pw0=1,pw1=1,inv=qpow(m,mod-2);
		for(int i=0;i<=min(n,k);i++)
		{
			ans+=s[k][i]*down*pw0*pw1;
			down*=n-i;
			pw0*=(m+1)/2;
			pw1*=inv;
		}
		ans*=qpow(m,n);
		printf("%d\n",ans.v);
	}
	return 0;
}