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
const int mod=998244353;
const int maxn=1<<15;
int n,k;
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
int R[1<<21],W[1<<21];
struct poly
{
	vector<int>v;
	int&operator[](const int &i){return v[i];}
	void ntt(int L,int typ)
	{
		int n=1<<L;
		for(int i=0;i<n;i++)R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
		W[0]=1;W[1]=qpow(3,(mod-1)/n);if(typ==-1)W[1]=qpow(W[1],mod-2);
		for(int i=2;i<n;i++)W[i]=(ll)W[i-1]*W[1]%mod;
		if(v.size()<n)v.resize(n);
		for(int i=0;i<n;i++)if(R[i]>i)swap(v[R[i]],v[i]);
		for(int t=n>>1,d=1;d<n;d<<=1,t>>=1)
			for(int i=0;i<n;i+=(d<<1))
				for(int j=0;j<d;j++)
				{
					int tmp=(ll)W[t*j]*v[i+j+d]%mod;
					v[i+j+d]=(v[i+j]-tmp+mod)%mod;
					v[i+j]=(v[i+j]+tmp)%mod;
				}
		if(typ==-1){int inv=qpow(n,mod-2);for(int i=0;i<n;i++)v[i]=(ll)v[i]*inv%mod;}
	}
	void operator *=(poly &x)
	{
		int L=ceil(log2(v.size()+x.v.size()-1)),n=1<<L;
		ntt(L,1);x.ntt(L,1);
		for(int i=0;i<n;i++)v[i]=(ll)v[i]*x[i]%mod;
		ntt(L,-1);
	}
}a,b;
int fac[maxn],dfac[maxn],inv[maxn],dinv[maxn],pow2[maxn];
void prework()
{
	fac[0]=1;for(int i=1;i<=k;i++)fac[i]=(ll)fac[i-1]*i%mod;
	for(int i=0;i<=k;i++)inv[i]=qpow(fac[i],mod-2);
	dfac[0]=1;for(int i=1;i<=k;i++)dfac[i]=(ll)dfac[i-1]*(n-i+1)%mod;
	for(int i=0;i<=k;i++)dinv[i]=qpow(dfac[i],mod-2);
	pow2[0]=1;for(int i=1;i<=k;i++)pow2[i]=pow2[i-1]*2%mod;
}
int main()
{
	n=read();k=read();
	prework();
	a.v.resize(k+1);
	for(int i=0;i<=k;i++)a[i]=(ll)dinv[i]*inv[i]%mod;
	for(int i=1;i<=k;i+=2)a[i]=mod-a[i];
	b.v.resize(k+1);
	for(int i=0;i<=k;i++)b[i]=(ll)pow2[i]*inv[i]%mod*inv[i]%mod;
	a*=b;
	for(int i=1;i<=k;i++)printf("%lld ",(ll)fac[i]*dfac[i]%mod*a[i]%mod);putchar('\n');
	return 0;
}