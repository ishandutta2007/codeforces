#include <bits/stdc++.h>
using namespace std;

inline void up(int &x, int y) {x < y ? x = y : 0;} 

const int N = 300005;
int n, m, p[N], r[N], q[N], cnt[N];
bool vis[N];

void solve() {
  scanf("%d%d", &n, &m);
  vector<int> ans;
  memset(cnt, 0, n * 4);
  for (int i = 1; i <= n; ++i) 
    scanf("%d", &p[i]), r[p[i]] = i;
  for (int i = 1; i <= n; ++i) {
    int j = r[i];
    if (j < i) j += n;
    ++cnt[j - i];
  }
  auto check = [&](int k) {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      q[i] = p[i + k > n ? (i + k - n) : i + k];
      vis[i] = false;
    }
    for (int i = 1; i <= n; ++i) {
      if (vis[i]) continue;
      vis[i] = true;
      for (int j = q[i]; j != i; j = q[j]) {
        vis[j] = true;
        ++cnt;
      }
    }
    if (cnt <= m) ans.emplace_back(k);
  };
  for (int i = 0; i < n; ++i) {
    int cur = (n - cnt[i]) / 2;
    if (cur <= m) check(i);
  }
  printf("%d ", ans.size());
  for (auto x : ans) printf("%d ", x);
  puts("");
}

int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}