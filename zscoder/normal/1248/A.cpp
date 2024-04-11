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
typedef pair<int,int> ii;
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void solve()
{
	int n; cin>>n;
	vi a(n);
	ll cnt[2][2]={};
	for(int i=0;i<n;i++) 
	{
		cin>>a[i]; cnt[0][a[i]&1]++;
	}
	int m; cin>>m;
	vi b(m);
	for(int i=0;i<m;i++) cin>>b[i];
	for(int i=0;i<m;i++) 
	{
		 cnt[1][b[i]&1]++;
	}
	cout<<cnt[0][0]*cnt[1][0]+cnt[0][1]*cnt[1][1]<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}