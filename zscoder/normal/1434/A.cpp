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

set<ll> S[111111];
set<ii> T;
map<int,vector<int> > ma;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll a[6]; 
	for(int i=0;i<6;i++) cin>>a[i];
	int n; cin>>n;
	
	ll minans=ll(1e18);
	
	for(int i=0;i<n;i++)
	{
		int x; cin>>x;
		for(int j=0;j<6;j++)
		{
			S[i].insert(x-a[j]);
			ma[x-a[j]].pb(i);
		}
	}
	
	for(int i=0;i<n;i++)
	{
		T.insert({(*S[i].begin()),i});
	}
	for(auto X:ma)
	{
		if(T.size()<n) break;
		ll beg = X.fi;
		ll r = (*(prev(T.end()))).fi;
		minans=min(minans,r-beg);
		for(auto i:X.se)
		{
			T.erase({(*S[i].begin()),i});
		}
		for(auto id:X.se)
		{
			S[id].erase(beg);
		}
		for(auto id:X.se)
		{
			if(!S[id].empty()) T.insert({(*S[id].begin()),id});
		}
	}
	cout<<minans<<'\n';
}