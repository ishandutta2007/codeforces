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

class LazySegmentTree {
private:
	int size_;
	vector<long long> v, lazy;
	void update(int a, int b, long long x, int k, int l, int r) {
		push(k, l, r);
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) {
			lazy[k] = x;
			push(k, l, r);
		}
		else {
			update(a, b, x, k * 2, l, (l + r) >> 1);
			update(a, b, x, k * 2 + 1, (l + r) >> 1, r);
			v[k] = merge(v[k * 2], v[k * 2 + 1]);
		}
	}
	long long query(int a, int b, int k, int l, int r) {
		push(k, l, r);
		if (r <= a || b <= l) return ll(2e18);
		if (a <= l && r <= b) return v[k];
		long long lc = query(a, b, k * 2, l, (l + r) >> 1);
		long long rc = query(a, b, k * 2 + 1, (l + r) >> 1, r);
		return merge(lc, rc);
	}
 
public:
	LazySegmentTree() : v(vector<long long>()), lazy(vector<long long>()) {};
	LazySegmentTree(int n) {
		for (size_ = 1; size_ < n;) size_ <<= 1;
		v.assign(size_ * 2,ll(2e18));
		lazy.resize(size_ * 2);
	}
	inline void push(int k, int l, int r) {
		if (lazy[k] != 0) {
			v[k] += lazy[k];
			if (r - l > 1) {
				lazy[k * 2] += lazy[k];
				lazy[k * 2 + 1] += lazy[k];
			}
			lazy[k] = 0;
		}
	}
	inline long long merge(long long x, long long y) {
		return min(x,y);
	}
	inline void update(int l, int r, long long x) {
		update(l, r, x, 1, 0, size_);
	}
	inline long long query(int l, int r) {
		return query(l, r, 1, 0, size_);
	}
};

ll a[211111];
ll b[211111];

vector<ii> adj[211111];
ll coeff[211111];
multiset<ll> ans;

ll getmx()
{
	auto it = ans.end();
	it--; return (*it);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,q; cin>>n>>m>>q;
	LazySegmentTree stb(n+1);
	for(int i = 0; i < n - 1; i++)
	{
		cin>>a[i]>>b[i];
	}
	b[n-1]=a[n-1]=0;
	for(int i = 0; i < m; i++)
	{
		int u,v; ll c;
		cin>>u>>v>>c;
		u--; v--;
		adj[u].pb(mp(v,c));
	}
	stb.update(0,1,-ll(2e18));
	for(int i = 0; i < n - 1; i++)
	{
		stb.update(i+1,i+2,b[i]-ll(2e18));
		//cerr<<i<<' '<<stb.query(i,i+1)<<'\n';
	}
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j < adj[i].size(); j++)
		{
			int v=adj[i][j].fi; ll w = adj[i][j].se;
			stb.update(0,v+1,w);
		}
		coeff[i] = stb.query(0,n);
	}
	for(int i=0;i<n;i++)
	{
		//cerr<<i<<' '<<a[i]<<' '<<coeff[i]<<'\n';
		ans.insert(a[i]+coeff[i]);
	}
	cout<<(*ans.begin())<<'\n';
	for(int i=0;i<q;i++)
	{
		int pos; ll v; cin>>pos>>v; pos--;
		auto it = ans.find(a[pos]+coeff[pos]);
		ans.erase(it);
		ans.insert(v+coeff[pos]);
		cout<<(*ans.begin())<<'\n';
		a[pos]=v;
	}
}