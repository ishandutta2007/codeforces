#include <bits/stdc++.h>
using namespace std;
const int N = 55;
char s[N][N];
int T, n, m;
void solve() {
  scanf("%d%d", &n, &m);
  int r = -1, w = -1;
  bool valid = true;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s[i] + 1);
    for (int j = 1; j <= m; ++j) {
      int cur = (i + j) & 1;
      if (s[i][j] == 'R') {
        if (~r && r != cur) valid = false;
        else r = cur;
      } else if (s[i][j] == 'W') {
        if (~w && w != cur) valid = false;
        else w = cur;
      }
    }
  }
  if (~r && r == w || !valid) return puts("NO"), void();
  if (r == -1 && w == -1) r = 0, w = 1;
  else if (r == -1) r = 1 - w;
  else if (w == -1) w = 1 - r;
  puts("YES");
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j)
      printf("%c", ((i + j) & 1) == r ? 'R' : 'W');
    puts("");
  }
}
int main() {
  for (scanf("%d", &T); T; --T) solve();
  return 0;
}