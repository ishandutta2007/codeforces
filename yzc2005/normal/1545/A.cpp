#include <bits/stdc++.h>
const int N = 100005;
int t, n, a[N], c[N], cnt[N][2];
void solve() {
  scanf("%d", &n);
  std::vector<int> p;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    p.emplace_back(a[i]);
  }
  std::sort(p.begin(), p.end());
  p.erase(std::unique(p.begin(), p.end()), p.end());
  int m = p.size();
  for (int i = 1; i <= n; ++i) {
    a[i] = std::lower_bound(p.begin(), p.end(), a[i]) - p.begin();
    ++cnt[a[i]][i & 1];
  }
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) 
    --cnt[a[i]][i & 1];
  bool valid = true;
  for (int i = 0; i < m; ++i) {
    if (cnt[i][0] || cnt[i][1]) valid = false;
    cnt[i][0] = cnt[i][1] = 0; 
  }
  puts(valid ? "YES" : "NO");
}
int main() { 
  for (scanf("%d", &t); t; --t) solve();
  return 0;
}