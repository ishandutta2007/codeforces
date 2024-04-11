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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

ll getS(ll k, vector<int> &v, bool mode=0) //k additional
{
	ll n=v.size();
	ll tp = (k+n) - ((k+n)/4);
	ll spared = k+n-tp;
	if(mode) //player 1, add 100s
	{
		//add that many ks
		if(spared>=v.size()) return 100*1LL*tp;
		//spared<v.size();
		ll ans = 100*1LL*tp;
		for(int i=0;i<int(v.size())-spared;i++)
		{
			ans-=100;
			ans+=v[i];
		}
		return ans;
	}
	else
	{
		ll ans=0;
		//top tp ones
		for(int i=0;i<min(n,tp);i++)
		{
			ans+=v[i];
		}
		return ans;
	}
}

void solve()
{
	int n; cin>>n;
	vi a(n);
	vi b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	sort(a.rbegin(),a.rend());
	sort(b.rbegin(),b.rend());
	ll lo=0; ll hi=ll(1e12);
	ll ans=0;
	while(lo<=hi)
	{
		ll mid=(lo+hi)>>1;
		ll p1score = getS(mid,a,1);
		ll p2score = getS(mid,b,0);
		if(p1score>=p2score)
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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}