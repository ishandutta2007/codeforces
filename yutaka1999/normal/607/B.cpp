#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <cmath>
#define SIZE 505

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int dp[SIZE][SIZE];
int str[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&str[i]);
	memset(dp,0,sizeof(dp));
	for(int L=1;L<=n;L++)
	{
		for(int i=0;i+L<=n;i++)
		{
			int s=i,t=i+L-1;
			if(L==1)
			{
				dp[s][t]=1;
			}
			else
			{
				dp[s][t]=n;
				for(int j=s;j<t;j++)
				{
					dp[s][t]=min(dp[s][t],dp[s][j]+dp[j+1][t]);
				}
				if(str[s]==str[t])
				{
					dp[s][t]=min(dp[s][t],L==2?1:dp[s+1][t-1]);
				}
			}
		}
	}
	printf("%d\n",dp[0][n-1]);
	return 0;
}