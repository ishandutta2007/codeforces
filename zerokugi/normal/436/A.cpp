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

int n, x;

int solve(vector<pii> &a, vector<pii> &b, int x){
	vector<int> ua(a.size()), ub(b.size());
	int ret = 0;
	while(1){
		int mx = -1;
		for(int i=0;i<a.size()&&a[i].first<=x;i++){
			if(ua[i]) continue;
			if(mx == -1 || a[mx].second < a[i].second) mx = i;
		}
		if(mx == -1) return ret;
		ret ++;
		x += a[mx].second;
		ua[mx] = 1;
		mx = -1;
		for(int i=0;i<b.size()&&b[i].first<=x;i++){
			if(ub[i]) continue;
			if(mx == -1 || b[mx].second < b[i].second) mx = i;
		}
		if(mx == -1) return ret;
		ret ++;
		x += b[mx].second;
		ub[mx] = 1;
	}
}

main(){
	scanf("%d%d", &n, &x);
	vector<pii> a, b;
	REP(i, n){
		int t, h, m;
		scanf("%d%d%d", &t, &h, &m);
		(t?a:b).push_back(pii(h, m));
	}
	sort(ALL(a));
	sort(ALL(b));
	printf("%d\n", max(solve(a, b, x), solve(b, a, x)));
	return 0;
}