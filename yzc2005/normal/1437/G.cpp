#include <bits/stdc++.h>
const int N = 3e5 + 5, K = 26;
int n, m, ch[N][K], tot = 1, ed[N], top[N], fail[N];
int val[N], cur[N];
std::multiset<int> vals[N];
char str[N];
inline void build() {
  std::queue<int> q;
  q.push(1);
  std::fill(ch[0], ch[0] + K, 1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    top[u] = ~val[u] ? u : top[fail[u]]; 
    for (int i = 0; i < K; ++i) {
      int &v = ch[u][i];
      if (!v) {
        v = ch[fail[u]][i];
      } else {
        fail[v] = ch[fail[u]][i];
        q.push(v);
      }
    }
  } 
}
int main() {
  std::memset(val, -1, sizeof(val));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", str);
    int p = 1, len = strlen(str);
    for (int i = 0; i < len; ++i) {
      int &q = ch[p][str[i] - 'a'];
      if (!q) {
        q = ++tot;
      }
      p = q;
    }
    ed[i] = p;
    vals[p].insert(0);
    val[p] = 0;
  }
  build();
  while (m--) {
    int op;
    scanf("%d", &op);
    if (op & 1) {
      int i, x;
      scanf("%d%d", &i, &x);
      int p = ed[i];
      vals[p].erase(vals[p].find(cur[i]));
      cur[i] = x;
      vals[p].insert(x);
      val[p] = *vals[p].rbegin();
    } else {
      scanf("%s", str);
      int p = 1, ans = -1, len = strlen(str);
      for (int i = 0; i < len; ++i) {
        p = ch[p][str[i] - 'a'];
        for (int q = top[p]; q; q = top[fail[q]]) {
          ans = std::max(ans, val[q]);
        }
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}