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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int cc=0;

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
			tmp.p = i; tmp.sum = 0;
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
			tmp.p = i; tmp.sum = 0;
			dsu.pb(tmp);
		}
	}
	
	void activate(int u)
	{
		dsu[u].sum = 1; cc++;
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
		cc--;
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

ll a[222222];
bool act[222222];
int n,q;
DSU dsu(1);
void activate(int u)
{
	act[u]=1;
	dsu.activate(u);
	if(u-1>=0&&act[u-1]) dsu.merge(u-1,u);
	if(u+1<n&&act[u+1]) dsu.merge(u,u+1);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);	
	ll L;
	cin>>n>>q>>L;
	dsu.reset(n);
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
		if(a[i]>L) {activate(i);}
	}
	for(int z=0;z<q;z++)
	{
		int t; cin>>t;
		if(t==0) cout<<cc<<'\n';
		else
		{
			int u,v; cin>>u>>v; u--;
			a[u]+=v;
			if(!act[u]&&a[u]>L)
			{
				act[u]=1;
				activate(u);
			}
		}
	}
}