#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MOD 1000000007
#define SIZE 1005
#define MX 1000005

using namespace std;
typedef long long int ll;

ll inv[MX],fac[MX],finv[MX];
ll dp[SIZE][SIZE];

void make()
{
	fac[0]=fac[1]=1;
	finv[0]=finv[1]=1;
	inv[1]=1;
	for(int i=2;i<MX;i++)
	{
		inv[i]=MOD-(MOD/i)*inv[MOD%i]%MOD;
		fac[i]=fac[i-1]*i%MOD;
		finv[i]=finv[i-1]*inv[i]%MOD;
	}
	for(int i=1;i<SIZE;i++)
	{
		if(i==1)
		{
			dp[i][i]=1;
			continue;
		}
		for(int j=1;j<=i;j++)
		{
			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])*j%MOD;
		}
	}
}
ll C(int a,int b)
{
	if(a<b) return 0;
	return fac[a]*(finv[b]*finv[a-b]%MOD)%MOD;
}
ll pw(ll x,int t)
{
	ll ret=1;
	for(int i=0;1<<i<=t;i++)
	{
		if(t>>i&1)
		{
			ret*=x;
			ret%=MOD;
		}
		x*=x;
		x%=MOD;
	}
	return ret;
}
int main()
{
	make();
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	if(m==1)
	{
		printf("%I64d\n",pw(k,n));
		return 0;
	}
	ll ret=0;
	for(int i=1;i<=min(n,k);i++)// E[A[F
	{
		for(int j=0;j<=i;j++)//E[A[v
		{
			ll one=C(k,j);//vFI
			ll sec=C(k-j,i-j)*C(k-i,i-j)%MOD;//E[A[vFI;
			ret+=((one*sec%MOD)*(dp[n][i]*dp[n][i]%MOD)%MOD)*pw(j,n*(m-2))%MOD;
			ret%=MOD;
		}
	}
	printf("%I64d\n",ret);
	return 0;
}