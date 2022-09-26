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

void solve()
{
	int n; cin>>n;
	vi a(n);
	int cnt[2]={0,0};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]%=2;
		cnt[a[i]]++;
	}
	if(abs(cnt[0]-cnt[1])>1){cout<<-1<<'\n'; return ;}
	ll ans=ll(1e18);
	for(int z=0;z<2;z++)
	{
		vi v;
		int c[2]={0,0};
		for(int i=0;i<n;i++)
		{
			v.pb(z^(i&1));
			c[v[i]]++;
		}
		if(c[0]!=cnt[0])
		{
			continue;
		}
		ll cur[2] = {0,1};
		if(z==1)
		{
			cur[0]=1; cur[1]=0;
		}
		ll res=0;
		for(int i=0;i<n;i++)
		{
			res+=abs(cur[a[i]]-i);
			cur[a[i]]+=2;
		}
		assert(res%2==0);
		ans=min(ans,res/2);
	}
	cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}