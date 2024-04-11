#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

void bfs(int s, vi & q, vi & d, vi & pr, const vvi& g) {
  int n = g.size();
  q.assign(1, s);
  pr.assign(n, -1);
  d.assign(n, 1e9);
  d[s] = 0;
  int it = 0;
  while (it < (int)q.size()) {
    for (int nv : g[q[it]]) {
      if (d[nv] > d[q[it]] + 1) {
        d[nv] = d[q[it]] + 1;
        q.push_back(nv);
        pr[nv] = q[it];
      }
    }
    ++it;
  }
}

vi was;
vi td;
void dfs(int v, const vvi & g) {
  if (was[v]) return;
  was[v] = 1;
  td.push_back(v);
  for (int nv : g[v]) if (nv != 0) dfs(nv, g);
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  vvi g(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
/*    if (a > b) swap(a, b);
    if (a == 0 && b == n-1) {
      cout << "1\n1 " << n << endl;
      return 0;
    }*/
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vi q, d, pr;
  bfs(0, q, d, pr, g);
  bool bad = q.size() == g[0].size() + 1;
  int s = -1;
  was.assign(n, 0);
  was[0] = 1;
  for (int v : g[0]) if (!was[v]) {
    td.clear();
    dfs(v, g);
    for (int i : td) {
      if (g[i].size() != td.size()) {
        bad = 0;
        s = i;
        break;
      }
    }
  }
  if (d[n-1] > n && bad) {
    cout << "-1\n";
    return 0;
  }
  vi res;
  if (d[n-1] <= n) {
    res.push_back(n - 1);
    while (res.back() != 0) {
      int nx = pr[res.back()];
      res.push_back(nx);
    }
    reverse(res.begin(), res.end());
  }
  if (q.size() == g[0].size() + 1) {
    if (res.size() > 5 || res.empty()) {
      res.clear();
      g[0].clear();
      bfs(s, q, d, pr, g);
      int cur = -1;
      for (int i = 0; i < n; ++i) if (d[i] == 2) cur = i;
      res = {0, s, pr[cur], cur, s, n-1};
    } 
  } else {
    if (res.size() > 4 || res.empty()) {
      res.clear();
      int cur = -1;
      for (int i = 0; i < n; ++i) if (d[i] == 2) cur = i;
      res = {0, pr[cur], cur, 0, n-1};
    }
  }
  cout << res.size() - 1 << endl;
  for (int i : res) cout << i + 1 << ' '; cout << endl;
  return 0;
}