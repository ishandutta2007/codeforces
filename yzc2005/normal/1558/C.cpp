#include <bits/stdc++.h>
using namespace std;
const int N = 2050;
int n, a[N], p[N];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) {
    if ((a[i] & 1) != (i & 1)) {
      puts("-1");
      return;
    }
    p[a[i]] = i;
  }
  vector<int> ans;
  auto add = [&](int x) {
    ans.emplace_back(x);
    reverse(a + 1, a + x + 1);
    for (int i = 1; i <= x; ++i) p[a[i]] = i;    
  };
  for (int i = n; i > 1; i -= 2) {
    add(p[i]);
    add(p[i - 1] - 1);
    add(p[i - 1] + 1);
    add(p[i]);
    add(i);
  }
  for (int i = 1; i <= n; ++i) assert(a[i] == i);
  assert(ans.size() <= (5 * n / 2));
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i)
    printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
}
int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}