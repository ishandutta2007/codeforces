#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 200200;
int a[maxn];
int aid[maxn];
int to[40];
vector<int> vals;
int pos[maxn];

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    vals.push_back(a[i]);
    pos[i] = n;
  }
  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());

  for (int i = 0; i < 40; ++i) {
    to[i] = n;
  }
  ll res = 0;
  for (int l = n - 1; l >= 0; --l) {
    pos[lower_bound(vals.begin(), vals.end(), a[l]) - vals.begin()] = l;
    for (int j = 0; j < 40; ++j) {
      if (a[l] & (1 << j))
        to[j] = l;
    }
    vector<pair<int, int>> rs;
    for (int j = 0; j < 31; ++j) {
      rs.emplace_back(to[j], j);
    }
    sort(rs.begin(), rs.end());
    int x = 0;
    int cur = 0;
    for (int j = 0; j < 30; ++j) {
      int bit = rs[j].second;
      int from = rs[j].first;
      int to = rs[j + 1].first;
      x |= 1 << bit;
      int id = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
      if (id == int(vals.size()) || vals[id] != x) {
        cur += to - from;
      } else {
        int bd = pos[id];
        cur += max(0, min(to, bd) - from);
      }
    }
    //cerr << cur << '\n';
    res += cur;
  }
  cout << res << '\n';
}