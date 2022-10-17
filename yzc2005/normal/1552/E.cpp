#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, k, c[N * N];
pair<int, int> ans[N];
vector<int> pos[N];
bool vis[N];

void solve() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n * k; ++i) scanf("%d", &c[i]);
  for (int i = n * k; i; --i) pos[c[i]].emplace_back(i);
  auto solve = [&](int l, int r) {
    for (int tt = l; tt <= r; ++tt) {
      int cur = 1e9, curr;
      for (int i = l; i <= r; ++i) {
        if (vis[i]) continue;
        assert(pos[i].size() >= 2);
        int tmp = pos[i][pos[i].size() - 2];
        if (cur > tmp) cur = tmp, curr = i;
      }
      vis[curr] = true;
      ans[curr] = make_pair(pos[curr].back(), cur);
      for (int i = l; i <= r; ++i) {
        if (vis[i]) continue;
        while (pos[i].back() <= cur) pos[i].pop_back(); 
      }
    }
  };
  for (int i = 1, j; i <= n; i = j + 1) 
    j = min(i + k - 2, n), solve(i, j);
  for (int i = 1; i <= n; ++i) printf("%d %d\n", ans[i].first, ans[i].second);
}

int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}