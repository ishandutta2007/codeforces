#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, a[N], t[N], v[N], p[N];
vector<int> ans[N];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    for (int cur = i - 1; ; cur = p[cur]) {
      if (t[cur] != a[i] - 1) continue;
      p[i] = cur, v[i] = ++t[cur]; break;
    }
  }
  for (int i = 1; i <= n; ++i) {
    ans[i] = ans[p[i]], ans[i].emplace_back(v[i]);
    for (int j = 0; j < ans[i].size() - 1; ++j) printf("%d.", ans[i][j]);
    printf("%d\n", ans[i].back());
  }
  for (int i = 0; i <= n; ++i) t[i] = p[i] = 0; 
}
int main() {
  int t;
  for (scanf("%d", &t); t; --t) solve();
  return 0;
}