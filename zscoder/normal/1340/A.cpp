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

multiset<ll> SS;

void er(ll x)
{
	auto it = SS.find(x);
	assert(it!=SS.end());
	SS.erase(it);
}

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
	
	bool sameset(int u, int v)
	{
		if(rt(u) == rt(v)) return true;
		return false;
	}
	
	void merge(int u, int v)
	{
		u = rt(u); v = rt(v);
		if(u == v) return ;
		if(rand()&1) swap(u, v);
		if(!sameset(S-1,u)) er(dsu[u].sum); 
		if(!sameset(S-1,v)) er(dsu[v].sum);
		dsu[v].p = u;		
		dsu[u].sum += dsu[v].sum;
		if(!sameset(S-1,u)) SS.insert(dsu[u].sum);
	}
	
	ll getstat(int u)
	{
		return dsu[rt(u)].sum;
	}
};

void solve()
{
	int n; cin>>n;
	vi p(n);
	SS.clear();
	vi pos(n);
	for(int i=0;i<n;i++)
	{
		cin>>p[i]; p[i]--;
		pos[p[i]]=i;
	}
	vi visited(n,0);
	DSU dsu(n);
	for(int i=0;i<n;i++)
	{
		int ps = pos[i];
		int lastcnt = 0;
		if(ps-1>=0&&visited[ps-1]&&!dsu.sameset(ps-1,n-1))
		{
			lastcnt=dsu.getstat(ps-1);
		}
		ll mx = 0;
		if(!SS.empty()) mx=(*prev(SS.end()));
		if(lastcnt==mx)
		{
			if(ps!=n-1) SS.insert(1);
			visited[ps]=1;
			if(ps-1>=0&&visited[ps-1]) dsu.merge(ps-1,ps);
			if(ps+1<n&&visited[ps+1]) dsu.merge(ps+1,ps);
		}
		else
		{
			cout<<"No\n"; return ;
		}
	}
	cout<<"Yes\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}