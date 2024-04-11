#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void fail() {
  cout << "NO\n";
  exit(0);
}

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<pair<int, int>> s(n);
  vector<int> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i].first;
    s[i].second = i;
  }
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  vector<int> f, b;
  for (int i = 0; i < n; ++i) {
    if (s[i].first < t[i]) {
      f.push_back(i);
    } else if (s[i].first > t[i]) {
      b.push_back(i);
    }
  }
  reverse(b.begin(), b.end());
  struct M {
    int a, b, d;
  };
  vector<M> res;
  for (int id : f) {
    while (s[id].first < t[id]) {
      if (b.empty()) {
        fail();
      }
      int j = b.back();
      int delta = min(t[id] - s[id].first, s[j].first - t[j]);
      s[id].first += delta;
      s[j].first -= delta;
      if (s[id].first > s[j].first) {
        fail();
      }
      res.push_back(M{s[id].second, s[j].second, delta});
      if (s[j].first == t[j]) {
        b.pop_back();
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (s[i].first != t[i]) {
      fail();
    }
  }
  cout << "YES\n" << res.size() << '\n';
  for (auto m : res) {
    cout << m.a + 1 << ' ' << m.b + 1 << ' ' << m.d << '\n';
  }
}