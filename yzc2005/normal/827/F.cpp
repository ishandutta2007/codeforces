#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m;
struct node {
  int l, r, v;
  node(int ll = 0, int rr = 0, int vv = 0) : l(ll), r(rr), v(vv) {}
  bool operator < (const node &rhs) const {
    if (l != rhs.l) {
      return l < rhs.l;
    }
    return r < rhs.r;
  }
  bool operator > (const node &rhs) const {
    return rhs < *this;  
  }
};
vector<node> g[N]; 
vector<node>::iterator cur[N];
int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    int u, v, l, r;
    scanf("%d%d%d%d", &u, &v, &l, &r);
    --r;
    int l0 = l + (l & 1), r0 = r - (r & 1);
    g[u].emplace_back(l0, r0, v + n);
    g[v].emplace_back(l0, r0, u + n);
    int l1 = l + !(l & 1), r1 = r - !(r & 1);
    g[u + n].emplace_back(l1, r1, v);
    g[v + n].emplace_back(l1, r1, u);
  }
  for (int i = 1; i <= 2 * n; ++i) {
    sort(g[i].begin(), g[i].end());
    cur[i] = g[i].begin();
  }
  priority_queue<node, vector<node>, greater<node>> pq;
  pq.emplace(0, 0, 1);
  while (!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    int l = p.l, r = p.r, u = p.v;
    if (u == n || u == 2 * n) {
      printf("%d\n", l);
      return 0;
    }
    for (auto &i = cur[u]; i != g[u].end(); ++i) {
      int ll = i -> l, rr = i -> r, v = i -> v;
      if (rr < l) {
        continue;
      }
      if (ll > r) {
        break;
      }
      pq.emplace(max(ll, l) + 1, rr + 1, v);
    }
  }
  puts("-1");
  return 0;
}