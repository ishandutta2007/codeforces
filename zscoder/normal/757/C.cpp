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

const int MOD = 1e9 + 7;
ll fact[1000001];

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

ii hsh[1000001];

ll ha(ii x)
{
	return (x.fi*(MOD+10)+x.se);
}

map<ll,vi> ma;

const int base = 1000003;
const int MOD2 = 1e9 + 9;
int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	fact[0]=1;
	for(int i = 1; i <= 1000000; i++) fact[i]=(fact[i-1]*i)%MOD;
	int n, m; scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++)
	{
		int x; scanf("%d", &x);
		for(int j = 0; j < x; j++)
		{
			int y; scanf("%d",&y);
			y--;
			hsh[y].fi=(hsh[y].fi*base)%MOD;
			hsh[y].se=(hsh[y].se*base)%MOD2;
			hsh[y].fi+=ll(i+1);
			hsh[y].se+=ll(i+1);
		}
	}
	for(int i = 0; i < m; i++)
	{
		//cerr<<i<<' '<<hsh[i]<<'\n';
		ma[ha(hsh[i])].pb(i);
	}
	DSU dsu(m);
	for(map<ll,vi>::iterator it = ma.begin(); it != ma.end(); it++)
	{
		//cerr<<it->fi<<' '<<it->se.size()<<'\n';
		for(int i = 0; i + 1 < it->se.size(); i++)
		{
			//cerr<<it->se[i]<<' '<<it->se[i+1]<<'\n';
			dsu.merge(it->se[i],it->se[i+1]);
		}
	}
	//cerr<<"END\n";
	
	ll ans = 1;
	for(int i = 0; i < m; i++)
	{
		if(dsu.rt(i)==i)
		{
			ans=(ans*fact[dsu.getstat(i)])%MOD;
		}
	}
	cout<<ans;
}