#include <bits/stdc++.h>

const int N = 2e5 + 5, M = 455;

int n, p[N], cnt;
std::vector<int> a[N], b[N];
int tag[N];

inline void work() {
  scanf("%d", &n), cnt = 0;
  for (int i = 1, m, x; i <= n; ++i) {
    a[i].clear(); scanf("%d", &m);
    while (m--) scanf("%d", &x), a[i].push_back(x), p[cnt++] = x;
  }
  std::sort(p, p + cnt), cnt = std::unique(p, p + cnt) - p;
  std::vector<int> bigger, smaller;
  for (int i = 1; i <= n; ++i) {
    for (auto &x : a[i]) x = std::lower_bound(p, p + cnt, x) - p;
    std::sort(a[i].begin(), a[i].end()), a[i].erase(std::unique(a[i].begin(), a[i].end()), a[i].end());
    a[i].size() < M ? smaller.push_back(i) : bigger.push_back(i);
  }
  memset(tag, 0, cnt << 2);
  for (auto i : bigger) {
    for (auto x : a[i]) tag[x] = 1;
    for (int j = 1; j <= n; ++j) if (j != i) {
      int cnt = 0;
      for (auto x : a[j]) cnt += tag[x];
      if (cnt >= 2) return void(printf("%d %d\n", i, j));
    }
    for (auto x : a[i]) tag[x] = 0;
  }
  for (int i = 0; i < cnt; ++i) b[i].clear();
  for (auto i : smaller) for (auto x : a[i]) b[x].push_back(i);
  for (int v = 0; v < cnt; ++v) {
    for (auto i : b[v]) {
      for (auto x : a[i]) if (x != v) {
        if (tag[x]) return void(printf("%d %d\n", tag[x], i));
        tag[x] = i;
      }
    } 
    for (auto i : b[v]) for (auto x : a[i]) tag[x] = 0;
  }
  puts("-1");
}

int main() {
  int t; scanf("%d", &t);
  while (t--) work();
  return 0;
}