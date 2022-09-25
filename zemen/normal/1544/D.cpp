#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }
  vector<int> used(n, -1);
  vector<int> sos;
  vector<int> res(n, -1);
  for (int i = 0; i < n; ++i) {
    if (used[a[i]] == -1) {
      used[a[i]] = i;
      res[i] = a[i];
    } else {
      sos.push_back(i);
    }
  }
  vector<int> free;
  for (int i = 0; i < n; ++i) {
    if (used[i] == -1) {
      free.push_back(i);
    }
  }
  assert(sos.size() == free.size());
  if ((int) sos.size() == 1) {
    int x = sos[0];
    if (free[0] == x) {
      int y = used[a[x]];
      res[y] = x;
      res[x] = a[x];
    } else {
      res[x] = free[0];
    }
  } else {
    while (!free.empty()) {
      int k = (int) free.size();
      if (free.back() == sos.back() || (k == 2 && free[k - 2] == sos[k - 2])) {
        swap(free.back(), free[k - 2]);
      }
      assert(sos.back() != free.back());
      res[sos.back()] = free.back();
      free.pop_back();
      sos.pop_back();
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += a[i] == res[i];
  }
  cout << ans << '\n';
  for (int i = 0; i < n; ++i) {
    assert(res[i] != -1 && res[i] != i);
    cout << res[i] + 1 << ' ';
  }
  cout << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}