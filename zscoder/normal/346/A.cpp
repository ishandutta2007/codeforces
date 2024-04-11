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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	ll gd = 0;
	vector<ll> vec;
	ll mx=0;
	for(int i=0;i<n;i++)
	{
		ll x; cin>>x; vec.pb(x);
		gd = __gcd(gd,x); mx=max(mx,x);
	}
	/*
	set<ll> S;
	for(int i=0;i<n;i++) S.insert(vec[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			S.insert(abs(vec[i]-vec[j]));
		}
	}
	int res = S.size()-n;
	*/
	int res = mx/gd-n;
	cout<<(res&1?"Alice":"Bob")<<'\n';
}