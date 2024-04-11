#include <bits/stdc++.h>
const int N = 2e5 + 5;

int n, m, q;
char s[N], t[N];

// namespace :: SAM
int pa[N], val[N], ch[N][26], pos[N], rec[N], tot = 1, np = 1;
std::vector<int> g[N]; 

#define q ch[p][x]
inline int extend(int x) {
  int p = np;
  val[np = ++tot] = val[p] + 1;
  while (p && !q) q = np, p = pa[p];
  if (!p) pa[np] = 1;
  else if (val[q] == val[p] + 1) pa[np] = q;
  else {
    int nq = ++tot;
    val[nq] = val[p] + 1, memcpy(ch[nq], ch[q], 104);
    pa[nq] = pa[q], pa[q] = pa[np] = nq;
    for (int Q = q; p && q == Q; q = nq, p = pa[p]);
  } 
  return np;
}
#undef q

namespace ST {
  const int M = 1e7;
  int tot, rt[N], ls[M], rs[M];
  
  void modify(int &p, int l, int r, int pos) {
    if (!p) p = ++tot;
    if (l == r) return;
    int mid = l + r >> 1;
    if (mid >= pos) modify(ls[p], l, mid, pos);
    else modify(rs[p], mid + 1, r, pos);
  }
  int merge(int p, int q) {
    if (!p || !q) return p | q;
    int r = ++tot;
    ls[r] = merge(ls[p], ls[q]);
    rs[r] = merge(rs[p], rs[q]);
    return r;
  }
  bool find(int p, int l, int r, int L, int R) {
    if (l >= L && r <= R) return true;
    int mid = l + r >> 1;
    if (mid >= L && ls[p] && find(ls[p], l, mid, L, R)) return true;
    if (mid < R && rs[p] && find(rs[p], mid + 1, r, L, R)) return true;
    return false; 
  }
  inline bool ask(int p, int l, int r) {return l > r ? 0 : find(rt[p], 1, n, l, r);}
}

void dfs(int u) {
  if (pos[u]) ST::modify(ST::rt[u], 1, n, pos[u]);
  for (auto v : g[u]) dfs(v), ST::rt[u] = ST::merge(ST::rt[u], ST::rt[v]);
}

int main() {
  scanf("%s", s + 1), n = strlen(s + 1), rec[0] = 1;
  for (int i = 1; i <= n; ++i) pos[extend(s[i] -= 'a')] = i;
  for (int i = 1; i <= tot; ++i) g[pa[i]].emplace_back(i);
  for (dfs(1), scanf("%d", &q); q; --q) {
    int l, r, p = 1, cur = 1;
    scanf("%d%d%s", &l, &r, t + 1), m = strlen(t + 1);
    for (; cur <= m && (p = ch[p][t[cur] -= 'a']) && ST::ask(p, l + cur - 1, r); rec[cur] = p, ++cur);
    for (; cur > 0; --cur)
      for (int i = cur > m ? 0 : (t[cur] + 1), p; i < 26; ++i)
        if ((p = ch[rec[cur - 1]][i]) && ST::ask(p, l + cur - 1, r)) {
          for (int j = 1; j < cur; ++j) printf("%c", 'a' + t[j]);
          printf("%c\n", 'a' + i);
          cur = -1; break;
        }
    if (!cur) puts("-1");
  }
  return 0;
}