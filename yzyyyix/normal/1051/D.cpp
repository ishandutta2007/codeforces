#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define N 2010
#define M 998244353
using namespace std;

ll n,k,dp[N][N][2];

inline void add(ll &u,ll v)
{
	u+=v;
	u%=M;
}

int main()
{
	ll i,j;
	cin>>n>>k;
	dp[1][1][0]=dp[1][2][1]=2;
	for(i=1;i<n;i++)
	{
		for(j=1;j<=k;j++)
		{
			add(dp[i+1][j][0],dp[i][j][0]+dp[i][j][1]*2);
			add(dp[i+1][j][1],dp[i][j][1]);
			add(dp[i+1][j+1][0],dp[i][j][0]);
			add(dp[i+1][j+1][1],dp[i][j][0]*2);
			add(dp[i+1][j+2][1],dp[i][j][1]);
		}
	}
	cout<<(dp[n][k][0]+dp[n][k][1])%M;
}