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

void solve()
{
	int n; cin>>n;
	ll w; cin>>w;
	vector<ii> a;
	for(int i=0;i<n;i++)
	{
		ll x; cin>>x; a.pb({x,i});
	}
	sort(a.begin(),a.end());
	while(!a.empty()&&a.back().fi>w) a.pop_back();
	reverse(a.begin(),a.end());
	vi ans;
	ll sum=0;
	for(int i=0;i<a.size();i++)
	{
		if(sum+a[i].fi>w) break;
		sum+=a[i].fi;
		ans.pb(a[i].se);
	}
	if(sum>=(w+1)/2&&sum<=w)
	{
		cout<<ans.size()<<'\n';
		for(int v:ans)
		{
			cout<<v+1<<' ';
		}
		cout<<'\n';
	}
	else
	{
		cout<<-1<<'\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}