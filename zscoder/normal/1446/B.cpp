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
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

short dp[5011][5011][2][2];

void amax(short &a, short b)
{
	a=max(a,b);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	string s,t; cin>>s>>t;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			for(int k=0;k<2;k++)
			{
				for(int l=0;l<2;l++) dp[i][j][k][l]=-30000;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i]==t[j]) dp[i][j][1][1]=4-1-1;
		}
	}
	short ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<2;k++)
			{
				for(int l=0;l<2;l++)
				{
					short v=dp[i][j][k][l];
					ans=max(ans,v);
					if(v<=-30000) continue;
					//advance s
					if(i+1<n&&k!=0)
					{
						amax(dp[i+1][j][k][l],v-1);
					}
					//stop s
					if(i+1<n)
					{
						amax(dp[i+1][j][0][l],v);
					}
					//advance t
					if(j+1<m&&l!=0)
					{
						amax(dp[i][j+1][k][l],v-1);
					}
					//stop t
					if(j+1<m)
					{
						amax(dp[i][j+1][k][0],v);
					}
					//advance s and t
					if(i+1<n&&j+1<m&&k>0&&l>0&&s[i+1]==t[j+1])
					{
						amax(dp[i+1][j+1][k][l],v+2);
					}
				}
			}
		}
	}
	cout<<ans<<'\n';	
}