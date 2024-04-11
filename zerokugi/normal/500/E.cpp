#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <deque>
#include <complex>
#include <string>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <valarray>
#include <unordered_map>
#include <iterator>
#include <functional>
#include <cassert>
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T> pair<S,T> operator+(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first+t.first, s.second+t.second);}
template<class S, class T> pair<S,T> operator-(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first-t.first, s.second-t.second);}

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;

struct handler_max{
	typedef int val_t;
	typedef int opr_t;
	handler_max(){}
	val_t def_val(){ return 0; }
	static val_t update(const val_t &l, const val_t &r){
		return max(l, r);
	}
	static val_t merge(const val_t &l, const val_t &r){
		return max(l, r);
	}
};

struct handler_sum{
	typedef int val_t;
	typedef int opr_t;
	handler_sum(){}
	val_t def_val(){ return 0; }
	static val_t update(const val_t &l, const val_t &r){
		return l + r;
	}
	static val_t merge(const val_t &l, const val_t &r){
		return l + r;
	}
};

template<typename Handler>
struct SegTree{
	typedef typename Handler::val_t val_t;
	vector<val_t> val;
	Handler hdl;
	int n;
	
	SegTree(int size):hdl(){
		n=1;
		while(n<size) n<<=1;
		val=vector<val_t>(2*n, hdl.def_val());
	}
	SegTree(const vector<val_t> &in):hdl(){
		n=1;
		while(n<in.size()) n<<=1;
		val=vector<val_t>(2*n, hdl.def_val());
		for(int i=n-1 + in.size()-1;i>=0;i--){
			if(n-1 <= i) val[i] = in[i - (n-1)];
			else val[i] = hdl.merge(val[i*2+1],val[i*2+2]);
		}
	}
	void update(int i, val_t a, function<val_t(const val_t&, const val_t&)> update = Handler::update){
		i += n-1;
		val[i] = update(val[i], a);
		while(i > 0){
			i = (i-1)/2;
			val[i] = hdl.merge(val[i*2+1],val[i*2+2]);
		}
	}
	val_t query(int a,int b,int k,int l,int r){
		if(r<=a||b<=l) return hdl.def_val();
		if(a<=l&&r<=b) return val[k];
		return hdl.merge(query(a, b, k*2+1, l, (l+r)/2),
					   query(a, b, k*2+2, (l+r)/2, r)
					  );
	}
	val_t query(int a, int b){return query(a, b, 0, 0, n);}
	val_t operator[](size_t i){return query(i, i+1);}
	friend ostream& operator<<(ostream &os, SegTree<Handler> &t){
		REP(i, t.n) os << (i ? ", " : "[") << t.query(i, i+1);
		return os << "]";
	}
};

template<typename Handler>
struct SegTreeDynamic{
	typedef typename Handler::val_t val_t;
	typedef typename Handler::opr_t opr_t;
	struct Node{
		int lch, rch;
		val_t val;
		Node(val_t val):val(val){lch = rch = 0;}
	};
	vector<Node> node;
	Handler hdl;
	ll n;
	
	SegTreeDynamic(ll size):hdl(){
		n = size;
		node.resize(2, hdl.def_val());	// dummy & root
	}
	int update(ll i, opr_t x, int k,ll l,ll r, const int &pers){
		if(r<=i||i<l) return k;
		if(pers || !k){
			node.pb(node[k]);
			k = node.size()-1;
		}
		if(r-l == 1){
			node[k].val = hdl.update(node[k].val, x);
			return k;
		}
		int lch = update(i, x, node[k].lch, l, (l+r)/2, pers);
		int rch = update(i, x, node[k].rch, (l+r)/2, r, pers);
		node[k].val = hdl.merge(node[node[k].lch=lch].val, node[node[k].rch=rch].val);
		return k;
	}
	val_t query(ll a,ll b,int k,ll l,ll r){
		if(r<=a||b<=l||!k) return hdl.def_val();
		if(a<=l&&r<=b) return node[k].val;
		return hdl.merge(query(a, b, node[k].lch, l, (l+r)/2),
					     query(a, b, node[k].rch, (l+r)/2, r));
	}
	int update(ll i, opr_t x, int root=1){return update(i, x, root, 0, n, 0);}
	int update_persistent(ll i, opr_t x, int root=1){return update(i, x, root, 0, n, 1);}
	val_t query(ll a, ll b, int root=1){return query(a, b, root, 0, n);}
};

int n, m;
ll p[200001], l[200001];

int main(int argc, char *argv[]){
	ios::sync_with_stdio(false);
	cin >> n;
	vi p(n+1, 2000000005), l(n+1, 0), root(n+1, 1);
	SegTree<handler_max> reach(n+1);
	SegTreeDynamic<handler_sum> cost(n+1);
	REP(i, n) cin >> p[i] >> l[i];
	vector<vector<pii>> query(n);
	cin >> m;
	vi ans(m);
	REP(i, m){
		int l, r;
		cin >> l >> r;
		query[l-1].emplace_back(r, i);
	}
	RREP(i, n){
		int right = upper_bound(ALL(p), p[i]+l[i]) - p.begin();
		right = max(p[i]+l[i], reach.query(0, right));
		reach.update(i, right);
		int next = upper_bound(ALL(p), right) - p.begin();
//		printf("right[%d] = %d, %d\n", i, right, p[next] - right);
		root[i] = cost.update_persistent(next, p[next] - right, root[next]);
		FOR(q, query[i]){
			int l = i, r = q->first;
			ans[q->second] = cost.query(0, r, root[i]);
		}
	}
	REP(i, m) printf("%d\n", ans[i]);
	return 0;
}