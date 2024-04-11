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

int dp[2][111][10111];

void init(int id)
{
	for(int i=0;i<111;i++)
	{
		for(int j=0;j<10111;j++)
		{
			dp[id][i][j]=-1;
		}
	}
}

void rmax(int &a, int b)
{
	a=max(a,b);
}

int ans[111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vector<ii> vec; int sumall=0;
	for(int i=0;i<n;i++)
	{
		ll x,y; cin>>x>>y;
		vec.pb({x,y}); sumall+=y;
	}
	init(0); init(1);
	dp[1][0][0]=0;
	for(int i=0;i<n;i++)
	{
		int cur=(i&1); int pre=(cur^1);
		init(cur);
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=10000;k++)
			{
				if(dp[pre][j][k]<0) continue;
				int v=dp[pre][j][k];
				rmax(dp[cur][j][k],v);
				rmax(dp[cur][j+1][k+vec[i].fi],v+vec[i].se);
			}
		}
	}
	int las = (n+1)&1;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=10000;j++)
		{
			if(dp[las][i][j]>=0) rmax(ans[i],min(2*j,dp[las][i][j]+sumall));
		}
	}
	for(int i=1;i<=n;i++) rmax(ans[i],ans[i-1]);
	for(int i=1;i<=n;i++)
	{
		cout<<fixed<<setprecision(10)<<ans[i]*0.5<<' ';
	}
	cout<<'\n';
}