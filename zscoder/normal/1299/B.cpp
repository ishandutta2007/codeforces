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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vector<ii> vec;
	vector<ii> D;
	for(int i=0;i<n;i++)
	{
		ll x,y; cin>>x>>y; vec.pb({x,y});
	}
	for(int i=0;i<n;i++)
	{
		D.pb({vec[(i+1)%n].fi-vec[i].fi,vec[(i+1)%n].se-vec[i].se});
	}
	if(n%2==0)
	{
		int pos=1;
		for(int i=0;i<n/2;i++)
		{
			D[i].fi*=-1; D[i].se*=-1;
			if(D[i]!=D[i+n/2]) pos=0;
		}
		if(pos) {cout<<"YES\n"; return 0;}
	}
	cout<<"NO\n";
}