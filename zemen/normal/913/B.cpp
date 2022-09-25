#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<int> ps(n);
  vector<bool> leaf(n, true);
  leaf[0] = false;
  vector<int> needles(n);
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    --p;
    ps[i] = p;
    leaf[p] = false;
  }
  for (int i = 1; i < n; ++i) {
    if (leaf[i]) {
      needles[ps[i]]++;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (needles[i] < 3 && !leaf[i]) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}