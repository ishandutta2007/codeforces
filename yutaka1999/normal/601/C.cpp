#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 105
#define MX 100005

using namespace std;

double dp[MX];
double cur[MX];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	if(m==1)
	{
		puts("1.00000000000000");
		return 0;
	}
	for(int i=0;i<MX;i++) dp[i]=0.0;
	dp[0]=1.0;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		int c;
		scanf("%d",&c);
		sum+=c;
		double now=0.0;
		for(int j=0;j<MX;j++)
		{
			cur[j]=dp[j];
			double vl=now;
			if(j>=c) vl-=cur[j-c];
			now+=dp[j];
			dp[j]=vl/(double) (m-1);
			if(j>=m) now-=cur[j-m];
		}
	}
	double all=0.0;
	for(int i=0;i<sum;i++) all+=dp[i];
	printf("%.13f\n",all*(double) (m-1)+1.0);
	return 0;
}