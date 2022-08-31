#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 1005
#define MX 15
#define INF 1000000000

using namespace std;

int dist[SIZE][SIZE];
char mp[SIZE][MX][MX];
int dp[SIZE],pos[SIZE];
bool use[SIZE];
int L[SIZE],R[SIZE];

int main()
{
	int n,m,k,w;
	scanf("%d %d %d %d",&n,&m,&k,&w);
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%s",&mp[i][j]);
		}
	}
	for(int i=0;i<k;i++)
	{
		for(int j=i+1;j<k;j++)
		{
			int cnt=0;
			for(int x=0;x<n;x++)
			{
				for(int y=0;y<m;y++)
				{
					if(mp[i][x][y]!=mp[j][x][y])
					{
						cnt+=w;
					}
				}
			}
			dist[i][j]=dist[j][i]=cnt;
		}
	}
	for(int i=0;i<k;i++)
	{
		dp[i]=n*m;
		pos[i]=-1;
		use[i]=false;
	}
	int sum=0;
	for(int i=0;i<k;i++)
	{
		int mn=INF,p=-1;
		for(int j=0;j<k;j++)
		{
			if(!use[j]&&mn>dp[j])
			{
				mn=dp[j];
				p=j;
			}
		}
		L[i]=p;R[i]=pos[p];
		use[p]=true;
		sum+=mn;
		for(int j=0;j<k;j++)
		{
			if(dp[j]>dist[j][p])
			{
				dp[j]=dist[j][p];
				pos[j]=p;
			}
		}
	}
	printf("%d\n",sum);
	for(int i=0;i<k;i++) printf("%d %d\n",L[i]+1,R[i]+1);
	return 0;
}