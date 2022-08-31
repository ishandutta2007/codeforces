#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define INF 1000000000
#define SIZE 305

using namespace std;

int rui[SIZE][SIZE],mp[SIZE][SIZE];
int dp[2][SIZE][SIZE];

int sum(int x,int s,int e)
{
	if(s==0) return rui[x][e];
	return rui[x][e]-rui[x][s-1];
}
void fill(int pos)
{
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
			dp[pos][i][j]=-INF;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&mp[i][j]);
			rui[i][j]=mp[i][j];
			if(j>0) rui[i][j]+=rui[i][j-1];
		}
	}
	int pos=0;
	fill(pos);
	dp[pos][0][0]=0;
	for(int i=0;i<n;i++)
	{
		pos^=1;
		fill(pos);
		for(int r=0;r<n;r++)
		{
			int mx=-INF;
			for(int l=0;l<r;l++)
			{
				mx=max(mx,dp[pos^1][l][r])+mp[i][l];
				dp[pos][l][r]=max(mx,l<r?dp[pos][l][r-1]:-INF)+mp[i][r];
			}
		}
		int mx=-INF;
		for(int l=0;l<n;l++)
		{
			for(int j=0;j<=l;j++) mx=max(mx,dp[pos^1][j][l]-(j==0?0:sum(i,0,j-1)));
			for(int r=l;r<n;r++) dp[pos][l][r]=max(dp[pos][l][r],mx+sum(i,0,r));
		}
		//puts("");
		//for(int l=0;l<n;l++) for(int r=l;r<n;r++) printf("%d %d %d\n",l,r,dp[pos][l][r]);
	}
	printf("%d\n",dp[pos][n-1][n-1]);
	return 0;
}