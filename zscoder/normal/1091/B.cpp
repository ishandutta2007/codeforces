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
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ii a[1111];
ii b[1111];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		ll x,y; cin>>x>>y; a[i]=mp(x,y);
	}
	for(int i=0;i<n;i++)
	{
		ll x,y; cin>>x>>y; b[i]=mp(x,y);
	}
	for(int i=0;i<n;i++)
	{
		map<ii,int> ma;
		for(int j=0;j<n;j++) ma[b[j]]++;
		ii pos = mp(a[0].fi+b[i].fi,a[0].se+b[i].se);
		bool p=1;
		for(int j=0;j<n;j++)
		{
			ii cur = mp(pos.fi-a[j].fi,pos.se-a[j].se);
			if(ma[cur]==0){p=0; break;}
			ma[cur]--;
		}
		if(p)
		{
			cout<<pos.fi<<' '<<pos.se<<'\n'; return 0;
		}
	}
}