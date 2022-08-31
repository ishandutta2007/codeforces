#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 105
#define MOD 1000000007

using namespace std;
typedef long long int ll;

int dp[2][SIZE][SIZE][SIZE];

int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);n++;m++;
	int pos=0,ret=0;
	memset(dp[pos],0,sizeof(dp[pos]));
	dp[pos][1][1][1]=1;
	for(int i=2;i<=m;i++)
	{
		pos^=1;
		memset(dp[pos],0,sizeof(dp[pos]));
		for(int j=1;j<=n;j++)
		{
			for(int p=1;p<=j;p++)
			{
				for(int q=1;q<=k;q++)
				{
					if(dp[pos^1][j][p][q]==0) continue;
					int way=1;
					for(int r=0;2*r+j<=n;r++)
					{
						if(way*q<=k)
						{
							dp[pos][j+2*r][r][way*q]+=dp[pos^1][j][p][q];
							if(dp[pos][j+2*r][r][way*q]>=MOD) dp[pos][j+2*r][r][way*q]-=MOD;
						}
						else break;
						if(p==0) break;
						way*=p+r;
						way/=r+1;
					}
				}
			}
		}
		if(i>2)
		{
			for(int j=1;j<=n;j++)
			{
				for(int q=1;q<=k;q++)
				{
					ret+=(int) ((ll) dp[pos][j][0][q]*(ll) (m-i+1)%MOD);
					if(ret>=MOD) ret-=MOD;
				}
			}
		}
	}
	printf("%d\n",ret);
	return 0;
}