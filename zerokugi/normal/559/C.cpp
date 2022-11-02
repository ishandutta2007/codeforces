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

template<int N, int MOD>
struct Comb{
	ll fact[N+1], inv[N+1];
	Comb(){
		fact[0] = inv[0] = inv[1] = 1;
		for(int i=2;i<=N;i++) inv[i] = (MOD+((ll)-inv[MOD%i]*(MOD/i))%MOD)%MOD;
		REPS(i, N){
			fact[i] = fact[i-1]*i%MOD;
			inv[i] = inv[i]*inv[i-1]%MOD;
		}
	}
	ll operator()(int n, int r){
		if(n < 0 || r < 0 || r > n) return 0;
		ll res = inv[r]*inv[n-r];
		if(res >= MOD) res%= MOD;
		res *= fact[n];
		if(res >= MOD) res%= MOD;
		return res;
	}
};
Comb<300000, MOD> C;

int h, w, n;
ll dp[2][2010];
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> h >> w >> n; h--; w--;
	vector<pair<int, pii>> p;
	p.eb(0, pii(0, 0));
	p.eb(h + w, pii(w, h));
	REP(i, n){
		int x, y;
		cin >> y >> x; y--; x--;
		p.eb(x + y, pii(x, y));
	}
	sort(ALL(p));
	dp[1][0] = 1;
	REPS(i, n+1){
		int x, y; tie(x, y) = p[i].second;
		REP(j, i){
			int px, py; tie(px, py) = p[j].second;
			if(px <= x && py <= y){
				ll coef = C(x - px + y - py, x - px);
				REP(k, 2){
					dp[!k][i] = (dp[!k][i] + coef * dp[k][j]) % MOD;
				}
			}
		}
	}
	cout << (dp[0][n+1]%MOD - dp[1][n+1]%MOD + MOD) % MOD << endl;
	return 0;
}