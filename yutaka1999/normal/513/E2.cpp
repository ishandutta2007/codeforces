#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 30005
#define INF 1500000000
#define MX 205

using namespace std;

int dp[2][MX][2][2][2];

void fill(int pos)
{
	for(int i=0;i<MX;i++)
	{
		for(int p=0;p<2;p++)
		{
			for(int q=0;q<2;q++)
			{
				for(int r=0;r<2;r++)
				{
					dp[pos][i][p][q][r]=-INF;
				}
			}
		}
	}
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int pos=0;
	fill(pos);
	dp[pos][0][0][0][1]=0;
	dp[pos][0][0][1][1]=0;
	dp[pos][0][1][0][1]=0;
	dp[pos][0][1][1][1]=0;
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		pos^=1;
		fill(pos);
		for(int j=0;j<=m;j++)
		{
			for(int p=0;p<2;p++)
			{
				for(int q=0;q<2;q++)
				{
					for(int r=0;r<2;r++)
					{
						if(dp[pos^1][j][p][q][r]<-INF/2) continue;
						int pl=0;
						if(r==0)
						{
							if(j!=1)
							{
								if(p==0) pl++;
								else pl--;
							}
							if(j!=m)
							{
								if(q==0) pl--;
								else pl++;
							}
							dp[pos][j][p][q][r]=max(dp[pos][j][p][q][r],dp[pos^1][j][p][q][r]+pl*x);
							dp[pos][j][q][0][1]=max(dp[pos][j][q][0][1],dp[pos^1][j][p][q][r]+pl*x);
							dp[pos][j][q][1][1]=max(dp[pos][j][q][1][1],dp[pos^1][j][p][q][r]+pl*x);
						}
						else
						{
							if(j!=0)
							{
								if(p==0) pl++;
								else pl--;
							}
							if(j+1!=m)
							{
								if(q==0) pl--;
								else pl++;
							}
							dp[pos][j][p][q][r]=max(dp[pos][j][p][q][r],dp[pos^1][j][p][q][r]);
							dp[pos][j+1][p][q][0]=max(dp[pos][j+1][p][q][0],dp[pos^1][j][p][q][r]+pl*x);
							dp[pos][j+1][q][0][1]=max(dp[pos][j+1][q][0][1],dp[pos^1][j][p][q][r]+pl*x);
							dp[pos][j+1][q][1][1]=max(dp[pos][j+1][q][1][1],dp[pos^1][j][p][q][r]+pl*x);
						}
					}
				}
			}
		}
	}
	int ret=-INF;
	for(int p=0;p<2;p++)
	{
		for(int q=0;q<2;q++)
		{
			for(int r=0;r<2;r++)
			{
				ret=max(ret,dp[pos][m][p][q][r]);
				//printf("[%d %d %d] %d\n",p,q,r,dp[pos][m][p][q][r]);
			}
		}
	}
	printf("%d\n",ret);
	return 0;
}