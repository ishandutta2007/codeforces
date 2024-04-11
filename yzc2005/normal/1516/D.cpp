#include <bits/stdc++.h>
using namespace std;
const int N = 100005, K = 17;
int n, q, a[N], to[N][K], cnt[N];
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int k = 1; k <= n; ++k) {
    to[k][0] = to[k - 1][0];
    for (int i = to[k][0] + 1; i <= n; ++i) {
      int x = a[i];
      vector<int> tmp;
      for (int j = 2; j * j <= a[i]; ++j) {
        if (x % j == 0) {
          tmp.emplace_back(j);
          while (x % j == 0) {
            x /= j;
          }
        }
      }
      if (x > 1) {
        tmp.emplace_back(x);
      }
      bool flag = 1;
      for (auto x : tmp) {
        if (cnt[x]) {
          flag = 0;
        }
      }
      if (!flag) {
        break;
      }
      ++to[k][0];
      for (auto x : tmp) {
        ++cnt[x];
      }
    }
    int x = a[k];
    for (int j = 2; j * j <= a[k]; ++j) {
      if (x % j == 0) {
        --cnt[j];
        while (x % j == 0) {
          x /= j;
        }
      }
    }
    if (x > 1) {
      --cnt[x];
    }
  }
  to[n + 1][0] = n + 1;
  for (int i = 1; i <= n; ++i) ++to[i][0];
  for (int k = 1; k < K; ++k)
    for (int i = 1; i <= n + 1; ++i) {
      to[i][k] = to[to[i][k - 1]][k - 1];
    }
  while (q--) {
    int l, r; 
    scanf("%d%d", &l, &r);
    int ans = 0;
    for (int k = K - 1; ~k; --k) {
      if (to[l][k] <= r) {
        ans |= 1 << k;
        l = to[l][k];
      }
    }
    printf("%d\n", ans + 1);
  }
  return 0;
}