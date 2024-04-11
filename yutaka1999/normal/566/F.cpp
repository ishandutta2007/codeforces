#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 1000005

using namespace std;

int A[SIZE];
int dp[SIZE];
int id[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		dp[A[i]]=0;
	}
	int ret=0;
	for(int i=1;i<SIZE;i++)
	{
		if(dp[i]==-1) continue;
		dp[i]++;
		ret=max(ret,dp[i]);
		for(int j=2*i;j<SIZE;j+=i) if(dp[j]>=0) dp[j]=max(dp[j],dp[i]);
	}
	printf("%d\n",ret);
	return 0;
}