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

int sgn(int x)
{
	if(x>0) return 1;
	else return -1;
}
void solve()
{
	int n; cin>>n; 
	vi a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vi cur; cur.pb(a[0]); cur.pb(a[1]);
	for(int i=2;i<n;i++)
	{
		int siz=cur.size();
		if(sgn(cur[siz-1]-cur[siz-2])==sgn(a[i]-cur[siz-1]))
		{
			cur.pop_back();
		}
		cur.pb(a[i]);
	}
	cout<<cur.size()<<'\n';
	for(int i=0;i<cur.size();i++)
	{
		cout<<cur[i];
		if(i+1<cur.size()) cout<<' ';
	}
	cout<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}