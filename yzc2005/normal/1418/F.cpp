#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int k = max(n, m);
  vector<vector<int>> d(k + 1);
  for (int i = 1; i <= k; ++i) {
    for (int j = i; j <= k; j += i) {
      d[j].push_back(i);
    }
  }
  long long l, r;
  scanf("%lld%lld", &l, &r);
  set<int> s;
  vector<int> cnt(k + 1, 0);
  int L = m, R = m;
  for (int x = 1; x <= n; ++x) {
    long long nL = (l - 1) / x + 1, nR = r / x;
    for (; L >= nL; --L) {
      for (auto x : d[L]) {
        if (!cnt[x]++) {
          s.insert(x);
        }
      }
    }
    for (; R > nR; --R) {
      for (auto x : d[R]) {
        if (!--cnt[x]) {
          s.erase(x);
        }
      }
    } 
    bool ok = 0;
    for (auto a : d[x]) {
      set<int>::iterator it = s.upper_bound(a);
      if (it != s.end()) {
        int b = *it;
        if (1ll * x / a * b <= n) {
          int y = (L / b + 1) * b;
          printf("%d %d %d %d\n", x, y, x / a * b, y / b * a); 
          ok = 1;
          break; 
        }
      }
    }
    if (!ok) {
      puts("-1");
    }
  }
  return 0;
}