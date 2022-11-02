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
int MOD;

int n, m;
ll dp[2][505][505];
main(){
	scanf("%d%d%d", &n, &m, &MOD);
	vi rest(n, 2);
	REP(i, m){
		REP(j, n){
			char c;
			scanf(" %c", &c);
			if(c == '1') rest[j] --;
		}
	}
	vi c(3);
	REP(i, n) c[rest[i]] ++;
	dp[0][c[1]][c[2]] = 1;
	m = n - m;
	REP(i, m){
		REP(one, 501)REP(two, 501-one){
			const ll t = dp[i&1][one][two] % MOD; dp[i&1][one][two] = 0;
			if(!t) continue;
			if(one >= 2)dp[1^i&1][one-2][two]   += t * ((one*(one-1))>>1);
			if(two >= 2)dp[1^i&1][one+2][two-2] += t * ((two*(two-1))>>1);
			if(one&&two)dp[1^i&1][one][two-1]   += t * two * one;
		}
	}
	cout << dp[m&1][0][0] << endl;
	return 0;
}