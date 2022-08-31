#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 1005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

ll dp[SIZE][SIZE];//dp[n][k]:(k-1)*k/2<=n
ll cnt[SIZE];
ll fac[SIZE],finv[SIZE],inv[SIZE];
int up[SIZE];

void make()
{
	fac[0]=fac[1]=1;
	finv[0]=finv[1]=1;
	inv[1]=1;
	for(int i=2;i<SIZE;i++)
	{
		inv[i]=MOD-inv[MOD%i]*(ll) (MOD/i)%MOD;
		fac[i]=fac[i-1]*(ll) i%MOD;
		finv[i]=finv[i-1]*inv[i]%MOD;
	}
}
ll C(int a,int b)
{
	if(a<b) return 0;
	return fac[a]*(finv[b]*finv[a-b]%MOD)%MOD;
}
void solve()
{
	memset(dp,0,sizeof(dp));
	for(int i=1;i<SIZE;i++)
	{
		int lim=0;
		for(;lim*(lim-1)/2<=i;lim++);
		up[i]=lim+2;
	}
	dp[0][0]=dp[0][1]=1;
	for(int i=1;i<SIZE;i++)
	{
		for(int j=SIZE-1;j>=i;j--)
		{
			for(int k=1;k<=up[j];k++)
			{
				dp[j][k]=(dp[j][k]+dp[j-i][k-1])%MOD;
			}
		}
	}/*
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++) printf("%llld ",dp[i][j]);
		puts("");
	}*/
}
int main()
{
	make();
	solve();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d %d",&n,&k);n++;
		ll ret=0;
		for(int i=0;i+k<=n-1;i++)
		{
			if(dp[i][k]==0) continue;
			ll pl=dp[i][k];
			pl=(pl*C(n-i-1,k))%MOD;
			ret+=pl;ret%=MOD;
		}
		ret=(ret*fac[k])%MOD;
		printf("%llld\n",ret);
	}
	return 0;
}