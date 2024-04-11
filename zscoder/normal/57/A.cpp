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

int n;

int proj(ii pt)
{
	int x=pt.fi; int y=pt.se;
	if(x==0) return y;
	if(y==n) return x+n;
	if(x==n) return 2*n+n-y;
	return 3*n+n-x;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	vector<ii> vec;
	cin>>n;
	for(int i=0;i<2;i++)
	{
		int x,y; cin>>x>>y;
		vec.pb({x,y});
	}	
	int a = proj(vec[0]); int b=proj(vec[1]);
	cout<<min(4*n-abs(a-b),abs(a-b))<<'\n';
}