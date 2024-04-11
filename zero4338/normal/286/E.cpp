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
const int maxn=1e6+5;
const int mod=998244353;
int n,m,a[maxn];
bool vis[maxn];
vector<int>ans;
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
int R[1<<21],W[1<<21];
struct poly
{
	vector<int>v;
	int&operator[](int &i){return v[i];}
	void ntt(int L,int typ)
	{
		int n=1<<L;
		for(int i=0;i<n;i++)R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
		W[0]=1;W[1]=qpow(3,(mod-1)/n);if(typ==-1)W[1]=qpow(W[1],mod-2);
		for(int i=2;i<n;i++)W[i]=(ll)W[i-1]*W[1]%mod;
		if(v.size()<n)v.resize(n);
		for(int i=0;i<n;i++)if(R[i]>i)swap(v[i],v[R[i]]);
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
	void adjust(){while(!v.empty()&&v.back()==0)v.pop_back();}
	void squ()
	{
		int L=ceil(log2(v.size())+1),n=1<<L;
		ntt(L,1);
		for(int i=0;i<n;i++)v[i]=(ll)v[i]*v[i]%mod;
		ntt(L,-1);adjust();
	}
}f;
int main()
{
	n=read();m=read();generate_n(a+1,n,read);
	f.v.resize(m+1);
	for(int i=1;i<=n;i++)f[a[i]]=1,vis[a[i]]=1;
	f.squ();
	f.v.resize(m+1);
	for(int i=1;i<=m;i++)
		if(!vis[i]&&f[i]){puts("NO");return 0;}
	for(int i=1;i<=m;i++)
		if(vis[i]&&!f[i])ans.push_back(i);
	printf("YES\n%lu\n",ans.size());
	for(int &i:ans)printf("%d ",i);putchar('\n');
	return 0;
}