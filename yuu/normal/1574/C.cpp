#include <bits/stdc++.h>
using namespace std;
int n, m;
int64_t a[200001];
int64_t x, y;
int64_t sum;
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; i++)
    sum += a[i];
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    int pos = lower_bound(a, a + n - 1, x) - a;
    if (a[pos] <= x) {
      cout << x - a[pos] + max(0LL, y - (sum - a[pos])) << '\n';
    } else {
      int64_t ans = max(0LL, y - (sum - a[pos]));
      if (pos)
        ans = min(ans, x - a[pos - 1] + max(0LL, y - (sum - a[pos - 1])));
      cout << ans << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  //   cin >> t;
  while (t--)
    solve();
}