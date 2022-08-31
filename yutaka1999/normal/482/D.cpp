#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

vector <int> vec[SIZE];
ll dp[SIZE][2];

void dfs(int v=0)
{
	dp[v][0]=0;
	dp[v][1]=1;
	ll s=1,t1=1,t2=0;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		dfs(to);
		ll A=(dp[v][0]*dp[to][0]+dp[v][1]*dp[to][1])%MOD;
		ll B=(dp[v][0]*dp[to][1]+dp[v][1]*dp[to][0])%MOD;
		dp[v][0]=A;
		dp[v][1]=B;
		s=s*dp[to][0]%MOD;
		ll T1=(t1+t2*dp[to][1])%MOD;
		ll T2=(t2+t1*dp[to][1])%MOD;
		t1=T1,t2=T2;
	}
	//size0OS
	dp[v][0]=dp[v][0]*2LL%MOD;
	dp[v][1]=dp[v][1]*2LL%MOD;
	dp[v][1]-=s;
	if(dp[v][1]<0) dp[v][1]+=MOD;
	dp[v][0]-=t2;
	if(dp[v][0]<0) dp[v][0]+=MOD;
	dp[v][0]++;
	if(dp[v][0]>=MOD) dp[v][0]-=MOD;
	//printf("%d : %lld %lld %lld : %lld %lld\n",v,s,t1,t2,dp[v][0],dp[v][1]);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int p;
		scanf("%d",&p);p--;
		vec[p].push_back(i+1);
	}
	dfs();
	printf("%lld\n",(dp[0][0]+dp[0][1]+MOD-1LL)%MOD);
	return 0;
}