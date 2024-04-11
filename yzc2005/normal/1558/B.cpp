#include <bits/stdc++.h>
using namespace std;
const int N = 4e6 + 5;
int pr[N / 6], tot, n, p, f[N];
int pp[20], qq[20], cnt; 
vector<int> d[N / 4], tmp;
void dfs(int x, int prod) {
  if (x == cnt + 1) {
    tmp.emplace_back(prod);
    return;
  }
  for (int j = 0; j <= qq[x]; ++j) {
    dfs(x + 1, prod);
    prod *= pp[x];
  }
}
vector<int> get(int x) {
  cnt = 0;
  auto div = d[x % 1000000];
  for (auto p : div) {
    pp[++cnt] = p, qq[cnt] = 0;
    while (x % p == 0) ++qq[cnt], x /= p;
  }
  tmp.clear(), dfs(1, 1);
  return tmp;
}
int main() {
  scanf("%d%d", &n, &p);
  for (int i = 2; i <= n; ++i) {
    if (!f[i]) pr[++tot] = i, f[i] = i;
    for (int j = 1; j <= tot && i * pr[j] <= n; ++j) {
      f[i * pr[j]] = pr[j];
      if (i % pr[j] == 0) break;
    }
  }
  f[1] = 1;
  int sum = 1, sum2 = 0;
  for (int i = 2; i <= n; ++i) {
    if (i % 1000000 == 2) {
      for (int j = 1; j <= tot; ++j) {
        int x = pr[j];
        for (int k = x; k <= min(n, i + 1000000); k += x)
          if (k >= i) d[k % 1000000].emplace_back(x);
      }
    }
    auto divs = get(i);
    for (auto x : divs) {
      if (x == 1) continue;
      int y = (i - 1) / x;
      sum2 = (sum2 - f[y] + p) % p;
    }
    for (auto x : divs) {
      if (x == 1) continue;
      int y = i / x;
      sum2 = (sum2 + f[y]) % p;
    }
    f[i] = (sum + sum2) % p;
    sum = (sum + f[i]) % p;
    d[i % 1000000].clear();
  }
  printf("%d\n", f[n]);
  return 0;
}