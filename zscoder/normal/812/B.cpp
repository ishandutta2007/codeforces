#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

char a[111][104];
int dp[101][2];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	m+=2;
	int highest = 10000000;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='1')
			{
				highest=min(highest,i);
			}
		}
	}
	if(highest>=10000000)
	{
		cout<<0<<'\n';
		return 0;
	}
	dp[n-1][0] = 0;
	dp[n-1][1] = int(1e8);
	for(int i=n-2;i>=highest;i--)
	{
		for(int j=0;j<2;j++)
		{
			dp[i][j]=int(1e8);
			for(int k=0;k<2;k++) //move from dp[i+1][k] to dp[i][j]
			{
				if(j!=k)
				{
					dp[i][j] = min(dp[i][j],dp[i+1][k]+m);
				}
				else
				{
					int l=m-1;
					int r=0;
					for(int z=m-1;z>=0;z--)
					{
						if(a[i+1][z]=='1')
						{
							l=z;
						}
					}
					for(int z=0;z<m;z++)
					{
						if(a[i+1][z]=='1')
						{
							r=z;
						}
					}
					if(k==0)
					{
						dp[i][j]=min(dp[i][j],dp[i+1][k]+2*r+1);
					}
					else
					{
						dp[i][j]=min(dp[i][j],dp[i+1][k]+2*(m-1-l)+1);
					}
				}
			}
		}
	}
	int ans=int(1e9);
	for(int i=0;i<2;i++)
	{
		int l=m-1;
		int r=0;
		for(int z=m-1;z>=0;z--)
		{
			if(a[highest][z]=='1')
			{
				l=z;
			}
		}
		for(int z=0;z<m;z++)
		{
			if(a[highest][z]=='1')
			{
				r=z;
			}
		}
		if(i==0)
		{
			ans=min(ans,dp[highest][i]+r);
		}
		else
		{
			ans=min(ans,dp[highest][i]+m-1-l);
		}
	}
	cout<<ans<<'\n';
}