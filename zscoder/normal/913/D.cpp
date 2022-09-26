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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<ii> vec;
	int n; ll T;
	cin>>n>>T;
	for(int i=0;i<n;i++)
	{
		ll a,t;
		cin>>a>>t;
		vec.pb(mp(a,t));
	}
	int lo=0; int hi=n;
	int ans=0;
	while(lo<=hi)
	{
		int mid=(lo+hi)>>1;
		//score = mid;
		vector<ii> V;
		for(int i=0;i<n;i++)
		{
			if(vec[i].fi>=mid)
			{
				V.pb(mp(vec[i].se,i));
			}
		}
		sort(V.begin(),V.end());
		ll sum=0;
		for(int i=0;i<V.size();i++)
		{
			if(i<mid) sum+=V[i].fi;
		}
		if(int(V.size())>=mid&&sum<=T)
		{
			ans=mid;
			lo=mid+1;
		}
		else
		{
			hi=mid-1;
		}
	}
	cout<<ans<<'\n';
	cout<<ans<<'\n';
	vector<ii> V;
	for(int i=0;i<n;i++)
	{
		if(vec[i].fi>=ans)
		{
			V.pb(mp(vec[i].se,i));
		}
	}
	sort(V.begin(),V.end());
	for(int i=0;i<V.size();i++)
	{
		if(i<ans) 
		{
			cout<<V[i].se+1;
			if(i+1<ans) cout<<' ';
		}
	}
	cout<<'\n';
}