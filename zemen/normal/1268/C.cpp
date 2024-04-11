#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template<typename T>
using oset = __gnu_pbds::tree<T, __gnu_pbds::null_type,
        std::less<T>,
        __gnu_pbds::rb_tree_tag,
        __gnu_pbds::tree_order_statistics_node_update>;

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct Fenwick {
  vector<ll> t, a;

  Fenwick(int n) : t(n), a(n) {
  }

  void add(int pos, ll delta) {
    assert(0 <= pos && pos < (int) t.size());
    a[pos] += delta;
    for (int i = pos; i < (int) t.size(); i |= i + 1) {
      t[i] += delta;
    }
  }

  void set(int pos, ll val) {
    add(pos, val - a[pos]);
  }

  ll get(int r) {
    ll res = 0;
    for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1) {
      res += t[i];
    }
    return res;
  }

  ll get(int l, int r) {
    return get(r) - get(l);
  }
};

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> p(n);
  vector<int> pos(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
    pos[p[i]] = i;
  }
  oset<int> s;
  Fenwick f(n);
  ll inv = 0;
  vector<ll> res;
  for (int k = 0; k < n; ++k) {
    int ord = f.get(pos[k]);
    inv += k - ord;
    f.add(pos[k], 1);

    inv -= min(ord, k - ord);
    if (ord * 2 == k) {
    } else if (ord < (k + 1) / 2) {
      int to = (k - 1) / 2;
      int p = *s.find_by_order(to);
      assert(p > pos[k]);
      inv += p - pos[k] - f.get(pos[k], p);
    } else {
      int to = k / 2;
      int p = *s.find_by_order(to);
      assert(pos[k] > p);
      inv += pos[k] - p - f.get(p, pos[k]);
    }

    s.insert(pos[k]);
    res.push_back(inv);
  }

  for (auto x : res) {
    cout << x << ' ';
  }
  cout << '\n';
}