#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <set>
#include <functional>
#include <queue>
#include <map>
#define SIZE 5005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int A[SIZE];
int dp[SIZE],sum[SIZE];
int n,all;

void dfs(int k,int d)
{
	if(d==n) dp[k]=A[k];
	else
	{
		dfs(k*2+1,d+1);
		dfs(k*2+2,d+1);
		dp[k]=max(dp[k*2+1],dp[k*2+2]);
		all+=dp[k]-dp[k*2+1];
		all+=dp[k]-dp[k*2+2];
		dp[k]+=A[k];
	}
}
int main()
{
	scanf("%d",&n);
	A[0]=0;
	for(int i=1;i<(1<<(n+1))-1;i++) scanf("%d",&A[i]);
	dfs(0,0);
	printf("%d\n",all);
	return 0;
}