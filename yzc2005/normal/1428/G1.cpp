#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, q, k, w[10];
long long f[N], g[N];
int main() {
  scanf("%d", &k);
  memset(f, 0xcf, sizeof(f));
  memset(g, 0xcf, sizeof(g));
  f[0] = g[0] = 0;
  for (int i = 1, pwr = 3; i <= 6; ++i, pwr *= 10) {
    scanf("%d", &w[i]);
    int cnt = min(k * 3, (N - 1) / pwr);
    for (int j = 0; j < 20 && cnt > 0; ++j) {
      int vol = min(cnt, 1 << j);
      cnt -= 1 << j;
      int x = vol * pwr;
      long long val = 1ll * vol * w[i];
      for (int v = N - 1; v >= x; --v) {
        f[v] = max(f[v], f[v - x] + val);
      }
    }
    cnt = min((k - 1) * 3, (N - 1) / pwr); 
    for (int j = 0; j < 20 && cnt > 0; ++j) {
      int vol = min(cnt, 1 << j);
      cnt -= 1 << j;
      int x = vol * pwr;
      long long val = 1ll * vol * w[i];
      for (int v = N - 1; v >= x; --v) {
        g[v] = max(g[v], g[v - x] + val);
      }
    }
  }
  scanf("%d", &q);
  while (q--) {
    int x;
    scanf("%d", &x);
    long long ans = f[x];
    for (int i = 0; i <= x; ++i) {
      long long cur = g[x - i], num = i;
      for (int j = 1; j <= 6; ++j) {
        int r = num % 10;
        cur += r % 3 ? 0 : 1ll * w[j] * (r / 3);
        num /= 10;
      }
      ans = max(ans, cur);
    }
    printf("%lld\n", ans);
  }
  return 0;
}