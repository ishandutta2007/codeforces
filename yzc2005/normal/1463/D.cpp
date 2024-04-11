#include <bits/stdc++.h>
const int N = 4e5 + 5;
int n, b[N];
bool used[N];
int calc() {
  std::set<int> s;
  memset(used, 0, sizeof used);
  for (int i = 1; i <= n; ++i) used[b[i]] = true;
  for (int i = 1; i <= 2 * n; ++i) if (!used[i]) s.insert(i);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (*s.begin() > b[i]) continue;
    ++ans, s.erase(s.begin());
  }
  return ans;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
    std::sort(b + 1, b + n + 1);
    int l = calc();
    for (int i = 1; i <= n; ++i) b[i] = 2 * n - b[i] + 1;
    std::reverse(b + 1, b + n + 1);
    int r = n - calc();
    printf("%d\n", abs(r - l) + 1);
  }
}