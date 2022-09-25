#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct pt {
  ll p, q, r;
  int id;

  void norm() {
    if (q < 0) {
      q *= -1;
      p *= -1;
    }
  }

  bool operator<(const pt& o) const {
    ll s = p * o.q - q * o.p;
    if (s != 0) {
      return s < 0;
    }
    return r < o.r;
  }
};

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

ll naive(int n, ll w, vector<ll> x, vector<ll> v) {
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      ll p = x[i] - x[j];
      ll q = v[j] - v[i];
      if (q == 0) {
        continue;
      }
      if (q < 0) {
        q *= -1, p *= -1;
      }
      ll xp = llabs(x[i] * q + p * v[i]);
      res += xp <= p * w;
    }
  }
  return res;
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  ll w;
  cin >> n >> w;
  vector<pt> pl, pr;
  vector<ll> x(n), v(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> v[i];
    ll r1 = v[i] > 0 ? 1e9 - v[i] : -1e9 - v[i];
    ll r2 = v[i] > 0 ? -1e9 + v[i] : 1e9 + v[i];
    pl.push_back(pt{x[i], -w - v[i], r2, i});
    pr.push_back(pt{x[i], w - v[i], r1, i});
    pl.back().norm();
    pr.back().norm();
  }
  sort(pl.begin(), pl.end());
  sort(pr.begin(), pr.end());
  //for (auto x : pl) {
    //cerr << double(x.p) / x.q << ' ' << x.id << '\n';
  //}
  //for (auto x : pr) {
    //cerr << double(x.p) / x.q << ' ' << x.id << '\n';
  //}
  vector<int> pos(n);
  for (int i = 0; i < n; ++i) {
    pos[pr[i].id] = i;
  }
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = pos[pl[i].id];
  }
  Fenwick fw(n);
  ll res = 0;
  for (int i = n - 1; i >= 0; --i) {
    res += fw.get(p[i]);
    fw.add(p[i], 1);
  }
  cout << res << '\n';
#ifdef LOCAL
  ll res2 = naive(n, w, x, v);
  cerr << res2 << '\n';
  assert(res == res2);
#endif
}