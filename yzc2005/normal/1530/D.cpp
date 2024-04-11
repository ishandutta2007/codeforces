#include <bits/stdc++.h>
const int N = 2e5 + 5;
int t, n, a[N], b[N];
std::vector<int> g[N];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) g[i].clear(), b[i] = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    g[a[i]].emplace_back(i);
  }
  int k = 0;
  std::set<int> cur;
  for (int i = 1; i <= n; ++i) k += !g[i].empty(), cur.insert(i);
  printf("%d\n", k);
  if (k == n - 1) {
    for (int i = 1; i <= n; ++i) {
      if (!g[i].empty()) continue;
      int j = a[i];
      b[i] = j, cur.erase(j);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (b[i]) continue;
    int j = a[i];
    if (cur.count(j)) b[i] = j, cur.erase(j);
  } 
  for (int i = 1; i <= n; ++i) {
    if (b[i] || !cur.count(i)) continue;
    auto it = cur.begin();
    if (*it == i) ++it;
    b[i] = *it, cur.erase(it);
  }
  for (int i = 1; i <= n; ++i) {
    if (b[i]) continue;
    auto it = cur.begin();
    b[i] = *it, cur.erase(it);
  }
  for (int i = 1; i <= n; ++i) printf("%d%c", b[i], " \n"[i == n]);
}
int main() {
  scanf("%d", &t); while (t--) solve();
  return 0;
}