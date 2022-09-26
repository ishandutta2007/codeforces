#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int dp[2][11111]; //max r for it to be possible

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,q; cin>>n>>q;
	vector<pair<ii,int> > vec;
	for(int i=0;i<q;i++)
	{
		int l,r,v; cin>>l>>r>>v; l--; r--;
		vec.pb(mp(mp(l,r),v));
	}
	sort(vec.begin(),vec.end());
	memset(dp,-1,sizeof(dp));
	dp[0][0] = int(1e9);
	dp[0][vec[0].se] = vec[0].fi.se;
	for(int i=1;i<q;i++)
	{
		int cur = (i&1); int pre = (cur^1);
		for(int j=0;j<=n;j++) dp[cur][j] = dp[pre][j];
		int l = vec[i].fi.fi; int r = vec[i].fi.se; int v = vec[i].se;
		for(int j=0;j<=n;j++)
		{
			if(j+v<=n&&l<=dp[pre][j]) dp[cur][j+v] = max(dp[cur][j+v], min(dp[pre][j], r));
		}
		/*
		for(int j=0;j<=n;j++)
		{
			cerr<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
		}
		*/
	}
	vi ans;
	for(int i=1;i<=n;i++)
	{
		if(dp[(q+1)&1][i]>=0) ans.pb(i);
	}
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i];
		if(i+1<ans.size()) cout<<' ';
	}
	cout<<'\n';
}