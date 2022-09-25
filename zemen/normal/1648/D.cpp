#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define int ll

const ll inf = 1e18;

struct Seg {
  int l, r;
  ll k;

  bool operator<(const Seg& s) const {
    if (r != s.r) {
      return r < s.r;
    }
    if (l != s.l) {
      return l < s.l;
    }
    return k < s.k;
  }
};

const int base = 1 << 19;
vector<ll> st(base * 2, -inf);

void put(int v, ll val) {
  v += base;
  st[v] = max(st[v], val);
  while (v > 1) {
    v /= 2;
    st[v] = max(st[v * 2], st[v * 2 + 1]);
  }
}

ll get_max(int l, int r, int v = 1, int cl = 0, int cr = base) {
  if (l <= cl && cr <= r) {
    return st[v];
  }
  if (r <= cl || cr <= l) {
    return -inf;
  }
  int cc = (cl + cr) / 2;
  return max(get_max(l, r, v * 2, cl, cc), get_max(l, r, v * 2 + 1, cc, cr));
}

ll rec(const vector<ll>& from, const vector<ll>& to, vector<Seg> seg, int cl = 0, int cr = base) {
  for (auto& s : seg) {
    s.l = max(s.l, cl);
    s.r = min(s.r, cr - 1);
  }
  sort(seg.begin(), seg.end());
  vector<Seg> nseg;
  nseg.reserve(seg.size());
  for (auto s : seg) {
    if (s.l > s.r) {
      continue;
    }
    if (nseg.empty() || s.l != nseg.back().l || s.r != nseg.back().r) {
      nseg.push_back(s);
    }
  }
  seg = nseg;
  if (seg.empty()) {
    return -inf;
  }

  ll res = -inf;
  if (cl + 1 == cr) {
    return from[cl] + to[cl] - seg.front().k;
  }
  const int cc = (cl + cr) / 2;

  {
    int l = min(cl, (int) from.size());
    int m = min(cc, (int) from.size());
    int r = min(cr, (int) from.size());
    vector<int> mx_from(m - l);
    vector<int> mx_to(r - m);

    ll vmax = -inf;
    for (int i = m; i < r; ++i) {
      vmax = max(vmax, to[i]);
      mx_to[i - m] = vmax;
    }

    vmax = -inf;
    for (int i = m - 1; i >= l; --i) {
      vmax = max(vmax, from[i]);
      mx_from[i - l] = vmax;
    }

    for (auto s : seg) {
      if (s.l >= m || s.r < m) {
        continue;
      }
      int sl = max(s.l, l);
      int sr = min(s.r, r - 1);
      res = max(res, mx_from[sl - l] + mx_to[sr - m] - s.k);
    }
  }

  auto resl = rec(from, to, seg, cl, cc);
  auto resr = rec(from, to, seg, cc, cr);

  return max({resl, resr, res});
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  array<vector<ll>, 3> a;
  for (int i = 0; i < 3; ++i) {
    a[i].resize(n);
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  vector<Seg> seg;
  for (int i = 0; i < q; ++i) {
    int l, r, k;
    cin >> l >> r >> k;
    --l, --r;
    seg.push_back(Seg{l, r, k});
  }
  vector<ll> s1 = a[0];
  vector<ll> s2 = a[1];
  for (int i = 1; i < n; ++i) {
    s1[i] += s1[i - 1];
    s2[i] += s2[i - 1];
  }

  for (int i = 0; i < n; ++i) {
    put(i, s1[i] + a[1][i] - s2[i]);
  }
  sort(seg.begin(), seg.end());
  for (auto s : seg) {
    int to = s.r + 1;
    if (to < n) {
      auto mx = get_max(s.l, s.r + 1);
      ll val = mx + s2[to] - s.k;
      put(to, val - s2[to]);
    }
  }
  vector<ll> from(n);
  for (int i = 0; i < n; ++i) {
    from[i] = st[i + base];
  }

  vector<ll> to = a[2];
  for (int i = n - 1; i > 0; --i) {
    to[i - 1] += to[i];
  }
  for (int i = 0; i < n; ++i) {
    to[i] += s2[i];
  }

  //for (int i = 0; i < n; ++i) {
    //cerr << from[i] + s2[i] << ' ';
    //cerr << from[i] << ' ';
  //}
  //cerr << '\n';
  //for (int i = 0; i < n; ++i) {
    //cerr << to[i] - s2[i] << ' ';
    //cerr << to[i] << ' ';
  //}
  //cerr << '\n';

  auto res = rec(from, to, seg);
  cout << res << '\n';
}