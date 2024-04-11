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

struct handler{
	typedef vi val_t;
	typedef int opr_t;
	vi def;
	handler():def(20){}
	val_t def_val(){ return def; }
	opr_t def_lazy(){ return 0; }
	static val_t resolve(const val_t &x, const opr_t &y, int l, int r){
		if(!y) return x;
		vi res = x;
		REP(i, 20) if(1&(y>>i)) res[i] = r-l-res[i];
		return res;
	}
	static opr_t push(const opr_t &x, const opr_t &y){
		return x ^ y;
	}
	static val_t merge(const val_t &x, const val_t &y){
		vi res = x;
		REP(i, 20) res[i] += y[i];
		return res;
	}
};

template<typename Handler>
struct SegTreeLazy{
	typedef typename Handler::val_t val_t;
	typedef typename Handler::opr_t opr_t;
	vector<val_t> val;
	vector<opr_t> lazy;
	Handler hdl;
	int n;
	
	SegTreeLazy(int size):hdl(){
		n=1;
		while(n<size) n<<=1;
		val=vector<val_t>(2*n, hdl.def_val());
		lazy=vector<opr_t>(2*n, hdl.def_lazy());
	}
	
	SegTreeLazy(const vector<val_t> &in):hdl(){
		n=1;
		while(n<in.size()) n<<=1;
		val=vector<val_t>(2*n, hdl.def_val());
		lazy=vector<opr_t>(2*n, hdl.def_lazy());
		for(int i=n-1 + in.size()-1;i>=0;i--){
			if(n-1 <= i) val[i] = in[i - (n-1)];
			else val[i] = hdl.merge(val[i*2+1],val[i*2+2]);
		}
	}
	val_t update(int a,int b,opr_t x, int k,int l,int r){
		if(r<=a||b<=l) return lazy[k] ? hdl.resolve(val[k], lazy[k], l, r) : val[k];
		if(a<=l&&r<=b){
			lazy[k] = hdl.push(lazy[k], x);
			return lazy[k] ? hdl.resolve(val[k], lazy[k], l, r) : val[k];
		}
		lazy[k*2+1] = hdl.push(lazy[k*2+1], lazy[k]);
		lazy[k*2+2] = hdl.push(lazy[k*2+2], lazy[k]);
		lazy[k] = hdl.def_lazy();
		return val[k] = hdl.merge(update(a, b, x, k*2+1, l, (l+r)/2),
								  update(a, b, x, k*2+2, (l+r)/2, r));
	}
	val_t query(int a,int b,int k,int l,int r){
		if(r<=a||b<=l) return hdl.def_val();
		if(a<=l&&r<=b) return hdl.resolve(val[k], lazy[k], l, r);
		if(lazy[k]){
			val[k] = hdl.resolve(val[k], lazy[k], l, r);
			lazy[k*2+1] = hdl.push(lazy[k*2+1], lazy[k]);
			lazy[k*2+2] = hdl.push(lazy[k*2+2], lazy[k]);
			lazy[k] = hdl.def_lazy();
		}
		return hdl.merge(query(a, b, k*2+1, l, (l+r)/2),
						 query(a, b, k*2+2, (l+r)/2, r));
	}
	val_t update(int a, int b, opr_t x){return update(a, b, x, 0, 0, n);}
	val_t query(int a, int b){return query(a, b, 0, 0, n);}
	val_t operator[](size_t i){return query(i, i+1);}
	friend ostream& operator<<(ostream &os, SegTreeLazy<Handler> &t){
		REP(i, t.n) os << (i ? ", " : "[") << t.query(i, i+1);
		return os << "]";
	}
};

int n, m;

int main(int argc, char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n){
		vector<vi> d(n, vi(20));
		REP(i, n){
			int x;
			cin >> x;
			REP(j, 20) d[i][j] = 1&(x>>j);
		}
		SegTreeLazy<handler> seg(d);
		cin >> m;
		REP(i, m){
			int t, l, r, x;
			cin >> t >> l >> r; l--;
			if(t == 1){
				vi res = seg.query(l, r);
				ll ans = 0;
				REP(j, 20) ans += res[j]*(1ll<<j);
				cout << ans << endl;
			}else{
				cin >> x;
				seg.update(l, r, x);
			}
		}
	}
	return 0;
}