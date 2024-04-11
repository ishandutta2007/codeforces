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
ll a,b,c,d; 
ll k,r;

ll getsumBatch(ll id)
{	
	if(id==k)
	{
		return -a+(r*(id+1)+(d-r)*id)*b;
	}
	return -a+((id+1)*d-1)*b;	
}

ll getprefixSum(ll id) //we want id < k here
{
	if(id<0) return 0;
	return -(id+1)*a + b*((((id+1)*(id+2))/2)*d-(id+1));
}

ll getAns(ll id) //last = id
{
	if(id<0||id>k) return ll(9e18);
	return getprefixSum(id-1)-a+id*b;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--)
	{
		cin>>a>>b>>c>>d;
		k = c/d;
		r = c%d;
		if(getsumBatch(k)<0)
		{
			cout<<-1<<'\n'; continue;
		}
		//cerr<<getsumBatch(0)<<'\n';
		//cerr<<getsumBatch(1)<<'\n';
		//cerr<<getprefixSum(0)<<'\n';
		//cerr<<getprefixSum(1)<<'\n';
		ll ans=min(getAns(k),getAns(0));
		/*
		for(ll i=0;i<=k;i++)
		{
			ans=min(ans,getAns(i));
		}
		*/
		ll lo = 1; ll hi = k-1;
		while(lo<=hi)
		{
			ll mid=(lo+hi)>>1;
			ans=min(ans,getAns(mid));
			ans=min(ans,getAns(mid-1));
			if(getAns(mid-1)<getAns(mid))
			{
				hi=mid-1;
			}
			else
			{
				lo=mid+1;
			}
		}
		for(ll i=lo-5;i<=lo+5;i++) ans=min(ans,getAns(i));
		cout<<-ans<<'\n';
	}
}