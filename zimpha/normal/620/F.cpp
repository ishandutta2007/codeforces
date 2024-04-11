#include <bits/stdc++.h>
using namespace std;
const int N = 50000 + 10, S = 1000000 + 10;

int s[S], a[N], b[N], f[N];
int x[N], y[N], z[N];;

int main() {
  for (int i = 1; i < S; ++ i) s[i] = s[i - 1] ^ i;
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++ i) {
    scanf("%d", a + i);
    f[i] = s[a[i]];
  }
  for (int i = 0; i < m; ++ i) {
    scanf("%d%d", &x[i], &y[i]);
    -- x[i]; -- y[i];
  }
  for (int i = 0; i < n; ++ i) {
    int mx = 0;
    for (int j = i; j < n; ++ j) {
      int tmp = f[i] ^ f[j] ^ (a[i] < a[j] ? a[i] : a[j]);
      mx = max(mx, tmp); b[j] = mx;
    }
    for (int k = 0; k < m; ++ k) {
      if (x[k] <= i && i <= y[k]) {
        z[k] = max(z[k], b[y[k]]);
      }
    }
  }
  for (int i = 0; i < m; ++ i) printf("%d\n", z[i]);
  return 0;
}