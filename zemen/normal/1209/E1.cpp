#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 12;
const int maxm = 2007;
vector<int> a[maxm];
int d[maxn + 1][1 << maxn];
int val[1 << maxn];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    a[i].resize(n);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[j][i];
    }
  }
  vector<pair<int, int>> vals;
  for (int i = 0; i < m; ++i) {
    vals.emplace_back(*max_element(a[i].begin(), a[i].end()), i);
  }
  sort(vals.rbegin(), vals.rend());
  vector<int> ids;
  for (int i = 0; i < min(m, n); ++i) {
    ids.push_back(vals[i].second);
  }
  for (int l = 0; l <= (int) ids.size(); ++l) {
    for (int i = 0; i < (1 << n); ++i) {
      d[0][i] = 0;
    }
  }
  for (int l = 0; l < (int) ids.size(); ++l) {
    for (int i = 0; i < (1 << n); ++i) {
      val[i] = 0;
      for (int j = 0; j < n; ++j) {
        if (i & (1 << j)) {
          val[i] += a[ids[l]][j];
        }
      }
    }
    for (int i = 0; i < (1 << n); ++i) {
      int m = i;
      for (int j = 0; j < 2 * n; ++j) {
        int to = m << 1;
        if (to >= (1 << n)) {
          to ^= (1 << n) ^ 1;
        }
        val[m] = max(val[m], val[to]);
        m = to;
      }
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
      d[l + 1][mask] = val[mask];
      for (int f = mask; f > 0; f = (f - 1) & mask) {
        d[l + 1][mask] = max(d[l + 1][mask], d[l][f] + val[mask ^ f]);
      }
    }
  }
  cout << d[(int) ids.size()][(1 << n) - 1] << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}