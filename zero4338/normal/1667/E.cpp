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
const int maxn=2e5+5,mod=998244353;
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
int n;
int f[maxn],fac[maxn],inv[maxn];
int C(int n,int m){return (ll)fac[n]*inv[m]%mod*inv[n-m]%mod;}
int R[1<<21],W[1<<21];
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
		W[0]=1;W[1]=qpow(3,(mod-1)/n);if(typ==-1)W[1]=qpow(W[1],mod-2)%mod;
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
	poly operator *(poly x)
	{
		poly tmp=*this,ret;
		int L=ceil(log2(len()+x.len())),n=1<<L;
		tmp.ntt(L,1);x.ntt(L,1);
		ret.set(n);
		for(int i=0;i<n;i++)ret[i]=(ll)tmp[i]*x[i]%mod;
		ret.ntt(L,-1);return ret;
	}
};
int main()
{
	n=read();
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=(ll)fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);for(int i=n-1;i>=0;i--)inv[i]=(ll)inv[i+1]*(i+1)%mod;
	f[0]=1;
	int sum=1;
	for(int i=1;i<=n;i++)
	{
		if(i>=(n+1)/2)(sum+=mod-(ll)f[i-(n+1)/2]*inv[i-(n+1)/2]%mod)%=mod;
		f[i]=(ll)sum*fac[i-1]%mod;
		(sum+=(ll)f[i]*inv[i]%mod)%=mod;
	}
	printf("%d ",f[n-1]);
	for(int i=0;i<(n-1)/2;i++)f[i]=0;
	for(int i=(n-1)/2;i<=n-2;i++)f[i]=(ll)f[i]*fac[n-i-2]%mod;
	poly tmp0,tmp1;
	tmp0.set(n-1);
	for(int i=0;i<n-1;i++)tmp0[i]=(ll)f[i]*inv[i]%mod;
	tmp1.set(n);
	for(int i=0;i<n;i++)tmp1[i]=inv[i];
	tmp0=tmp0*tmp1;
	for(int i=2;i<=n;i++)printf("%lld ",(ll)tmp0[n-i]*fac[n-i]%mod*(i-1)%mod);
	return 0;
}