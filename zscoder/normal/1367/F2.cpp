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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int dp[201111];

void solve()
{
	int n; cin>>n;
	vi a(n);
	vi coord;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]; coord.pb(a[i]);
	}
	sort(coord.begin(),coord.end()); coord.erase(unique(coord.begin(),coord.end()),coord.end());
	map<int,vi> ma;
	for(int i=0;i<n;i++)
	{
		a[i]=lower_bound(coord.begin(),coord.end(),a[i])-coord.begin();
		ma[a[i]].pb(i);
	}
	for(int i=0;i<n;i++)
	{
		dp[i]=0;
	}
	int ans=0;
	for(int i=int(coord.size())-1;i>=0;i--)
	{
		//start from i
		int l = ma[i].front();
		int r = ma[i].back();
		if(i==int(coord.size())-1) dp[i]=ma[i].size();
		else
		{
			int l2 = ma[i+1].front();
			int r2 = ma[i+1].back();
			if(r<l2)
			{
				dp[i]=dp[i+1]+ma[i].size();
			}
			else
			{
				dp[i]=ma[i].size()+(ma[i+1].size()-(lower_bound(ma[i+1].begin(),ma[i+1].end(),r)-ma[i+1].begin()));
			}
		}
	}
	for(int i=0;i<coord.size();i++)
	{
		//use the whole guy
		ans=max(ans,dp[i]);
		//use partially
		if(i+1<coord.size())
		{
			int l=ma[i+1].front(); int r=ma[i+1].back();
			int cnt = lower_bound(ma[i].begin(),ma[i].end(),l)-ma[i].begin();
			ans=max(ans,dp[i+1]+cnt);
		}
		//use partial here partial next
		if(i+1<coord.size())
		{
			for(int j=0;j<ma[i].size();j++)
			{
				ans=max(ans,j+1+(int(ma[i+1].size())-(lower_bound(ma[i+1].begin(),ma[i+1].end(),ma[i][j])-ma[i+1].begin())));
			}
		}
	}
	cout<<n-ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}