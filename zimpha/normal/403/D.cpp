#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXN = 1000 + 10;
const int MOD = 1e9 + 7;

int part[MAXN][MAXN], fact[MAXN], binom[MAXN][MAXN];

int main() {
	memset(part, 0, sizeof(part));
	part[0][0] = 1;
	for (int i = 1; i < MAXN; ++ i) {
		for (int j = 1; j <= i; ++ j) {
			part[i][j] = part[i - j][j - 1] + part[i - j][j];
			if (part[i][j] >= MOD) part[i][j] -= MOD;
		}
	}
	fact[0] = 1;
	for (int i = 1; i < MAXN; ++ i) {
		fact[i] = (LL)fact[i - 1] * i % MOD;
	}
	memset(binom, 0, sizeof(binom));
	for (int i = 0; i < MAXN; ++ i) {
		binom[i][0] = 1;
		for (int j = 1; j <= i; ++ j) {
			binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
			if (binom[i][j] >= MOD) binom[i][j] -= MOD;
		}
	}
	int tests; scanf("%d", &tests);
	while (tests --) {
		int n, k; scanf("%d%d", &n, &k);
		int ret = 0;
		for (int sum = (k - 1) * k / 2; sum + k <= n; ++ sum) {
			ret += (LL)part[sum + k][k] * binom[n - sum][k] % MOD;
			if (ret >= MOD) ret -= MOD;
		}
		ret = (LL)ret * fact[k] % MOD;
		printf("%d\n", ret);
	}
	return 0;
}