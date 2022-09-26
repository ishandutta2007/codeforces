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

ll p[200011];
ll P[200011];
ll fen[200011];
const ll N = 200010;
void add(ll pos, ll v)
{
	for(;pos<=N;pos+=(pos&(-pos)))
	{
		fen[pos]+=v;
	}
}

ll get(ll x)
{
	if(x<0) return 0;
	ll ans=0;
	for(;x>0;x-=(x&(-x)))
	{
		ans+=fen[x];
	}
	return ans;
}

const ll C = 10;
vector<ii> queries[200011];
ll ans[200011*C];
vector<pair<ii,ii> > vec;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n,q; cin>>n>>q;
	for(ll i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	ll cnt=0;
	for(ll i=0;i<q;i++)
	{
		ll l,d,r,u;
		cin>>l>>d>>r>>u;
		d--;
		vec.pb(mp(mp(l,r),mp(d,u)));
		
		//find # of pairs x, y which works with min(p[x],p[y])<=u
		
		//count for x<l,y>=l
		queries[l-1].pb(mp(u,cnt++));
		
		//count for x<=r,y>r
		queries[r].pb(mp(u,cnt++));
		
		
		//count for l<=x<y<=r
		//find # of pairs x, y with min(p[x],p[y])<=d
		
		//count for x < l,y>=l
		queries[l-1].pb(mp(d,cnt++));
		queries[r].pb(mp(d,cnt++));
		
	}
	
	for(ll i=0;i<=n;i++)
	{
		if(i>0) add(p[i],1);
		for(ll j=0;j<queries[i].size();j++)
		{
			//////cerr<<i<<' '<<queries[i][j].se<<' '<<get(queries[i][j].fi)<<'\n';
			ans[queries[i][j].se]=get(queries[i][j].fi); //get # of <=
		}
	}
	
	for(ll i=0;i<q;i++)
	{
		ll l=vec[i].fi.fi; ll r=vec[i].fi.se;
		ll d=vec[i].se.fi; ll u=vec[i].se.se;
		
		ll ans1 = 0;
		
		//find # of pairs x, y which works with min(p[x],p[y])<=u
		ll L1 = ans[i*4];
		ll L2 = ans[i*4+1];
		////cerr<<L1<<' '<<L2<<'\n';
		//count for x<l,y>=l
		ans1 += (l-1)*(n-(l-1)) - (l - 1 - L1)*(n - (l - 1) - (u - L1));
		
		//count for x<=r,y>r
		ans1 += r*(n-r) - (r - L2)*(n - r - (u - L2));
		ans1 -= (l-1)*(n-r) - (l-1-L1)*(n-r-(u-L2));
		//cerr<<"ANS 1 : "<<ans1<<'\n';
		//count for l<=x<y<=r
		ll bad = (r - l + 1) - (L2 - L1);
		ans1 += ((r-l+1)*(r-l))/2 - (bad*(bad-1))/2;
		ll ans2 = 0;
		//find # of pairs x, y with max(p[x],p[y])<=d
		L1 = ans[i*4+2];
		L2 = ans[i*4+3];
		////cerr<<L1<<' '<<L2<<'\n';
		ans2 += L1*((d - L1));
		//count for x<=r,y>r
		ans2 += L2*((d - L2));
		ans2 -= L1*(d-L2);
		//cerr<<"ANS 2 : "<<ans2<<'\n';
		//count for l<=x<y<=r
		ll good = L2 - L1;
		ans2 += (good*(good-1))/2;
		cout<<ans1-ans2<<'\n';
	}
}