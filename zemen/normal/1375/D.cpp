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
  }
  vector<int> op;
  while (true) {
    vector<char> used(n + 1);
    for (int i = 0; i < n; ++i) {
      used[a[i]] = true;
    }
    int mex = 0;
    while (used[mex]) {
      ++mex;
    }
    int id = -1;
    if (mex > 0) {
      id = mex - 1;
    } else {
      for (int i = 0; i < n; ++i) {
        if (a[i] != i + 1) {
          id = i;
        }
      }
    }
    if (id == -1) {
      break;
    }
    op.push_back(id);
    a[id] = mex;
  }
  assert((int) op.size() <= 2 * n);
  for (int i = 0; i < n; ++i) {
    assert(a[i] == i + 1);
  }
  cout << op.size() << '\n';
  for (int x : op) {
    cout << x + 1 << ' ';
  }
  cout << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}