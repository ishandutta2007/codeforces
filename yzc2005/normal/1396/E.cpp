#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, rt, p[N], sz[N], fa[N], dep[N], cur;
long long lower, upper, k;
set<int> g[N];
set<pair<int, int>> leaves[N], subs, last;
vector<pair<int, int>> pairs;
vector<int> rest[N];
bool del[N];
void find(int u, int fa) {
  int max_size = 1;
  sz[u] = 1; for (auto v : g[u]) if (v != fa) find(v, u), max_size = max(max_size, sz[v]), sz[u] += sz[v];
  if (max(max_size, n - sz[u]) <= (n + 1) / 2) rt = u;
}
void dfs(int u) {
  sz[u] = 1; if (fa[u]) g[u].erase(fa[u]);
  for (auto v : g[u]) fa[v] = u, dep[v] = dep[u] + 1, dfs(v), sz[u] += sz[v], lower += sz[v] & 1, upper += sz[v];
}
void push_leaf(int u, int belong) {
  if (sz[u] == 1) leaves[belong].insert({dep[u], u});
  for (auto v : g[u]) push_leaf(v, belong);
} 
void push_rest(int u, int belong) {
  if (!del[u]) rest[belong].emplace_back(u);
  for (auto v : g[u]) push_rest(v, belong);
}
void insert(int u, int v) {
  pairs.emplace_back(u, v);
  del[u] = del[v] = true;
}
int main() {
  cin >> n >> k;
  for (int i = 1, u, v; i < n; ++i) cin >> u >> v, g[u].insert(v), g[v].insert(u);
  find(1, 0), dfs(rt);
  if (lower > k || upper < k || (k = upper - k) & 1) return cout << "NO\n", 0;
  cout << "YES\n", k /= 2;
  for (auto v : g[rt]) push_leaf(v, v), subs.insert({sz[v], v});
  while (k) {
    auto biggest = *subs.rbegin(); subs.erase(biggest);
    int v = biggest.second; subs.insert({sz[v] -= 2, v});
    auto leaf = *leaves[v].rbegin();
    int x = leaf.second, father = fa[x], d = leaf.first - 1;
    if (k >= d) { 
      k -= d;
      auto erase = [&](int x) {
        leaves[v].erase({dep[x], x});
        g[fa[x]].erase(x);
      }; erase(x);
      auto push = [&](int x) {
        if (g[x].empty()) leaves[v].insert({dep[x], x});
      };
      if (g[father].empty()) g[fa[father]].erase(father), insert(x, father), push(fa[father]);
      else insert(x, *g[father].begin()), erase(*g[father].begin()), push(father); 
    } else {
      int cur = x; while (dep[cur] > k + 1) cur = fa[cur];
      insert(cur, fa[cur]); break;
    }
  }
  rest[cur++] = {rt};
  for (auto v : g[rt]) push_rest(v, cur++);
  for (int i = 0; i < cur; ++i) if (!rest[i].empty()) last.insert({rest[i].size(), i});
  auto pair = [&](int x, int y) {
    insert(rest[x].back(), rest[y].back()); 
    rest[x].pop_back(), rest[y].pop_back();
  };
  while (!last.empty()) {
    assert(last.size() >= 2);
    auto it = --last.end(), ij = it--;
    last.erase(it), last.erase(ij);
    auto p = *it, q = *ij;
    assert(p.first == rest[p.second].size());
    assert(q.first == rest[q.second].size());
    pair(p.second, q.second);
    if (--p.first) last.insert(p);
    if (--q.first) last.insert(q);
  }
  for (auto &p : pairs) cout << p.first << " " << p.second << "\n";
  return 0;
}