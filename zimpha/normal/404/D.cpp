#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
const int MAXN = 1000000 + 10;
const int MOD = 1e9 + 7;

LL dp[MAXN][5];
char st[MAXN];
int n;

int main() {
	scanf("%s", st + 1);
	n = strlen(st + 1);
	if (n == 1) {
		if (st[1] == '?') puts("2");
		else if (st[1] == '0' || st[1] == '*') puts("1");
		else puts("0");
	}
	else {
		memset(dp[1], 0, sizeof(dp[1]));
		if (st[1] == '?') {
			dp[1][0] = dp[1][2] = dp[1][4] = 1;
		}
		else {
			if (st[1] == '0') dp[1][0] = 1;
			if (st[1] == '1') dp[1][2] = 1;
			if (st[1] == '*') dp[1][4] = 1;
		}
		for (int i = 2; i <= n; ++ i) {
			memset(dp[i], 0, sizeof(dp[i]));
			if (st[i] == '?') {
				dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
				dp[i][1] = dp[i - 1][4];
				if (i < n) {
					dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
					dp[i][3] = dp[i - 1][4];
				}
				dp[i][4] = (dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4]) % MOD;
			}
			else if (st[i] == '0') {
				dp[i][0] = (dp[i - 1][0] + dp[i  -1][1]) % MOD;
			}
			else if (st[i] == '1') {
				dp[i][1] = dp[i - 1][4];
				if (i < n) dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
			}
			else if (st[i] == '2') {
				if (i < n) dp[i][3] = dp[i - 1][4];
			}
			else if (st[i] == '*') {
				dp[i][4] = (dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4]) % MOD;
			}
		}
		LL ret = 0;
		for (int i = 0; i < 5; ++ i)
			ret = (ret + dp[n][i]) % MOD;
		printf("%d\n", (int)ret);
	}
	return 0;
}