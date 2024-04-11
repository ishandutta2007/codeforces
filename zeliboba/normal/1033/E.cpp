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
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//typedef long long int;

const int DEBUG = 0;
vvi A;
int CNT = 0;

int ask(vi x) {
  if (x.size() <= 1) return 0;
  ++CNT;
  if (DEBUG) assert(CNT <= 20000);
  sort(x.begin(), x.end());
  for (int i = 1; i < x.size(); ++i) assert(x[i] != x[i-1]);
  cout << "? " << x.size() << '\n';
  for (int i : x) cout << i + 1 << ' ';
  cout << endl;
  fflush(stdout);
  int res = 0;
  if (!DEBUG) cin >> res;
  else {
    for (int i = 0; i < x.size(); ++i) for (int j = i + 1; j < x.size(); ++j) res += A[x[i]][x[j]];
  }
  if (res == -1) exit(0);
  return res;
}

int cross(vi a, vi b) {
  vi c = a;
  for (int x : b) c.push_back(x);
  int all = ask(c);
  int ca = ask(a);
  int cb = ask(b);
  return all - ca - cb;
}

void bin(int v, int d, const vi& ab, vi& neig) {
  assert(d <= ab.size());
  if (d <= 0) return;
  if (d == ab.size()) {
    for (int i : ab) neig.push_back(i);
    return;
  }
  vi a, b;
  for (int i = 0; i < ab.size(); ++i) {
    if (i < ab.size() / 2) a.push_back(ab[i]);
    else b.push_back(ab[i]);
  }
  int da = cross(vi(1, v), a);
  assert(da <= d && da >= 0);
  bin(v, da, a, neig);
  bin(v, d - da, b, neig);
}

void dfs(int v, vvi& g, vi& was) {
  vi rem;
  for (int i = 0; i < was.size(); ++i) if (g[i].empty() && !was[i]) rem.push_back(i);
  random_shuffle(rem.begin(), rem.end());
  int d = cross(vi(1, v), rem);
  if (d == 0) return;
  vi neig;
  bin(v, d, rem, neig);
  for (int i : neig) {
    g[v].push_back(i);
    g[i].push_back(v);
  }
  for (int i : neig) {
    dfs(i, g, was);
  }
}

void dfs2(int v, const vvi& g, vi& col, int c) {
  if (col[v] != -1) return;
  col[v] = c;
  for (int nv : g[v]) {
    dfs2(nv, g, col, 1 - c);
  }
}

bool path(int v, int pr, int to, const vvi& g, vi& res) {
  if (v == to) {
    res.push_back(v);
    return true;
  }
  for (int nv : g[v]) if (nv != pr) {
    if (path(nv, v, to, g, res)) {
      res.push_back(v);
      return true;
    }
  }
  return false;
}

void solve() {
  CNT = 0;
  int n = 600;
  if (!DEBUG) {
    cin >> n;
  } else {
    A.assign(n, vi(n, 0));
    if (rand() % 2) {
      for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) {
        A[j][i] = A[i][j] = rand() % 2;
      }
    } else {
      vi col(n);
      for (int i = 0; i < n; ++i) col[i] = rand() % 2;
      for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) if (col[i] != col[j]) {
        A[j][i] = A[i][j] = rand() % 2;
      }
    }
  }
  vi x(n);
  for (int i = 0; i < n; ++i) x[i] = i;
  vvi g(n);
  vi was(n);
  vi ord(n);
  for (int i = 0; i < n; ++i) ord[i] = i;
  random_shuffle(ord.begin(), ord.end());
  for (int i : ord) if (g[i].empty() && !was[i]) {
    was[i] = 1;
    dfs(i, g, was);
  }
  vi col(n, -1);
  for (int i = 0; i < n; ++i) {
    dfs2(i, g, col, 0);
  }
  vvi p(2);
  for (int i = 0; i < n; ++i) {
    p[col[i]].push_back(i);
  }
  vi cp(2);
  for (int i = 0; i < 2; ++i) {
    cp[i] = ask(p[i]);
  }
  if (cp[0] == 0 && cp[1] == 0) {
    cout << "Y " << p[0].size() << '\n';
    for (int i : p[0]) cout << i + 1 << ' ';
    cout << endl;
    fflush(stdout);
    if (DEBUG) {
      for (int i : p[0]) for (int j : p[0]) assert(!A[i][j]);
      for (int i : p[1]) for (int j : p[1]) assert(!A[i][j]);
    }
  } else {
    vi bad = cp[0] > 0 ? p[0] : p[1];
    for (int i = (int)bad.size() - 1; i >= 0; --i) {
      if (bad.size() == 2) break;
      vi nbad = bad;
      nbad.erase(nbad.begin() + i);
      if (ask(nbad) > 0) {
        bad = nbad;
      }
    }
    assert(bad.size() == 2 && bad[0] != bad[1]);
    vi cyc;
    path(bad[0], -1, bad[1], g, cyc);
    assert(cyc.size() % 2);
    cout << "N " << cyc.size() << '\n';
    for (int i : cyc) cout << i + 1 << ' ';
    cout << endl;
    fflush(stdout);
    if (DEBUG) {
      for (int i = 0; i < cyc.size(); ++i) {
        int a = cyc[i], b = cyc[(i + 1) % cyc.size()];
        assert(A[a][b]);
      }
    }
  }
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  srand(2123912848032758147250721870382789373243534623463526356521342);
  solve();
  if (DEBUG) for (int i = 0; i < 100; ++i) solve();
  return 0;
}