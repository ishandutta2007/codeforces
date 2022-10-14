#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const int INF = 1e9;

class Dsu {
  vi par, ss;
  int get(int x) { return par[x] == x ? x : par[x] = get(par[x]); }

  public:
  Dsu(int n) : par(n), ss(n, 1) {
    for (int i = 0; i < n; i++) par[i] = i;
  }
  bool eq(int a, int b) { return get(a) == get(b); }
  void merge(int a, int b) {
    a = get(a); b = get(b);
    if (a == b) return;
    if (ss[a] > ss[b]) swap(a, b);
    par[a] = b;
    ss[b] += ss[a];
  }
};

int n, k;
vvi es;
vi rs;
int st, en;

bool check(int maxd) {
  vi ds(n, INF);

  deque<int> q;
  for (int i = 0; i < k; i++) {
    int x = rs[i];
    ds[x] = 0;
    q.pb(x);
  }
  while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    int nd = ds[v] + 1;
    if (2 * nd > maxd) continue;

    for (int i = 0; i < sz(es[v]); i++) {
      int b = es[v][i];
      if (ds[b] > nd) {
        ds[b] = nd;
        q.pb(b);
      }
    }
  }

  Dsu dsu(n);
  for (int a = 0; a < n; a++) if (ds[a] < INF)
  for (int i = 0; i < sz(es[a]); i++) {
    int b = es[a][i];
    if (ds[b] >= INF) continue;

    assert(abs(ds[a] - ds[b]) <= 1);
    if (ds[a] + 1 == ds[b]) {
      dsu.merge(a, b);
    }
    if (ds[a] + 1 + ds[b] <= maxd) {
      dsu.merge(a, b);
    }
  }
  return dsu.eq(st, en);
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int m;
  while (scanf("%d%d%d", &n, &m, &k) >= 1) {
    rs = vi(k);
    for (int i = 0; i < k; i++)
      scanf("%d", &rs[i]), rs[i]--;

    es = vvi(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      es[a].pb(b);
      es[b].pb(a);
    }

    scanf("%d%d", &st, &en), st--, en--;
    rs.pb(en);
    sort(rs.begin(), rs.end());
    rs.erase(unique(rs.begin(), rs.end()), rs.end());
    k = sz(rs);

    int L = -1, R = n;
    if (!check(R)) {
      printf("-1\n");
    } else {
      while (L + 1 < R) {
        int M = (L + R) / 2;
        if (check(M)) R = M;
        else L = M;
      }
      printf("%d\n", R);
    }
  }
  return 0;
}