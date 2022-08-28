#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 3005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

char mp[SIZE][SIZE];
int dp[SIZE][SIZE];
int n,m;

void calc()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i+1<n&&mp[i+1][j]=='.')
			{
				dp[i+1][j]+=dp[i][j];
				if(dp[i+1][j]>=MOD) dp[i+1][j]-=MOD;
			}
			if(j+1<m&&mp[i][j+1]=='.')
			{
				dp[i][j+1]+=dp[i][j];
				if(dp[i][j+1]>=MOD) dp[i][j+1]-=MOD;
			}
		}
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",&mp[i]);
	memset(dp,0,sizeof(dp));
	if(mp[0][1]!='#') dp[0][1]=1;
	calc();
	ll e11=dp[n-2][m-1],e12=dp[n-1][m-2];
	memset(dp,0,sizeof(dp));
	if(mp[1][0]!='#') dp[1][0]=1;
	calc();
	ll e21=dp[n-2][m-1],e22=dp[n-1][m-2];
	printf("%I64d\n",(e11*e22%MOD-e12*e21%MOD+MOD)%MOD);
	return 0;
}