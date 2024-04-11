#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MOD 1000000007
#define SIZE 1005

using namespace std;
typedef long long int ll;

ll inv[SIZE],finv[SIZE],fac[SIZE];
ll dp[SIZE];
int swt[SIZE];

void make()
{
	inv[1]=1;
	fac[0]=1;fac[1]=1;
	finv[0]=1;finv[1]=1;
	for(int i=2;i<SIZE;i++)
	{
		inv[i]=MOD-(MOD/i)*inv[MOD%i]%MOD;
		fac[i]=(fac[i-1]*i)%MOD;
		finv[i]=(finv[i-1]*inv[i])%MOD;
	}
	dp[0]=1;dp[1]=1;
	for(int i=2;i<SIZE;i++) dp[i]=(dp[i-1]*2)%MOD;
}
void kk(ll&ret,ll t)
{
	ret*=t;
	ret%=MOD;
}
int main()
{
	make();
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++) scanf("%d",&swt[i]);
	sort(swt,swt+m);
	ll ret=fac[n-m];
	kk(ret,finv[swt[0]-1]);
	kk(ret,finv[n-swt[m-1]]);
	for(int i=0;i<m-1;i++)
	{
		int len=swt[i+1]-swt[i]-1;
		kk(ret,dp[len]);
		kk(ret,finv[len]);
	}
	printf("%I64d\n",ret);
	return 0;
}