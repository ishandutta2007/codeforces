#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#define SIZE 25
#define MM 1<<25
#define MOD 1000000007

using namespace std;
typedef long long int ll;

int dp[MM];
ll sum[MM];
int in[SIZE];
int ng[3];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++) scanf("%d",&ng[i]);
	dp[0]=1;
	sum[0]=0;
	for(int bit=0;bit<1<<n;bit++)
	{
		bool up=true;
		for(int i=0;i<k;i++)
		{
			if(ng[i]==sum[bit])
			{
				up=false;
				break;
			}
		}
		if(!up||dp[bit]==0) continue;
		for(int i=0;i<n;i++)
		{
			if(!(bit>>i&1))
			{
				int nb=bit|1<<i;
				dp[nb]+=dp[bit];
				if(dp[nb]>=MOD) dp[nb]-=MOD;
				sum[nb]=sum[bit]+in[i];
			}
		}
	}
	for(int i=0;i<k;i++)
	{
		if(sum[(1<<n)-1]==ng[i])
		{
			puts("0");
			return 0;
		}
	}
	printf("%d\n",dp[(1<<n)-1]);
	return 0;
}