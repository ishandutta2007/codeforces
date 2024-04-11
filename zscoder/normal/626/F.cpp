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

const int MOD = 1e9 + 7;
int dp[2][210][1001];
int a[201];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin>>n>>m;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	dp[0][0][0] = 1;
	dp[0][1][0] = 1;
	int ans = 0;
	for(int i = 1; i < n; i++)
	{
		int cur = (i&1); int prev = (cur^1);
		memset(dp[cur],0,sizeof(dp[cur]));
		for(int j = 0; j <= i; j++)
		{
			for(int k = 0; k <= m; k++)
			{
				int val = dp[prev][j][k];
				int nval = k+j*(a[i]-a[i-1]);
				if(nval>m) continue;
				dp[cur][j][nval] = (dp[cur][j][nval]+val)%MOD; //handle [] case
				dp[cur][j+1][nval] = (dp[cur][j+1][nval]+val)%MOD; //[
				if(j>0) dp[cur][j-1][nval] = (dp[cur][j-1][nval]+(ll(j)*val)%MOD)%MOD; //]
				if(j>0) dp[cur][j][nval] = (dp[cur][j][nval]+(ll(j)*val)%MOD)%MOD; //default mode
			}
		}
	}	
	for(int i = 0; i <= m; i++)
	{
		ans = (ans+dp[(n&1)^1][0][i])%MOD;
	}
	cout<<ans<<'\n';
}