#include <bits/stdc++.h>
using namespace std;
int n;
int a[10001];
int f[2001];
int g[2001];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 0; i <= 2000; i++)
    f[i] = 1e9;
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 2000; j++) {
      g[j] = 1e9;
    }
    for (int j = 0; j <= 2000; j++) {
      if (j + a[i] <= 2000) {
        g[j + a[i]] = min(g[j + a[i]], max(f[j], j + a[i]));
      }
      if (j - a[i] >= 0) {
        g[j - a[i]] = min(g[j - a[i]], f[j]);
      } else {
        g[0] = min(g[0], f[j] - j + a[i]);
      }
    }
    for (int j = 0; j <= 2000; j++)
      f[j] = g[j];
  }
  cout << *min_element(f, f + 2001) << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}