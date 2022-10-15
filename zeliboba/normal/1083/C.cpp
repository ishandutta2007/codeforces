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
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

vvi g;
vi in, out, pr;
int T = 1;
const int B = 18;
int up[200001][B];

void dfs(int v, int p) {
  in[v] = ++T;
  pr[v] = p;
  up[v][0] = max(p, 0);
  for (int i=1; i < B; ++i)
    up[v][i] = up[up[v][i-1]][i-1];
  for (auto nv : g[v]) {
    if (nv == p) continue;
    dfs(nv, v);
  }
  out[v] = ++T;
}

bool upper (int a, int b) {
  return in[a] <= in[b] && out[a] >= out[b];
}

int lca (int a, int b) {
  if (upper (a, b))  return a;
  if (upper (b, a))  return b;
  for (int i = B - 1; i>=0; --i)
    if (! upper (up[a][i], b))
      a = up[a][i];
  return up[a][0];
}

vi p, pos;

const int N = 1 << 18;
array<int, 3> tr[2 * N];

array<int, 3> calc(const array<int, 3>& a, const array<int, 3>& b) {
  array<int, 3> c = {-1, -1, -1};
  c[0] = lca(a[0], b[0]);
  if (a[1] < 0 || b[1] < 0) {
    c[1] = -1;
  } else {
    vi v = {a[1], a[2], b[1], b[2]};
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int x : {a[2], b[2]}) {
      bool ok = true;
      for (int y : v) if (!upper(y, x)) {
        ok = false; break;
      }
      if (ok) {
        c[1] = c[0];
        c[2] = x;
      }
    }
    for (int i = 0; c[1] == -1 && i < v.size(); ++i) for (int j = i + 1; c[1] == -1 && j < v.size(); ++j) {
      int x = v[i], y = v[j];
      bool ok = true;
      for (int z : v) {
        if (!upper(z, x) && !upper(z, y)) {
          ok = false; break;
        }
      }
      if (ok) {
        if (lca(x, y) != c[0]) {
          c[1] = -2; break;
        }
        c[1] = x;
        c[2] = y;
      }
    }
  }
  if (c[1] >= 0 && upper(c[2], c[1])) swap(c[1], c[2]);
  return c;
}

int main() {
  int n;
  scanf("%d", &n);
  g.resize(n);
  in.assign(n, 0);
  pr.assign(n, 0);
  p.assign(n, 0);
  pos.assign(n, 0);
  out.assign(n, 0);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    pos[p[i]] = i;
  }
  for (int i = 0; i < n-1; ++i) {
    int a, b = i + 1;
    scanf("%d", &a);
    --a;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, -1);
  for (int i = 0; i < n; ++i) {
    tr[i + N] = {pos[i], pos[i], pos[i]};
  }
  for (int i = n; i < N; ++i) {
    tr[i + N] = {0, -1, -1};
  }
  for (int i = N-1; i > 0; --i) {
    tr[i] = calc(tr[2*i], tr[2*i+1]);
  }
  int Q;
  scanf("%d", &Q);
  for (int tt = 0; tt < Q; ++tt) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int a, b;
      scanf("%d%d", &a, &b);
      --a; --b;
      swap(p[a], p[b]);
      for (int x : {a, b}) {
        pos[p[x]] = x;
        int i = p[x] + N;
        tr[i] = {x, x, x};
        while (i > 1) {
          i /= 2;
          tr[i] = calc(tr[2*i], tr[2*i+1]);
        }
      }
    } else {
/*      for (int i = 0; i < n; ++i) cerr << p[i] << ' '; cerr << endl;
      for (int i = 0; i < n; ++i) cerr << pos[i] << ' '; cerr << endl;
      for (int i = 2*N-1; i > 0; --i) {
        if (tr[i][1] >= 0) cerr << i << ' ' << tr[i][0] << ' ' << tr[i][1] << ' ' << tr[i][2] << endl;
      }*/
      array<int, 3> cur = tr[N];
      int s = 0;
      for (int l = N; l > 0; l /= 2) {
        if (s + l > n) continue;
        int ind = (s + N) / (l);
        array<int, 3> nx = calc(cur, tr[ind]);
        if (nx[1] >= 0) {
          cur = nx;
          s += l;
        }
      }
      printf("%d\n", s);
    }
  }
  return 0;
}