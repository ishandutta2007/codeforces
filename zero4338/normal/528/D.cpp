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
const int maxn=2e5+5;
int n,m,k;
int ans;
string s,t;
bool valid[maxn];
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
int R[1<<21],W[1<<21];
struct poly
{
	vector<int>v;
	int& operator [](int &i){return v[i];}
	void set(int len){v.resize(len);}
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
};
void calc(poly &x,poly &y,poly &ret)
{
	int L=ceil(log2(y.v.size()+x.v.size()-1)),n=1<<L;
	y.ntt(L,1);x.ntt(L,1);
	ret.v.resize(n);
	for(int i=0;i<n;i++)ret[i]=(ll)y.v[i]*x[i]%mod;
	ret.ntt(L,-1);y.ntt(L,-1);x.ntt(L,-1);
}
poly a,b,ret1,ret2;
void solve(char x)
{
	static int diff[maxn];
	for(int i=0;i<n;i++)diff[i]=0;
	for(int i=0;i<n;i++)if(s[i]==x){diff[max(0,i-k)]++;diff[min(n,i+k+1)]--;}
	for(int i=1;i<n;i++)diff[i]+=diff[i-1];
	a.set(n);for(int i=0;i<n;i++)a[i]=diff[i]?1:4;
	b.set(m);for(int i=0;i<m;i++)b[i]=(t[i]==x);reverse(b.v.begin(),b.v.end());
	calc(a,b,ret1);
	a.set(n);for(int i=0;i<n;i++)a[i]=diff[i]?1:2;b.set(m);
	calc(a,b,ret2);
	int sum=0;
	for(int i=0;i<m;i++)if(t[i]==x)sum++;
	for(int i=0;i<n;i++)if((ret1[i]-2*ret2[i]+sum)%mod)valid[i]=0;
}
int main()
{
	n=read();m=read();k=read();cin>>s>>t;
	for(int i=0;i<n;i++)valid[i]=1;
	solve('A');solve('C');solve('G');solve('T');
	for(int i=m-1;i<n;i++)ans+=valid[i];
	printf("%d\n",ans);
	return 0;
}