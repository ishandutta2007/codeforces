#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,x,y,dp[3][300005];
vector<ll>s[300005];
const ll mod=998244353;
void dfs(int p,int f)
{
	int v,ok=0;
	ll sum=1;
	dp[0][p]=dp[1][p]=dp[2][p]=1;
	for(int i=0;i<s[p].size();i++)
	{
		v=s[p][i];
		if(v==f)continue;
		ok=1;
		dfs(v,p);
		dp[0][p]=dp[0][p]*(2ll*dp[0][v]+2ll*dp[1][v]+dp[2][v])%mod;
		dp[1][p]=dp[1][p]*(2ll*dp[0][v]+dp[1][v])%mod;
		dp[2][p]=dp[2][p]*(dp[0][v]+dp[1][v])%mod;
	}
	dp[1][p]=(dp[1][p]-dp[2][p]+mod)%mod;
	if(ok==0)dp[1][p]=0;
}
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		s[x].push_back(y);
		s[y].push_back(x);
	}
	dfs(1,0);
	printf("%lld\n",(dp[0][1]+dp[1][1]-1+mod)%mod);
	return 0;
}