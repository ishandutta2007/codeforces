#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll d[15][100][15];

void pre() {
  for (int b = 2; b <= 10; ++b) {
    d[b][0][0] = 1;
    for (int i = 1; i < 70; ++i) {
      for (int j = 0; j <= b; ++j) {
        d[b][i][j] = d[b][i - 1][j - 1] * j + d[b][i - 1][j + 1] * (b - j);
      }
    }
  }
}

int b;
string l, r;

ll go(int i, bool el, bool er, bool ez, int mask) {
  if (i == int(l.size()) || (!el && !er && !ez)) {
    int j = __builtin_popcount(mask);
    ll res = d[b][int(l.size()) - i][j];
    //cerr << i << ' ' << "d " << int(l.size()) - i << ' ' << j << ' ' << res << '\n';
    return res;
  }
  ll res = 0;
  for (int d = 0; d < b; ++d) {
    if (el && d < l[i] - '0')
      continue;
    if (er && d > r[i] - '0')
      continue;
    bool nel = el && d == l[i] - '0';
    bool ner = er && d == r[i] - '0';
    bool nez = ez && d == 0;
    int nmask = mask;
    if (!nez)
      nmask ^= (1 << d);
    res += go(i + 1, nel, ner, nez, nmask);
  }
  return res;
}

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  pre();
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    ll il, ir;
    cin >> b >> il >> ir;
    l.clear();
    r.clear();
    while (ir) {
      r.push_back('0' + ir % b);
      ir /= b;
    }
    for (int iter = 0; iter < int(r.size()); ++iter) {
      l.push_back('0' + il % b);
      il /= b;
    }
    reverse(l.begin(), l.end());
    reverse(r.begin(), r.end());

    //cerr << l << ' ' << r << '\n';

    ll res = go(0, 1, 1, 1, 0);
    cout << res << '\n';
  }
}