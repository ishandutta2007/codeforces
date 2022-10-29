#include <bits/stdc++.h>
using namespace std;

namespace ST {
  const int SIZE = 200000 + 10;
  int ls[SIZE], rs[SIZE], cnt[SIZE], sz;
  void init() {
    ls[0] = rs[0] = cnt[0] = 0; sz = 1;
  }
  int ins(int o, int l, int r, int x) {
    int p = sz++; cnt[p] = cnt[o] + 1;
    ls[p] = ls[o], rs[p] = rs[o];
    if (l + 1 == r) return p;
    int m = (l + r) >> 1;
    if (x < m) ls[p] = ins(ls[o], l, m, x);
    else rs[p] = ins(rs[o], m, r, x);
    return p;
  }
  int ask(int a, int b, int l, int r, int x) { // >= x
    if (x <= l) return cnt[a] - cnt[b];
    int m = (l + r) >> 1, ret = 0;
    if (x >= m) return ask(rs[a], rs[b], m, r, x);
    else return ask(ls[a], ls[b], l, m, x) + cnt[rs[a]] - cnt[rs[b]];
  }
}

const int MAXN = 3000 + 10;
char s[MAXN][MAXN];
int zl[MAXN][MAXN], zr[MAXN][MAXN];
int rt[MAXN], n, m;

int calc(int d) {
  int l = max(1, d - m), r = min(n, d - 1);
  ST::init(); rt[l - 1] = 0;
  int ret = 0;
  for (int x = l, y; x <= r; ++x) {
    if (s[x][y = d - x] == '.') rt[x] = 0, l = x + 1;
    else {
      rt[x] = ST::ins(rt[x - 1], 0, m + n, x + zl[x][y] - 1);
      ret += ST::ask(rt[x], rt[max(l - 1, x - zr[x][y])], 0, m + n, x);
    }
  }
  return ret;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i][j] == 'z') zl[i][j] = zl[i][j - 1] + 1;
      else zl[i][j] = 0;
    }
    for (int j = m; j >= 1; --j) {
      if (s[i][j] == 'z') zr[i][j] = zr[i][j + 1] + 1;
      else zr[i][j] = 0;
    }
  }
  long long ret = 0;
  for (int d = 2; d <= n + m; ++d) {
    ret += calc(d);
  }
  cout << ret << endl;
  return 0;
}