#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2000000 + 10, MOD = 1e9 + 7;

char s[MAXN];
LL dp[MAXN];
int last[26], n, k;

int main() {
  scanf("%d%d%s", &n, &k, s + 1);
  int m = strlen(s + 1);
  dp[0] = 0;
  for (int i = 0; i < k; ++i) last[i] = 0;
  for (int i = 1; i <= m; ++i) {
    int o = s[i] - 'a';
    if (last[o] == 0) dp[i] = (2 * dp[i - 1] + 1) % MOD;
    else dp[i] = (2 * dp[i - 1] % MOD + MOD - dp[last[o] - 1]) % MOD;
    last[o] = i;
  }
  for (int i = m + 1; i <= n + m; ++i) {
    int o = 0;
    for (int j = 0; j < k; ++j) {
      if (last[j] < last[o]) o = j;
    }
    if (last[o] == 0) dp[i] = (2 * dp[i - 1] + 1) % MOD;
    else dp[i] = (2 * dp[i - 1] % MOD + MOD - dp[last[o] - 1]) % MOD;
    last[o] = i;
  }
  printf("%lld\n", (dp[n + m] + 1) % MOD);
  return 0;
}