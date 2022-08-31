#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 2005

using namespace std;

double dp[SIZE][SIZE];
bool u1[SIZE],u2[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		u1[a]=true;
		u2[b]=true;
	}
	int p1=0,p2=0;
	for(int i=0;i<n;i++)
	{
		if(!u1[i]) p1++;
		if(!u2[i]) p2++;
	}
	for(int i=0;i<=p1;i++)
	{
		for(int j=0;j<=p2;j++)
		{
			if(i==0&&j==0) dp[i][j]=0.0;
			else
			{
				double d1=(double) i/(double) n,d2=(double) j/(double) n;
				double z2=1.0-(1.0-d1)*(1.0-d2);
				dp[i][j]=1.0;
				if(i>=1&&j>=1) dp[i][j]+=d1*d2*dp[i-1][j-1];
				if(i>=1) dp[i][j]+=d1*(1.0-d2)*dp[i-1][j];
				if(j>=1) dp[i][j]+=(1.0-d1)*d2*dp[i][j-1];
				dp[i][j]/=z2;
			}
		}
	}
	printf("%.8f\n",dp[p1][p2]);
	return 0;
}