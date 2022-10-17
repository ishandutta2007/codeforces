#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, m, cnt[N], ans[N];
std::vector<int> p[N]; 

void solve() {
  scanf("%d%d", &n, &m);
  memset(cnt, 0, (n + 1) * 4);
  for (int i = 1; i <= m; ++i) {
    int t; scanf("%d", &t);
    p[i].clear(), p[i].resize(t);
    for (auto &x : p[i]) scanf("%d", &x);
    if (p[i].size() == 1) ++cnt[p[i][0]]; 
  }
  int lim = (m + 1) / 2;
  for (int i = 1; i <= n; ++i) {
    if (cnt[i] > lim) {
      puts("NO");
      return;
    }
  }
  memset(cnt, 0, (n + 1) * 4);
  for (int i = 1; i <= m; ++i)
    for (auto x : p[i]) ++cnt[x];
  int x = std::max_element(cnt + 1, cnt + n + 1) - cnt;
  for (int i = 1; i <= m; ++i) {
    ans[i] = 0;
    if (p[i].size() == 1 && p[i][0] == x) {
      ans[i] = x;
      --lim;
    } 
  }
  for (int i = 1; i <= m; ++i) {
    if (ans[i]) continue;
    if (lim) {
      ans[i] = p[i][0];
      for (auto y : p[i]) {
        if (y == x) {
          ans[i] = x;
          --lim;
          break;
        }
      }
    } else {
      for (auto y : p[i]) {
        if (y != x) {
          ans[i] = y;
          break;
        }
      }
    }
  }
  puts("YES");
  for (int i = 1; i <= m; ++i) 
    printf("%d%c", ans[i], " \n"[i == m]);
}

int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}