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

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;


ll n;
int T;
main(){
	vector<ll> fib;
	ll a = 1, b = 0;
	while(a+b <= 1000000000000000000LL){
		fib.push_back(a+b);
		a = a+b;
		b = a-b;
	}
	cin >> T;
	REP(t, T){
		cin >> n;
		vi tbl(1);
		RREP(i, fib.size()) if(n >= fib[i]){
			n -= fib[i];
			tbl.push_back(i+1);
		}
		sort(ALL(tbl));
		vi dp0(tbl.size());
		vi dp1(tbl.size());
		dp1[0] = 1;
//		cout << tbl << endl;
		REP(i, tbl.size()){
			if(!i) continue;
			dp1[i] += dp0[i-1] + dp1[i-1];
			dp0[i] += ((tbl[i] - tbl[i-1] - 1) / 2) * (dp1[i-1] + dp0[i-1]);
			dp0[i] += ((tbl[i] - tbl[i-1] - 1) % 2) * dp0[i-1];
		}
//		cout << dp0 << endl;
//		cout << dp1 << endl;
		cout << (dp1.back() + dp0.back()) << endl;
	}
	return 0;
}