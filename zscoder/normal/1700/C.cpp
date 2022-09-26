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
typedef pair<int,int> ii;
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef bitset<155> b100;

void solve()
{
	int n; cin>>n;
	vi a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vi d(n); d[0]=a[0];
	for(int i=1;i<n;i++) d[i]=a[i]-a[i-1];
	ll ans=0;
	for(int i=1;i<n;i++)
	{
		if(d[i]<0)
		{
			ans+=abs(d[i]);
			d[0]-=abs(d[i]);
			d[i]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		ans+=abs(d[i]);
	}
	cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}