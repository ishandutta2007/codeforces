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
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) container.begin(), container.end()
#define RALL(container) container.rbegin(), container.rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

const int INF = 1<<28;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

unsigned long xor128(){
    static unsigned long x=123456789,y=362436069,z=521288629,w=88675123;
    unsigned long t;
    t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) );
}
#include <complex>
#include <cmath>
#define EPS 1.0e-10
#define PI 3.1415926535897932384 

// 
inline int signum(double x) { return (abs(x) < EPS ? 0 : x > 0 ? 1 : -1); }
//XYW
#define X real()
#define Y imag()
// _
typedef complex<double> P;

// p`
typedef vector<P> G;
 
// std::norm abs(p)*abs(p)x
inline double norm(P p){
	return p.X*p.X+p.Y*p.Y;
}
// xNgOvZ
inline double outp(const P& a, const P& b) {
	return (conj(a)*b).Y;
}

inline int ccw(const P& p, const P& r, const P& s) {
    P a(r-p), b(s-p);
    return signum(outp(a, b));
}

bool xy_less(const P& a, const P& b) {
    if (abs(a.imag()-b.imag()) < EPS) return (a.real() < b.real());
    return (a.imag() < b.imag());
}
template<class IN>
void walk_rightside(IN begin, IN end, vector<P>& v) {
    IN cur = begin;
    v.push_back(*cur++);
    vector<P>::size_type s = v.size();
    v.push_back(*cur++);
    while(cur != end) {
        if (v.size() == s || ccw(v[v.size()-2], v.back(), *cur) > 0)
            v.push_back(*cur++);
        else
            v.pop_back();
    }
    v.pop_back();
}
//
vector<P> convex_hull(vector<P> v) {
    if (v.size() <= 1)
        return v; // EXCEPTIONAL
    sort(v.begin(), v.end(), xy_less);
    vector<P> cv;
    walk_rightside(v.begin(), v.end(), cv);
    walk_rightside(v.rbegin(), v.rend(), cv);
    return cv;
}

vi lans;
int sum;
int n, r;
int dist[50][50];
void dfs(int gs, vi &ans, int s, int rest, int cur){
	if(rest == 0){
		if(chmax(sum, cur)){
			lans = ans;
		}
		return ;
	}
	if(4*r*r*rest*n/2 + cur < sum) return;
	for(int i=s;i<gs;i++){
		int pl = 0;
		REP(j, ans.size()) pl += dist[i][ans[j]];
		ans.push_back(i);
		dfs(gs, ans, i, rest - 1, cur + pl);
		ans.pop_back();
	}
	return ;
}

main(){

	scanf("%d %d", &n, &r);
	vector<P> g;
	for(int y = -r;y <= r; y++)
		for(int x = -r;x <= r; x++)
			if(x*x+y*y<=r*r){
				g.emplace_back(x, y);
			}
	g = convex_hull(g);
	REP(i, g.size())REP(j, g.size()) dist[i][j] = norm(g[i]-g[j]) + EPS;
	sum = -INF;
	vi ans;
	dfs(g.size(), ans, 0, n, 0);
	cout << sum << endl;
	REP(i, n) cout << g[lans[i]].X << " " << g[lans[i]].Y << endl;
	return 0;
}