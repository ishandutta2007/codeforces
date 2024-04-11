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

#define REP(i,x) for(ll i=0;i<(ll)(x);i++)
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


ll t, a, b;
long double x[2][60];
ll dfs(int co, ll re1, ll re2){
	if(co == 1){
		if(t == a || (re1-re2) % (t-a)) return 0;
		ll i = (re1 - re2) / (t-a);
		return !(re1 - i*t < 0 || re2 - i*a < 0 || i < 0);
	}
	ll ans = 0;
	while(re1 >= 0 && re2 >= 0){
		if(dfs(co-1, re1, re2)) return 1;
		re1 -= x[0][co]; re2 -= x[1][co];
	}
	return 0;
}

main(){
	cin >> t >> a >> b;
	if(t == 1 && a == 1 && b == 1){
		puts("inf");
		return 0;
	}
	if(t == a && a == b){
		puts("2");
		return 0;
	}
	if(t == a){
		puts("0");
		return 0;
	}
	REP(i, 60){
		x[0][i] = powl(t, i);
		x[1][i] = powl(a, i);
	}
	cout << dfs(59, a, b) << endl;
	return 0;
}