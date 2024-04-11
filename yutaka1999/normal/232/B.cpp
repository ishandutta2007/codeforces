#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 105
#define MOD 1000000007

using namespace std;
typedef long long int ll;

ll inv[SIZE],fac[SIZE],finv[SIZE];
ll dp[SIZE*SIZE],pl[SIZE];

void make()
{
	inv[1]=1;
	fac[0]=fac[1]=1;
	finv[0]=finv[1]=1;
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
ll mpow(ll x,ll t)
{
	if(t==0) return 1;
	ll val=mpow(x,t/2);
	val=val*val%MOD;
	if(t%2==1) val=val*x%MOD;
	return val;
}
int main()
{
	make();
	int n,k;
	ll m;
	scanf("%d %llld %d",&n,&m,&k);
	dp[0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=n;j>=1;j--)
		{
			pl[j]=mpow(C(n,j),(m-i+n-1)/n);
		}
		for(int j=k;j>=0;j--)
		{
			for(int p=1;p<=min(j,n);p++)
			{
				dp[j]+=dp[j-p]*pl[p]%MOD;
				if(dp[j]>=MOD) dp[j]-=MOD;
			}
		}
	}
	printf("%llld\n",dp[k]);
	return 0;
}