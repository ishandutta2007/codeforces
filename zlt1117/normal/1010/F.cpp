#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define sz(x) (int)(x.size())
#define pb push_back
#define PII pair<int,int>
#define ll long long
#define gc getchar()
//#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
using namespace std;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=1e5+5,mod=998244353;
int n;ll x;
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
inline void input()
{
	n=gi();scanf("%lld",&x);
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u);
	}
}
int fa[maxn],siz[maxn],son[maxn];
inline void dfs(int u)
{
	siz[u]=1;
	for(int v:e[u])
	{
		if(v==fa[u])continue;
		fa[v]=u;
		dfs(v);siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
	}
}
poly dp[maxn];
inline pair<poly,poly>cdq(vector<poly>&seq,int l,int r)
{
	if(l==r)return {seq[l],seq[l]};
	int mid=(l+r)>>1;
	pair<poly,poly>p1=cdq(seq,l,mid),p2=cdq(seq,mid+1,r);
	return {p1.first*p2.first,p1.first*p2.second+p1.second};
}
inline poly dfs2(int u)
{
	vector<poly>seq;
	for(int x=u;x;x=son[x])
	{
		dp[x]={0,1};
		for(int v:e[x])
		{
			if(v==fa[x]||v==son[x])continue;
			dp[x]=dp[x]+dp[x]*dfs2(v);
		}
		seq.pb(dp[x]);
	}
	return cdq(seq,0,sz(seq)-1).second;
}
inline void solve()
{
	dfs(1);
	poly ans=dfs2(1);
	x%=mod;int now=1;
	int answer=0;
	FOR(i,1,n)
	{
		answer=(answer+1ll*now*ans[i])%mod;
		now=1ll*now*(x+i)%mod*qpow(i,mod-2)%mod;
	}
	printf("%d\n",answer);
}
int main()
{
	input();
	solve();
	return 0;
}