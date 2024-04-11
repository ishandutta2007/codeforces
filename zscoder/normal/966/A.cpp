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
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n,m,cl,ce,v; cin>>n>>m>>cl>>ce>>v;
	vi A,B;
	A.pb(-int(1e9));
	for(int i=0;i<cl;i++)
	{
		int z; cin>>z; A.pb(z);
	}
	A.pb(int(1e9));
	B.pb(-int(1e9));
	for(int i=0;i<ce;i++)
	{
		int z; cin>>z; B.pb(z);
	}
	B.pb(int(1e9));
	int q; cin>>q;
	for(int z=0;z<q;z++)
	{
		ll x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
		auto it = lower_bound(A.begin(),A.end(),y1);
		ll ans = ll(1e18);
		if(x1==x2) ans=min(ans,abs(y2-y1));
		ans = min(ans, abs(y1-(*it))+abs(x2-x1)+abs(y2-(*it)));
		it--;
		ans = min(ans, abs(y1-(*it))+abs(x2-x1)+abs(y2-(*it)));
		it = lower_bound(B.begin(),B.end(),y2);
		ans = min(ans, abs(y1-(*it))+abs(y2-(*it))+((abs(x2-x1)+v-1)/v));
		it--;
		ans = min(ans, abs(y1-(*it))+abs(y2-(*it))+((abs(x2-x1)+v-1)/v));
		cout<<ans<<'\n';
	}
}