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
typedef vector<int> vi;
typedef long double ld; 
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
		if (r <= a || b <= l) return 0;
		if (a <= l && r <= b) return v[k];
		long long lc = query(a, b, k * 2, l, (l + r) >> 1);
		long long rc = query(a, b, k * 2 + 1, (l + r) >> 1, r);
		return merge(lc, rc);
	}
 
public:
	LazySegmentTree() : v(vector<long long>()), lazy(vector<long long>()) {};
	LazySegmentTree(int n) {
		for (size_ = 1; size_ < n;) size_ <<= 1;
		v.resize(size_ * 2);
		lazy.assign(size_ * 2,-1);
	}
	inline void push(int k, int l, int r) {
		if (lazy[k] != -1) {
			v[k] = lazy[k] * (r - l);
			if (r - l > 1) {
				lazy[k * 2] = lazy[k];
				lazy[k * 2 + 1] = lazy[k];
			}
			lazy[k] = -1;
		}
	}
	inline long long merge(long long x, long long y) {
		return x + y;
	}
	inline void update(int l, int r, long long x) {
		update(l, r, x, 1, 0, size_);
	}
	inline long long query(int l, int r) {
		return query(l, r, 1, 0, size_);
	}
};

void solve()
{
	int n,q; cin>>n>>q;
	string s,t; cin>>s>>t;
	vector<ii> vec;
	for(int i=0;i<q;i++)
	{
		int l,r; cin>>l>>r; l--; r--;
		vec.pb({l,r});
	}
	LazySegmentTree st(n+2);
	reverse(vec.begin(),vec.end());
	for(int i=0;i<n;i++)
	{
		st.update(i,i+1,t[i]-'0');
	}
	/*
	for(int i=0;i<n;i++)
	{
		cout<<st.query(i,i+1);
	}
	cout<<'\n';
	*/
	for(ii x:vec)
	{
		int l=x.fi; int r=x.se;
		int sum = st.query(l,r+1);
		int len=(r-l+1);
		int change1 = sum;
		int change0 = len-sum;
		//cerr<<change0<<' '<<change1<<' '<<len<<'\n';
		if(change0*2<len)
		{
			//change
			st.update(l,r+1,1); 
		}
		else if(change1*2<len)
		{
			st.update(l,r+1,0);
		}
		else
		{
			cout<<"NO\n"; return ;
		}
	}
	bool pos=1;
	for(int i=0;i<n;i++)
	{
		if(s[i]-'0'!=st.query(i,i+1)) 
		{
			pos=0; break;
		}
	}
	if(pos) cout<<"YES\n";
	else cout<<"NO\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}