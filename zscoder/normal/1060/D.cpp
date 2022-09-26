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
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

multiset<ii> A,B;

void del(ll x, ll y)
{
	auto it = A.lower_bound(mp(x,y)); 
	A.erase(it);
	it = B.lower_bound(mp(y,x));
	B.erase(it);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vector<ii> vec;
	for(int i=0;i<n;i++)
	{
		ll x,y; cin>>x>>y;
		vec.pb(mp(x,0)); vec.pb(mp(y,1));
		A.insert({x,y}); B.insert({y,x});
	}
	ll ans=0;
	/*
	ll L, R; L=R=-1;
	while(!A.empty())
	{
		auto 
	}
	*/
	sort(vec.rbegin(),vec.rend());
	int cnt[2]={0,0};
	for(ii x:vec)
	{
		ll v=x.fi; int ty=x.se;
		if(cnt[ty^1]>0)
		{
			cnt[ty^1]--;
			continue;
		}
		cnt[ty]++; ans+=v;
	}
	ans+=n;
	cout<<ans<<'\n';
}