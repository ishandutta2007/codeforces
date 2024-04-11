#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pr = pair<int, ll>;
const int inf = 0x3f3f3f3f;

const int N = 1e5 + 5, S = 1 << 8 | 5;
int n, d[8][N], D[8][8], msk[N], cnt[8][S], res[8][S][8][S];
char s[N];
vector<int> pos[8];
pr ans;

inline void update(pr y) {
  if (ans.first < y.first) ans = y;
  else if (ans.first == y.first) ans.second += y.second;
}

void solve(int c, int *d) {
  bool vis[8];
  memset(vis, false, sizeof vis);
  queue<int> que;
  for (auto x : pos[c]) {
    d[x] = 0;
    que.push(x);
  }
  vis[c] = true;
  while (!que.empty()) {
    int x = que.front(); 
    que.pop();
    if (!vis[s[x]]) {
      for (auto y : pos[s[x]]) {
        if (d[y] == inf) {
          d[y] = d[x] + 1;
          que.push(y);
        }
      }
      vis[s[x]] = true;
    }
    if (x > 1 && d[x - 1] == inf) {
      d[x - 1] = d[x] + 1;
      que.push(x - 1);
    } 
    if (x < n && d[x + 1] == inf) {
      d[x + 1] = d[x] + 1;
      que.push(x + 1); 
    }
  }
  for (int i = 1; i <= n; ++i)
    D[c][s[i]] = min(D[c][s[i]], d[i]);
}
inline int calc(int i, int j) {
  int ans = abs(i - j);
  for (int c = 0; c < 8; ++c) ans = min(ans, d[c][i] + 1 + d[c][j]);
  return ans;
}

int main() {
  scanf("%d%s", &n, s + 1);
  memset(D, 0x3f, sizeof D);
  memset(d, 0x3f, sizeof d);
  for (int i = 1; i <= n; ++i) 
    pos[s[i] -= 'a'].emplace_back(i);
  for (int i = 0; i < 8; ++i) solve(i, d[i]);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 8; ++j) 
      if (d[j][i] > D[j][s[i]]) msk[i] |= 1 << j;
  }
  for (int i = 0; i < 8; ++i)
    for (int s = 0; s < 256; ++s)
      for (int j = 0; j < 8; ++j)
        for (int t = 0; t < 256; ++t) {
          int cur = inf;
          for (int k = 0; k < 8; ++k) 
            cur = min(cur, D[i][k] + (s >> k & 1) + 1 + D[k][j] + (t >> k & 1));
          res[i][s][j][t] = cur;
        } 
  for (int i = n; i; --i) {
    if (i + 16 <= n) ++cnt[s[i + 16]][msk[i + 16]];
    for (int j = 0; j < 16 && i + j <= n; ++j) update(pr(calc(i, i + j), 1));
    for (int c = 0; c < 8; ++c) 
      for (int s = 0; s < 256; ++s) if (cnt[c][s]) 
        update(pr(res[::s[i]][msk[i]][c][s], cnt[c][s]));
  }
  printf("%d %lld\n", ans.first, ans.second);
  return 0;
}