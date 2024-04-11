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


ll dp[111111]; //min cost if i choose back flights from index i
vector<pair<pair<ll,ll>,pair<ll,ll> > > vec;
ll best[111111];
const ll INF = ll(2e12);
vi res;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,k; cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		ll t; int x,y; ll c;
		cin>>t>>x>>y>>c;
		vec.pb(mp(mp(t,c),mp(x,y)));
		res.pb(t);
	}
	sort(vec.begin(),vec.end());
	sort(res.begin(),res.end());
	ll sum=0;
	for(int i=n;i>=1;i--)
	{
		best[i]=INF;
		sum+=best[i];
	}
	for(int i=m-1;i>=0;i--)
	{
		if(vec[i].se.fi==0)
		{
			if(best[vec[i].se.se]>vec[i].fi.se)
			{
				sum-=best[vec[i].se.se];
				sum+=vec[i].fi.se;
				best[vec[i].se.se]=vec[i].fi.se;
			}
		}
		dp[i]=sum;
	}
	sum=0;
	for(int i=n;i>=1;i--)
	{
		sum+=INF;
		best[i]=INF;
	}
	ll ans = INF;
	for(int i=0;i<m;i++)
	{
		if(vec[i].se.se==0)
		{
			if(best[vec[i].se.fi]>vec[i].fi.se)
			{
				sum-=best[vec[i].se.fi];
				sum+=vec[i].fi.se;
				best[vec[i].se.fi]=vec[i].fi.se;
			}
		}
		//cerr<<i<<' '<<sum<<'\n';
		//suppose i only use departure flights from [0,i]
		ll t = vec[i].fi.fi; //last arrival time
		//conference from t + 1 to t + k
		int lb = lower_bound(res.begin(),res.end(),t+k+1)-res.begin();
		if(lb>=int(res.size())) continue;
		ans = min(ans, sum + dp[lb]);
	}
	if(ans>=INF)
	{
		cout<<-1<<'\n';
	}
	else
	{
		cout<<ans<<'\n';
	}
}