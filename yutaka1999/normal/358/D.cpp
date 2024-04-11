#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 3005
#define INF 1000000000

using namespace std;

int dp[2][2];
int a[SIZE],b[SIZE],c[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) scanf("%d",&b[i]);
	for(int i=0;i<n;i++) scanf("%d",&c[i]);
	int pos=0;
	memset(dp[pos],0,sizeof(dp[pos]));
	dp[pos][1]=-INF;
	for(int i=0;i<n;i++)
	{
		pos^=1;
		dp[pos][0]=max(dp[pos^1][1]+c[i],dp[pos^1][0]+b[i]);
		dp[pos][1]=max(dp[pos^1][1]+b[i],dp[pos^1][0]+a[i]);
		///printf("%d %d\n",dp[pos][0],dp[pos][1]);
	}
	printf("%d\n",dp[pos][1]);
	return 0;
}