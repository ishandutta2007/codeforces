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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

ii combine(ii a, ii b)
{
	ii c = {0,0};
	c.fi=a.fi+b.fi;
	//min prefix
	c.se = min(a.se, a.fi+b.se);
	return c;
}

ii dp[1111][1111];
ii x[1111];

void solve()
{
	int n; cin>>n;
	vector<ll> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		if(i&1) x[i]={-a[i],-a[i]};
		else x[i]={a[i],0};
	}
	for(int i=0;i<n;i++)
	{
		ii cur={0,0};
		for(int j=i;j<n;j++)
		{
			cur=combine(cur,x[j]);
			dp[i][j]=cur;
		}
	}
	ll ans=0;
	for(int i=0;i<n;i+=2)
	{
		for(int j=i+1;j<n;j+=2)
		{
			ll x = dp[i+1][j-1].fi;
			ll y = dp[i+1][j-1].se;
			if(j-i==1){x=y=0;}
			ll lef = -y;
			ll ri = min(a[i],a[j]-x);
			//cerr<<i<<' '<<j<<": "<<lef<<' '<<ri<<'\n';
			if(lef<=ri) 
			{
				ans+=ri-lef+1;
				if(j-i==1) ans--; //remove empty
			}
		}
	}
	cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	while(t--) solve();
}