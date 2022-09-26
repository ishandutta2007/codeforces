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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n; cin>>n;
	vector<ll> D;
	for(ll i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			D.pb(i); 
			if(i*i!=n) D.pb(n/i);
		}
	}
	set<ll> S;
	for(ll x:D)
	{
		ll sum = (ll(n/x)*ll(n/x-1))/2;
		sum*=x;
		sum+=n/x;
		S.insert(sum);
	}
	for(ll x:S)
	{
		cout<<x<<' ';
	}
	cout<<'\n';
}