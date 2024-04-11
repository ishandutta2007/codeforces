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

int dp[111111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vector<ii> vec;
	for(int i=0;i<n;i++)
	{
		int x,y; cin>>x>>y; vec.pb({x,y});
	}
	sort(vec.begin(),vec.end());
	int ans=int(1e9);
	for(int i=0;i<n;i++)
	{
		//press the button
		int x=vec[i].fi; int y=vec[i].se;
		int lb = lower_bound(vec.begin(),vec.end(),mp(x-y,-1))-vec.begin();
		dp[i]=i-lb+(lb-1>=0?dp[lb-1]:0);
		ans=min(ans,n-1-i+dp[i]);
	}
	cout<<ans<<'\n';
}