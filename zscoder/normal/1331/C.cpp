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
	vi p = {0,5,3,2,4,1};
	int x; cin>>x;
	vi digs;
	for(int z=0;z<6;z++)
	{
		digs.pb(x%2); x/=2;
	}
	reverse(digs.begin(),digs.end());
	vi nwdigs(6,0);
	int ans=0;
	for(int z=0;z<6;z++)
	{
		nwdigs[z]=digs[p[z]];
		if(nwdigs[z]) ans|=(1<<(5-z));
	}
	cout<<ans<<'\n';
	/*
	int ans=0;
	for(int i=0;i<6;i++)
	{
		if(x&(1<<(5-i)))
		{
			//cerr<<i<<' '<<p[i]<<'\n';
			ans|=(1<<(p[5-i]));
		}	
	}
	cout<<ans<<'\n';
	*/
}