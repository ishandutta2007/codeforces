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

struct HLDecomp{
	struct NodeInfo{
		int idx, pos, cnt, par, heavy, depth, upar;
	};
	int n;
	vector<NodeInfo> V;
	vector<vi> e;
	HLDecomp(const vector<vi> &g, int root = 0):n(g.size()), V(n){
		stack<int> st;
		st.push(root);
		V[root].depth = 0;
		V[root].par = -1;
		while(!st.empty()){
			int v = st.top(); st.pop();
			if(v<0){
				v = ~v;
				if(v != root) V[V[v].par].cnt += V[v].cnt;
				V[v].heavy = -1;
				int mc = 0;
				FOR(u, g[v])if(*u!=V[v].par && chmax(mc, V[*u].cnt)) V[v].heavy = *u;
			}else{
				V[v].cnt = 1;
				st.push(~v);
				FOR(u, g[v])if(*u!=V[v].par){
					V[*u].upar = V[*u].par = v;
					V[*u].depth = V[v].depth+1;
					st.push(*u);
				}
			}
		}
		st.push(root);
		while(!st.empty()){
			vi d;
			int v = st.top();st.pop();
			int p = V[v].par;
			for(;v>=0;v=V[v].heavy){
				FOR(u, g[v])if(*u!=V[v].par && *u!=V[v].heavy) st.push(*u);
				V[v].idx = e.size();
				V[v].pos = d.size();
				V[v].par = p;
				d.pb(v);
			}
			e.pb(d);
		}
//		cout << e << endl;
	}
	size_t size(){return e.size();}
	const vi &operator[](int i) const{return e[i];}
	pii getPos(int v){return pii(V[v].idx, V[v].pos);}
	struct Path{
		int idx, s, t;
		Path(int idx, int s, int t):idx(idx), s(s), t(t){}
	};
	vector<tuple<int, int, int>> path(int u, int v, int onlyEdge=0){
		vector<tuple<int, int, int>> res, rev;
		while(V[u].idx!=V[v].idx){
			int pu = V[u].par;
			int pv = V[v].par;
			if((pu==-1 ? -1 : V[pu].depth) > (pv == -1 ? -1 : V[pv].depth)){
				res.eb(V[u].idx, V[u].pos, 0);
				u = V[u].par;
			}else{
				rev.eb(V[v].idx  ,0 ,V[v].pos);
				v = V[v].par;
			}
		}
		int c = abs(V[u].pos - V[v].pos);
		if(!onlyEdge) res.eb(V[u].idx, V[u].pos, V[v].pos);
		else if(V[u].depth > V[v].depth) res.eb(V[u].idx, V[u].pos, V[v].pos + (V[v].pos < V[u].pos ? 1 : -1));
		else if(V[u].depth < V[v].depth) res.eb(V[u].idx, V[u].pos + (V[u].pos < V[v].pos ? 1 : -1), V[v].pos);
		res.insert(res.end(), RALL(rev));
		return res;
	}
	int lca(int u, int v){
		while(V[u].idx!=V[v].idx){
			int pu = V[u].par;
			int pv = V[v].par;
			if((pu==-1 ? -1 : V[pu].depth) > (pv == -1 ? -1 : V[pv].depth)){
				u = V[u].par;
			}else{
				v = V[v].par;
			}
		}
		return (V[u].depth > V[v].depth) ? v : u;
	}
	int getDepth(int v){
		return V[v].depth;
	}
	int par(int v){
		return V[v].upar;
	}
};
template<class H, class S>
struct SegTreeOnHLDecomp{
	typedef typename H::val_t val_t;
	typedef typename H::opr_t opr_t;
	vector<S> seg;
	HLDecomp hld;
	SegTreeOnHLDecomp(const vector<vi> &g, const vector<val_t> &val, int root=0)
		:hld(g, root){
		REP(i, hld.size()){
			vector<val_t> d;
			const vi& nodes = hld[i];
			FOR(v, nodes) d.pb(val[*v]);
			seg.eb(d);
			reverse(ALL(d));
			seg.eb(d);
		}
	}
	void update(int u, int v, const opr_t &x){
		auto paths = hld.path(u, v);
		FOR(p, paths){
			int i, s, t;tie(i, s, t) = *p;
			if(s > t) swap(s, t);
			seg[2*i].update(s, t+1, x);
			seg[2*i+1].update(hld[i].size() - t - 1, hld[i].size() - s, x);
		}
	}
	val_t query(int u, int v){
		auto res = H::def_val();
		auto paths = hld.path(u, v);
		FOR(p, paths){
			int i, s, t; tie(i, s, t) = *p;
			if(s <= t) res = H::merge(res, seg[2*i].query(s, t+1));
			else res = H::merge(res, seg[2*i+1].query(hld[i].size()-1-s, hld[i].size()-t));
		}
		return res;
	}
	int lca(int u, int v){
		return hld.lca(u, v);
	}
	int par(int u){
		return hld.par(u);
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
struct handler{
	typedef vector<int> val_t;
	typedef ll opr_t;
	handler(){}
	static val_t def_val(){ return val_t(); }
	opr_t def_lazy(){ return 0; }
	static val_t resolve(const val_t &x, const opr_t &y, int l, int r){
		return x;
	}
	static opr_t push(const opr_t &x, const opr_t &y){
		return x;
	}
	static val_t merge(const val_t &x, const val_t &y){
		vi t(x.size() + y.size());
		std::merge(ALL(x), ALL(y), t.begin());
		if(t.size() > 10) t.resize(10);
		return t;
	}
};

int n, m, q;

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d%d", &n, &m, &q);
	vector<vi> g(n);
	REP(i, n-1){
		int u, v;
		scanf("%d%d", &u, &v); u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<vector<int>> d(n);
	REP(i, m){
		int c;
		scanf("%d", &c); c--;
		d[c].push_back(i+1);
	}
	REP(i, n){
		sort(ALL(d[i]));
		if(d[i].size() > 10) d[i].resize(10);
	}
	SegTreeOnHLDecomp<handler, SegTreeLazy<handler>> seg(g, d);
	REP(i, q){
		int u, v, a;
		scanf("%d%d%d", &u, &v, &a); u--; v--;
		auto res = seg.query(u, v);
		if(res.size() > a) res.resize(a);
		
		printf("%d", res.size());
		REP(i, res.size()) printf(" %d", res[i]);
		puts("");
	}
	return 0;
}