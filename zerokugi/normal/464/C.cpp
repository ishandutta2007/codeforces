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

int n, q;

char in[100005];
char qs[100005];
vector<char> qt[100005];
char query[100005];
int dp[10];
int tenpows[10];
main(){
	scanf("%s", in);
	scanf("%d", &n);
	REP(i, n){
		scanf("%s", query);
		qs[i] = query[0]-'0';
		for(char *p=query+3;*p;++p) qt[i].push_back(*p-'0');
	}
	REP(i, 10){
		dp[i] = i;
		tenpows[i] = 10;
	}
	RREP(j, n){
		ll res = 0, tp = 1;
		FOR(k, qt[j]){
			tp = tp*tenpows[*k]%MOD;
			res = (res*tenpows[*k]%MOD + dp[*k])%MOD;
		}
		dp[qs[j]] = res;
		tenpows[qs[j]] = tp;
	}
	int m = strlen(in);
	ll res = 0;
	for(char *p=in;*p;++p) res = (res*tenpows[*p-'0'] + dp[*p-'0']) % MOD;
	cout << res << endl;
	return 0;
}