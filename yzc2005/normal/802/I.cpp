#include <bits/stdc++.h>
const int N = 100005, M = N * 2;
int tot, np, fa[M], len[M], ch[M][26], sz[M];
std::vector<int> g[M];
#define q ch[p][x]
inline void extend(int x) {
  int p = np; np = ++tot, len[np] = len[p] + 1;
  memset(ch[np], 0, 104), sz[np] = 1;
  for (; p && !q; q = np, p = fa[p]);
  if (!p) fa[np] = 1;
  else if (len[q] == len[p] + 1) fa[np] = q;
  else {
    int nq = ++tot; len[nq] = len[p] + 1;
    sz[nq] = 0, memcpy(ch[nq], ch[q], 104);
    fa[nq] = fa[q], fa[np] = fa[q] = nq;
    for (int Q = q; p && q == Q; q = nq, p = fa[p]);
  }
}
#undef q
int n;
char s[N]; 
void solve() {
  scanf("%s", s + 1), n = strlen(s + 1);
  tot = np = 1; sz[1] = 0, memset(ch[1], 0, 104);
  for (int i = 1; i <= n; ++i) extend(s[i] - 'a');
  for (int i = 1; i <= tot; ++i) g[i].clear();
  for (int i = 2; i <= tot; ++i) g[fa[i]].emplace_back(i);
  long long ans = 0;
  std::function<void(int)> dfs = [&](int u) {
    for (auto v : g[u]) dfs(v), sz[u] += sz[v];
    ans += 1ll * sz[u] * sz[u] * (len[u] - len[fa[u]]); 
  }; dfs(1);
  printf("%lld\n", ans);
}
int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}