#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int n, I;
  cin >> n >> I;
  int lim = (I * 8) / n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (lim > 30) {
    cout << 0 << '\n';
    return 0;
  }
  lim = 1 << lim;
  sort(a.begin(), a.end());
  vector<pair<int, int>> v;
  for (int i = 0; i < n; ++i) {
    int r = i + 1;
    while (r < n && a[r] == a[i]) {
      ++r;
    }
    v.emplace_back(a[i], r - i);
    i = r - 1;
  }
  int sum = 0;
  for (int i = 0; i < min((int) v.size(), lim); ++i) {
    sum += v[i].second;
  }
  int best = sum;
  for (int i = 1; i + lim <= (int) v.size(); ++i) {
    sum -= v[i - 1].second;
    sum += v[i - 1 + lim].second;
    best = max(best, sum);
  }
  cout << n - best << '\n';
}