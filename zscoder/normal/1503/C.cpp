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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vector<ii> vec;
	ll ans=0;
	ii ori;
	for(int i=0;i<n;i++)
	{
		ll x,y; cin>>x>>y;
		ans+=y;
		if(i==0) ori={x,x+y};
		vec.pb({x,x+y});
	}
	ll mx=0;
	sort(vec.begin(),vec.end());
	int id=-1;
	for(int i=0;i<n;i++)
	{
		if(ori==vec[i]){id=i; break;}
	}
	assert(id!=-1);
	//for(int i=0;i<=id;i++) mx=max(mx,vec[i].se);
	for(int i=0;i<n;i++)
	{
		mx=max(mx,vec[i].se);
		if(i+1<n&&mx<vec[i+1].fi)
		{
			ans+=vec[i+1].fi-mx;
		}
	}
	cout<<ans<<'\n';
}