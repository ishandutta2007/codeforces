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

void solve()
{
	int n,k,d; cin>>n>>k>>d;
	vi a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int ans=int(1e9);
	for(int i=0;i+d<=n;i++)
	{
		set<int> S;
		for(int j=i;j<i+d;j++)
		{
			S.insert(a[j]);
		}
		ans=min(ans,int(S.size()));
	}
	cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}