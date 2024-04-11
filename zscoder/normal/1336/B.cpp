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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll f(ll x, ll y, ll z)
{
	return (x-y)*(x-y)+(x-z)*(x-z)+(y-z)*(y-z);
}
void solve()
{
	vi vec[3];
	int siz[3];
	for(int i=0;i<3;i++)
	{
		cin>>siz[i];
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<siz[i];j++)
		{
			ll x; cin>>x; vec[i].pb(x);
		}
		sort(vec[i].begin(),vec[i].end());
	}
	vi p(3);
	for(int i=0;i<3;i++) p[i]=i;
	ll ans = ll(9e18);
	do
	{
		vi a[3];
		for(int i=0;i<3;i++)
		{
			a[i]=vec[p[i]];
		}
		//a[0] is the middle
		for(int i=0;i<a[0].size();i++)
		{
			int lb = lower_bound(a[1].begin(),a[1].end(),a[0][i])-a[1].begin();
			int lb2 = upper_bound(a[2].begin(),a[2].end(),a[0][i])-a[2].begin();
			lb2--; //<= it
			if(lb2>=0&&lb2<a[2].size()&&lb>=0&&lb<a[1].size())
			{
				ans=min(ans,f(a[0][i],a[1][lb],a[2][lb2]));
			}
		}
	}while(next_permutation(p.begin(),p.end()));
	cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--)
	{
		solve();
	}
}