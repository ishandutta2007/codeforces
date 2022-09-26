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

struct PBDS
{
	tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> t;
	int timer;
	
	PBDS(){timer = 0;}
	void insert(ll x)
	{
		t.insert(mp(x, timer));
		timer++;
	}
	
	int lower(ll x)
	{
		return t.order_of_key(ii(x, -1));
	}
	
	void del(ll x) //make sure x exists
	{
		ii tmp = (*t.find_by_order(lower(x)));
		t.erase(tmp);
	}
	
	int higher(ll x)
	{
		int tmp = lower(x+1);
		return (int(t.size()) - tmp);
	}
};
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; ll t; cin>>n>>t;
	PBDS T;
	T.insert(0); 
	ll sum=0;
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		ll x; cin>>x;
		sum+=x;
		ans+=T.higher(sum-t);
		T.insert(sum);
	}
	cout<<ans<<'\n';
}