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
typedef pair<pii, int> ppiii;
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
#define F first
#define S second
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
const int MOD = 1000000009;
const int BLOCK = 1050;
int n, m;

int F[300005];
int sumFib[300005];
int qt[300005];
int ql[300005];
int qr[300005];
int init[300005];
int sum[300005];
int fib[300005];

main(){
	F[0] = 1;
	F[1] = 1;
	REP(i, 300000) F[i+2] = (F[i+1] + F[i]) % MOD;
	REP(i, 300002) sumFib[i+1] = (sumFib[i] + F[i]) % MOD;

	scanf("%d%d", &n, &m);
	REP(i, n) scanf("%I64d", &init[i+1]);
	REP(i, n+1) sum[i+1] = (sum[i] + init[i]) % MOD;
	
	REP(i, m){
		scanf("%d%d%d", &qt[i], &ql[i], &qr[i]);
		qr[i] ++;
	}
	int p = 0;
	while(p<m){
		REP(i, BLOCK){
			if(p+i >= m) break;
			int l = ql[p+i];
			int r = qr[p+i];
			if(qt[p+i] == 2){
				ll res = sum[r] - sum[l];
				REP(j, i){
					if(qt[p+j] == 1){
						int ll = max(l, ql[p+j]);
						int rr = min(r, qr[p+j]);
						if(ll < rr) res += sumFib[rr - ql[p+j]] - sumFib[ll - ql[p+j]];
					}
				}
				printf("%I64d\n", ((res % MOD) + MOD) % MOD);
			}else{
				fib[l] += F[0];
				fib[r] += MOD - F[r-l];
				fib[r+1] += MOD - (r-l-1 >= 0 ? F[r-l-1] : 1);
				if(fib[l] >= MOD) fib[l] %= MOD;
				if(fib[r] >= MOD) fib[r] %= MOD;
				if(fib[r+1] >= MOD) fib[r+1] %= MOD;
			}
		}
		p += BLOCK;
		fib[1] += fib[0];
		if(fib[1] >= MOD) fib[1] -= MOD;
		REP(i, n+4){
			if(i+2 < n+3){
				fib[i+2] += (fib[i+1] + fib[i])%MOD;
				if(fib[i+2] >= MOD) fib[i+2] -= MOD;
			}
			(init[i] += fib[i]) %= MOD;
			sum[i+1] = (sum[i] + init[i]) % MOD;
			fib[i] = 0;
		}
	}
	return 0;
}