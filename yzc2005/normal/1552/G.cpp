#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int N = 42, K = 12;
int n, k, fst[K], a[K][N], lim[K];
bool vis[N];

void dfs(int cur, ull msk) {
  if (cur == k) {
    for (int i = 1; i < n; ++i) 
      if ((msk >> i & 3) == 1) puts("REJECTED"), exit(0); 
    return;
  }
  int cnt = 0, sz = lim[cur];
  for (int i = 0; i < sz; ++i) cnt += msk >> a[cur][i] & 1;
  for (int i = 0; i < sz - cnt; ++i) 
    if (msk >> a[cur][i] & 1) msk ^= 1ull << a[cur][i];
  for (int i = sz - cnt; i < sz; ++i) msk |= 1ull << a[cur][i];
  dfs(cur + 1, msk);
  for (int i = 0, j = sz - cnt - 1; i < fst[cur]; ++i, --j) 
    msk |= 1ull << a[cur][j], dfs(cur + 1, msk); 
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", &lim[i]);
    for (int j = 0; j < lim[i]; ++j) {
      scanf("%d", &a[i][j]);
      if (!vis[a[i][j]]) {
        vis[a[i][j]] = true;
        ++fst[i];
      }
    }
  } 
  if (count(vis + 1, vis + n + 1, 0) && n > 1) 
    return puts("REJECTED"), 0;
  dfs(0, 0);
  puts("ACCEPTED");
  return 0;
}