#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, Q = 5e5 + 5, C = 26;
int n, q, cnt, fail[N], son[N][C];
vector<int> pos[N], g[N];
int dfn, l[N], r[N];
char str[N];
struct query {
  int id, coef, p;
}; vector<query> queries[N];
long long ans[Q]; 
struct FenwickTree {
  long long sum[N];
  inline void add(int p) {
    for (; p <= dfn; p += p & -p) {
      ++sum[p];
    }
  }
  inline int ask(int p) {
    long long res = 0;
    for (; p; p -= p & -p) {
      res += sum[p];
    }
    return res;
  }
  inline long long query(int pos) {
    return ask(r[pos]) - ask(l[pos] - 1);
  }
} bit;
int main() {
  scanf("%d%d", &n, &q);
  for (int j = 1; j <= n; ++j) {
    scanf("%s", str);
    int len = strlen(str), p = 0;
    for (int i = 0; i < len; ++i) {
      int &q = son[p][str[i] - 'a'];
      if (!q) {
        q = ++cnt;
      }
      pos[j].push_back(q);
      p = q;
    }
  }
  for (int i = 1, l, r, p; i <= q; ++i) {
    scanf("%d%d%d", &l, &r, &p);
    queries[l - 1].push_back((query) {i, -1, p});
    queries[r].push_back((query) {i, 1, p});
  }
  queue<int> qu;
  for (int i = 0; i < C; ++i) {
    if (son[0][i]) {
      qu.push(son[0][i]);
    }
  } 
  while (!qu.empty()) {
    int u = qu.front();
    qu.pop();
    for (int i = 0; i < C; ++i) {
      int &v = son[u][i];
      if (v) {
        fail[v] = son[fail[u]][i];
        qu.push(v);
      } else {
        v = son[fail[u]][i];
      }
    }
  }
  for (int i = 1; i <= cnt; ++i) {
    g[fail[i]].push_back(i);
  }
  function<void(int)> dfs = [&](int u) {
    l[u] = ++dfn;
    for (auto v : g[u]) {
      dfs(v);
    }
    r[u] = dfn;
  }; dfs(0);
  for (int i = 1; i <= n; ++i) {
    for (auto p : pos[i]) {
      bit.add(l[p]);
    }
    for (auto q : queries[i]) {
      ans[q.id] += q.coef * bit.query(pos[q.p].back());
    }
  }
  for (int i = 1; i <= q; ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}