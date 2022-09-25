#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  struct ByP {
    int p;
    vector<ll> vals;
    multiset<ll> sorted;

    ll calc() const {
      return *sorted.rbegin() * (int) vals.size();
    }
  };
  vector<ByP> ps;
  for (int x = 2; x <= n; ++x) {
    if (n % x) {
      continue;
    }
    bool good = true;
    for (auto& p : ps) {
      if (x % p.p == 0) {
        good = false;
        break;
      }
    }
    if (good) {
      ps.push_back(ByP{x, {}, {}});
    }
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (auto& st : ps) {
    st.vals.resize(n / st.p);
    for (int r = 0; r < n / st.p; ++r) {
      for (int i = 0; i < st.p; ++i) {
        st.vals[r] += a[i * (n / st.p) + r];
      }
    }
    for (int i = 0; i < (int) st.vals.size(); ++i) {
      st.sorted.insert(st.vals[i]);
    }
  }
  ll res = 0;
  for (auto& p : ps) {
    res = max(res, p.calc());
  }
  cout << res << '\n';
  for (int ii = 0; ii < q; ++ii) {
    int p, v;
    cin >> p >> v;
    --p;
    ll delta = v - a[p];
    a[p] = v;
    for (auto& st : ps) {
      int i = p % (int) st.vals.size();
      auto it = st.sorted.find(st.vals[i]);
      assert(it != st.sorted.end());
      st.sorted.erase(it);
      st.vals[i] += delta;
      st.sorted.insert(st.vals[i]);
    }
    res = 0;
    for (auto& p : ps) {
      res = max(res, p.calc());
    }
    cout << res << '\n';
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}