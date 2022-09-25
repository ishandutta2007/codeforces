#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct E {
  int state_update = -1;
  string col0, col1;

  E() {}

  E(string s) {
    if (s == "lock") {
      state_update = 1;
    } else if (s == "unlock") {
      state_update = 0;
    } else {
      col0 = s;
    }
  }

  E(const E& a, const E& b) {
    state_update = b.state_update == -1 ? a.state_update : b.state_update;
    if (!b.col1.empty()) {
      col1 = b.col1;
    } else if (!b.col0.empty() && a.state_update == 0) {
      col1 = b.col0;
    } else {
      col1 = a.col1;
    }
    if (!b.col1.empty()) {
      col0 = b.col1;
    } else if (!b.col0.empty() && a.state_update != 1) {
      col0 = b.col0;
    } else {
      col0 = a.col0;
    }
  }
};

const int base = 1 << 17;
vector<E> t(base * 2);

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  t[base] = E("blue");
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    t[i + base + 1] = E(s);
  }
  for (int i = base - 1; i > 0; --i) {
    t[i] = E(t[i * 2], t[i * 2 + 1]);
  }
  cout << t[1].col0 << '\n';
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int pos;
    string s;
    cin >> pos >> s;
    int v = pos + base;
    t[v] = s;
    while (v > 1) {
      v /= 2;
      t[v] = E(t[v * 2], t[v * 2 + 1]);
    }
    cout << t[1].col0 << '\n';
  }
}