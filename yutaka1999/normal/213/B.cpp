#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define MOD 1000000007
#define SIZE 105

using namespace std;
typedef long long int ll;

ll inv[SIZE],fac[SIZE],finv[SIZE];
ll dp[2][SIZE];
int in[12];
void make()
{
	inv[1]=1;
	fac[0]=1;fac[1]=1;
	finv[0]=1;finv[1]=1;
	for(int i=2;i<SIZE;i++)
	{
		inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
		fac[i]=(fac[i-1]*i)%MOD;
		finv[i]=(finv[i-1]*inv[i])%MOD;
	}
}
int main()
{
	make();
	int n;
	scanf("%d",&n);
	for(int i=0;i<10;i++) scanf("%d",&in[i]);
	memset(dp[0],0,sizeof(dp[0]));
	dp[0][0]=1;
	int pos=1;
	for(int i=1;i<10;i++)
	{
		int a=in[i];
		memset(dp[pos],0,sizeof(dp[pos]));
		for(int j=a;j<=n;j++)
		{
			for(int k=a;k<=j;k++)
			{
				dp[pos][j]+=(dp[pos^1][j-k]*finv[k])%MOD;
				if(dp[pos][j]>=MOD) dp[pos][j]-=MOD;
			}
		}
		pos^=1;
	}pos^=1;
	ll ret=0;
	for(int k=1;k<=n;k++)
	{
		for(int i=in[0];i<=k;i++)
		{
			ll plus=(dp[pos][k-i]*finv[i])%MOD;
			plus*=fac[k];plus%=MOD;
			ret+=plus;
			if(ret>=MOD) ret-=MOD;
		}
		for(int i=max(in[0],1);i<=k;i++)
		{
			ll gen=(dp[pos][k-i]*finv[i-1])%MOD;
			gen*=fac[k-1];gen%=MOD;
			ret-=gen;
			if(ret<0) ret+=MOD;
		}
	}
	printf("%I64d\n",ret);
	return 0;
}