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
#include <iterator>
#include <assert.h>
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
#define UNIQUE(v) sort(ALL(v)); v.erase( unique(v.begin(), v.end()), v.end() );

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

struct handler{
	typedef int val_t;
	typedef int opr_t;
	handler(){}
	val_t def_val(){ return 0; }
	static val_t update(const val_t &l, const opr_t &r){
		return max(l, r);
	}
	static val_t merge(const val_t &l, const val_t &r){
		return max(l, r)	;
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

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d", &n);
	SegTreeDynamic<handler> seg(1ll<<31);
	vi d(n);
	vector<pii> p;
	REP(i, n){
		int x, y;
		scanf("%d%d", &x, &y);
		p.eb(x, y);
	}
	sort(ALL(p));
	int ans = 0;
	REP(i, n){
		int x = p[i].first ,w = p[i].second;
		int t = seg.query(0, x-w+1);
		seg.update(x+w, t+1);
		ans = max(ans, t+1);
	}
	cout << ans << endl;
	return 0;
}