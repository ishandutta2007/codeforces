#include <stdio.h>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

vi p;

int getp(int v) {
  if (v == p[v]) return v;
  return p[v] = getp(p[v]);
}

void join(int a, int b) {
  a = getp(a);
  b = getp(b);
  if (a == b) return;
  if (rand() % 2) swap(a, b);
  p[a] = b;
}

int cnt = 0, sumdeg = 0;

void dfs(int v, const vvi & g, vi & was) {
  if (was[v]) return;
  was[v] = 1;
  ++cnt;
  sumdeg += g[v].size();
  for (int nv : g[v]) dfs(nv, g, was);
}

int main() {
  //std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  scanf("%d%d", &n, &m);
  vector<array<int, 3>> e(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &e[i][1], &e[i][2], &e[i][0]);
    --e[i][1]; --e[i][2];
  }
  auto ts = e;
  sort(ts.begin(), ts.end());
  p.resize(n);
  for (int i = 0; i < n; ++i) p[i] = i;
  int q;
  scanf("%d", &q);
  vi res(q, 1);
  vector<pair<pii, vi>> que;
  for (int t = 0; t < q; ++t) {
    int k;
    scanf("%d", &k);
    vii v(k);
    for (int i = 0; i < k; ++i) {
      scanf("%d", &v[i].second);
      --v[i].second;
      v[i].first = e[v[i].second][0];
    }
    sort(v.begin(), v.end());
    for (pii p : v) {
      pii x(p.first, t);
      if (que.empty() || que.back().first != x) {
        que.emplace_back(x, vi(1, p.second));
      } else {
        que.back().second.push_back(p.second);
      }
    }
  }
  sort(que.begin(), que.end());
  int it = 0;
  vi was(n, 0);
  vvi g(n);
  for (int i = 0; i < que.size(); ++i) {
    int ind = que[i].first.second;
    int w = que[i].first.first;
    while (it < ts.size() && ts[it][0] < w) {
      join(ts[it][1], ts[it][2]);
      ++it;
    }
    vii x(que[i].second.size());
    for (int j = 0; j < que[i].second.size(); ++j) {
      int l = que[i].second[j];
      x[j] = pii(getp(e[l][1]), getp(e[l][2]));
      g[x[j].first].push_back(x[j].second);
      g[x[j].second].push_back(x[j].first);
//      cerr << ind << ' ' << w << ' ' << x[j].first << ' ' << x[j].second << endl;
    }
    for (pii p : x) if (!was[p.first]) {
      cnt = 0;
      sumdeg = 0;
      dfs(p.first, g, was);
//      cerr << "dfs: " << ind << ' ' << w << ' ' << cnt << ' ' << sumdeg << endl;
      if (2 * cnt - 2 != sumdeg) {
        res[ind] = 0;
        break;
      }
    }
    for (pii p : x) {
      was[p.first] = was[p.second] = 0;
      g[p.first].clear();
      g[p.second].clear();
    }
  }
  for (int i = 0; i < res.size(); ++i) {
    if (res[i]) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}