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

int n, m;
int Map[4][1001][1001];
int dp[4][1001][1001][2];

int setdp(int t){
	REP(i, t&1?m:n)REP(j, t&1?n:m){
		int my = max(dp[t][i][j][0], dp[t][i][j][1]);
		if(my < 0) continue;
		if(i+1 < t&1?m:n) dp[t][i+1][j][0] = max(dp[t][i+1][j][0], my + Map[t][i][j]);
		if(j+1 < t&1?n:m) dp[t][i][j+1][1] = max(dp[t][i][j+1][1], my + Map[t][i][j]);
	}
}

main(){
	scanf("%d%d", &n, &m);
	REP(i, n)REP(j, m){
		int x;
		scanf("%d", &x);
		Map[0][i][j] = x;
		Map[1][m-j-1][i] = x;
		Map[2][n-i-1][m-j-1] = x;
		Map[3][j][n-i-1] = x;
	}
	memset(dp, -1, sizeof(dp));
	REP(i, 4)REP(j, 2) dp[i][0][0][j] = 0;
	REP(i, 4) setdp(i);
	int ans = 0;
/*	REP(k, 4)REP(i, n)REP(j, m){
		printf("%6d ", dp[k][i][j][0]);
		if(j == m-1) puts("");
	}
*/	REP(i, n)REP(j, m)REP(k, 2){
		if(!i || !j || i==n-1 || j==m-1) continue;
		int a = dp[0][i][j][k];
		int b = dp[1][m-j-1][i][k];
		int c = dp[2][n-i-1][m-j-1][k];
		int d = dp[3][j][n-i-1][k];
//		printf("%d %d %d\n", i, i, a+b+c+d);
		if(a>=0 && b>=0 && c>=0 && d>=0) ans = max(ans, a+b+c+d);
	}
	printf("%d\n", ans);
	return 0;
}