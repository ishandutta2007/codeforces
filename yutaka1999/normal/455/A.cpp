#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005

using namespace std;
typedef long long int ll;

ll dp[2][2];
ll all[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		all[a]+=(ll) a;
	}
	int pos=0;
	dp[pos][0]=0;
	dp[pos][1]=0;
	for(int i=1;i<SIZE;i++)
	{
		dp[pos^1][0]=max(dp[pos][0],dp[pos][1]);
		dp[pos^1][1]=dp[pos][0]+all[i];
		pos^=1;
	}
	printf("%I64d\n",max(dp[pos][0],dp[pos][1]));
	return 0;
}