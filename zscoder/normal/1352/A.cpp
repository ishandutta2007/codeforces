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
	string s; cin>>s;
	vi vec; int cur=1;
	for(int i=int(s.length())-1;i>=0;i--)
	{
		if(s[i]!='0')
		{
			vec.pb((s[i]-'0')*cur);
		}
		cur*=10;
	}
	cout<<vec.size()<<'\n';
	for(int v:vec) cout<<v<<' ';
	cout<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}