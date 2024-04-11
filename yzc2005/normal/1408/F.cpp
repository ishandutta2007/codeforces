#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> ans;
vector<int> v, r;
void solve(vector<int> v) {
  int n = v.size();
  if (n == 1) {
    return;
  }
  vector<int> lef, rig;
  for (int i = 0; i < n / 2; ++i) {
    lef.push_back(v[i]);
    rig.push_back(v[n / 2 + i]);
  }
  solve(lef);
  solve(rig);
  for (int i = 0; i < n / 2; ++i) {
    ans.push_back({lef[i], rig[i]});
  }
}
int main() {
  int n, m;
  scanf("%d", &n);
  for (m = 1; m * 2 < n; m *= 2);
  for (int i = 1; i <= m; ++i) {
    v.push_back(i);
  }
  solve(v);
  v.clear();
  for (int i = n - m + 1; i <= n; ++i) {
    v.push_back(i);
  }
  solve(v);
  printf("%d\n", ans.size());
  for (auto x : ans) {
    printf("%d %d\n", x.first, x.second);
  }
  return 0;
}