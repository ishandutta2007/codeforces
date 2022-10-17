#include <bits/stdc++.h>
using namespace std;

inline void up(int &x, int y) {x < y ? x = y : 0;} 

const int N = 100005;
int n, m, nxt[N][26][2];
char s[N], t[N];

void solve() {
  scanf("%s%s", s + 1, t + 1);
  n = strlen(s + 1), m = strlen(t + 1);
  for (int j = 0; j < 26; ++j)
    for (int k = 0; k < 2; ++k)
      nxt[n + 1][j][k] = n + 1;
  for (int i = n; i; --i) {
    for (int j = 0; j < 26; ++j)
      for (int k = 0; k < 2; ++k)
        nxt[i][j][k] = nxt[i + 1][j][k];
    nxt[i][s[i] - 'a'][i & 1] = i;
  }
  bool ok = false;
  auto solve = [&](int st) {
    for (int i = 2; i <= m; ++i) {
      st = nxt[st][t[i] - 'a'][!(st & 1)];
      if (st == n + 1) break;
    } 
    if (st <= n && (n - st) % 2 == 0) {
      ok = true;
      puts("YES");
    } 
  };
  for (int i = 1; i <= n; ++i) 
    if (s[i] == t[1] && (i & 1)) {
      solve(i); break;
    }
  if (!ok) {
    for (int i = 1; i <= n; ++i) 
      if (s[i] == t[1] && (!(i & 1))) {
        solve(i); break;
      }
  }
  if (!ok) puts("NO");
}

int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}