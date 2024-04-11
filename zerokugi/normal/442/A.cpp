#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x)-1;i>=0;i--)
#define RFOR(i,c) for(auto i=(c).rbegin();i!=(c).rend();++i)
#define ALL(container) container.begin(), container.end()
#define SZ(container) ((int)container.size())
#define mp(a, b) make_pair(a, b)
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;

int n;
int g[5][5];
int q[128];
main(){
	scanf("%d", &n);
	q['R'] = 0;
	q['G'] = 1;
	q['B'] = 2;
	q['Y'] = 3;
	q['W'] = 4;
	REP(i, n){
		char c, d;
		scanf(" %c%c", &c, &d);
		g[q[c]][d-'1'] = 1;
	}
	int ans = 10;
	REP(i, 1<<5)REP(j, 1<<5){
		int c = 0;
		vector<int> a(5), b(5);
		REP(y, 5)REP(x, 5){
			if(g[y][x]){
				if(((i>>y)&1) && ((j>>x)&1)) continue;
				if(((i>>y)&1)) a[y]++;
				else if(((j>>x)&1)) b[x]++;
				else c++;
			}
		}
		int f=1;
		REP(k, 5) if(a[k]>1 || b[k]>1) f=0;
		if(c>1) f=0;
		if(f) ans = min(ans, __builtin_popcount(i) + __builtin_popcount(j));
	}
	printf("%d\n", ans);
	return 0;
}