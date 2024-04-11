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
#include <unordered_set>
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


int m, h, x, y, a;
pll cycle(int h, int x, int y, int m, int a){	// return p*k + q = a (mod m);
	vi idx(m, -1);
	REP(i, 2*m){
		if(h == a && idx[h] >= 0){
			return pll(i - idx[h], idx[h]);
		}
		idx[h] = i;
		h = ((ll)x*h + y) % m;
	}
	if(idx[a] >= 0) return pll(0, idx[a]);
	return pll(-1, -1);
}

ll check(pll c1, pll c2){
	unordered_set<ll> s;
	REP(i, m) s.insert(c1.first*i + c1.second);
	REP(i, m){
		ll t = c2.first*i + c2.second;
		if(s.count(t)) return t;
	}
	return 1ll<<60;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m;
	cin >> h >> a >> x >> y;
	pll c1 = cycle(h, x, y, m, a);
	cin >> h >> a >> x >> y;
	pll c2 = cycle(h, x, y, m, a);
	if(c1.first == -1 || c2.first == -1){
		puts("-1");
		return 0;
	}
	ll ans = min(check(c1, c2), check(c2, c1));
	if(ans == 1ll<<60) puts("-1");
	else cout << ans << endl;
	return 0;
}