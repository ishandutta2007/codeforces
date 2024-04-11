#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, a[N], b[N], ans[N];
pii c[N];

vector<int> g[N], gr[N];
bool used[N];
vector<int> order, component;

void add_edge(int v, int u) {
  g[v].pb(u);
  gr[u].pb(v);
}

void dfs1(int v) {
  used[v] = true;
  for (size_t i = 0; i < g[v].size(); ++i)
    if (!used[g[v][i]])
      dfs1(g[v][i]);
  order.push_back(v);
}

void dfs2(int v) {
  used[v] = true;
  component.push_back(v);
  for (size_t i = 0; i < gr[v].size(); ++i)
    if (!used[gr[v][i]])
      dfs2(gr[v][i]);
}

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  for (int i = 0; i < n; i++)
    scanf("%d", &b[i]);

  for (int i = 0; i < n; i++)
    c[i] = {a[i], i};
  sort(c, c + n);
  for (int i = 1; i < n; i++)
    add_edge(c[i].s, c[i - 1].s);

  for (int i = 0; i < n; i++)
    c[i] = {b[i], i};
  sort(c, c + n);
  for (int i = 1; i < n; i++)
    add_edge(c[i].s, c[i - 1].s);

  for (int i = 0; i < n; i++)
    used[i] = 0;
  for (int i = 0; i < n; ++i)
    if (!used[i])
      dfs1(i);
  for (int i = 0; i < n; i++)
    used[i] = 0;
  for (int i = 0; i < n; ++i) {
    int v = order[n - 1 - i];
    if (!used[v]) {
      dfs2(v);
      if (i == 0) {
        for (auto v : component)
          ans[v] = 1;
      }
      component.clear();
      break;
    }
  }
  for (int i = 0; i < n; i++)
    printf("%d", ans[i]);
  printf("\n");

  order.clear();
  for (int i = 0; i < n; i++) {
    g[i].clear();
    gr[i].clear();
    ans[i] = 0;
  }
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--)
    solve();
}