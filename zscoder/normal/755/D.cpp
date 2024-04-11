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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

ll ans[1000001];
vector<ii> edges;
pbds t;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, k; cin>>n>>k;
	k=min(k,n-k);
	//O(n^2)
	ans[0]=2;
	edges.pb(mp(0,k));
	t.insert(0);
	for(ll i = 1; i < n; i++)
	{
		int u = (k*i)%n; int v = (k*(i+1))%n;
		/*
		ans[i]=1;
		for(int j = 0; j < edges.size(); j++)
		{
			int l = edges[j].fi; int r = edges[j].se;
			if(l==u||l==v||r==u||r==v) continue;
			bool x = 0;
			if(l<u&&u<r) x^=1;
			if(l<v&&v<r) x^=1;
			if(x) ans[i]++;
		}
		ans[i]+=ans[i-1];	
		edges.pb(mp(min(u,v),max(u,v)));
		*/
		if(v<u) v+=n;
		ans[i]++;
		//cerr<<i<<' '<<u+1-k<<' '<<v-1<<' '<<u-n+1-k<<' '<<v-n<<'\n';
		ans[i] += t.order_of_key(v)-t.order_of_key(u+1-k);
		ans[i] += t.order_of_key(v-n) - t.order_of_key(u-n+1-k);
		ans[i] += t.order_of_key(v+n) - t.order_of_key(u+n+1-k);
		ans[i]+=ans[i-1];
		t.insert(u);
	}
	for(int i = 0; i < n; i++)
	{
		cout<<ans[i]<<' ';
	}
}