#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

vector<int> a;
vector<int> res;

int calc(int p) {
  if (res[p] != -1) {
    return res[p];
  }
  res[p] = 0;
  int x = a[p];
  for (int i = p % x; i < (int) a.size(); i += x) {
    if (a[i] <= x) {
      continue;
    }
    if (!calc(i)) {
      res[p] = 1;
    }
  }
  return res[p];
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  int n;
  cin >> n;
  a.resize(n);
  res.resize(n, -1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    calc(i);
  }
  for (int i = 0; i < n; ++i) {
    cout << "BA"[res[i]];
  }
  cout << '\n';
}