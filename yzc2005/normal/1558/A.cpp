#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b;
  scanf("%d%d", &a, &b);
  int n = a + b;
  int c0 = (n + 1) / 2, c1 = n - c0;
  vector<int> ans;
  auto solve = [&]() {
    for (int i = 0; i <= min(b, c0); ++i) {
      int cur = i;
      int rest = b - i;
      if (rest > c1) continue;
      cur += c1 - rest;
      ans.emplace_back(cur);
    }
  };
  solve();
  swap(a, b);
  solve();
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i)
    printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
}
int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}