#include<bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
template<typename T=int>T read()
{
	T ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T,m;
const int mod=1e9+7;
namespace sub1
{
	const int maxn=550;
	int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
	struct modint
	{
		int val;
		int qmod(int x)const{return x>=mod?x-mod:x<0?x+mod:x;}
		modint(int v=0){val=v%mod;}
		modint operator +(const modint&x)const{return qmod(val+x.val);}
		modint operator -(const modint&x)const{return qmod(val-x.val);}
		modint operator *(const modint&x)const{return (ll)val*x.val%mod;}
		modint operator /(const modint&x)const{return (ll)val*qpow(x.val,mod-2)%mod;}
	};
	modint fac[maxn],inv[maxn],s[maxn][maxn];
	void prework()
	{
		int n=510;
		fac[0]=1;for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i;
		inv[0]=inv[1]=1;for(int i=2;i<=n;i++)inv[i]=inv[mod%i]*(mod-mod/i);
		for(int i=2;i<=n;i++)inv[i]=inv[i-1]*inv[i];
		s[0][0]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)s[i][j]=s[i-1][j-1]+s[i-1][j]*(i-1);
	}
	modint C(int n,int m){return fac[n]*inv[m]*inv[n-m];}
	struct Int
	{
		modint a,b;
		Int(modint aa=0,modint bb=0){a=aa;b=bb;}
		Int operator +(const Int &x)const{return {a+x.a,b+x.b};}
		Int operator -(const Int &x)const{return {a-x.a,b-x.b};}
		Int operator *(const Int &x)const{return {a*x.a+b*x.b*5,a*x.b+b*x.a};}
		Int operator *(const modint &x)const{return {a*x.val,b*x.val};}
		Int operator /(const Int &x)const{modint bas=x.a*x.a-x.b*x.b*5;return {(a*x.a-b*x.b*5)/bas,(b*x.a-a*x.b)/bas};}
	};
	Int qpow(Int a,ll b){Int ret(1,0);for(;b;b>>=1,a=a*a)if(b&1)ret=ret*a;return ret;}
	const Int A(0,400000003),B(0,600000004),X(500000004,500000004),Y(500000004,500000003);
	int calc(ll l,ll r,int k)
	{
		int ret=0;
		for(int i=0;i<=k;i++)
		{
			Int sum(0,0);
			for(int j=0;j<=i;j++)
			{
				Int sum1(0,0);
				Int now=qpow(X,j)*qpow(Y,i-j);
				if(now.a.val==1&&now.b.val==0)sum1=Int(r-l+1,0);
				else sum1=(qpow(now,r+2)-qpow(now,l+1))/(now-(Int){1,0});
				sum=sum+sum1*C(i,j)*qpow(A,j)*qpow(B,i-j);
			}
			if((k-i)&1)ret=(ret-(ll)sum.a.val*s[k][i].val%mod+mod)%mod;
			else ret=(ret+(ll)sum.a.val*s[k][i].val%mod)%mod;
		}
		return (ll)ret*inv[k].val%mod;
	}
}
signed main()
{
	sub1::prework();
	int k=read();ll l=read<ll>()+1,r=read<ll>()+1;
	printf("%lld\n",sub1::calc(l,r,k));
	return 0;
}