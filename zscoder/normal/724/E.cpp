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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

ll dp[2][10001];
ll p[10001];
ll s[10001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; ll c; cin>>n>>c;
	for(int i = 0; i < n; i++)
	{
		cin>>p[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin>>s[i];
	}
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			dp[i][j] = ll(1e18);
		}
	}
	dp[0][0] = p[0];
	dp[0][1] = s[0];
	ll ans = ll(1e18);
	for(int i = 1; i < n; i++)
	{
		int cur=(i&1); int prev = (cur^1);
		for(int j = 0; j <= n; j++)
		{
			dp[cur][j] = ll(1e18);
		}
		for(int j = 0; j <= i+1; j++)
		{
			dp[cur][j] = dp[prev][j]+ll(j)*c+p[i];
			if(j>0) dp[cur][j]=min(dp[cur][j],dp[prev][j-1]+s[i]);			
			if(i==n-1) ans = min(ans, dp[cur][j]);
			//cerr<<i<<' '<<j<<' '<<dp[cur][j]<<'\n';
		}
	}
	cout<<ans;
}