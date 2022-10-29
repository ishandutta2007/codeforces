#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 300000 + 10;

void setA(double a[2][2]) {
  a[0][0] = a[1][1] = 1;
  a[0][1] = a[1][0] = 0;
}
void setY(double y[2]) {
  y[0] = y[1] = 0;
}
struct Node {
  double a[2][2];
  double x[2], y[2];
  bool ok;
  void push(double va[2][2], double vy[2]) {
    double c[2][2];
    for (int i = 0; i < 2; ++ i) {
      for (int j = 0; j < 2; ++ j) {
        c[i][j] = 0;
        for (int k = 0; k < 2; ++ k) {
          c[i][j] += a[i][k] * va[k][j];
        }
      }
    }
    double s = va[0][0] * y[0] + va[0][1] * y[1];
    double t = va[1][0] * y[0] + va[1][1] * y[1];
    y[0] = s + vy[0]; y[1] = t + vy[1];

    s = va[0][0] * x[0] + va[0][1] * x[1];
    t = va[1][0] * x[0] + va[1][1] * x[1];
    x[0] = s + vy[0]; x[1] = t + vy[1];
    for (int i = 0; i < 2; ++ i) {
      for (int j = 0; j < 2; ++ j) {
        a[i][j] = c[i][j];
      }
    }
    ok = 1;
  }
} T[MAXN << 2];

#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
void psd(int rt) {
  if (T[rt].ok) {
    T[lson].push(T[rt].a, T[rt].y);
    T[rson].push(T[rt].a, T[rt].y);
    T[rt].ok = 0;
    setA(T[rt].a); setY(T[rt].y);
  }
}
void build(int rt, int l, int r) {
  setA(T[rt].a); setY(T[rt].y);
  T[rt].ok = 0;
  if (l + 1 == r) {
    T[rt].x[0] = l;
    T[rt].y[0] = 0;
    return;
  }
  build(rson, mid, r);
  build(lson, l, mid);
}
void ins(int rt, int l, int r, int L, int R, double a[2][2], double y[]) {
  if (L <= l && R >= r) {
    T[rt].push(a, y);
    return;
  }
  psd(rt);
  if (L < mid) ins(lson, l, mid, L, R, a, y);
  if (R > mid) ins(rson, mid, r, L, R, a, y);
}
double ss, tt;
void ask(int rt, int l, int r, int x) {
  if (l + 1 == r) {
    ss = T[rt].x[0];
    tt = T[rt].x[1];
    return;
  }
  psd(rt);
  if (x < mid) ask(lson, l, mid, x);
  else ask(rson, mid, r, x);
}
int main() {
  int n, m; scanf("%d%d", &n, &m);
  build(1, 0, n + 1);
  for (int i = 0; i < m; ++ i) {
    int op; scanf("%d", &op);
    double A[2][2], Y[2];
    setA(A); setY(Y);
    if (op == 1) {
      int x, l; scanf("%d%d", &x, &l);
      ask(1, 0, n + 1, x - 1);
      double x1 = ss, y1 = tt;
      ask(1, 0, n + 1, x);
      double x2 = ss, y2 = tt;
      double len = hypot(x1 - x2, y1 - y2);
      Y[0] = (x2 - x1) / len * l;
      Y[1] = (y2 - y1) / len * l;
      ins(1, 0, n + 1, x, n + 1, A, Y);
    } else {
      int x, a; scanf("%d%d", &x, &a);
      a = 360 - a;
      double aa = a / 180.0 * acos(-1.0);
      A[0][0] = cos(aa); A[0][1] = -sin(aa);
      A[1][0] = sin(aa); A[1][1] = cos(aa);
      ask(1, 0, n + 1, x - 1);
      ins(1, 0, n + 1, x, n + 1, A, Y);
      Y[0] = A[0][0] * -ss + A[0][1] * -tt;
      Y[1] = A[1][0] * -ss + A[1][1] * -tt;
      Y[0] += ss; Y[1] += tt;
      setA(A);
      ins(1, 0, n + 1, x, n + 1, A, Y);
    }
    ask(1, 0, n + 1, n);
    printf("%.10f %.10f\n", ss, tt);
  }
  return 0;
}