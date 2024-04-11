#include <bits/stdc++.h>

typedef long long ll;

const int N = 2205, inf = 1e9, M = N * 7, E = M * 20;
int n, a[2 * N], b[2 * N], id[2 * N];
ll g[2 * N];
int head[M], dis[M], pre[M];
bool in[M];
struct edge {
  int to, cost, cap, nxt;
  edge(int _to = 0, int _cost = 0, int _cap = 0, int _nxt = 0) : to(_to), cost(_cost), cap(_cap), nxt(_nxt) {}
} e[E];

ll f(int i, int t) {return 1ll * a[i] * t + b[i];}

bool check(int mid) {
  std::iota(id + 1, id + 2 * n + 1, 1), std::sort(id + 1, id + 2 * n + 1, [&](int i, int j) {return b[i] < b[j];});
  ll cur_max = 0;
  for (int i = 1, j; i <= 2 * n; i = j + 1) {
    for (j = i; j < 2 * n && b[id[j + 1]] == b[id[i]]; ++j);
    for (int k = i; k <= j; ++k) cur_max = std::max(cur_max, f(id[k], mid));
    for (int k = i; k <= j; ++k) g[id[k]] = cur_max;
  }
  for (int i = n + 1; i <= 2 * n; ++i) g[i] = f(i, mid);
  std::sort(id + 1, id + 2 * n + 1, [&](int i, int j) {return g[i] == g[j] ? i > j : g[i] <= g[j];});
  for (int i = 1, cnt = 0; i <= 2 * n; ++i) {
    if (id[i] <= n) {if (--cnt < 0) return false;}
    else ++cnt;
  }
  return true;
}

int calc(int mid) {
  int s = 0, t = n * 7 + 1, cnt = 1, res = 0;
  auto add_edge = [&](int u, int v, int w, int c) {
    e[++cnt] = edge(v, w, c, head[u]);
    head[u] = cnt;
  }; 
  auto add = [&](int u, int v, int w, int c) {
    add_edge(u, v, w, c), add_edge(v, u, -w, 0);
  };
  for (int i = 1; i <= n; ++i) add(s, i, 0, 1), add(i, i + 2 * n, 0, 1);
  for (int i = n + 1; i <= 2 * n; ++i) add(i, t, 0, 1), add(i + 2 * n, i, 0, 1);
  std::iota(id + 1, id + 2 * n + 1, 1), std::sort(id + 1, id + 2 * n + 1, [&](int i, int j) {return b[i] < b[j];});
  for (int i = 1, j; i <= 2 * n; i = j + 1) {
    for (j = i; j < 2 * n && b[id[j + 1]] == b[id[i]]; ++j);
    for (int k = i; k <= j; ++k) {
      int u = id[k]; add(id[i] + 4 * n, u + 2 * n, 1, inf);
      if (u <= n) add(u, id[i] + 4 * n, 0, inf);
    }
    if (j < 2 * n) add(id[j + 1] + 4 * n, id[i] + 4 * n, 0, inf);
  }
  for (int i = 1; i <= 2 * n; ++i) id[i] = i, g[i] = f(i, mid);
  std::sort(id + n + 1, id + 2 * n + 1, [&](int i, int j) {return g[i] < g[j];});
  for (int i = n + 1, j; i <= 2 * n; i = j + 1) {
    for (j = i; j < 2 * n && g[id[j + 1]] == g[id[i]]; ++j);
    for (int k = i; k <= j; ++k) add(id[i] + 5 * n, id[k], 0, 1), add(id[k] + 2 * n, id[i] + 5 * n, 1, inf), id[k] = id[i];
    if (j < 2 * n) add(id[j + 1] + 5 * n, id[i] + 5 * n, 0, inf);
  } 
  std::sort(id + 1, id + n + 1, [&](int i, int j) {return g[i] < g[j];});
  for (int i = 1, j = n; i <= n; ++i) {
    while (j < 2 * n && g[id[j + 1]] <= g[id[i]]) ++j;
    if (j > n) add(id[i] + 2 * n, id[j] + 5 * n, 1, inf);
  }
  int tt = 0;
  for (; ; ++tt) {
    memset(dis, 0x3f, sizeof dis), dis[s] = 0;
    memset(in, 0, sizeof in), in[s] = true;
    std::deque<int> que; que.push_back(s);
    while (!que.empty()) {
      int u = que.front(); que.pop_front(); in[u] = false;
      for (int i = head[u]; i; i = e[i].nxt) {
        if (!e[i].cap) continue;
        int v = e[i].to, c = e[i].cost;
        if (dis[v] > dis[u] + c) {
          dis[v] = dis[u] + c, pre[v] = i;
          if (!in[v]) c < 0 ? que.push_front(v) : que.push_back(v), in[v] = true;
        }        
      }
    }
    if (dis[t] == 0x3f3f3f3f) return assert(tt == n), res; res += dis[t];
    for (int u = t; u != s; u = e[pre[u] ^ 1].to) 
      --e[pre[u]].cap, ++e[pre[u] ^ 1].cap;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 2 * n; ++i) scanf("%d%d", &a[i], &b[i]);
  int l = 0, r = 1e9, t = -1;
  while (l <= r) {
    int mid = l + r >> 1;
    if (check(mid)) t = mid, r = mid - 1;
    else l = mid + 1;
  } 
  if (t == -1) return puts("-1"), 0;
  printf("%d %d\n", t, calc(t));
  return 0;
}