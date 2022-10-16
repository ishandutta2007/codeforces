#include <bits/stdc++.h>
using namespace std;
int n, m, k;
char c[11][21];
char f[11][21];
void solve() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      cin >> c[i][j];
    c[i][m + 1] = '.';
  }

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      f[i][j] = '.';
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int d = 0;
      while (c[i - d][j - d] == '*' && c[i - d][j + d] == '*')
        d++;
    //   cerr<<i<<' '<<j<<' '<<d<<'\n';
      if (d > k) {
        for (int h = 0; h < d; h++) {
          f[i - h][j - h] = f[i - h][j + h] = '*';
        }
      }
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (f[i][j] != c[i][j]) {
        cout << "No\n";
        return;
      }
  cout << "Yes\n";
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