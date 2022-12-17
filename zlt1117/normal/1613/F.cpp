#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define sz(x) (int)(x.size())
#define pb push_back
#define PII pair<int,int>
#define ll long long
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=2.5e5+5,mod=998244353;
int n;
vector<int>e[maxn];
namespace Poly
{
	const int G=3;
	typedef vector<int> poly;
	vector<int>rev;
	inline int qpow(int x,int k)
	{
		int ret=1;
		while(k)
		{
			if(k&1)ret=1ll*x*ret%mod;
			k>>=1,x=1ll*x*x%mod;
		}
		return ret;
	}
	inline int getbit(int len)
	{
		int bit=0;
		while(1<<bit<len)bit++;
		return bit;
	}
	inline void calcrev(int len)
	{
		rev.resize(len);
		int bit=getbit(len);
		FOR(i,0,len-1)rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	}
	inline void dft(poly &a)
	{
		int n=sz(a);
		FOR(i,0,n-1)if(i<rev[i])swap(a[i],a[rev[i]]);
		for(int l=1;l<n;l<<=1)
		{
			int wn=qpow(G,(mod-1)/(l<<1));
			for(int i=0;i<n;i+=l<<1)
			{
				int w=1;
				for(int j=0;j<l;++j,w=1ll*w*wn%mod)
				{
					int v1=a[i+j],v2=1ll*a[i+j+l]*w%mod;
					a[i+j]=(v1+v2)%mod;
					a[i+j+l]=(v1-v2+mod)%mod;
				}
			}
		}
	}
	inline void idft(poly &a)
	{
		int n=sz(a);
		reverse(a.begin()+1,a.end());
		dft(a);
		int inv=qpow(n,mod-2);
		FOR(i,0,n-1)a[i]=1ll*a[i]*inv%mod;
	}
	inline poly operator * (poly a,poly b)
	{
		int len=sz(a)+sz(b),l=len-1;
		if(!sz(a)||!sz(b))return poly();
		len=1<<getbit(len);calcrev(len);
		a.resize(len),b.resize(len);
		dft(a),dft(b);
		FOR(i,0,len-1)a[i]=1ll*a[i]*b[i]%mod;
		idft(a);
		a.resize(l);
		return a;
	}
	inline poly operator + (poly a,poly b)
	{
		if(sz(a)>sz(b))swap(a,b);
		FOR(i,0,sz(a)-1)b[i]=(b[i]+a[i])%mod;
		return b;
	}
}
using namespace Poly;
int fac[maxn],inv[maxn];
inline void input()
{
	n=gi();
	inv[0]=inv[1]=fac[0]=fac[1]=1;
	FOR(i,2,n)fac[i]=1ll*fac[i-1]*i%mod;
	FOR(i,2,n)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,n)inv[i]=1ll*inv[i-1]*inv[i]%mod;
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u);
	}
}
int son[maxn],fa[maxn],tp[maxn],siz[maxn],sons[maxn];
inline void dfs(int u)
{
	siz[u]=1;
	for(int v:e[u])
	{
		if(v==fa[u])continue;
		fa[v]=u;
		dfs(v);
		siz[u]+=siz[v];sons[u]++;
		if(siz[v]>siz[son[u]])son[u]=v;
	}
}
poly dp[maxn];
int f[maxn];
inline poly cdq(vector<poly>&seq,int l,int r)
{
	if(l==r)return seq[l];
	int mid=(l+r)>>1;
	return cdq(seq,l,mid)*cdq(seq,mid+1,r);
}
inline void dfs2(int u)
{
	vector<poly>seq;
	for(int x=u;x;x=son[x])
	{
		seq.clear();seq.pb(dp[x]);
		for(int v:e[x])
		{
			if(v==fa[x]||v==son[x])continue;
			dfs2(v);
			seq.pb(dp[v]);
		}
		dp[x]=cdq(seq,0,sz(seq)-1);
	}
	seq.clear();
	for(int x=u;x;x=son[x])seq.pb(dp[x]);
	dp[u]=cdq(seq,0,sz(seq)-1);
}
inline void solve()
{
	dfs(1);
	FOR(i,1,n)dp[i]={sons[i],1};
//	dfs2(1);
	vector<poly>seq;
	FOR(i,1,n)seq.pb(dp[i]);
	dp[1]=cdq(seq,0,sz(seq)-1);
	FOR(i,0,n)f[i]=1ll*dp[1][n-i]*fac[n-i]%mod;
	int ans=0;
	FOR(i,0,n)i&1?ans=(ans+mod-f[i])%mod:ans=(ans+f[i])%mod;
	printf("%d\n",ans);
}
int main()
{
	input();
	solve();
	return 0;
}