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

int n,m,k;
main(){
	scanf("%d%d%d", &n, &m, &k);
	vector<vi> l(n, vi(m, 0));
	vector<vi> r(n, vi(m, 0));
	vector<int> ans(m, 0);
	REP(i, n)REP(j, m){
		char c;
		scanf(" %c", &c);
		if(c == 'U' && ((i&1) == 0)) ans[j]++;
		if(c == 'L') l[i][j]++;
		if(c == 'R') r[i][j]++;
	}
	REP(i, m){
		REP(j, n){
			if(i-j>=0) ans[i] += r[j][i-j];
			if(i+j<m)  ans[i] += l[j][i+j];
		}
	}
	REP(i, m) printf("%d ", ans[i]);
	return 0;
}