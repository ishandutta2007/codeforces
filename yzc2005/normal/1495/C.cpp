#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m;
char s[N][N], t[N][N];
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      t[i][j] = s[i][j];
  for (int k = (n % 3 == 0) ? 2 : 1; k <= n; k += 3) {
    for (int j = 1; j <= m; ++j) t[k][j] = 'X';
    if (k + 3 <= n) {
      int pos = 1;
      for (int j = 1; j <= m; ++j)
        if (t[k + 1][j] == 'X' || t[k + 2][j] == 'X') pos = j;
      t[k + 1][pos] = t[k + 2][pos] = 'X';
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j)
      printf("%c", t[i][j]);
    puts("");
  }
}
int main() {
  int t; 
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}