#include<iostream>
#include<cstdio>
#define ll long long
#define N 40
#define M 1000000007
using namespace std;

ll n,m,C[N][N],cnt[N][2],dp[N][N][2],ans;

inline void add(ll &u,ll v)
{
	u+=v;
	u%=M;
}

int main()
{
	ll i,j;
	cin>>n;
	for(i=1;i<=n;i<<=1,m++);
	for(i=0; i<=m; i++)
	{
		C[i][0]=C[i][i]=1;
		for(j=1; j<i; j++)
		{
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%M;
		}
		for(j=0; j<=i; j++)
		{
			add(cnt[i][j&1],C[i][j]);
		}
	}
	
	dp[m][0][1]=1;
	for(i=m; i>=1; i--)
	{
		for(j=0; j<=m; j++)
		{
			add(dp[i-1][j][0],dp[i][j][0]*(1 << j)%M);
			add(dp[i-1][j+1][0],dp[i][j][0]);
			if((1 << (i-1))&n)
			{
				add(dp[i-1][j][0],dp[i][j][1]*cnt[j][0]%M);
				add(dp[i-1][j][1],dp[i][j][1]*cnt[j][1]%M);
				add(dp[i-1][j+1][1],dp[i][j][1]);
			}
			else add(dp[i-1][j][1],dp[i][j][1]*cnt[j][0]%M);
		}
	}
	
	for(i=0; i<=m; i++)
	{
		add(ans,dp[0][i][0]+dp[0][i][1]);
	}
	cout<<ans;
}