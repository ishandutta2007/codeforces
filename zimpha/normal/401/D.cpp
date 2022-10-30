#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

char s[100];
vector<int> v[10];
int cnt[10];
LL dp[1<<18][110];
int N, M;

LL solve(int mask, int m) {
	if (mask + 1 == (1 << N)) return m == 0;
	if (dp[mask][m] != -1) return dp[mask][m];
	dp[mask][m] = 0;
	for (int i = 0; i < 10; ++ i) {
		if (cnt[i]) {
			if (!mask && i == 0) continue;
			cnt[i] --;
			dp[mask][m] += solve(mask | (1 << v[i][cnt[i]]), (m * 10 + i) % M);
			cnt[i] ++;
		}
	}
	return dp[mask][m];
}

int main() {
	scanf("%s%d", s, &M);
	N = strlen(s);
	for (int i = 0; i < 10; ++ i) cnt[i] = 0, v[i].clear();
	for (int i = 0; i < N; ++ i) {
		v[s[i] - '0'].push_back(i);
		cnt[s[i] - '0'] ++;
	}
	memset(dp, -1, sizeof(dp));
	printf("%I64d\n", solve(0, 0));
	return 0;
}