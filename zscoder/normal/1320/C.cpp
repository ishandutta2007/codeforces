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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<ii> monster[222222];

class LazySegmentTree {
private:
	int size_;
	vector<int> v, lazy;
	void update(int a, int b, int x, int k, int l, int r) {
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
	int query(int a, int b, int k, int l, int r) {
		push(k, l, r);
		if (r <= a || b <= l) return -int(1e9);
		if (a <= l && r <= b) return v[k];
		int lc = query(a, b, k * 2, l, (l + r) >> 1);
		int rc = query(a, b, k * 2 + 1, (l + r) >> 1, r);
		return merge(lc, rc);
	}
 
public:
	LazySegmentTree() : v(vector<int>()), lazy(vector<int>()) {};
	LazySegmentTree(int n) {
		for (size_ = 1; size_ < n;) size_ <<= 1;
		v.resize(size_ * 2);
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
	inline int merge(long long x, long long y) {
		return max(x,y);
	}
	inline void update(int l, int r, long long x) {
		update(l, r, x, 1, 0, size_);
	}
	inline int query(int l, int r) {
		return query(l, r, 1, 0, size_);
	}
};
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,p; cin>>n>>m>>p;
	vector<ii> a;
	for(int i=0;i<n;i++)
	{
		int x,c; cin>>x>>c;
		a.pb({x,c});
	}
	sort(a.begin(),a.end());
	vector<ii> newa;
	for(int i=0;i<n;i++)
	{
		if(i==0||a[i].fi>a[i-1].fi) newa.pb(a[i]);
	}
	a=newa; n=a.size();
	vector<ii> b;
	for(int i=0;i<m;i++)
	{
		int x,c; cin>>x>>c;
		b.pb({x,c});
	}
	vector<ii> newb;
	sort(b.begin(),b.end());
	for(int i=0;i<m;i++)
	{
		if(i==0||b[i].fi>b[i-1].fi) newb.pb(b[i]);
	}
	b=newb; m=b.size();
	for(int i=0;i<p;i++)
	{
		int x,y,z; cin>>x>>y>>z;
		x = lower_bound(a.begin(),a.end(),mp(x+1,-1))-a.begin(); //only the x-th weapon can attack it
		y = lower_bound(b.begin(),b.end(),mp(y+1,-1))-b.begin();
		monster[x].pb({y,z});
	}
	int ans = -int(2e9);
	LazySegmentTree st(m);
	for(int i=0;i<m;i++)
	{
		st.update(i,i+1,-b[i].se);
	}
	for(int i=0;i<n;i++)
	{
		//use the i-th attack
		for(auto X:monster[i])
		{
			//cerr<<i<<' '<<X.fi<<' '<<X.se<<'\n';
			st.update(X.fi,m,X.se);
		}
		ans=max(ans,st.query(0,m)-a[i].se);
	}
	cout<<ans<<'\n';
}