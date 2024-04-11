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
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int mn[333333];
int mx[333333];

void solve()
{
	int n; cin>>n;
	vi a(n);
	for(int i=0;i<=n;i++)
	{
		mn[i]=int(1e9); mx[i]=-1;
	}
	vi coord;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i]; a[i]--;
		mn[a[i]]=min(mn[a[i]],i);
		mx[a[i]]=max(mx[a[i]],i);
		coord.pb(a[i]);
	}
	sort(coord.begin(),coord.end()); coord.erase(unique(coord.begin(),coord.end()),coord.end());
	vector<ii> vec;
	for(int i=0;i<coord.size();i++)
	{
		vec.pb({mn[coord[i]],mx[coord[i]]});
	}
	int mxlen=0;
	int r=1;
	for(int i=1;i<vec.size();i++)
	{
		if(vec[i].fi>vec[i-1].se)
		{
			r++;
		}
		else
		{
			mxlen=max(mxlen,r); r=1;
		}
	}
	mxlen=max(mxlen,r);
	cout<<coord.size()-mxlen<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q; cin>>q;
	while(q--)
	{
		solve();
	}
}