#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <stack>
#define SIZE 300005
#define MOD 998244353

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

vector <int> vec[SIZE];
ll dp[SIZE][3];

void dfs(int v=0,int p=-1)
{
	dp[v][0]=0;
	dp[v][1]=0;
	dp[v][2]=1;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			dfs(to,v);
			ll a=dp[v][0]*((dp[to][1]*2LL+dp[to][2])%MOD)%MOD+dp[v][2]*dp[to][1]%MOD;
			ll b=(dp[v][0]+dp[v][2])%MOD*((dp[to][0]+dp[to][2])%MOD)%MOD+dp[v][1]*((dp[to][1]*2LL+dp[to][2])%MOD)%MOD;
			ll c=dp[v][2]*((dp[to][1]+dp[to][2])%MOD)%MOD;
			dp[v][0]=a%MOD;
			dp[v][1]=b%MOD;
			dp[v][2]=c%MOD;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs();
	printf("%lld\n",(dp[0][1]+dp[0][2])%MOD);
	return 0;
}