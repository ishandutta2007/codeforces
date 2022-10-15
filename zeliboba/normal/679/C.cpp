#include <cstdio>
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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
char s0[505][505];
int n, k;

bool in(int i, int j) {
  return i >= 0 && j >= 0 && i < n && j < n;
}

int getp(int v, vi & p) {
  if (v == p[v]) return v;
  return p[v] = getp(p[v], p);
}

void join(int a, int b, vi & p, vi & r) {
  a = getp(a, p);
  b = getp(b, p);
  if (a == b) return;
  if (r[a] > r[b]) swap(a, b);
  p[a] = b;
  r[b] += r[a];
}

void upmi(int & x, int y) {
  x = min(x, y);
}

void upma(int & x, int y) {
  x = max(x, y);
}

int main() {
  scanf("%d%d", &n, &k);
  vvi s(n, vi(n));
  for (int i = 0; i < n; ++i) {
    scanf("%s", s0[i]);
    for (int j = 0; j < n; ++j) if (s0[i][j] == 'X') s[i][j] = 1;
  }
  vi p(n * n), r(n * n, 1);
  for (int i = 0; i < (int)p.size(); ++i) {
    p[i] = i;
  }
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (!s[i][j]) {
    for (int d = 0; d < 4; ++d) {
      int ni = i + dx[d];
      int nj = j + dy[d];
      if (!in(ni, nj) || s[ni][nj]) continue;
      join(i*n+j, ni*n+nj, p, r);
    }
  }
  vi minx(p.size(), n);
  vi maxx(p.size(), 0);
  vi miny(p.size(), n);
  vi maxy(p.size(), 0);
  int ma = 0;
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (!s[i][j]) {
    p[i*n+j] = getp(i*n+j, p);
    ma = max(ma, r[i*n+j]);
    upmi(minx[p[i*n+j]], i);
    upma(maxx[p[i*n+j]], i);
    upmi(miny[p[i*n+j]], j);
    upma(maxy[p[i*n+j]], j);
//    cerr << i << ' ' << j << ' ' << p[i*n+j] << ' ' << r[i*n+j] << endl;
  }
//  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (!s[i][j] && p[i*n+j] == i*n+j) {
//    cerr << i << ' ' << j << ' ' << minx[p[i*n+j]] << ' ' << maxx[p[i*n+j]] << ' ' << miny[i*n+j] << ' ' << maxy[i*n+j] << endl;
//  }
  vi was(n * n);
  vi wasp(n * n, -1);
  int add = 0;
  for (int i = 0; i <= n-k; ++i) for (int j = 0; j <= n-k; ++j) {
    if (j == 0) {
      add = 0;
      for (int i1 = i; i1 < i+k; ++i1) for (int j1 = j; j1 < j+k; ++j1) {
        if (s[i1][j1]) {
          ++add;
        } else {
          int pt = p[i1*n+j1];
          if (wasp[pt] != i && minx[pt] >= i && maxx[pt] < i + k && miny[pt] >= j && maxy[pt] < j + k) {
            add += r[pt];
            wasp[pt] = i;
          }
        }
      }
    } else {
      for (int i1 = i; i1 < i+k; ++i1) {
        int j1 = j + k - 1;
        if (s[i1][j1]) {
          ++add;
        } else {
          int pt = p[i1*n+j1];
          if (wasp[pt] != i && minx[pt] >= i && maxx[pt] < i + k && miny[pt] >= j && maxy[pt] < j + k) {
            add += r[pt];
            wasp[pt] = i;
          }
        }
        j1 = j - 1;
        if (s[i1][j1]) {
          --add;
        } else {
          int pt = p[i1*n+j1];
          if (wasp[pt] == i) {
            add -= r[pt];
            wasp[pt] = -1;
          }
        }
      }
    }
    int T = i * n + j + 1;
//    vi p1;//, r1;
    int sum = add;
    if (i) {
      for (int t = 0; t < k; ++t) {
        int a = i-1, b = j + t;
        if (s[a][b]) continue;
        int x = p[n*a + b];
        if (was[x] != T) {
          was[x] = T;
          sum += r[x];
        }
      }
    }
    if (i + k < n) {
      for (int t = 0; t < k; ++t) {
        int a = i+k, b = j + t;
        if (s[a][b]) continue;
        int x = p[n*a + b];
        if (was[x] != T) {
          was[x] = T;
          sum += r[x];
        }
      }
    }
    if (j) {
      for (int t = 0; t < k; ++t) {
        int a = i+t, b = j - 1;
        if (s[a][b]) continue;
        int x = p[n*a + b];
        if (was[x] != T) {
          was[x] = T;
          sum += r[x];
        }
      }
    }
    if (j + k < n) {
      for (int t = 0; t < k; ++t) {
        int a = i+t, b = j + k;
        if (s[a][b]) continue;
        int x = p[n*a + b];
        if (was[x] != T) {
          was[x] = T;
          sum += r[x];
        }
      }
    }
//    cerr << i << ' ' << j << ' ' << add << ' ' << sum << endl;
    ma = max(ma, sum);
  }
  cout << ma << endl;
  return 0;
}