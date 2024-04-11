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
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
			tmp.p = i; tmp.sum = i;
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
			tmp.p = i; tmp.sum = i;
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
		dsu[u].sum = max(dsu[u].sum,dsu[v].sum);
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

void solve()
{
	int n; cin>>n;
	vi a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ll ans=0;
	DSU dsu(n);
	for(int i=0;i<n;i++)
	{
		if(a[i]==1)
		{
			if(i>0&&a[i-1]==1) dsu.merge(i-1,i);
			if(i+1<n&&a[i+1]==1) dsu.merge(i,i+1);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]>n)
		{
			ans+=a[i]-n;
			a[i]=n;
		}
		while(a[i]>1)
		{
			int cur=i;
			while(cur<n)
			{
				int c = cur;
				cur+=a[c];
				if(a[c]==2)
				{
					if(c-1>0&&a[c-1]==1) dsu.merge(c-1,c);
					if(c+1<n&&a[c+1]==1) dsu.merge(c,c+1);
				}
				a[c]=max(a[c]-1,1);	
				if(cur<n)
				{
					cur=dsu.getstat(cur);
				}
			}
			ans++;
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