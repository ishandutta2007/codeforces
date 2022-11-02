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

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;

int n, v;
int fr[3002];
main(){
	scanf("%d%d", &n, &v);
	int ans=0;
	REP(i, n){
		int x, y;
		scanf("%d%d", &x, &y);
		fr[x] += y;
	}
	REP(x, 3001){
		int c = v;
		c -= min(fr[x], c);
		int t = min(fr[x+1], c);
		fr[x+1] -= t;
		c -= t;
		ans += v-c;
	}
	printf("%d\n", ans);
	return 0;
}