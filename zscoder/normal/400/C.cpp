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
	vector<ii> vec;
	int n,m,x,y,z,p; cin>>n>>m>>x>>y>>z>>p;
	for(int i=0;i<p;i++)
	{
		int a,b; cin>>a>>b;
		a--; b--;
		vec.pb({a,b});
	}
	x%=4; y%=4; z%=4;
	for(int a=0;a<x;a++)
	{
		for(ii &e:vec)
		{
			int x=e.fi; int y=e.se;
			e.fi=y;
			e.se=n-1-x;
		}
		swap(n,m);
	}
	for(int a=0;a<y;a++)
	{
		for(ii &e:vec)
		{
			int x=e.fi; int y=e.se;
			e.se=m-1-e.se;
		}
	}
	for(int a=0;a<z*3;a++)
	{
		for(ii &e:vec)
		{
			int x=e.fi; int y=e.se;
			e.fi=y;
			e.se=n-1-x;
		}
		swap(n,m);
	}
	for(int i=0;i<p;i++)
	{
		cout<<vec[i].fi+1<<' '<<vec[i].se+1<<'\n';
	}
}