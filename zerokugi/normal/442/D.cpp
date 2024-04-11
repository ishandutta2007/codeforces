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
int dp1[1000005];
int dp2[1000005];
int par[1000005];
vi childs[1000005];
void recalc(int r, int c){
	int a=dp1[r], b=dp2[r], d = max(dp1[c], dp2[c]+1);
	if(b<d) swap(b,d);
	if(a<b) swap(a,b);
	if(dp1[r] != a || dp2[r] != b){
		int a=0,b=0,d;
		FOR(c, childs[r]){
			d=max(dp1[*c], dp2[*c]+1);
			if(b<d) swap(b,d);
			if(a<b) swap(a,b);
		}
		if(dp1[r] != a || dp2[r] != b){
			dp1[r] = a;
			dp2[r] = b;
			if(par[r] >= 0) recalc(par[r], r);
		}
	}
}

main(){
	scanf("%d", &n);n++;
	par[0] = -1;
	int ans;
	REP(i, n-1){
		int x;
		scanf("%d", &x);x--;
		par[i+1] = x;
		childs[x].push_back(i+1);
		recalc(x, i+1);
//		printf("%2d: ", i+2);
//		REP(j, n) printf("%d ", dp1[j+1]);
//		puts("");
		printf("%d ", dp1[0]);
	}
	return 0;
}