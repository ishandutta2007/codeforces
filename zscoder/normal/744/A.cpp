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

struct DSU
{
	int S;
	
	struct node
	{
		int p; ll sum;
	};
	vector<node> dsu;
	
	DSU(int n)
	{
		S = n;
		for(int i = 0; i < n; i++)
		{
			node tmp;
			tmp.p = i; tmp.sum = 1;
			dsu.pb(tmp);
		}
	}
	
	void reset(int n)
	{
		dsu.clear();
		S = n;
		for(int i = 0; i < n; i++)
		{
			node tmp;
			tmp.p = i; tmp.sum = 1;
			dsu.pb(tmp);
		}
	}
	
	int rt(int u)
	{
		if(dsu[u].p == u) return u;
		dsu[u].p = rt(dsu[u].p);
		return dsu[u].p;
	}
	
	void merge(int u, int v)
	{
		u = rt(u); v = rt(v);
		if(u == v) return ;
		if(rand()&1) swap(u, v);
		dsu[v].p = u;
		dsu[u].sum += dsu[v].sum;
	}
	
	bool sameset(int u, int v)
	{
		if(rt(u) == rt(v)) return true;
		return false;
	}
	
	ll getstat(int u)
	{
		return dsu[rt(u)].sum;
	}
};

DSU dsu(1);

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	dsu.reset(n);
	vi vec;
	for(int i = 0; i < k; i++)
	{
		int x; cin>>x; x--;
		vec.pb(x);
	}
	for(int i = 0; i < m; i++)
	{
		int u,v; cin>>u>>v;
		u--; v--;
		dsu.merge(u,v);
	}
	vector<ll> sd;
	for(int i = 0; i < k; i++)
	{
		sd.pb(dsu.getstat(vec[i]));
	}
	sort(sd.begin(),sd.end());
	int sum = n;
	for(int i = 0; i < k; i++)
	{
		sum-=sd[i];
	}
	sd[k-1]+=sum;
	ll ans = 0;
	for(int i =0; i < k; i++)
	{
		ans+=(ll(sd[i])*ll(sd[i]-1))/2;
	}
	ans-=m;
	cout<<ans;
}