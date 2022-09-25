#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int base = 1 << 18;
vector<set<int>> st(2 * base + 100);

void put(int v, int val) {
  v += base;
  while (v > 0) {
    st[v].insert(val);
    v /= 2;
  }
}

bool get(int l, int r, int ql, int qr, int v = 1, int cl = 0, int cr = base) {
  if (l <= cl && cr <= r) {
    auto it = st[v].lower_bound(ql);
    return it != st[v].end() && *it < qr;
  }
  if (r <= cl || cr <= l) {
    return false;
  }
  int cc = (cl + cr) / 2;
  return get(l, r, ql, qr, v * 2, cl, cc) ||
         get(l, r, ql, qr, v * 2 + 1, cc, cr);
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  set<int> s;
  for (int i = 0; i < n; ++i) {
    s.insert(i);
  }
  for (int i = 0; i < q; ++i) {
    int t;
    cin >> t;
    if (t == 0) {
      int l, r, x;
      cin >> l >> r >> x;
      --l;
      if (x == 0) {
        auto it = s.lower_bound(l);
        while (it != s.end() && *it < r) {
          it = s.erase(it);
        }
      } else {
        put(l, r);
      }
    } else {
      int p;
      cin >> p;
      --p;
      if (!s.count(p)) {
        cout << "NO\n";
      } else {
        auto it = s.find(p);
        auto nx = next(it);
        int l = it == s.begin() ? 0 : *prev(it) + 1;
        int r = nx == s.end() ? n : *nx;
        if (get(l, p + 1, p + 1, r + 1)) {
          cout << "YES\n";
        } else {
          cout << "N/A\n";
        }
      }
    }
  }
}