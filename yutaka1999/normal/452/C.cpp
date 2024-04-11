#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 1005

using namespace std;

double dp[2][SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int pos=0;
	dp[pos][0]=1.0;
	for(int i=1;i<=n;i++)
	{
		pos^=1;
		for(int j=0;j<SIZE;j++) dp[pos][j]=0.0;
		for(int j=0;j<=m;j++)
		{
			int zan=m-j;
			int all=m*n-(i-1);
			dp[pos][j]+=dp[pos^1][j]*(double) (all-zan)/(double) all;
			dp[pos][j+1]+=dp[pos^1][j]*(double) zan/(double) all;
		}
	}
	double ret=0;
	for(int i=0;i<=m;i++)
	{
		ret+=dp[pos][i]*(double) (i*i)/(double) (n*n);
	}
	printf("%.8f\n",ret*n);
	return 0;
}