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
typedef bitset<5000> b100;

void solve()
{
	int n; cin>>n;
	vi p(2*n);
	int cur=-1;
	int run=0;
	vi knaps;
	for(int i=0;i<2*n;i++)
	{
		cin>>p[i];
		if(p[i]<cur)
		{
			run++; continue;
		}
		else
		{
			if(run>0) knaps.pb(run);
			cur=p[i];
			run=1;
		}
	}
	if(run>0) knaps.pb(run);
	//check if can knapsack
	b100 b;
	/*
	for(int x:knaps)
	{
		cerr<<x<<' ';
	}
	cerr<<'\n';
	*/
	b.reset();
	b.set(0,1);
	for(int x:knaps)
	{
		b100 nwb;
		nwb = (b|(b<<x));
		b = nwb;
	}
	cout<<(b[n]?"YES":"NO")<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}