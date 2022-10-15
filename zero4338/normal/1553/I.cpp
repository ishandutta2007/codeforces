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
int n,a[maxn],b[maxn],cnt;
int ans;
int R[1<<21],W[1<<21];
struct poly
{
	vector<int>v;
	int&operator[](const int &i){return v[i];}
	poly()=default;
	poly(initializer_list<int>_v){v=_v;}
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
		int L=ceil(log2(x.len()+tmp.len())),n=1<<L;
		tmp.ntt(L,1);x.ntt(L,1);
		ret.set(n);
		for(int i=0;i<n;i++)ret[i]=(ll)tmp[i]*x[i]%mod;
		ret.ntt(L,-1);
		return ret;
	}
	void operator +=(poly x)
	{
		if(len()<x.len())set(x.len());
		for(int i=0;i<x.len();i++)(v[i]+=x[i])%=mod;
	}
	void print()
	{
		for(int &i:v)printf("%d ",i);
		putchar('\n');
	}
};
vector<vector<poly>>solve(int l,int r)
{
	if(l==r)return {{{0,min(b[l],2)},{0,mod-2}},{{1},{mod-1}}};
	int mid=(l+r)>>1;
	auto lans=solve(l,mid),rans=solve(mid+1,r);
	decltype(lans)ret;
	ret.resize(2,vector<poly>(2));
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				ret[i][j]+=lans[i][k]*rans[k][j];
	return ret;
}
int main()
{
	generate_n(a+1,n=read(),read);
	for(int i=1;i<=n;i+=a[i])
	{
		b[++cnt]=a[i];
		for(int j=i;j<=i+a[i]-1;j++)
			if(a[j]!=a[i]){puts("0");return 0;}
	}
	poly f=solve(1,cnt)[0][0];
	int fac=1;
	for(int i=1;i<f.len();i++)(ans+=(ll)fac*f[i]%mod)%=mod,fac=(ll)fac*(i+1)%mod;
	printf("%d\n",ans);
	return 0;
}