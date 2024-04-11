#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

vector<int> p;
vector<pair<int, int>> res;
int n;

void fix_index(int i) {
  int a = i, b = p[i];
  if (abs(a - b) >= n / 2) {
    res.emplace_back(a, b);
  } else if (max(a, b) < n / 2) {
    res.emplace_back(a, n - 1);
    res.emplace_back(b, n - 1);
    res.emplace_back(a, n - 1);
  } else if (min(a, b) >= n / 2) {
    res.emplace_back(a, 0);
    res.emplace_back(b, 0);
    res.emplace_back(a, 0);
  } else {
    if (a > b) {
      swap(a, b);
    }
    res.emplace_back(a, n - 1);
    res.emplace_back(0, n - 1);
    res.emplace_back(0, b);
    res.emplace_back(0, n - 1);
    res.emplace_back(a, n - 1);
  }
  swap(p[a], p[b]);
};

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  cin >> n;
  p.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }
  for (int i = 0; i < n; ++i) {
    while (i != p[i]) {
      fix_index(i);
    }
  }
  for (int i = 0; i < n; ++i) {
    assert(i == p[i]);
  }
  cout << res.size() << '\n';
  for (auto p : res) {
    cout << p.first+1 << ' ' << p.second+1 << '\n';
  }
}