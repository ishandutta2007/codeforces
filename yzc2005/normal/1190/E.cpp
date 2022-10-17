#include <bits/stdc++.h>
using namespace std;
const int N = 200005, K = 18;
const double pi = acos(-1.0);
int n, m, f[N][K];
double x[N], y[N], d[N];
struct node {
  double l, r;
  inline bool operator < (const node &rhs) const {
    return l < rhs.l;
  }
} s[N];
inline bool check(double mid) {
  for (int i = 1; i <= n; ++i) {
    double dgr = atan2(y[i], x[i]), dlt = acos(mid / d[i]);
    s[i] = (node) {dgr - dlt, dgr + dlt};
    if (s[i].l < 0) {
      s[i].l += 2 * pi;
      s[i].r += 2 * pi;
    }
    s[i + n] = (node) {s[i].l + 2 * pi, s[i].r + 2 * pi};
  }
  sort(s + 1, s + n * 2 + 1);
  for (int i = n * 2, j = n * 2; i; --i) {
    for (; s[j].l > s[i].r; --j);
    f[i][0] = j + 1;
  }
  f[n * 2 + 1][0] = n * 2 + 1;
  for (int k = 1; k < K; ++k) {
    for (int i = 1; i <= n * 2 + 1; ++i) {
      f[i][k] = f[f[i][k - 1]][k - 1];
    }
  }
  for (int i = 1; i <= n; ++i) {
    int u = i;
    for (int k = 0; k < K; ++k) {
      if (m >> k & 1) {
        u = f[u][k];
      }
    }
    if (u >= i + n) {
      return 1;
    }
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  double l = 0, r = 1e100;
  for (int i = 1; i <= n; ++i) {
    scanf("%lf%lf", &x[i], &y[i]);
    r = min(r, d[i] = sqrt(x[i] * x[i] + y[i] * y[i]));
  }
  for (int t = 1; t <= 50; ++t) {
    double mid = (l + r) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  printf("%lf\n", l);
  return 0;
}