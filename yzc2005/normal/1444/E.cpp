#include <bits/stdc++.h>
using namespace std;

typedef __int128 u128;

const int N = 105;
vector<int> g[N];
int n, fa[N], d[N];
u128 f[N], p[N];
bool vis[N];

void print(u128 x) {
  for (int i = n - 1; ~i; --i)
    cout << ((x & p[i]) ? "1" : "0");
  cout << endl;
}

void dfs(int u) {
  for (auto v : g[u]) 
    if (v != fa[u]) {
      fa[v] = u;
      dfs(v);
    }
  f[u] = p[n] - 1;
  for (int i = n - 1; ~i; --i) {
    f[u] ^= p[i];
    priority_queue<u128> pq;
    for (auto v : g[u])
      if (v != fa[u])
        pq.emplace(f[v]);
    bool ok = true;
    for (int j = n - 1; ~j; --j) {
      if (f[u] & p[j]) {
        if (!pq.empty()) {
          auto x = pq.top();
          pq.pop();
          if (x / p[j] >= 2) {
            ok = false;
            break;
          } else if (x & p[j]) {
            pq.emplace(x ^ p[j]);
          }
        }
      } else {
        if (!pq.empty()) {
          if (pq.top() >= p[j]) {
            ok = false;
            break;
          }
        }
      }
    }
    if (!pq.empty()) 
      ok = false;
    if (!ok) 
      f[u] ^= p[i];
  }
  priority_queue<pair<u128, int>> pq;
  for (auto v : g[u])
    if (v != fa[u])
      pq.emplace(f[v], v);
  for (int i = n - 1; ~i; --i) {
    if (f[u] & p[i]) {
      if (!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        if (x.first & p[i]) {
          x.first ^= p[i];
          pq.emplace(x);
        } else {
          d[x.second] = i;
        }
      }
    }
  }
}

void del(int u, int fa) {
  vis[u] = true;
  for (auto v : g[u]) 
    if (v != fa && !vis[v]) 
      del(v, u);
}

int main() {
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int u, v; 
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  p[0] = u128(1);
  for (int i = 1; i <= n; ++i) 
    p[i] = p[i - 1] << u128(1);
  dfs(1);
  while (true) {
    int u = 0;
    for (int i = 2; i <= n; ++i)
      if (!vis[i] && !vis[fa[i]])
        if (!u || d[i] > d[u]) 
          u = i;
    if (!u) 
      for (int i = 1; i <= n; ++i) 
        if (!vis[i]) 
          cout << "! " << i << endl, exit(0);
    cout << "? " << u << " " << fa[u] << endl;
    int x; 
    cin >> x; 
    del(u + fa[u] - x, x);
  }
  return 0;
}