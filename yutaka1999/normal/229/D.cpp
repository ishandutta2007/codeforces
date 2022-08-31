#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 5005
#define INF 1000000000

using namespace std;
template <class T> void chmin(T&a,T b){a=min(a,b);}

int dp[SIZE][SIZE];
int sum[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&sum[i]);
		if(i>0) sum[i]+=sum[i-1];
	}
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j]=INF;
	dp[0][0]=sum[0];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(dp[i][j]==INF) continue;
			if(i==n-1)
			{
				printf("%d\n",j);
				return 0;
			}
			chmin(dp[i+1][j+1],dp[i][j]+(sum[i+1]-sum[i]));
			int s=dp[i][j]+sum[i];
			int pos=lower_bound(sum,sum+n,s)-sum;
			int cst=pos-(i+1)+j;
			if(pos<n) chmin(dp[pos][cst],sum[pos]-sum[i]);
		}
	}
}