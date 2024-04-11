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
typedef pair<int, int> pii;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x)-1;i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

int n, m, s, e;

vector<int> Bpos[100001];

main(){
	scanf("%d%d%d%d", &n, &m, &s, &e);
	vector<int> a(n), b(m);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, m){
		scanf("%d", &b[i]);
		Bpos[b[i]].push_back(i);
	}
	int maxN = s / e;
	int ans = 0;
	vector<pii> dp(maxN+1, pii(-1, -1));
	dp[0] = pii(s, 0);
	REP(i, n+1)RREP(j, maxN+1){
		if(dp[j].first < 0) continue;
		if(dp[j].first - e > 0 && i<n){
			auto it = lower_bound(Bpos[a[i]].begin(), Bpos[a[i]].end(), dp[j].second);
			if(it != Bpos[a[i]].end() && (dp[j+1].second == -1 || 1+*it < dp[j+1].second)) dp[j+1] = pii(dp[j].first-e, 1+*it);
		}
//		printf("dp[%d][%d] = (%d, %d)\n", i, j, dp[j].first, dp[j].second);
		if(dp[j].first >= i + dp[j].second) ans = max(ans, j);
	}
	
	printf("%d\n", ans);
	return 0;
}