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
	opr_t def_lazy(){ return -1; }
	static val_t resolve(const val_t &x, const opr_t &y, int l, int r){
		if(y == -1) return x;
		return y*(r - l);
	}
	static opr_t push(const opr_t &x, const opr_t &y){
		if(y == -1) return x;
		return y;
	}
	static val_t merge(const val_t &x, const val_t &y){
		return x + y;
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
		if(r<=a||b<=l) return hdl.resolve(val[k], lazy[k], l, r);
		if(a<=l&&r<=b){
			lazy[k] = hdl.push(lazy[k], x);
			return hdl.resolve(val[k], lazy[k], l, r);
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
		val[k] = hdl.resolve(val[k], lazy[k], l, r);
		lazy[k*2+1] = hdl.push(lazy[k*2+1], lazy[k]);
		lazy[k*2+2] = hdl.push(lazy[k*2+2], lazy[k]);
		lazy[k] = hdl.def_lazy();
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

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d", &n, &m);
	vector<SegTreeLazy<handler>> seg(26, SegTreeLazy<handler>(n));
	REP(i, n){
		char c;
		scanf(" %c", &c);
		seg[c - 'a'].update(i, i+1, 1);
	}
	REP(i, m){
		int l, r, t;
		scanf("%d%d%d", &l, &r, &t); l--;
		int p = l;
		REP(jj, 26){
			int j = t ? jj : 25 - jj;
			int c = seg[j].query(l, r);
			seg[j].update(l, r, 0);
			seg[j].update(p, p+c, 1);
			p += c;
		}
	}
	string ans(n, ' ');
	REP(i, n)REP(j, 26) if(seg[j].query(i, i+1)){
		ans[i] = 'a' + j; break;
	}
	cout << ans << endl;
	return 0;
}