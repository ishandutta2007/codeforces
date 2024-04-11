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
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
const int maxn=1e5+5;
int n,a,b;
int ans;
int C(int n,int m)
{
	int ret=1;
	for(int i=1;i<=m;i++)ret=(ll)ret*i%mod;
	ret=qpow(ret,mod-2);
	for(int i=n;i>=n-m+1;i--)ret=(ll)ret*i%mod;
	return ret;
}
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
	poly operator *(poly &x)
	{
		poly ret;
		int L=ceil(log2(len()+x.len()-1)),n=1<<L;
		ntt(L,1);x.ntt(L,1);
		ret.set(n);
		for(int i=0;i<n;i++)ret[i]=(ll)v[i]*x[i]%mod;
		ret.ntt(L,-1);
		return ret;
	}
	void operator *=(poly &x)
	{
		int L=ceil(log2(len()+x.len()-1)),n=1<<L;
		ntt(L,1);x.ntt(L,1);
		for(int i=0;i<n;i++)v[i]=(ll)v[i]*x[i]%mod;
		ntt(L,-1);
	}
};
int fac[maxn],inv[maxn];
void prework()
{
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=(ll)fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);for(int i=n-1;i>=0;i--)inv[i]=(ll)inv[i+1]*(i+1)%mod;
}
poly solve(int n)
{
	if(n==1)return {{0,1}};
	if(n&1)
	{
		n--;
		poly retl=solve(n/2),retr;
		poly f,g;
		f.set(n/2+1);
		for(int i=0;i<=n/2;i++)f[i]=(ll)retl[i]*fac[i]%mod;
		g.set(n/2+1);
		g[n/2]=1;
		for(int i=n/2-1;i>=0;i--)g[i]=(ll)g[i+1]*(n/2)%mod;
		for(int i=0;i<=n/2;i++)g[i]=(ll)g[i]*inv[n/2-i]%mod;
		f*=g;
		retr.set(n/2+1);
		for(int i=0;i<=n/2;i++)retr[i]=(ll)inv[i]*f[n/2+i]%mod;
		retl*=retr;retl.v.push_back(0);
		for(int i=retl.len()-1;i>=1;i--)retl[i]=((ll)retl[i]*n%mod+retl[i-1])%mod;
		retl[0]=(ll)retl[0]*n%mod;		
		return retl;
	}
	else
	{
		poly retl=solve(n/2),retr;
		poly f,g;
		f.set(n/2+1);
		for(int i=0;i<=n/2;i++)f[i]=(ll)retl[i]*fac[i]%mod;
		g.set(n/2+1);
		g[n/2]=1;
		for(int i=n/2-1;i>=0;i--)g[i]=(ll)g[i+1]*(n/2)%mod;
		for(int i=0;i<=n/2;i++)g[i]=(ll)g[i]*inv[n/2-i]%mod;
		f*=g;
		retr.set(n/2+1);
		for(int i=0;i<=n/2;i++)retr[i]=(ll)inv[i]*f[n/2+i]%mod;
		return retl*retr;
	}
}
int s(int n,int m)
{
	if(n==0)return m==0;
	return solve(n)[m];
}
int main()
{
	n=read();a=read()-1;b=read()-1;
	if(a<0||b<0||a+b>n-1){puts("0");return 0;}
	prework();
	ans=(ll)s(n-1,a+b)*C(a+b,a)%mod;
	printf("%d\n",ans);
	return 0;
}