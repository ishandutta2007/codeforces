#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  map<int, vector<int>> pos;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    pos[a[i]].push_back(i);
  }
  vector<int> mxr(n + 1, -1);
  for (int j = 0; j < m; ++j) {
    int l, r;
    cin >> l >> r;
    --l;
    mxr[l] = max(mxr[l], r);
  }
  for (int i = 0; i < n - 1; ++i) {
    mxr[i + 1] = max(mxr[i + 1], mxr[i]);
  }
  int L = n, R = -1;
  bool good = true;
  vector<pair<int, int>> c;
  for (auto& [x, xpos] : pos) {
    int k = (int) xpos.size();
    int r = -1;
    for (int l = 0; l < k; ++l) {
      while (r + 1 < k && mxr[xpos[l]] > xpos[r + 1]) {
        ++r;
      }
      if (l < r) {
        good = false;
        L = min(L, xpos[l + 1]);
        R = max(R, xpos[r - 1]);
        //cerr << "chain";
        //for (int i = l; i <= r; ++i) {
          //cerr << ' ' << xpos[i];
        //}
        //cerr << '\n';
        c.emplace_back(xpos[l], xpos[r]);
      }
    }
  }
  if (good) {
    cout << 0 << '\n';
    return;
  }
  int best = n;
  sort(c.rbegin(), c.rend());
  for (int l = 0; l <= L; ++l) {
    best = min(best, R - l + 1);
    while (!c.empty() && c.back().first == l) {
      R = max(R, c.back().second);
      c.pop_back();
    }
  }
  cout << best << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}