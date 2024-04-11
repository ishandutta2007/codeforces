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

int n, h;

main(){
	scanf("%d%d", &n, &h);
	vi d(n+1, 0);
	REP(i, n){
		scanf("%d", &d[i]);
		d[i] = h - d[i];
		if(d[i] < 0){
			puts("0");
			return 0;
		}
	}
	vector<ll> dp(2002);
	dp[0] = 1;
	ll ans = 1;
	ll c = 0;
	REP(i, n+1){
		vector<ll> next(2002);
		ll sum = 0;
		if(d[i]-1 >= 0) sum += dp[d[i]-1];
		sum += dp[d[i]];

		if(d[i]-1 >= 0) next[d[i]-1] = sum*d[i]%MOD;
		next[d[i]  ] = sum%MOD;
		dp.swap(next);
	}
	cout << dp[0] << endl;
	return 0;
}
/*
01221
 1111
  11
    
 11
  11
   11
   
 111
  111
 
 1111
  1
   1
 
 111
  1
   11

  111
   1
 11
 
121
111
 1
 
11
 11
 
 
*/