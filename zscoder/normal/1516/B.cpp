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
	int n; cin>>n;
	
	vi a(n);
	int x=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]; x^=a[i];
	}
	
	if(x==0)
	{
		cout<<"YES\n"; return ;
	}
	
	//3 segments
	vi L,R;
	{
		int xx=0;
		for(int i=0;i<n;i++)
		{
			xx^=a[i];
			if(xx==x) L.pb(i);
		}
	}
	{
		int xx=0;
		for(int i=n-1;i>=0;i--)
		{
			xx^=a[i];
			if(xx==x) R.pb(i);
		}
	}
	for(int v:L)
	{
		for(int y:R)
		{
			if(v<y) {cout<<"YES\n"; return ;}
		}
	}
	cout<<"NO\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}