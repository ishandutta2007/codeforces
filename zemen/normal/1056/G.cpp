#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int n, m, s;
ll t;

vector<int> p;

void build() {
  p.resize(n);
  iota(p.begin(), p.end(), 0);
  for (int r = n - 1; r > 0; --r) {
    vector<int> np(n);
    for (int i = 0; i < n; ++i) {
      if (p[i] < m) {
        np[i] = (p[i] + r) % n;
      } else {
        np[i] = (p[i] + n - r) % n;
      }
    }
    p = np;
  }
  for (int i = 0; i < n; ++i) {
    cerr << p[i] << ' ';
  }
  cerr << '\n';
}

int step(int x, int r) {
  if (x < m) {
    x += r;
    if (x >= n) {
      x -= n;
    }
  } else {
    x -= r;
    if (x < 0) {
      x += n;
    }
  }
  return x;
}

const int maxn = 100100;
int pre[maxn];
int lp[maxn];
int its = 0;

int go(int x, ll t, int c = 0) {
  if (t % n) {
    return go(step(x, t % n), t - 1);
  }
  if (t == 0) {
    return x;
  }
  if (pre[x] != -1) {
    if (c != -1) {
      return go(x, t % ((c - lp[x]) * n), -1);
    } else {
      return go(pre[x], t - n, -1);
    }
  }
  ++its;
  int y = x;
  for (int r = n - 1; r > 0; --r) {
    y = step(y, r);
  }
  pre[x] = y;
  lp[x] = c;
  return go(y, t - n, c + 1);
}

signed main() {
#ifdef LOCAL
  assert(freopen("g.in", "r", stdin));
#endif
  int s;
  ll t;
  cin >> n >> m >> s >> t;
  for (int i = 0; i < n; ++i) {
    pre[i] = -1;
  }
  cout << go(s - 1, t) + 1 << '\n';
  assert(its < 200);
  cerr << "iters: " << its << '\n';
}