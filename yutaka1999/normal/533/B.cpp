#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005
#define INF 100000000000000000LL

using namespace std;
typedef long long int ll;

vector <int> vec[SIZE];
int A[SIZE];
ll dp[SIZE][2];

void dfs(int v=0)
{
	dp[v][0]=0;
	dp[v][1]=-INF;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		dfs(to);
		ll even=max(dp[v][0]+dp[to][0],dp[v][1]+dp[to][1]);
		ll odd=max(dp[v][0]+dp[to][1],dp[v][1]+dp[to][0]);
		dp[v][0]=even;
		dp[v][1]=odd;
	}
	dp[v][1]=max(dp[v][1],dp[v][0]+A[v]);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int p;
		scanf("%d %d",&p,&A[i]);p--;
		if(p>=0) vec[p].push_back(i);
	}
	dfs();
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		ret=max(ret,dp[i][0]);
		ret=max(ret,dp[i][1]);
		//printf("%d : %lld %lld\n",i,dp[i][0],dp[i][1]);
	}
	printf("%lld\n",ret);
	return 0;
}