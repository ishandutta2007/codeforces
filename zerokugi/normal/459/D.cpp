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

int n;
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
	vi d(n);
	vi head(n), tail(n);
	map<int, int> cnt1, cnt2;
	REP(i, n){
		scanf("%d", &d[i]);
		head[i] = cnt1[d[i]];
		cnt1[d[i]] ++;
	}
	RREP(i, n){
		tail[i] = cnt2[d[i]];
		cnt2[d[i]] ++;
	}
	vi idx = head;
	idx.insert(idx.end(), tail.begin(), tail.end());
	sort(ALL(idx));
	UNIQUE(idx);
	map<int, int> to;
	REP(i, idx.size()) to[idx[i]] = i;
	REP(i, head.size()) head[i] = to[head[i]];
	REP(i, tail.size()) tail[i] = to[tail[i]];
	int m = idx.size();
	BIT bit(m);
	ll ans = 0;
	REP(i, n){
		ans += bit.sum(tail[i]+1, m);
		bit.add(head[i], 1);
		
	}
	cout << ans << endl;
	return 0;
}