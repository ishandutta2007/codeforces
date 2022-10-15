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
int qmod(int x){return x>=mod?x-mod:x;}
int n,k;
int ans;
int inv[1<<22];
void prework(){inv[1]=1;for(int i=2;i<(1<<22);i++)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;}
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
int R[1<<22],W[1<<22];
struct poly
{
	vector<int>v;
	int&operator[](const int &i){return v[i];}
	int len(){return v.size();}
	void set(int l){v.resize(l);}
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
					v[i+j+d]=qmod(v[i+j]-tmp+mod);
					v[i+j]=qmod(v[i+j]+tmp);
				}
		if(typ==-1){int inv=qpow(n,mod-2);for(int i=0;i<n;i++)v[i]=(ll)v[i]*inv%mod;}
	}
	void adjust(){while(len()>1&&v.back()==0)v.pop_back();}
	poly operator *(poly &x)
	{
		poly ret,tmp0=*this,tmp1=x;
		int L=ceil(log2(tmp0.len()+tmp1.len()-1)),n=1<<L;
		tmp0.ntt(L,1);tmp1.ntt(L,1);
		ret.set(n);
		for(int i=0;i<n;i++)ret[i]=(ll)tmp0[i]*tmp1[i]%mod;
		ret.ntt(L,-1);ret.adjust();
		return ret;
	}
	void operator *=(poly &x)
	{
		int L=ceil(log2(len()+x.len()-1)),n=1<<L;
		ntt(L,1);x.ntt(L,1);
		for(int i=0;i<n;i++)v[i]=(ll)v[i]*x[i]%mod;
		ntt(L,-1);adjust();
	}
	poly getinv(int deg=-1)
	{
		if(deg==-1)deg=len();
		if(deg==1)return {{qpow(v[0],mod-2)}};
		poly ret=getinv((deg+1)>>1);
		int L=ceil(log2(deg))+1,n=1<<L;
		poly tmp;tmp.set(deg);
		for(int i=0;i<min(len(),deg);i++)tmp[i]=v[i];
		tmp.ntt(L,1);ret.ntt(L,1);
		for(int i=0;i<n;i++)ret[i]=(ll)ret[i]*qmod(2-(ll)tmp[i]*ret[i]%mod+mod)%mod;
		ret.ntt(L,-1);ret.v.resize(deg);
		return ret;
	}
	poly getln(int deg=-1)
	{
		if(deg==-1)deg=len();
		poly ret,rev=getinv();
		ret.set(deg);
		for(int i=0;i+1<len();i++)ret[i]=(ll)v[i+1]*(i+1)%mod;
		ret*=rev;
		ret.set(deg);
		for(int i=ret.len()-1;i>=1;i--)ret[i]=(ll)ret[i-1]*inv[i]%mod;
		ret[0]=0;
		return ret;
	}
	poly getexp(int deg=-1)
	{
		if(deg==-1)deg=len();
		if(deg==1)return {{1}};
		poly ret=getexp((deg+1)>>1);
		ret.set(deg);
		poly ln=ret.getln();
		int L=ceil(log2(deg))+1,n=1<<L;
		ln[0]=qmod(v[0]+1-ln[0]+mod);
		for(int i=1;i<deg;i++)ln[i]=qmod(v[i]-ln[i]+mod);
		ret*=ln;ret.set(deg);
		return ret;
	}
	poly getpow(int k)
	{
		poly ln=getln();
		for(int &i:ln.v)i=(ll)i*k%mod;
		return ln.getexp();
	}
	void print(){for(int &i:v)printf("%d ",i);putchar('\n');}
}f;
int main()
{
	n=read();k=read();
	f.set(5*n);
	int mi=10;
	for(int i=1;i<=k;i++)
	{
		int v=read();
		mi=min(mi,v);
		f[v]=1;
	}
	for(int i=0;i<=9;i++)if(f[i]&&mi){f[i-mi]=1;f[i]=0;}
	prework();
	f=f.getpow(n/2);
	for(int &i:f.v)(ans+=(ll)i*i%mod)%=mod;
	printf("%d\n",ans);
	return 0;
}