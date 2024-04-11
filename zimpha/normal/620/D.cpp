#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2000 + 10;

struct Node {
  LL v;
  int i, j;
  bool operator < (const Node &rhs) const {
    return v < rhs.v;
  }
} X[MAXN * MAXN], Y[MAXN * MAXN];
int a[MAXN], b[MAXN], n, m;
LL sa, sb;

void solve(int a[], int n, int b[], int m, int o) {
  sa = sb = 0;
  for (int i = 0; i < n; ++ i) sa += a[i];
  for (int i = 0; i < m; ++ i) sb += b[i];
  vector<PII> ot;
  LL v = abs(sa - sb);
  // swap 1
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < m; ++ j) {
      LL ta = sa - a[i] + b[j];
      LL tb = sb - b[j] + a[i];
      if (abs(ta - tb) < v) {
        v = abs(ta-  tb);
        ot.clear();
        ot.push_back(PII(i + 1, j + 1));
      }
    }
  }
  // swap 2
  int ca = 0, cb = 0;
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < i; ++ j) {
      X[ca ++] = (Node){(a[i] + a[j]) * 2ll, i + 1, j + 1};
    }
  }
  for (int i = 0; i < m; ++ i) {
    for (int j = 0; j < i; ++ j) {
      Y[cb ++] = (Node){(b[i] + b[j]) * 2ll, i + 1, j + 1};
    }
  }
  sort(X, X + ca); sort(Y, Y + cb);
  LL s = sa - sb;
  for (int i = 0; i < ca; ++ i) {
    int j = lower_bound(Y, Y + cb, (Node){X[i].v - s, 0, 0}) - Y;
    if (j != cb) {
      LL tp = s - (X[i].v - Y[j].v);
      if (tp < v) {
        v = tp;
        ot.clear();
        ot.push_back(PII(X[i].i, Y[j].i));
        ot.push_back(PII(X[i].j, Y[j].j));
      }
    }
    -- j;
    if (j >= 0) {
      LL tp = abs(s - (X[i].v - Y[j].v));
      if (tp < v) {
        v = tp;
        ot.clear();
        ot.push_back(PII(X[i].i, Y[j].i));
        ot.push_back(PII(X[i].j, Y[j].j));
      }
    }
  }
  printf("%lld\n", v);
  printf("%d\n", (int)ot.size());
  for (auto &x: ot) {
    if (o) swap(x.first, x.second);
    printf("%d %d\n", x.first, x.second);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    scanf("%d", a + i);
    sa += a[i];
  }
  scanf("%d", &m);
  for (int i = 0; i < m; ++ i) {
    scanf("%d", b + i);
    sb += b[i];
  }
  if (sa < sb) solve(b, m, a, n, 1);
  else solve(a, n, b, m, 0);
  return 0;
}