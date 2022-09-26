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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

ll c[111];

const ll INF = ll(2e18);

ll mult(ll a, ll b)
{
	if(b==0||a==0) return 0;
	if(a>INF/b) return INF;
	return a*b;
}

ll add(ll a, ll b)
{
	a+=b;
	if(a>=INF) a=INF;
	return a;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n; ll S; cin>>S;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		if(i>0)
		{
			c[i]=min(c[i],c[i-1]*2);
		}
	}
	
	ll lo=0; ll hi=ll(2e18);
	ll ans=0;
	while(lo<=hi)
	{
		ll mid=(lo+hi)>>1;
		ll cur=0;
		ll cost=mid;
		for(int i=n-1;i>=0;i--)
		{
			ll canbuy = cost/c[i];
			cur=add(cur,mult(canbuy,(1LL<<i)));
			cost -= canbuy*c[i];
		}
		if(cur>=S)
		{
			ans=mid; hi=mid-1;
		}
		else
		{
			lo=mid+1;
		}
	}
	cout<<ans<<'\n';
}