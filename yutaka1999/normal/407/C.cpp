#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 100150
#define MOD 1000000007
#define MX 105

using namespace std;
typedef long long int ll;

ll inv[SIZE];
ll fac[SIZE],finv[SIZE];
ll dp[SIZE][MX];

void make()
{
	inv[0]=inv[1]=1;
	fac[0]=fac[1]=1;
	finv[0]=finv[1]=1;
	for(int i=2;i<SIZE;i++)
	{
		inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
		finv[i]=finv[i-1]*inv[i]%MOD;
		fac[i]=fac[i-1]*(ll) i%MOD;
	}
}
ll C(int a,int b)
{
	if(a<b) return 0;
	return fac[a]*(finv[a-b]*finv[b]%MOD)%MOD;
}
int main()
{
	make();
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		ll a;
		scanf("%lld",&a);
		dp[i+MX][0]+=a;
		dp[i+MX+1][0]+=MOD-a;
		dp[i+MX][0]%=MOD;
		dp[i+MX+1][0]%=MOD;
	}
	for(int i=0;i<m;i++)
	{
		int l,r,k;
		scanf("%d %d %d",&l,&r,&k);l--;r--;
		l+=MX;r+=MX;
		dp[l-k][k]++;
		dp[l-k][k]%=MOD;
		for(int j=0;j<=k;j++)
		{
			dp[r+1][j]+=MOD-C(r+1-l+k,k-j);
			dp[r+1][j]%=MOD;
		}
	}
	for(int i=0;i<SIZE-1;i++)
	{
		for(int j=0;j<MX-1;j++)
		{
			dp[i+1][j]+=dp[i][j]+dp[i][j+1];
			dp[i+1][j]%=MOD;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%I64d",dp[i+MX][0]);
	}puts("");
	return 0;
}