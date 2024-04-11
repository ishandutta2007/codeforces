#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 55

using namespace std;
typedef long long int ll;

double dp[SIZE][SIZE];
int in[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	int p;
	scanf("%d",&p);
	dp[0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=p;j>=0;j--)
		{
			for(int k=1;k<=i+1;k++)
			{
				dp[j][k]*=(double) (i+1-k)/(double) (i+1);
				if(j>=in[i]) dp[j][k]+=dp[j-in[i]][k-1]*(double) k/(double) (i+1);
			}
		}
	}
	double ret=0;
	for(int i=0;i<=p;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ret+=dp[i][j];
		}
	}
	printf("%.8f\n",ret);
	return 0;
}