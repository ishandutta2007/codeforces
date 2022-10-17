#include <bits/stdc++.h>
const int N = 1e6 + 5, M = N * 2;

// namespace :: SAM
int pa[M], val[M], ch[M][26], ti[M], w[M], cnt = 1, np = 1;
std::vector<int> g[M];
#define q ch[p][x]
inline void extend(int x) {
  int p = np; 
  val[np = ++cnt] = val[p] + 1, w[np] = 1;
  while (p && !q) q = np, p = pa[p];
  if (!p) pa[np] = 1;
  else if (val[q] == val[p] + 1) pa[np] = q;
  else {
    int nq = ++cnt;
    val[nq] = val[p] + 1, memcpy(ch[nq], ch[q], 104);
    pa[nq] = pa[q], pa[q] = pa[np] = nq;
    for (int Q = q; p && q == Q; q = nq, p = pa[p]);
  }
}
#undef q
void dfs(int u) { for (auto v : g[u]) dfs(v), w[u] += w[v]; }

int n, m, q;
char s[N], t[N];

int main() {
  scanf("%s", s), n = strlen(s);
  for (int i = 0; i < n; ++i) extend(s[i] -= 'a');
  for (int i = 1; i <= cnt; ++i) g[pa[i]].emplace_back(i);
  dfs(1), scanf("%d", &q);
  for (int tt = 1; tt <= q; ++tt) {
    scanf("%s", t), m = strlen(t);
    int p = 1, cur = 0;
    long long ans = 0;
    auto move = [&](int x) {
      if (ch[p][x]) p = ch[p][x], ++cur;
      else {
        while (p && !ch[p][x]) p = pa[p];
        if (!p) p = 1, cur = 0;
        else cur = val[p] + 1, p = ch[p][x];
      }
    };
    for (int i = 0; i < m; ++i) move(t[i] -= 'a');
    for (int i = 0; i < m; ++i) {
      if (move(t[i]), cur > m) 
        if (--cur == val[pa[p]]) p = pa[p];
      if (cur == m && ti[p] != tt) ti[p] = tt, ans += w[p];
    }
    printf("%lld\n", ans);
  }
  return 0;
}