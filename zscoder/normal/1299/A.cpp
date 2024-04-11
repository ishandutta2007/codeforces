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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll p[111111];
ll s[111111];
ll a[111111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		p[i]=a[i];
		if(i>0) p[i]|=p[i-1];
	}
	for(int i=n-1;i>=0;i--)
	{
		s[i]=a[i];
		if(i+1<n) s[i]|=s[i+1];
	}
	ll mx=-1; int id=0;
	for(int i=0;i<n;i++)
	{
		ll v = s[i+1];
		if(i>0) v|=p[i-1];
		ll ans = (a[i]|v)-v;
		if(ans>mx)
		{
			mx=ans; id=i;
		}
	}
	cout<<a[id]<<' ';
	for(int i=0;i<n;i++)
	{
		if(i!=id) cout<<a[i]<<' ';
	}
	cout<<'\n';
}