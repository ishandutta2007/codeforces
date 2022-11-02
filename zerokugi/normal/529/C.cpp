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
	handler(){}
	val_t def_val(){ return INF; }
	static val_t update(const val_t &l, const val_t &r){
		return r;
	}
	static val_t merge(const val_t &l, const val_t &r){
		if(l == INF) return r;
		if(r == INF) return l;
		return min(l, r);
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
	void update(int i, val_t a){
		i += n-1;
		val[i] = hdl.update(val[i], a);
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

int n, m, k, q;
int ans[200005];
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d%d%d", &m, &n, &k, &q);
	vector<tuple<int, int, int, int, int>> query(q);
	vector<pii> rooks(k);
	REP(i, k){
		int x, y;
		scanf("%d%d", &x, &y);
		rooks[i] = mp(y, x);
	}
	REP(i, q){
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		query[i] = tie(y2, y1, x2, x1, i);
	}
	REP(j, 2){
		sort(ALL(query));
		sort(ALL(rooks));
		vi d(m+2, -1);
		SegTree<handler> seg(d);
		int ri = 0, qi = 0;
		REPS(i, n){
			while(ri < k && rooks[ri].first == i){
				seg.update(rooks[ri].second, i);
				ri ++;
			}
			while(qi < q && get<0>(query[qi]) == i){
				int x1, y1, x2, y2, idx;
				tie(y2, y1, x2, x1, idx) = query[qi];
				if(seg.query(x1, x2+1) >= y1) ans[idx] = 1;
				qi ++;
			}
		}
		if(j) break;
		REP(i, k) swap(rooks[i].first, rooks[i].second);
		REP(i, q) swap(get<0>(query[i]), get<2>(query[i]));
		REP(i, q) swap(get<1>(query[i]), get<3>(query[i]));
		swap(n, m);
	}
	REP(i, q) puts(ans[i] ? "YES" : "NO");
	return 0;
}