#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll read()
{
	ll ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<1)+(ret<<3)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int mod=998244353;
int n,m;
int fac[54],inv[54];
int C(int n,int m){if(n<0||m<0||n<m)return 0;return (ll)fac[n]*inv[m]%mod*inv[n-m]%mod;}
int ans[54];
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
struct basis
{
	ll v[53];int rk;
	basis(){memset(v,0,sizeof v);rk=0;}
	void insert(ll x)
	{
		for(int i=m-1;i>=0;i--)
			if((x>>i)&1)
			{
				if(!v[i]){v[i]=x;rk++;return;}
				else x^=v[i];
			}
	}
	void adjust()
	{
		for(int i=m-1;i>=0;i--)
			for(int j=m-1;j>i;j--)
				if(v[j]>>i&1)v[j]^=v[i];
	}
	basis getortho()
	{
		adjust();
		basis ret;
		for(int i=0;i<m;i++)
		{
			if(v[i])continue;ret.v[i]|=1ll<<i;ret.rk++;
			for(int j=0;j<m;j++)if(v[j]>>i&1)ret.v[i]|=1ll<<j;
		}
		return ret;
	}
	vector<int>getspancnt()
	{
		vector<int>ret(m+1);vector<ll>vv;for(int i=0;i<m;i++)if(v[i])vv.push_back(v[i]);
		assert(vv.size()<=(m+1)/2);
		function<void(int,ll)>dfs=[&](int u,ll xsum)
		{
			if(u==vv.size()){ret[__builtin_popcountll(xsum)]++;return;}
			dfs(u+1,xsum^vv[u]);
			dfs(u+1,xsum);
		};
		dfs(0,0);
		return ret;
	}
}bas;
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)bas.insert(read());
	if(bas.rk<m/2)
	{
		vector<int>sp=bas.getspancnt();
		for(int i=0;i<=m;i++)ans[i]=sp[i];
	}
	else
	{
		fac[0]=1;for(int i=1;i<=m;i++)fac[i]=(ll)fac[i-1]*i%mod;
		inv[m]=qpow(fac[m],mod-2);for(int i=m-1;i>=0;i--)inv[i]=(ll)inv[i+1]*(i+1)%mod;
		vector<int>cnt=bas.getortho().getspancnt();
		for(int i=0;i<=m;i++)
			for(int j=0;j<=m;j++)
			{
				if(!cnt[j])continue;
				int tmp=0;
				for(int k=0;k<=i&&k<=j;k++)
				{
					if(k&1)(tmp+=mod-(ll)C(j,k)*C(m-j,i-k)%mod)%=mod;
					else (tmp+=(ll)C(j,k)*C(m-j,i-k)%mod)%=mod;
				}
				(ans[i]+=(ll)cnt[j]*tmp%mod)%=mod;
			}
		int inv=qpow((mod+1)/2,m-bas.rk);
		for(int i=0;i<=m;i++)ans[i]=(ll)ans[i]*inv%mod;
	}
	int ex=qpow(2,n-bas.rk);
	for(int i=0;i<=m;i++)ans[i]=(ll)ans[i]*ex%mod;
	for(int i=0;i<=m;i++)printf("%d ",ans[i]);
	putchar('\n');
	return 0;
}