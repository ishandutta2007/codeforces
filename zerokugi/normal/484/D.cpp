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


int n, m;
vi d;

ll calc(vi& d){
	if(d.size() < 2) return 0;
	int n = d.size();
	vector<ll> dp(n+1);
	int p = 0;
//	cout << d << endl;
	for(int i=1;i+1<n;i++){
		if((d[i-1] < d[i]) ^ (d[i] < d[i+1])){
			// [p, i)
			dp[i]   = max(dp[i]  , dp[p] + abs(d[p] - d[i-1]));
			// [p, i]
			dp[i+1] = max(dp[i+1], dp[p] + abs(d[p] - d[i]));
			// (p, i)
			if(p+1<=i-1)
			dp[i]   = max(dp[i]  , dp[p+1] + abs(d[p+1] - d[i-1]));
			// (p, i]
			dp[i+1] = max(dp[i+1], dp[p+1] + abs(d[p+1] - d[i]));
			p = i;
//		cout << dp << endl;
		}
	}
//	cout << dp << endl;
//	cout << p << endl;
	// [p, i)
	dp[n]   = max(dp[n]  , dp[p] + abs(d[p] - d[n-1]));
	// (p, i)
	if(p+1<=n-1)
	dp[n]   = max(dp[n]  , dp[p+1] + abs(d[p+1] - d[n-1]));
//	cout << dp << endl;
	return dp[n];
}

main(){
	scanf("%d", &n);
	ll ans = 0;
	REP(i, n){
		int x;
		scanf("%d", &x);
		if(!d.empty() && d.back() == x){
			ans += calc(d);
			d.clear();
		}
		d.push_back(x);
	}
	ans += calc(d);
	cout << ans << endl;
	return 0;
}