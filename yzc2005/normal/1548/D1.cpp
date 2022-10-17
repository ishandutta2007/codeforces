#include <bits/stdc++.h>
using namespace std;

const int N = 6005;
int n, x[N], y[N], sum[2][2];
long long ans;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &x[i], &y[i]), x[i] /= 2, y[i] /= 2;
  for (int i = 1; i <= n; ++i) {
    memset(sum, 0, sizeof sum);
    for (int j = n; j > i; --j) {
      int dx = abs(x[i] - x[j]) % 2, dy = abs(y[i] - y[j]) % 2;
      if (dx == 0 && dy == 0) {
        ans += n - j;
      } else if (dx == 1 && dy == 1) {
        ans += sum[0][0] + sum[1][1];
      } else if (dx == 0 && dy == 1) {
        ans += sum[0][0] + sum[0][1];
      } else {
        ans += sum[0][0] + sum[1][0];
      }
      ++sum[dx][dy];
    }
  }
  printf("%lld\n", ans);
  return 0;
}