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
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void solve()
{
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x;
	}
	cout<<3*n<<'\n';
	for(int i=1;i<=n;i+=2)
	{
		cout<<1<<' '<<i<<' '<<i+1<<'\n';
		cout<<2<<' '<<i<<' '<<i+1<<'\n';
		cout<<1<<' '<<i<<' '<<i+1<<'\n';
		cout<<1<<' '<<i<<' '<<i+1<<'\n';
		cout<<2<<' '<<i<<' '<<i+1<<'\n';
		cout<<1<<' '<<i<<' '<<i+1<<'\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}