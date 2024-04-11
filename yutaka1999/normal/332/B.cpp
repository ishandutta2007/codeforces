#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 200005

using namespace std;
typedef long long int ll;

ll dp[SIZE];
int pos[SIZE];
int in[SIZE];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	memset(dp,-1,sizeof(dp));
	memset(pos,-1,sizeof(pos));
	ll sum=0;
	for(int i=n-k;i<n;i++) sum+=in[i];
	dp[n-k]=sum;
	pos[n-k]=n-k;
	int a=-1,b=-1;
	ll mx=0;
	for(int i=n-k-1;i>=0;i--)
	{
		sum+=in[i];
		sum-=in[i+k];
		if(dp[i+1]>sum)
		{
			dp[i]=dp[i+1];
			pos[i]=pos[i+1];
		}
		else
		{
			dp[i]=sum;
			pos[i]=i;
		}
		if(dp[i+k]!=-1&&mx<=dp[i+k]+sum)
		{
			mx=dp[i+k]+sum;
			a=i;
			b=pos[i+k];
		}
	}
	printf("%d %d\n",a+1,b+1);
	return 0;
}