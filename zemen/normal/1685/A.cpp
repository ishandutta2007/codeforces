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
  if (n % 2) {
    cout << "NO\n";
    return;
  }
  vector<int> b(n);
  sort(a.begin(), a.end());
  for (int i = 0; i < n / 2; ++i) {
    b[i * 2] = a[i];
  }
  for (int i = n / 2; i < n; ++i) {
    b[(i - n / 2) * 2 + 1] = a[i];
  }
  //for (int x : b) {
    //cerr << x << ' ';
  //}
  //cerr << '\n';
  for (int i = 0; i < n; i += 2) {
    if (b[i] >= b[i + 1] || b[i] >= b[(i + n - 1) % n]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  for (int x : b) {
    cout << x << ' ';
  }
  cout << '\n';
}
  
signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}