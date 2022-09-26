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
	multiset<ll> vec;
	for(int i=0;i<n;i++)
	{
		ll x; cin>>x; vec.insert(x);
	}
	vector<ll> processed;
	while(vec.size()>=2)
	{
		auto it = vec.begin();
		auto it2 = it;
		it2++;
		if((*it)==(*it2))
		{
			ll x = (*it);
			vec.erase(vec.find(x));
			vec.erase(vec.find(x));
			vec.insert(x+1);
			continue;
		}
		else
		{
			ll x = (*it);
			processed.pb(x);
			vec.erase(vec.find(x));
			continue;
		}
	}
	for(ll x:vec) processed.pb(x);
	sort(processed.begin(),processed.end());
	ll mx = processed.back();
	mx++;
	mx-=processed.size();
	cout<<mx<<'\n';
}