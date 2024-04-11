#include <bits/stdc++.h>
const int N = 300005;
int n, a[N], f[N];
struct stack {
  int s[N], tp;
  std::function<bool(int, int)> cmp;
  inline int getval(int x) {
    int res = 1e9;
    for (; tp && cmp(s[tp], x); --tp) {
      res = std::min(res, f[s[tp]]);
    }
    if (a[s[tp + 1]] ^ a[x]) {
      res = std::min(res, f[s[tp]]);
    }
    return res;
  }
  inline void insert(int x) {
    s[++tp] = x;
  }
} max, min;
int main() {
  std::cin >> n;
  max.cmp = [&](int x, int y) {
    return a[x] <= a[y];
  };
  min.cmp = [&](int x, int y) {
    return a[x] >= a[y];
  };
  f[0] = 1e9;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    if (i > 1) {
      f[i] = std::min(max.getval(i), min.getval(i)) + 1;
    }
    max.insert(i);
    min.insert(i);
  }
  std::cout << f[n] << "\n";
  return 0;
}