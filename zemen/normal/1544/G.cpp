#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

vector<pair<int, int>> solve1(int k, string& s) {
  if (k == 0) {
    return {};
  }

  vector<int> a;
  int block = 0;
  for (int i = 0; i < (int) s.size(); ++i) {
    if (s[i] == '0') {
      ++block;
    } else {
      a.push_back(block);
      block = 0;
    }
  }
  a.push_back(block);
  int m = (int) a.size();

  vector<pair<int, int>> ops;
  auto op = [&](int l, int r, int sh) {
    //cerr << "op " << l << ' ' << r << ' ' << sh << '\n';
    assert(0 <= l && l < r && r < m);
    assert(r - l == k);
    int lb = 0;
    for (int i = 0; i < l; ++i) {
      lb += a[i] + 1;
    }
    if (sh != +1) {
      lb += a[l];
    }
    int rb = (int) s.size();
    for (int i = r + 1; i < m; ++i) {
      rb -= a[i] + 1;
    }
    if (sh != -1) {
      rb -= a[r];
    }
    assert(lb < rb);
    int cnt1 = 0;
    for (int i = lb; i < rb; ++i) {
      cnt1 += s[i] == '1';
    }
    assert(cnt1 == k);

    reverse(s.begin() + lb, s.begin() + rb);
    reverse(a.begin() + l + 1, a.begin() + r);
    if (sh == +1) {
      a[r] += a[l];
      a[l] = 0;
    } else if (sh == -1) {
      a[l] += a[r];
      a[r] = 0;
    }
    ops.emplace_back(lb, rb);
  };

  for (int r = (int) a.size() - 1; r - k >= 0; --r) {
    op(r - k, r, -1);
  }
  if (k == m - 1) {
    assert(m >= 2);
    vector<int> b = a;
    reverse(b.begin() + 1, b.end() - 1);
    if (b < a) {
      op(0, k, 0);
    }
  }

  if (k < m - 1) {
    for (int i = 0; i < k - 1; ++i) {
      if (i % 2 == 0) {
        op(1, k + 1, +1);
      } else {
        op(0, k, -1);
      }
    }
    if (k % 2 == 1) {
      for (int i = 0; i < k + 1; ++i) {
        if (i % 2 == 0) {
          op(1, k + 1, -1);
        } else {
          op(0, k, -1);
        }
      }
    }
  }

  return ops;
}

void solve(string a, string b, int k) {
  auto ops = solve1(k, a);
  auto ops2 = solve1(k, b);
  if (a != b) {
    cout << -1 << '\n';
    return;
  }
  reverse(ops2.begin(), ops2.end());
  ops.insert(ops.end(), ops2.begin(), ops2.end());
  //cerr << "ops: " << ops.size() << '\n';
  if ((int) ops.size() > 4 * (int) a.size()) {
    while (true);
  }
  cout << ops.size() << '\n';
  for (auto [l, r] : ops) {
    cout << l + 1 << ' ' << r << '\n';
  }
}

void stress() {
  mt19937 rnd(1337);
  while (true) {
    int n = 1 + rnd() % 10;
    string a;
    for (int i = 0; i < n; ++i) {
      a += '0' + rnd() % 2;
    }
    string b = a;
    shuffle(b.begin(), b.end(), rnd);
    int k = 1 + rnd() % 10;
    cout << a << ' ' << b << ' ' << k << endl;
    solve(a, b, k);
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("g.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  //stress();
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    int n, k;
    string a, b;
    cin >> n >> k >> a >> b;
    solve(a, b, k);
  }
}