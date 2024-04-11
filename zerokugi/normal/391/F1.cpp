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
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)


ll n, k, x;
ll dp[3001][2];
const ll INF = 1LL<<62;
main(){
	while(cin >> n >> k){
		REP(i, k+1) dp[i][0] = dp[i][1] = -INF;
		dp[k][0] = 0;
		ll ans = 0;
		REP(i, n){
			cin >> x;
			REP(i, k){
				ans = max(ans, dp[i][0] = max(dp[i][0], dp[i  ][1] + x));
				ans = max(ans, dp[i][1] = max(dp[i][1], dp[i+1][0] - x));
			}
		}
		cout << ans << endl;
	}
	return 0;
}