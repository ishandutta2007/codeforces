#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 55
#define LIM 1000000000000000005LL

using namespace std;
typedef long long int ll;

ll dp[SIZE];
int ans[SIZE];

int main()
{
	int n;
	ll L;
	scanf("%d %I64d",&n,&L);
	dp[n]=1;
	for(int i=n-1;i>=0;i--)
	{
		dp[i]=dp[i+1]+dp[i+2];
		dp[i]=min(dp[i],L+1);
	}
	for(int i=0;i<n;i++)
	{
		if(L<=dp[i+1]) ans[i]=i;
		else
		{
			L-=dp[i+1];
			ans[i]=i+1;
			ans[i+1]=i;
			i++;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",ans[i]+1);
	}puts("");
	return 0;
}