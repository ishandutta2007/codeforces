#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 2005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

ll dp[SIZE],gen[SIZE];
ll cur[SIZE];
int in[SIZE];
int n;

void make(int x)
{
	if(x==0)
	{
		memset(dp,0,sizeof(dp));
		dp[0]=1;
	}
	else
	{
		make(x/2);
		for(int i=0;i<n;i++)
		{
			cur[i]=0;
			for(int j=0;j<=i;j++) cur[i]=(cur[i]+dp[j]*dp[i-j]%MOD)%MOD;
		}
		for(int i=0;i<n;i++) dp[i]=cur[i];
		if(x%2==1)
		{
			for(int i=1;i<n;i++) dp[i]=(dp[i]+dp[i-1])%MOD;
		}
	}
}
int main()
{
	int k;
	scanf("%d %d",&n,&k);
	make(k);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	for(int i=0;i<n;i++)
	{
		ll val=0;
		for(int j=0;j<=i;j++)
		{
			val=(val+(ll) in[j]*dp[i-j])%MOD;
		}
		if(i!=0) printf(" ");
		printf("%llld",val);
	}puts("");
	return 0;
}