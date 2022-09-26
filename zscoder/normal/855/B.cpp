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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

ll a[111111];
ll p[3];
ll dp[111111][3];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<3;i++) cin>>p[i];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			dp[i][j]=-ll(5e18);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			ll v=0;
			if(j>0) v=dp[i][j-1];
			dp[i][j] = max(dp[i][j], v + p[j]*a[i]);
			if(i>0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
		}
	}
	cout<<dp[n-1][2]<<'\n';
}