#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void fail() {
  cout << "NO\n";
  exit(0);
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  int n;
  cin >> n;

  vector<int> L, R;
  vector<int> ans;
  L.resize(n);
  R.resize(n);
  ans.resize(n, -1);
  for (int i = 0; i < n; ++i) {
    cin >> L[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> R[i];
  }
  for (int i = 0; i < n; ++i) {
    ans[i] = n - L[i] - R[i];
  }
  for (int i = 0; i < n; ++i) {
    int l1 = 0, r1 = 0;
    for (int l = 0; l < i; ++l) {
      l1 += ans[l] > ans[i];
    }
    for (int l = i + 1; l < n; ++l) {
      r1 += ans[l] > ans[i];
    }
    if (l1 != L[i] || r1 != R[i]) {
      fail();
    }
  }
  cout << "YES\n";
  for (int x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
}