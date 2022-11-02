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


int n, m;
int a[4001][4001], cost[4001][4001];
int dp[801][4001];

void solve(int l, int r, int k, int kl, int kr){
	if(k == 1){
		for(int i = l; i < r; i++){
			dp[k][i] = cost[0][i+1];
		}
		return ;
	}
	if(l>=r) return;
	if(kl + 1 == kr){
		for(int i = l; i < r; i++){
			dp[k][i] = dp[k-1][kl] + cost[kl+1][i+1];
		}
		return ;
	}
	int m = (l+r)/2, A;
	// solve dp[k][m]
	for(int i=kl;i<min(m, kr);i++){
		int c = dp[k-1][i] + cost[i+1][m+1];
		if(c <= dp[k][m]){
			dp[k][m] = c;
			A = i;
		}
	}
//	printf("%d, [%d, %d], %d: (%d, %d)\n", k, l, r, m, dp[k][m], A);
	solve(l, m, k, kl, A+1);
	solve(m+1, r, k, A, kr);
}



main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, 63, sizeof(dp));
	scanf("%d%d", &n, &m);
	REP(i, n){
		REPS(j, n){
			int c;
			while(c = getchar(), !isdigit(c));
			a[i][j] = a[i][j-1] + c - '0';
		}
	}
	REP(i, n)for(int j=i+1;j<n;j++){
		cost[i][j+1] = cost[i][j] + a[j][j] - a[j][i];
//		printf("%d, %d: %d\n", i, j+1, cost[i][j+1]);
	}
	REPS(i, m) solve(0, n, i, 0, n);
//	REPS(i, m)REP(j, n) printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
	cout << dp[m][n-1] << endl;
	return 0;
}