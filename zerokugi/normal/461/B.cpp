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
int color[100005];
int n;

vector<vi> g;

pair<ll, ll> dfs(int r, int p){
	vector<ll> white, black;
	FOR(v, g[r]) if(*v != p){
		pair<ll, ll> ret = dfs(*v, r);
		white.push_back(ret.first);
		black.push_back(ret.second);
	}
	
	ll dp0 = !color[r], dp1 = color[r];
	REP(i, white.size()){
		dp1 = (dp1 * (black[i]) + dp0 * black[i] + dp1 * white[i]) % MOD;
		dp0 = (dp0 * (black[i]) + dp0 * white[i]) % MOD;
	}
	return pair<ll, ll>(dp0, dp1);
}

main(){
	scanf("%d", &n);
	g = vector<vi>(n);
	int ans;
	REP(i, n-1){
		int x;
		scanf("%d", &x);
		g[i+1].push_back(x);
		g[x].push_back(i+1);
	}
	REP(i, n) scanf("%d", &color[i]);
	cout << dfs(0, -1).second << endl;
	return 0;
}