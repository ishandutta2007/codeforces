#include <bits/stdc++.h>
using namespace std;
const int N = 300005, K = 18;
int n, p[N], dp[N], tp[N];
int st[K][N], lg[N];
char s[N];
void solve() {
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
    lg[i] = lg[i >> 1] + 1;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
    st[0][i] = i + p[i]; 
  } 
  for (int k = 1; k <= lg[n]; ++k) {
    for (int i = 1; i + (1 << k) - 1 <= n; ++i) {
      st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << k - 1)]);
    }
  }
  auto query = [&](int l, int r) {
    if (l > r) {
      return 0;
    }
    int t = lg[r - l + 1];
    return max(st[t][l], st[t][r - (1 << t) + 1]);
  };
  for (int i = 1; i <= n; ++i) {
    dp[i] = 0;
    auto check = [&](int v, int t) {
      if (dp[i] < v) {
        dp[i] = v;
        tp[i] = t;
      }
    };
    check(dp[i - 1], -1);
    if (dp[i - 1] >= i) {
      check(i + p[i], -1);
    } 
    int k = lower_bound(dp, dp + i, i - p[i] - 1) - dp;
    if (k != i) {
      check(max(i - 1, query(k + 1, i - 1)), k);
    }
  }
  if (dp[n] < n) {
    puts("NO");
  } else {
    puts("YES");
    for (int i = n; i; ) {
      if (tp[i] == -1) {
        s[i] = 'R';
        --i;
      } else {
        s[i] = 'L';
        int k = tp[i];
        for (int j = k + 1; j < i; ++j) {
          s[j] = 'R';
        }
        i = k;
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%c", s[i]);
    }
    puts("");
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}