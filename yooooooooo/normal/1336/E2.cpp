/*
G=prod_{i=1}^n (1+x^{p_i})
p_i<2^m
f[i]=sigma_{j=0}^{2^m-1}[popcount(j)=i]*G[j];
f[0]......f[m]
O(m^3+2^{m/2}+nm)
solutioncfround635div1E2 
*/
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m,x,bas[2][55],cnt[2],ans[55],mdr,fac[55],invfac[55],tot[55],xs[55][55],tpr[55];
const ll mod=998244353,inv2=(mod+1)/2;
ll mypow(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
void Dfs(int id,ll x)
{
	if(id==cnt[mdr])
	{
		int tmp;
		ans[tmp=__builtin_popcountll(x)]++;
		if(ans[tmp]>=mod)ans[tmp]-=mod;
		return;	
	}	
	Dfs(id+1,x);Dfs(id+1,x^bas[mdr][id]);
}
ll C(ll n,ll m){return fac[n]*invfac[m]%mod*invfac[n-m]%mod;}
ll neg(ll x){return (x&1)?mod-1:1;}
void solve1()
{
	for(int i=0;i<m;i++)
	{
		if(bas[0][i])continue;
		bas[1][i]^=(1ll<<i);
		for(int j=0;j<m;j++)
		{
			if(!bas[0][j])continue;
			if(bas[0][j]&(1ll<<i))bas[1][i]^=(1ll<<j);
		}
	}
	mdr=1;
	cnt[1]=0;
	for(int i=0;i<m;i++)if(bas[1][i])bas[1][cnt[1]++]=bas[1][i];
	Dfs(0,0);
	for(int i=0;i<=m;i++)for(int j=0;j<=i;j++)for(int k=0;k<=m-i;k++)xs[i][j+k]=(xs[i][j+k]+C(i,j)*C(m-i,k)%mod*neg(j))%mod;
	for(int i=0;i<=m;i++)for(int j=0;j<=m;j++)tpr[i]=(tpr[i]+ans[j]*xs[j][i])%mod;
	for(int i=0;i<=m;i++)ans[i]=tpr[i]*mypow(inv2,m-cnt[0])%mod;
}
void solve0()
{
	mdr=0;
	cnt[0]=0;
	for(int i=0;i<m;i++)if(bas[0][i])bas[0][cnt[0]++]=bas[0][i];
	Dfs(0,0);
}
int main()
{
	fac[0]=1;
	for(int i=1;i<55;i++)fac[i]=fac[i-1]*i%mod;
	invfac[54]=mypow(fac[54],mod-2);
	for(int i=53;i>=0;i--)invfac[i]=invfac[i+1]*(i+1)%mod;
	scanf("%lld%lld",&n,&m);
	if(m==0)
	{
		printf("%lld ",mypow(2,n));
		for(int i=1;i<=m;i++)printf("0 ");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		for(int j=0;j<m;j++)
		{
			if(!((1ll<<j)&x))continue;
			if(!bas[0][j])
			{
				cnt[0]++;
				bas[0][j]=x;
				for(int k=j+1;k<m;k++)if(bas[0][k]&&((1ll<<k)&bas[0][j]))bas[0][j]^=bas[0][k];
				for(int k=0;k<j;k++)if((1ll<<j)&bas[0][k])bas[0][k]^=bas[0][j];
				break;
			}
			else x^=bas[0][j];
		}
	}
	if(cnt[0]<=27)solve0();
	else solve1();
	for(int i=0;i<=m;i++)printf("%lld ",ans[i]*mypow(2ll,n-cnt[0])%mod);
	return 0;
}