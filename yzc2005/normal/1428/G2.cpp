#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n, q, k, w[10];
long long f[N];
int main() {
  scanf("%d", &k);
  memset(f, 0xcf, sizeof(f));
  f[0] = 0;
  for (int i = 1, pwr = 3; i <= 6; ++i, pwr *= 10) {
    scanf("%d", &w[i]);
    int cnt = min((k - 1) * 3, (N - 1) / pwr);
    for (int j = 0; j < 20 && cnt > 0; ++j) {
      int vol = min(cnt, 1 << j);
      cnt -= 1 << j;
      int x = vol * pwr;
      long long val = 1ll * vol * w[i];
      for (int v = N - 1; v >= x; --v) {
        f[v] = max(f[v], f[v - x] + val);
      }
    }
    for (int v = N - 1; ~v; --v) {
      for (int j = 1; j < 10; ++j) {
        int x = j * pwr / 3;
        long long val = j % 3 ? 0 : 1ll * (j / 3) * w[i];
        if (v >= x) {
          f[v] = max(f[v], f[v - x] + val);
        }
      }
    }
  }
  scanf("%d", &q);
  while (q--) {
    int x;
    scanf("%d", &x);
    printf("%lld\n", f[x]);
  }
  return 0;
}