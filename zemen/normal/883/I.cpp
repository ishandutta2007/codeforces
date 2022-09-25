#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

bool check(vector<int> a, int bd, int k) {
  int n = int(a.size());
  vector<int> d(n + 1);
  d[0] = 1;
  int p = 0;
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    //cerr << i << '\n';
    if (i >= k && i - p >= k) {
      //cerr << "add " << i - k << ' ' << d[i - k] << '\n';
      sum += d[i - k];
    }
    while (a[i - 1] - a[p] > bd) {
      if (i - p >= k) {
        //cerr << "rem " << p << ' ' << d[i - p] << '\n';
        sum -= d[p];
      }
      ++p;
    }
    d[i] = sum > 0;
  }
  return d[n];
}

signed main() {
#ifdef LOCAL
  assert(freopen("i.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int L = -1, R = 2e9;
  while (L + 1 < R) {
    int C = (L + R) / 2;
    if (check(a, C, k))
      R = C;
    else
      L = C;
  }
  cout << R << '\n';
}