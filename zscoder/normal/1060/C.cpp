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
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll a[2222];
ll b[2222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	ll x; cin>>x;
	vector<pair<ll,int> > A;
	for(int i=0;i<n;i++)
	{
		ll s=0;
		for(int j=i;j<n;j++)
		{
			s+=a[j]; A.pb(mp(s,j-i+1));
		}
	}
	sort(A.rbegin(),A.rend());
	vector<pair<ll,int> > B;
	for(int i=0;i<m;i++)
	{
		ll s=0;
		for(int j=i;j<m;j++)
		{
			s+=b[j]; B.pb(mp(s,j-i+1));
		}
	}
	sort(B.begin(),B.end());
	ll ans=0; int mx = 0; int ptr = 0;
	for(ii p:A)
	{
		ll v = p.fi; ll val = p.se;
		ll s2 = x/v;
		while(ptr<B.size()&&B[ptr].fi<=s2)
		{
			mx=max(mx,B[ptr].se);
			ptr++;
		}
		ans = max(ans, val*mx);
	}
	cout<<ans<<'\n';
}