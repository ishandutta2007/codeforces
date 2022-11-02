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
typedef vector<ll> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) container.begin(), container.end()
#define RALL(container) container.rbegin(), container.rend()
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

const ll INF = 1LL<<60;
const double EPS = 1e-8;
const int MOD = 1000000007;

int n, m, k, p;

main(){
	scanf("%d%d%d%d", &n, &m, &k, &p);
	vi row(n), col(m);
	REP(i, n)REP(j, m){
		int t;
		scanf("%d", &t);
		row[i] += t;
		col[j] += t;
	}
	
	priority_queue<ll> R, C;
	REP(i, n) R.push(row[i]);
	REP(i, m) C.push(col[i]);
	ll mrow = 0, mcol = 0;
	ll ans = -INF;
	vi rtake(1), ltake(1);
	REP(i, k+1){
		ll t = R.top();R.pop();
		rtake.push_back(t+rtake.back());
		R.push(t - p*m);
		t = C.top();C.pop();
		ltake.push_back(t+ltake.back());
		C.push(t - p*n);
	}
	REP(i, k+1) ans = max(ans, rtake[i] + ltake[k-i] - (ll)p*i*(k-i));
	cout << ans << endl;
	return 0;
}