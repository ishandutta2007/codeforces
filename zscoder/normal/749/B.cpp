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
	vector<ii> vec;
	for(int i=0;i<3;i++)
	{
		int x,y; cin>>x>>y; vec.pb({x,y});
	}
	if((vec[1].se-vec[0].se)*(vec[2].fi-vec[0].fi)==(vec[1].fi-vec[0].fi)*(vec[2].se-vec[0].se)){cout<<0<<'\n'; return 0;}
	set<ii> cand;
	sort(vec.begin(),vec.end());
	do
	{
		int x = vec[0].fi+vec[1].fi-vec[2].fi;
		int y = vec[0].se+vec[1].se-vec[2].se;
		cand.insert({x,y});
	}while(next_permutation(vec.begin(),vec.end()));
	
	cout<<cand.size()<<'\n';
	for(ii x:cand)
	{
		cout<<x.fi<<' '<<x.se<<'\n';
	}
}