#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#define SIZE 200005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

vector <int> vec[SIZE];
int dp[SIZE],go[SIZE];
int n,x,y;

void dfs(int v=0,int p=-1)
{
	dp[v]=0;
	go[v]=0;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			dfs(to,v);
			dp[v]+=dp[to];
			go[v]+=go[to];
		}
	}
	if(go[v]==0)
	{
		dp[v]++;
		go[v]=1;
	}
	else if(go[v]>=2)
	{
		dp[v]--;
		go[v]=0;
	}
}
ll solve1()
{
	dfs();
	//printf("%d\n",dp[0]);
	ll ret=(ll) (dp[0]-1)*(ll) y+(ll)(n-dp[0])*(ll) x;
	return ret;
}
ll solve2()
{
	int mx=0;
	for(int i=0;i<n;i++) mx=max(mx,(int) vec[i].size());
	if(mx==n-1) return (ll) x+(ll) y*(ll) (n-2);
	return (ll) y*(ll) (n-1);
}
int main()
{
	scanf("%d %d %d",&n,&x,&y);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	printf("%I64d\n",min(solve1(),solve2()));
	return 0;
}