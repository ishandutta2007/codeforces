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

template <typename T=int>
struct Zipper{
	vector<T> dec;
	unordered_map<T, int> enc;
	Zipper(){}
	void add(T t){dec.pb(t);}
	size_t size(){return dec.size();}
	void compile(){
		sort(ALL(dec)); UNIQUE(dec);
		REP(i, dec.size()) enc[dec[i]] = i;
	}
	T operator[](int i){return dec[i];}
	int operator()(T t){return enc[t];}
	int lb(T t){return lower_bound(ALL(dec), t) - dec.begin();}
	int ub(T t){return upper_bound(ALL(dec), t) - dec.begin();}
};

struct handler{
	typedef pii val_t;
	handler(){}
	static val_t def_val(){ return pii(0, 0); }
	static val_t update(const val_t &l, const val_t &r){
		return max(l, r);
	}
	static val_t merge(const val_t &l, const val_t &r){
		return max(l, r);
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


int n, m;

tuple<ll, int, int> solve(vector<tuple<int, int, int>> mv, vector<tuple<int, int, int, int>> ch){
	Zipper<int> zip;
	REP(i, n){
		zip.add(get<0>(mv[i]));
		zip.add(get<1>(mv[i]));
	}
	REP(i, m){
		zip.add(get<0>(ch[i]));
		zip.add(get<1>(ch[i]));
	}
	zip.compile();
	REP(i, n){
		get<0>(mv[i]) = zip(get<0>(mv[i]));
		get<1>(mv[i]) = zip(get<1>(mv[i]));
	}
	REP(i, m){
		get<0>(ch[i]) = zip(get<0>(ch[i]));
		get<1>(ch[i]) = zip(get<1>(ch[i]));
	}
	vector<pii> ends(zip.size(), pii(0, -1));
	pii cur(-1, -1);
	REP(ii, n){
		int l, r, i; tie(l, r, i) = mv[ii];
		cur = max(cur, pii(r, i));
		ends[l] = cur;
	}
	REP(i, (int)zip.size()-1) ends[i+1] = max(ends[i], ends[i+1]);
//	cout << zip.dec << endl;
//	cout << ends << endl;
	tuple<ll, int, int> ans(0, -1, -1);
	REP(ii, m){
		int l, r, c, i; tie(l, r, c, i) = ch[ii];
//		cout << zip[min(ends[l].first, r)] << " - " << zip[l] << endl;
		chmax(ans, tuple<ll, int, int>((ll)(zip[min(ends[l].first, r)] - zip[l])*c, ends[l].second, i));
	}
	return ans;
}

tuple<ll, int, int> solve2(vector<tuple<int, int, int>> mv, vector<tuple<int, int, int, int>> ch){
	Zipper<int> zip;
	REP(i, n){
		zip.add(get<0>(mv[i]));
		zip.add(get<1>(mv[i]));
	}
	REP(i, m){
		zip.add(get<0>(ch[i]));
		zip.add(get<1>(ch[i]));
	}
	zip.compile();
	REP(i, n){
		get<0>(mv[i]) = zip(get<0>(mv[i]));
		get<1>(mv[i]) = zip(get<1>(mv[i]));
	}
	REP(i, m){
		get<0>(ch[i]) = zip(get<0>(ch[i]));
		get<1>(ch[i]) = zip(get<1>(ch[i]));
	}
	sort(ALL(mv), [&](const tuple<int, int, int> & x, const tuple<int, int, int> &y){
		return get<1>(x) < get<1>(y);
	});
	sort(ALL(ch), [&](const tuple<int, int, int, int> & x, const tuple<int, int, int, int> &y){
		return get<1>(x) < get<1>(y);
	});
	SegTree<handler> seg(zip.size());
	tuple<ll, int, int> ans(0, -1, -1);
	for(int i=0, j=0;i<=n && j<m;i++){
		while(j<m && (i==n || get<1>(ch[j]) < get<1>(mv[i]))){
			pii d = seg.query(get<0>(ch[j]), get<1>(ch[j])+1);
			chmax(ans, tuple<ll, int, int>((ll)d.first*get<2>(ch[j]), d.second, get<3>(ch[j])));
			j++;
		}
		if(i < n) seg.update(get<0>(mv[i]), pii(zip[get<1>(mv[i])] - zip[get<0>(mv[i])], get<2>(mv[i])));
	}
	return ans;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d", &n, &m);
	vector<tuple<int, int, int>> mv1, mv2;
	vector<tuple<int, int, int, int>> ch1, ch2;
	REP(i, n){
		int x, y;
		scanf("%d%d", &x, &y);
		mv1.eb(x, y, i);
		mv2.eb(-y, -x, i);
	}
	REP(i, m){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		ch1.eb(x, y, z, i);
		ch2.eb(-y, -x, z, i);
	}
	sort(ALL(mv1));
	sort(ALL(mv2));
	sort(ALL(ch1));
	sort(ALL(ch2));
	auto ans = max(solve(mv1, ch1), solve(mv2, ch2));
	ans = max(ans, solve2(mv1, ch1));
//	ans = max(ans, solve2(mv2, ch2));
	if(get<0>(ans) == 0) cout << 0 << endl;
	else{
		cout << get<0>(ans) << endl;
		cout << get<1>(ans)+1 << " " << get<2>(ans)+1 << endl;
	}
	return 0;
}