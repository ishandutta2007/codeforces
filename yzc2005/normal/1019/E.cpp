#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

const int N = 2e5 + 5;
int n, m, sz_glb, sz[N], root, par[N];
bool vis_e[N];
vector<pair<int, pr>> G[N];
vector<pr> all;

struct edge {
  int to, nxt;
  pr f;
} e[N << 1];
int head[N], cnt = 1;
inline void add_e(int u, int v, pr f) {
  e[++cnt] = (edge) {v, head[u], f};
  head[u] = cnt;
}
inline void add(int u, int v, pr f) {
  add_e(u, v, f);
  add_e(v, u, f);
}

void build(int u, int fa) {
  int last = 0;
  for (auto p : G[u]) {
    int v = p.first;
    pr w = p.second;
    if (v == fa) continue;
    if (!last) {
      add(u, v, w);
      last = u;
    } else {
      add(last, ++n, pr(0, 0));
      add(n, v, w);
      last = n;
    }
    build(v, u);
  } 
}
void find_rt(int u) {
  sz[u] = 1;
  for (int i = head[u]; i; i = e[i].nxt) {
    if (vis_e[i >> 1] || i == par[u]) continue;
    int v = e[i].to; 
    par[v] = i ^ 1;
    find_rt(v);
    sz[u] += sz[v];
  }
  if(!root || max(sz[u], sz_glb - sz[u]) < max(sz[root], sz_glb - sz[root])) root = u;
}

inline ll calc(const pr &p, int x) {
  return p.first * x + p.second;
}
typedef __int128 u128;
inline u128 operator * (const pr &p, const pr &q) {
  return (u128)p.first * q.second - (u128)p.second * q.first;
}
inline pr operator - (const pr &p, const pr &q) {
  return pr(p.first - q.first, p.second - q.second);
}
inline pr operator + (const pr &p, const pr &q) {
  return pr(p.first + q.first, p.second + q.second);
}
inline bool judge(pr x, pr y, pr z) {
  return (y - x) * (z - x) >= 0;
}
struct hull {
  vector<pr> H;
  inline void build(vector<pr> cand) {
    sort(cand.begin(), cand.end());
    for (auto p : cand) {
      while (H.size() > 1 && judge(H[H.size() - 2], H.back(), p)) H.pop_back();
      H.emplace_back(p);
    }
  } 
  inline void get() {
    if (!H.size()) {
      while (m--) printf("0 ");
    } else {
      for (int i = 0, r = 0; i < m; ++i) {
        while (r + 1 < H.size() && calc(H[r + 1], i) >= calc(H[r], i)) ++r;
        printf("%lld ", calc(H[r], i));
      }
    }
  }
};
inline void work(vector<pr> &h1, vector<pr> &h2) {
  int j = 0;
  pr l1 = pr(0, 0), l2 = pr(0, 0);
  for (int i = 0; i < h1.size(); ++i) {
    while (j < h2.size() && (h1[i] - l1) * (h2[j] - l2) >= 0) {
      l2 = h2[j++];
      all.emplace_back(l1 + l2);
    } 
    l1 = h1[i];
    all.emplace_back(l1 + l2);
  }
  while (j < h2.size()) all.emplace_back(l1 + h2[j++]);
} // merge vertices with all

vector<pr> tmp[2];
void dfs(bool type, int par, int u, pr cur) {
  bool is_leaf = true;
  for (int i = head[u]; i; i = e[i].nxt) {
    if (vis_e[i >> 1]) continue;
    int v = e[i].to;
    if (v == par) continue;
    dfs(type, u, v, cur + e[i].f);
    is_leaf = false;
  }
  if (is_leaf && max(cur.first, cur.second) > 0) tmp[type].emplace_back(cur); 
}
void solve(int u) {
  if (sz_glb == 1) return; 
  root = par[u] = 0, find_rt(u);
  u = root, vis_e[par[u] >> 1] = true;
  int v = e[par[u]].to;
  tmp[0].clear(), tmp[1].clear();
  dfs(0, 0, u, e[par[u]].f);
  dfs(1, 0, v, pr(0, 0));
  hull h0, h1;
  h0.build(tmp[0]), h1.build(tmp[1]);
  work(h0.H, h1.H);
  int s1 = sz[u], s2 = sz_glb - sz[u];
  sz_glb = s1, solve(u);
  sz_glb = s2, solve(v);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; ++i) {
    int u, v, a, b; 
    scanf("%d%d%d%d", &u, &v, &a, &b);
    pr w = pr(a, b);
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
  }
  build(1, 0);
  sz_glb = n, solve(1);
  hull res;
  res.build(all), res.get();
  return 0;
}