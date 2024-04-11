#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#define SIZE 100005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

vector <int> vec[SIZE];
ll dp[SIZE][2];
int col[SIZE];

void dfs(int v=0,int p=-1)
{
	dp[v][0]=dp[v][1]=0;
	dp[v][col[v]]=1;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			dfs(to,v);
			ll zero=dp[v][0],one=dp[v][1];
			dp[v][0]=(zero*dp[to][0]%MOD+zero*dp[to][1]%MOD)%MOD;
			dp[v][1]=(one*(dp[to][0]+dp[to][1])%MOD+zero*dp[to][1]%MOD)%MOD;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int p;
		scanf("%d",&p);
		vec[p].push_back(i);
		vec[i].push_back(p);
	}
	for(int i=0;i<n;i++) scanf("%d",&col[i]);
	dfs();
	printf("%I64d\n",dp[0][1]);
	return 0;
}