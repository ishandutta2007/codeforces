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

void addMOD(int &dst, const int &src){
	dst += src;
	if(dst >= MOD) dst -= MOD;
	if(dst < 0) dst += MOD;
}

int n, a, b, k;

main(){
	scanf("%d%d%d%d", &n, &a, &b, &k); a--; b--;
	vi bit(n+1);
	bit[a+1] = 1;
	REP(i, k){
		vi next(n+1);
		REP(j, n){
			int d=abs(j-b)-1;
			int p=bit[j+1];
			if(d <= 0 || !p) continue;
			addMOD(next[max(0, j - d)], p);
			addMOD(next[j], -p);
			addMOD(next[j+1], p);
			addMOD(next[min(n, j + d + 1)], -p);
		}
		bit[0] = 0;
		REP(i, n) bit[i+1] = ((bit[i]+next[i])%MOD+MOD)%MOD;
	}
	ll ans = 0;
	REP(i, n) ans += bit[i+1];
	cout << ans % MOD << endl;
	return 0;
}