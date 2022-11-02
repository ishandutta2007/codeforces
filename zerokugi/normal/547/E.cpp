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

struct SuffixArray{
	template <bool End, class T>
	vi compute_buckets(const T *s, int n, int k) const {
		vi buckets(k);
		REP(i, n) ++buckets[s[i]];
		int sum = 0;
		REP(i, k){
			sum += buckets[i];
			buckets[i] = (End ? sum : (sum - buckets[i]));
		}
		return buckets;
	}
	template <class T>
	void induce_sa_l(int *sa, const T *s, int n, int k, const vi &ls) const{
		vi buckets(compute_buckets<false>(s, n, k));
		REP(i, n){
			const int j = sa[i] - 1;
			if(j >= 0 && !ls[j]){ sa[buckets[s[j]]++] = j; }
		}
	}
	template <class T>
	void induce_sa_s(int *sa, const T *s, int n, int k, const vi &ls) const{
		vi buckets(compute_buckets<true>(s, n, k));
		RREP(i, n){
			const int j = sa[i] - 1;
			if(j >= 0 && ls[j]){ sa[--buckets[s[j]]] = j; }
		}
	}
	bool is_lms(const vi& ls, int i)const {
		return i>0 && !ls[i-1] && ls[i];
	}
	
	template <class T>
	void sa_is(int *sa, const T *s, int n) const{
		vi ls(n); // 0:L 1:S
		ls[n-1] = 1;
		RREP(i, n-1) ls[i] = (s[i] != s[i+1]) ? s[i] < s[i+1] : ls[i+1];
		const int k = (int)*std::max_element(s, s + n) + 1;
		vi buckets = compute_buckets<true>(s, n, k);
		REP(i, n) sa[i] = -1;
		REPS(i, n-1) if(is_lms(ls, i)) sa[--buckets[s[i]]] = i;
		induce_sa_l(sa, s, n, k, ls);
		induce_sa_s(sa, s, n, k, ls);
		int m = 0;
		REP(i, n) if(is_lms(ls, sa[i])) sa[m++] = sa[i];
		for(int i=m;i<n;i++) sa[i] = -1;
		int num = 0, prev = -1;
		REP(i, m){
			int p = sa[i], diff = 0;
			REP(d, n){
				const int l = p+d, r = prev + d;
				if(prev < 0 || s[l] != s[r] || ls[l] != ls[r]){
					diff = 1;
					break;
				}else if(d > 0 && (is_lms(ls, l) || is_lms(ls, r))){
					break;
				}
			}
			if(diff){
				num ++;
				prev = p;
			}
			p = (p-(p&1))/2;
			sa[m+p] = num-1;
		}
		for(int i=n-1, j=n-1;i>=m;i--) if(sa[i] >= 0) sa[j--]=sa[i];
		int *reduced_s = sa+n-m;
		if(num < m) sa_is(sa, reduced_s, m);
		else REP(i, m) sa[reduced_s[i]] = i;
		buckets = compute_buckets<true>(s, n, k);
		int j=0;
		REPS(i, n-1)if(is_lms(ls, i)) reduced_s[j++] = i;
		REP(i, m) sa[i] = reduced_s[sa[i]];
		for(int i=m;i<n;i++) sa[i] = -1;
		RREP(i, m){
			const int j = sa[i];
			sa[i] = -1;
			sa[--buckets[s[j]]] = j;
		}
		induce_sa_l(sa, s, n, k, ls);
		induce_sa_s(sa, s, n, k, ls);
	}
	
	vi sa;

	template <class T>
	vi sa_is(const T &s) const {
		if(s.size() == 0){ return vi(1); }
		const int n = s.size() + 1;
		vi vs(n), sa(n);;
		REP(i, n-1){ vs[i] = s[i]; }
		sa_is(&sa[0], &vs[0], n);
		return sa;
	}
	template <class T>
	explicit SuffixArray(const T &s):sa(sa_is(s)){}
	size_t size() const { return sa.size(); }
	int operator[](int i) const { return sa[i]; }
};

template <class T>
struct LCP{
	int n;
	vi vs, isa, lcp;
	LCP(const T &s, const vi &sa):n(sa.size()),vs(n),isa(n),lcp(n - 1){
		REP(i, n-1) vs[i] = s[i];
		REP(i, n) isa[sa[i]] = i;
		int h = 0, j;
		REP(i, n)if((j = isa[i]) > 0){
			while(vs[sa[j] + h] == vs[sa[j-1] + h]) h++;
			lcp[j-1] = h;
			if(h > 0) --h;
		}
	}
	int operator[](int i) const{
		return lcp[i];
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

struct handler_sum{
	typedef int val_t;
	handler_sum(){}
	static val_t def_val(){ return 0; }
	static val_t update(const val_t &l, const val_t &r){
		return l + r;
	}
	static val_t update_overwrite(const val_t &l, const val_t &r){
		return r;
	}
	static val_t merge(const val_t &l, const val_t &r){
		return l + r;
	}
};

struct handler_rmq{
	typedef int val_t;
	handler_rmq(){}
	static val_t def_val(){ return INF; }
	static val_t update(const val_t &l, const val_t &r){
		return r;
	}
	static val_t merge(const val_t &l, const val_t &r){
		return min(l, r);
	}
};

template<class Handler>
class NazoTable{
	typedef typename Handler::val_t val_t;
	int N, K;
	vector< vector<val_t> > d;
	Handler hdl;
	
public:
	NazoTable(vector<val_t> v):hdl(){
		N=v.size();
		K = 1;
		while((1<<K)<v.size()) K++;
		v.resize(1<<K, hdl.def_val());
		d = vector< vector<val_t> >(K, vector<val_t>(1<<K));
		for(int k=0;k<K;k++){
			for(int i=0;i<1<<(K-k-1);i++){
				int center = (i<<(k+1)) | (1<<k);
				d[k][center-1] = v[center-1];
				d[k][center  ] = v[center  ];
				for(int j=2;j<=(1<<k);j++) if(center  <N) d[k][center-j] = hdl.merge(v[center-j], d[k][center-j+1]);
				for(int j=1;j<(1<<k);j++)  if(center+j<N) d[k][center+j] = hdl.merge(d[k][center+j-1], v[center+j]);
			}
		}
	}
	
	int query(int l, int r){
		r --;
		if(r<l) return hdl.def_val();
		if(l^r){
			int k = 31 - __builtin_clz(l^r);
			return hdl.merge(d[k][l], d[k][r]);
		}
		return d[0][l];
	}
};


int n, m;
char buf[210001];

main(){
	scanf("%d%d", &n, &m);
	string s;
	vi len(n), offset(n);
	REP(i, n){
		scanf(" %s", buf);
		string t = string(buf);
		offset[i] = s.size();
		len[i] = t.size();
		s += t + "{";
	}
	offset.pb(s.size());
	SuffixArray sa(s);
//	REP(i, sa.size()) cout << i << ": " << s.substr(sa[i]) << endl;
	LCP<string> lcp(s, sa.sa);
	vi &isa = lcp.isa;
	vector<pii> rng(n);
	REP(i, n){
		int t = isa[offset[i]];
		
	}
	
	vector<tuple<int, int, int>> q;
	vi ans(m);
	REP(i, m){
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k); l--; k--;
		q.eb(l, k, ~i);
		q.eb(r, k, i);
	}
	NazoTable<handler_rmq> seglcp(lcp.lcp);
	SegTree<handler_sum> seg(s.size());
	sort(ALL(q));
	int added = 0;
	REP(j, q.size()){
		int r, k, i; tie(r, k, i) = q[j];
//		cout << "?" << r << ", " << k << ", " << i << endl;
		while(added < r){
			for(int j=offset[added];j<offset[added+1];j++) seg.update(isa[j], 1);
			added ++;
		}
		int b, u;
		{
			int l = -1, r = isa[offset[k]]+1;
			while(l+1 < r){
				int med = (l+r)/2;
				if(seglcp.query(med, isa[offset[k]]) < len[k]) l = med;
				else r = med;
			}
			b = r;
		}
		{
			int l = isa[offset[k]], r = lcp.lcp.size() + 1;
			while(l+1 < r){
				int med = (l+r)/2;
				if(seglcp.query(isa[offset[k]], med) < len[k]) r = med;
				else l = med;
			}
			u = r;
		}
//		cout << seg << ", " << k << ": " << b << ", " << u << endl;
		if(i < 0) ans[~i] -= seg.query(b, u);
		else ans[i] += seg.query(b, u);
	}
	REP(i, m) printf("%d\n", ans[i]);
	return 0;
}