#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#define SIZE 200005
#define MOD 998244353

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

vector <int> vec[SIZE];
ll dp0[SIZE],dp1[SIZE],dp2[SIZE];

void dfs(int v=0)
{
	if(vec[v].size()==0)
	{
		dp0[v]=0;
		dp1[v]=0;
		dp2[v]=1;
	}
	else
	{
		ll a=1,b=0,c=0;
		for(int i=0;i<vec[v].size();i++)
		{
			int to=vec[v][i];
			dfs(to);
			ll na=a*(dp0[to]+dp2[to])%MOD;
			ll nb=(b*(dp0[to]+dp2[to])%MOD+a*(dp1[to]+dp2[to])%MOD)%MOD;
			ll nc=(c*((dp0[to]+dp1[to]+2LL*dp2[to])%MOD)%MOD+b*(dp1[to]+dp2[to])%MOD)%MOD;
			a=na,b=nb,c=nc;
		}
		dp0[v]=a,dp1[v]=b,dp2[v]=c;
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
		p--;
		vec[p].push_back(i);
	}
	dfs();
	printf("%lld\n",(dp0[0]+dp2[0])%MOD);
	return 0;
}