#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, P = 998244353;
int n, x[N], y[N], s[N], f[N], sum, g[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d%d", &x[i], &y[i], &s[i]);
  for (int i = 1; i <= n; ++i) {
    int pos = upper_bound(x + 1, x + i + 1, y[i]) - x;
    if (pos == i) f[i] = (x[pos] - y[i]) % P;
    else f[i] = ((x[pos] - y[i] + (sum + P - g[pos]) % P) % P + x[i] - x[i - 1]) % P;
    sum = (sum + (f[i] + x[i] - x[i - 1]) % P) % P;
    g[i] = (sum - f[i] + P) % P;
  }
  int ans = (x[n] + 1) % P;
  for (int i = 1; i <= n; ++i) 
    if (s[i] == 1) ans = (ans + f[i]) % P;
  printf("%d\n", ans);
  return 0;
}