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
const int maxn=1e5+5,mod=998244353;
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
int n,k,ans;
int R[1<<21],W[1<<21];
struct poly
{
	vector<int>v;
	poly()=default;
	poly(int l){v.resize(l);}
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
	poly operator *(poly x)
	{
		poly ret,tmp=*this;
		int L=ceil(log2(tmp.len()+x.len()+1)),n=1<<L;
		ret.set(n);
		tmp.ntt(L,1);x.ntt(L,1);
		for(int i=0;i<n;i++)ret[i]=(ll)tmp[i]*x[i]%mod;
		ret.ntt(L,-1);
		return ret;
	}
};
int inv[maxn],down[maxn];
void prework()
{
	inv[k]=1;
	for(int i=1;i<=k;i++)inv[k]=(ll)inv[k]*i%mod;
	inv[k]=qpow(inv[k],mod-2);
	for(int i=k-1;i>=0;i--)inv[i]=(ll)inv[i+1]*(i+1)%mod;
	down[0]=1;
	for(int i=1;i<=k;i++)down[i]=(ll)down[i-1]*(n-i+1)%mod;
}
int main()
{
	n=read();k=read();
	prework();
	poly f(k+1),g(k+1);
	for(int i=0;i<=k;i++)f[i]=(i&1)?mod-inv[i]:inv[i];
	for(int i=0;i<=k;i++)g[i]=(ll)qpow(i,k)*inv[i]%mod;
	f=f*g;
	for(int i=0;i<=min(n,k);i++)
		(ans+=(ll)f[i]*down[i]%mod*qpow(n+1,n-i)%mod)%=mod;
	printf("%d\n",ans);
	return 0;
}