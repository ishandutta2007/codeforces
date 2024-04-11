#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

vector<int> a;
const int inf = 1e9;

using State = array<int, 4>;

void uax(int& a, int b) {
  a = max(a, b);
}

State rec(int l, int r) {
  //cerr << "rec " << l << ' ' << r << '\n';
  if (l + 2 == r) {
    State s{{0, -inf, -inf, -inf}};
    if (a[l] + a[l + 1] > 0) {
      s[1] = s[2] = 1;
    }
    if (a[l] + a[l + 1] == 2) {
      s[3] = 1;
    }
    return s;
  }
  int m = (l + r) / 2;
  State a = rec(l, m);
  State b = rec(m, r);
  State res{{0, -inf, -inf, -inf}};
  for (int ma = 0; ma < 4; ++ma) {
    for (int mb = 0; mb < 4; ++mb) {
      int add = __builtin_popcount(ma | mb);
      if (add == 2) {
        uax(res[3], a[ma] + b[mb] + add + 1);
      }
      if (ma == 0 && mb == 0) {
        uax(res[0], a[ma] + b[mb] + add);
      }
      if (ma < 2 && mb < 2 && ma + mb > 0) {
        uax(res[1], a[ma] + b[mb] + add);
      }
      if (ma + mb > 0) {
        uax(res[2], a[ma] + b[mb] + add + 1);
      }
      if (ma == 1 && mb == 1) {
        uax(res[3], a[ma] + b[mb] + add + 1);
      }
    }
  }
  return res;
}

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n, k;
  cin >> n >> k;
  a.resize(1 << n);
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    --x;
    a[x] = 1;
  }
  auto s = rec(0, 1 << n);
  int res = 0;
  for (int i = 0; i < 4; ++i) {
    res = max(res, s[i] + (i > 0));
  }
  cout << res << '\n';
}