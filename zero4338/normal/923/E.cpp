#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll read()
{
	ll ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int mod=998244353;
const int maxn=1e5+5;
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
int n,p[maxn];ll m;
int R[1<<21],W[1<<21];
int fac[maxn],inv[maxn],ifac[maxn];
void prework()
{
	fac[0]=1;for(int i=1;i<=n+1;i++)fac[i]=(ll)fac[i-1]*i%mod;
	inv[1]=1;for(int i=2;i<=n+1;i++)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	ifac[0]=1;for(int i=1;i<=n+1;i++)ifac[i]=(ll)ifac[i-1]*inv[i]%mod;
}
struct poly
{
	vector<int>v;
	int&operator[](const int &i){return v[i];}
	void set(int l){v.resize(l);}
	int len(){return v.size();}
	void ntt(int L,int typ)
	{
		int n=1<<L;
		for(int i=0;i<n;i++)R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
		W[0]=1;W[1]=qpow(3,(mod-1)/n);if(typ==-1)W[1]=qpow(W[1],mod-2);
		for(int i=2;i<n;i++)W[i]=(ll)W[i-1]*W[1]%mod;
		set(n);
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
		int L=ceil(log2(len()+x.len())),n=1<<L;
		ntt(L,1);x.ntt(L,1);
		for(int i=0;i<n;i++)v[i]=(ll)v[i]*x[i]%mod;
		ntt(L,-1);
	}
};
int main()
{
	n=read();m=read();m%=(mod-1);
	generate_n(p,n+1,read);
	prework();
	poly tmp0,tmp1;
	tmp0.set(n+1);tmp1.set(n+1);
	for(int i=0;i<=n;i++)tmp0[i]=(ll)p[i]*fac[i]%mod;
	for(int i=0;i<=n;i++)tmp1[i]=ifac[n-i];
	tmp0*=tmp1;
	for(int i=0;i<=n;i++)p[i]=(ll)ifac[i]*tmp0[n+i]%mod*qpow(inv[i+1],m)%mod;
	tmp0.set(n+1);tmp1.set(n+1);
	for(int i=0;i<=n;i++)tmp0[i]=(i&1)?(mod-(ll)fac[i]*p[i]%mod)%mod:(ll)fac[i]*p[i]%mod;
	for(int i=0;i<=n;i++)tmp1[i]=ifac[n-i];
	tmp0*=tmp1;
	for(int i=0;i<=n;i++)p[i]=(ll)ifac[i]*tmp0[n+i]%mod;
	for(int i=0;i<=n;i++)if(i&1)p[i]=(mod-p[i])%mod;
	for(int i=0;i<=n;i++)printf("%d ",p[i]);putchar('\n');
	return 0;
}