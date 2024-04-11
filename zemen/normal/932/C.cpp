#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  int n, a, b;
  cin >> n >> a >> b;
  for (int i = 0; i * a <= n; ++i) {
    int j = (n - i * a) / b;
    if (i * a + j * b != n) {
      continue;
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    auto it = p.begin();
    for (int ci = 0; ci < i; ++ci) {
      rotate(it, it + 1, it + a);
      it += a;
    }
    for (int cj = 0; cj < j; ++cj) {
      rotate(it, it + 1, it + b);
      it += b;
    }
    for (int i = 0; i < n; ++i) {
      cout << p[i] + 1 << ' ';
    }
    cout << '\n';
    return 0;
  }
  cout << -1 << '\n';
}