#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

const int MAXN = 1e5 + 123;
const int MAXLOG = 17;

int n, max_sz;
vector<int> E[MAXN];

int D[MAXN];
int depth[MAXN];
int uplink[MAXLOG][MAXN];

void dfs(int x, int dad, int dep) {
  static int tick = 0;
  uplink[0][x] = dad;
  D[x] = tick++;
  depth[x] = dep;
  for (int b : E[x]) {
    if (b == dad) continue;
    dfs(b, x, dep+1);
  }
}

int lca(int a, int b) {
  if (depth[a] > depth[b]) swap(a, b);
  int delta = depth[b] - depth[a];
  REP(pos, MAXLOG) if (delta&(1<<pos)) b = uplink[pos][b];
  if (a == b) return a;
  for (int pos = MAXLOG - 1; pos >= 0; --pos) {
    int A = uplink[pos][a];
    int B = uplink[pos][b];
    if (A != B) { a = A; b = B; }
  }
  return uplink[0][a];
}

struct D_cmpf { bool operator () (int a, int b) const { return D[a] < D[b]; } };

struct Subtree {
  int sz;
  int bef_lca;
  set<int, D_cmpf> S;

  Subtree() { sz = 0; bef_lca = -1; }

  int get_closest(int x) {
    int closest_lca = -1;
    auto it = S.lower_bound(x);
    if (it != S.end()) { 
      int tmp = lca(*it, x); 
      if (closest_lca == -1 || depth[tmp] > depth[closest_lca]) closest_lca = tmp; 
    }
    if (it != S.begin()) {
      --it;
      int tmp = lca(*it, x);
      if (closest_lca == -1 || depth[tmp] > depth[closest_lca]) closest_lca = tmp;
    }
    return closest_lca;
  }

  void insert(int x) {
    if (sz == 0) { S.insert(x); sz = 1; bef_lca = x; return ; }

    int closest_lca = get_closest(x);
    S.insert(x);
    sz += depth[x] - depth[closest_lca];

    int new_lca = lca(bef_lca, x);
    sz += depth[bef_lca] - depth[new_lca];
    bef_lca = new_lca;
  }

  void erase(int x) {
    S.erase(x);
    if (S.empty()) { bef_lca = -1; sz = 0; return; }

    int closest_lca = get_closest(x);
    sz -= depth[x] - depth[closest_lca];
    int new_lca = lca(*S.begin(), *S.rbegin());
    sz -= depth[new_lca] - depth[bef_lca];
    bef_lca = new_lca;
  }

  int get_size() {
    return sz;
  }
} S;

int main(void)
{
  scanf("%d %d", &n, &max_sz);
  REP(i, n-1) {
    int a, b; scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  dfs(0, -1, 0);
  for (int l = 1; l < MAXLOG; ++l)
    REP(i, n) {
      int u = i;
      if (u != -1) u = uplink[l-1][u];
      if (u != -1) u = uplink[l-1][u];
      uplink[l][i] = u;
    }

  int L = 0;
  int maks = 0;
  REP(R, n) {
    S.insert(R);
    while (L < R && S.get_size() > max_sz) { S.erase(L++); }
    maks = max(maks, R-L+1);
  }

  printf("%d\n", maks);
  return 0;
}