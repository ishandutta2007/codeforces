#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 1000005
#define INF 1000000000

using namespace std;

char in[SIZE];
int dp[SIZE][2];

int main()
{
	memset(dp,0,sizeof(dp));
	memset(in,0,sizeof(in));
	scanf("%s",&in);
	int s=strlen(in);
	dp[s][0]=0;
	dp[s][1]=INF;
	for(int i=s-1;i>=0;i--)
	{
		if(in[i]=='0')
		{
			dp[i][0]=min(dp[i+1][0],dp[i+1][1]+1);// 00 || 01 - 01 = 00
			dp[i][1]=dp[i+1][1]+1;//01 + 01 = 10
		}
		else
		{
			dp[i][0]=dp[i+1][0]+1;// 01 - 01 = 00
			dp[i][1]=min(dp[i+1][0]+1,dp[i+1][1]);// 01 + 01 || 10 = 10
		}
	}
	printf("%d\n",min(dp[0][0],dp[0][1]+1));
	return 0;
}