#include <bits/stdc++.h>
using namespace std;

const int N = 20005, K = 16, L = 32;
int n, q, lg[N], r[N], st[K][N], to[N][K][L];

inline int better(int i, int j) {return r[i] < r[j] ? j : i;}
inline void up(int &x, const int y) {if (r[x] < r[y]) x = y;}
inline int query(int l, int r) {
  int k = lg[r - l + 1];
  return better(st[k][l], st[k][r - (1 << k) + 1]);
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &r[i]);
    r[i] = min(i + r[i], n);
    st[0][i] = i;
  }
  for (int i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
  for (int k = 1; k < K; ++k)
    for (int i = 1; i + (1 << k) - 1 <= n; ++i)
      st[k][i] = better(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
  for (int i = 1; i <= n; ++i)
    for (int l = 0; l < L; ++l)
      to[i][0][l] = query(i, min(r[i] + l, n));
  for (int k = 1; k < K; ++k)
    for (int i = 1; i <= n; ++i) 
      for (int x = 0; x < L; ++x)
        for (int y = 0; x + y < L; ++y)
          up(to[i][k][x + y], to[to[i][k - 1][x]][k - 1][y]);
  while (q--) {
    int i, j, l; 
    scanf("%d%d%d", &i, &j, &l);
    if (i == j) puts("0");
    else if (r[i] + l >= j) puts("1");
    else {
      int cur[L], res = 0;
      memset(cur, 0, sizeof cur);
      cur[0] = i;
      for (int k = K - 1; ~k; --k) {
        int nxt[L], pos = 0;
        memset(nxt, 0, sizeof nxt);
        for (int x = 0; x <= l; ++x)
          for (int y = 0; x + y <= l; ++y) 
            up(nxt[x + y], to[cur[x]][k][y]);
        for (int x = 0; x <= l; ++x) pos = max(pos, r[nxt[x]] + l - x);
        if (pos < j) {
          res += (1 << k);
          memcpy(cur, nxt, sizeof cur);
        }
      }
      printf("%d\n", res + 2);
    }
  }
  return 0;
}