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

ll dp[100001][6][3];
ll a[100001][3];
const ll INF = ll(1e18);

void amax(ll &a, ll b)
{
	a=max(a,b);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin>>a[j][i];
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			for(int k = 0; k < 3; k++)
			{
				dp[i][j][k] = -INF;
			}
		}
	}
	dp[0][0][0] = a[0][0];
	dp[0][1][1] = a[0][1]+a[0][0];
	dp[0][4][2] = a[0][2]+a[0][1]+a[0][0];
	for(int i = 1; i < n; i++)
	{
		amax(dp[i][0][0],dp[i-1][0][0]+a[i][0]);
		amax(dp[i][1][1],dp[i-1][0][0]+a[i][0]+a[i][1]);
		amax(dp[i][4][2],dp[i-1][0][0]+a[i][0]+a[i][1]+a[i][2]);
		
		amax(dp[i][5][1], dp[i-1][5][1]+a[i][1]);
		amax(dp[i][1][0], dp[i-1][5][1]+a[i][1]+a[i][0]);
		amax(dp[i][3][2], dp[i-1][5][1]+a[i][1]+a[i][2]);
		
		amax(dp[i][2][2], dp[i-1][2][2]+a[i][2]);
		amax(dp[i][3][1], dp[i-1][2][2]+a[i][2]+a[i][1]);
		amax(dp[i][4][0],dp[i-1][2][2]+a[i][2]+a[i][1]+a[i][0]);
		
		amax(dp[i][0][0], dp[i-1][1][0]+a[i][0]);
		amax(dp[i][1][1],dp[i-1][1][0]+a[i][0]+a[i][1]);
		amax(dp[i][4][2],dp[i-1][1][0]+a[i][0]+a[i][1]+a[i][2]);
		
		amax(dp[i][5][1],dp[i-1][1][1]+a[i][1]);
		amax(dp[i][1][0],dp[i-1][1][1]+a[i][1]+a[i][0]);
		amax(dp[i][3][2],dp[i-1][1][1]+a[i][1]+a[i][2]);
		
		amax(dp[i][5][1],dp[i-1][3][1]+a[i][1]);
		amax(dp[i][1][0],dp[i-1][3][1]+a[i][1]+a[i][0]);
		amax(dp[i][3][2],dp[i-1][3][1]+a[i][1]+a[i][2]);
		
		amax(dp[i][2][2], dp[i-1][3][2]+a[i][2]);
		amax(dp[i][3][1], dp[i-1][3][2]+a[i][2]+a[i][1]);
		amax(dp[i][4][0],dp[i-1][3][2]+a[i][2]+a[i][1]+a[i][0]);
		
		//all version
		amax(dp[i][0][0], dp[i-1][4][0]+a[i][0]);
		amax(dp[i][1][1],dp[i-1][4][0]+a[i][0]+a[i][1]);
		amax(dp[i][4][2], dp[i-1][4][0]+a[i][0]+a[i][1]+a[i][2]);
		amax(dp[i][4][0], dp[i-1][4][0]+a[i][0]+a[i][1]+a[i][2]);
		
		amax(dp[i][2][2], dp[i-1][4][2]+a[i][2]);
		amax(dp[i][3][1], dp[i-1][4][2]+a[i][2]+a[i][1]);
		amax(dp[i][4][0], dp[i-1][4][2]+a[i][2]+a[i][1]+a[i][0]);
		amax(dp[i][4][2], dp[i-1][4][2]+a[i][2]+a[i][1]+a[i][0]);
		
		
	}
	ll ans = -INF;
	for(int i = 0; i < 5; i++)
	{
		ans=max(ans, dp[n-1][i][2]);
	}
	cout<<ans;
}