#include <bits/stdc++.h>
using namespace std;

const int N = 300006;

struct DJS {
  int p[N];
  void init(int n) {
    for (int i = 0; i <= n; ++i) {
      p[i] = i;
    }
  }
  int Find(int x) {
    return p[x] == x ? x : p[x] = Find(p[x]);
  }
  void Union(int x, int y) {
    p[Find(x)] = Find(y);
  }
} djs;

vector<int> G[N];

int deg[N];
bool vis[N];
bool done[N];
int dis[N];
vector<int> v[N];

typedef pair<int, int> pii;
#define F first
#define S second

void go() {
  int n, m; cin >> n >> m;
  djs.init(n);
  for (int i = 1; i <= n; ++i) {
    vis[i] = false;
    done[i] = false;
    deg[i] = 0;
    G[i].clear();
    v[i].clear();
    dis[i] = -1;
  }
  for (int i = 1; i <= m; ++i) {
    int x, y; cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
    ++deg[x], ++deg[y];
    djs.Union(x, y);
  }
  for (int i = 1; i <= n; ++i) {
    if (djs.Find(1) != djs.Find(i)) {
      cout << "NO" << '\n';
      return;
    }
  }
  cout << "YES" << '\n';
  /*
  priority_queue<pii, vector<pii>, greater<pii> > pq;
  for (int i = 1; i <= n; ++i) {
    pq.push(make_pair(deg[i], i));
  }
  while (!pq.empty()) {
    pii p = pq.top(); pq.pop();
    int id = p.second;
    if (done[id]) continue;
    done[id] = true;
    bool have = false;
    for (int i : G[id]) {
      if (vis[i]) {
        have = true;
        break;
      }
    }
    if (!have) {
      vis[id] = true;
    }
    for (int i : G[id]) {
      if (!done[i]) {
        --deg[i];
        pq.push(make_pair(deg[i], i));
      }
    }
  }
  */
  queue<int> que;
  que.push(1); dis[1] = 1;
  while (!que.empty()) {
    int t = que.front(); que.pop();
    v[dis[t]].push_back(t);
    for (int i : G[t]) {
      if (dis[i] == -1) {
        dis[i] = dis[t] + 1;
        que.push(i);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j : v[i]) {
      // check is same level neighbor
      bool ok = true;
      for (int k : G[j]) {
        if (vis[k] && dis[k] <= dis[j]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        vis[j] = true;
      }
    }
  }
  vector<int> ans;
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) {
      ans.push_back(i);
    }
  }
  bool first = false;
  cout << ans.size() << '\n';
  for (int i : ans) {
    if (first) cout << ' ';
    cout << i;
    first = true;
  }
  cout << '\n';
  
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    go();
  }
}