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

namespace geom{
#define X real()
#define Y imag()
#define at(i) ((*this)[i])
#define SELF (*this)
	enum {TRUE = 1, FALSE = 0, BORDER = -1};
	typedef int BOOL;
	typedef long double R;
	const R INF = 1e8;
	R EPS = 1e-6;
	const R PI = 3.1415926535897932384626;
	inline int sig(const R &x) { return (abs(x) < EPS ? 0 : x > 0 ? 1 : -1); }
	inline BOOL less(const R &x, const R &y) {return sig(x-y) ? x < y : BORDER;}
	typedef complex<R> P;
	inline R norm(const P &p){return p.X*p.X+p.Y*p.Y;}
	inline R inp(const P& a, const P& b){return (conj(a)*b).X;}
	inline R outp(const P& a, const P& b){return (conj(a)*b).Y;}
	inline P unit(const P& p){return p/abs(p);}
	inline P proj(const P &s, const P &t){return t*inp(s, t)/norm(t);}
	inline int ccw(const P &s, const P &t, const P &p, int adv=0){
		int res = sig(outp(t-s, p-s));
		if(res || !adv) return res;
		if(sig(inp(t-s, p-s)) < 0) return -2;	// p-s-t
		if(sig(inp(s-t, p-t)) < 0) return 2;	// s-t-p
		return 0;								// s-p-t
	}

#undef SELF
#undef at
}

using namespace geom;

int f = 0;
namespace std{
	bool operator<(const P &a, const P &b){return sig(a.X-b.X) ? a.X < b.X : a.Y+EPS < b.Y;}
	bool operator==(const P &a, const P &b){return abs(a-b) < EPS;}
	istream& operator>>(istream &is, P &p){R x,y;is>>x>>y;p=P(x, y);return is;}

}

int n, m;
typedef long double R;
P p, q, v, w;
R vmax, ct;

R dist(P v, P wind, R t){
	if(abs(v) > EPS) v = unit(v);
	R l=0, r=1e10;
	REP(_, 100){
		R mid = (l+r)/2;
		
		R vx = v.X * mid;
		R vy = v.Y * mid;
		
		if((vx*vx + vy*vy) <= vmax * vmax) l = mid;
		else r = mid;
	}
	return abs(v*l)*t;
}

int check(R t){
	P s = q + v * min<R>(t, ct) + w * max<R>(t - ct, 0);
	P vec = p - s;
	return dist(vec, v,  min<R>(t, ct)) + dist(vec, w, max<R>(t - ct, 0)) >= abs(vec);
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> q >> p;
	cin >> vmax >> ct;
	cin >> v >> w;
	R l=0, r=1e10;
	REP(_, 100){
		R mid = (l+r)/2;
		if(check(mid)) r = mid;
		else l = mid;
	}
	printf("%.20f\n", (double)l);
	return 0;
}