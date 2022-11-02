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
	
	int query(int l, int r){ // [l, r]
		if(r<l) return hdl.def_val();
		if(l^r){
			int k = 31 - __builtin_clz(l^r);
			return hdl.merge(d[k][l], d[k][r]);
		}
		return d[0][l];
	}
};
struct handler_min{
	typedef int val_t;
	handler(){}
	val_t def_val(){ return MOD; }
	static val_t merge(const val_t &l, const val_t &r){
		return min(l, r);
	}
};

struct handler_max{
	typedef int val_t;
	handler(){}
	val_t def_val(){ return 0; }
	static val_t merge(const val_t &l, const val_t &r){
		return max(l, r);
	}
};


int n, k;

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d", &n, &k);
	vi a(n), b(n);
	REP(i, n){
		int x;
		scanf("%d", &x);
		a[i] = 100*x;
	}
	REP(i, n){
		int x;
		scanf("%d", &x);
		b[i] = x;
	}
	NazoTable<handler_max> seg1(a);
	NazoTable<handler_min> seg2(b);
	int r = 0;
	
	vi score;
	
	REP(l, n){
		r = max(r, l);
		while(r + 1 < n && seg1.query(l, r + 1) < seg2.query(l, r + 1)) r ++;
		int x = min(seg1.query(l, r), seg2.query(l, r));
		if(r + 1 < n) x = max(x, min(seg1.query(l, r + 1), seg2.query(l, r + 1)));
		score.pb(x);
	}
	sort(ALL(score));
	long double ans = 0, p = (long double)(k) / (n);
	REP(i, n - k + 1){
		ans += p * score[i];
		p *= (long double)(n - k - i) / (n - i - 1);
	}
	printf("%.20f\n", (double)ans);
	return 0;
}