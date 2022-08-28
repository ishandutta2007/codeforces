#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 100005
#define INF 1000000000

using namespace std;

int in[SIZE];
int dp[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	fill(dp,dp+SIZE,INF);
	dp[0]=0;
	int ret=0;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		int s=0,e=SIZE;
		while(e-s>1)
		{
			int med=(s+e)/2;
			if(dp[med]<a) s=med;
			else e=med;
		}
		dp[s+1]=a;
		ret=max(ret,s+1);
	}
	printf("%d\n",ret);
	return 0;
}