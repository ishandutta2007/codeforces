#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void build(int n) {
  if (n == 2) {
    cout << -1 << '\n';
    return;
  }

  int k = 1;
  while (k * k < n) {
    ++k;
  }
  if (k * k == n + 2) {
    ++k;
  }
  int s = (k * k - n) % 2 ? 1 : 0;
  while (k * k - (s + 2) * (s + 2) >= n) {
    s += 2;
  }
  vector<string> res(k, string(k, 'o'));
  for (int i = 0; i < s; ++i) {
    for (int j = 0; j < s; ++j) {
      res[i][k - j - 1] = '.';
    }
  }
  int rem = k * k - s * s - n;
  assert(rem % 2 == 0);
  for (int i = 0; i < s; ++i) {
    for (int j = k - s - 1; j > 0; --j) {
      if (rem > 0) {
        rem -= 2;
        assert(i != j);
        res[i][j] = res[k - j - 1][k - i - 1] = '.';
      }
    }
  }
  assert(rem == 0);
  cout << k << '\n';
  for (auto& t : res) {
    cout << t << '\n';
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  int n;
  cin >> n;
  build(n);
}