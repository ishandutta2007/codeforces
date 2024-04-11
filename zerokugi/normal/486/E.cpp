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
class BIT {
	int n;
	vector<int> vs;
public:
	BIT(int size) {
		n = size;
		vs = vector<int>(n);
	}
	//O(log n)
	void add(int k, int a) {
		for(int i = k; i < n; i |= i + 1) vs[i] += a;
	}
	//[s,t)	O(log n)
	int sum(int s, int t) {
		if(s > 0) return sum(0, t) - sum(0, s);
		int res = 0;
		for(int i = t - 1; i >= 0; i = (i & (i + 1)) - 1) res += vs[i];
		return res;
	}
};

main(){
	scanf("%d", &n);
	vi v(n);
	REP(i, n){
		int x;
		scanf("%d", &x);
		v[i] = x;
	}
	vector<int> dp(v.size(), INF);
	vector<int> level(n);
	vector<vector<pii> > memo(v.size() + 1);
	REP(i, v.size()){
		int p = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
		dp[p] = v[i];
		level[i] = p;
		memo[p].push_back(pii(v[i], i));
	}
	int r = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
	vi ma(r+1);
	ma[r] = INF;
	vi dist(100001);
	RREP(i, n){
		if(ma[level[i]+1] <= v[i]) level[i] = -1;
		else{
			ma[level[i]] = max(ma[level[i]], v[i]);
			dist[level[i]] ++;
		}
	}
	REP(i, n) cout << (level[i] == -1 ? 1 : dist[level[i]] == 1 ? 3 : 2);
	cout << endl;
	return 0;
}