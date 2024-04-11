#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  vector<pair<int, int>> b(n);
  vector<int> res(n);
  forn (i, n) {
    cin >> a[i].first;
    a[i].second = i;
  }
  forn (i, n) {
    cin >> b[i].first;
    b[i].second = i;
  }
  sort(all(a));
  sort(all(b));
  reverse(all(a));
  forn (i, n) {
    res[b[i].second] = a[i].first;
  }
  forn (i, n)
    cout << res[i] << ' ';
  cout << '\n';
}