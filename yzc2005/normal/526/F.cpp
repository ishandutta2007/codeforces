#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
}
const int N = 3e5 + 5;
struct SegmentTree {
  int l[N << 2], r[N << 2];
  int val[N << 2], cnt[N << 2], lzy[N << 2];
  #define mid (l[p] + r[p] >> 1)
  #define ls p << 1
  #define rs p << 1 | 1
  void build(int p, int L, int R) {
    l[p] = L;
    r[p] = R;
    val[p] = L;
    cnt[p] = 1;
    if (L == R) {
      return;
    }
    build(ls, L, mid);
    build(rs, mid + 1, R);
  }
  inline void pushup(int p) {
    val[p] = min(val[ls], val[rs]);
    cnt[p] = (val[p] == val[ls]) * cnt[ls] + (val[p] == val[rs]) * cnt[rs];
  }
  inline void tag(int p, int v) {
    val[p] += v;
    lzy[p] += v;
  }
  inline void pushdown(int p) {
    if (lzy[p]) {
      tag(ls, lzy[p]);
      tag(rs, lzy[p]);
      lzy[p] = 0;
    }
  }
  void modify(int p, int L, int R, int v) {
    if (L <= l[p] && r[p] <= R) {
      return tag(p, v);
    }
    pushdown(p);
    if (mid >= L) {
      modify(ls, L, R, v);
    } 
    if (mid < R) {
      modify(rs, L, R, v);
    }
    pushup(p);
  }
} smt;
int n, a[N];
int s1[N], t1, s2[N], t2; 
int main() {
  read(n);
  for (int i = 1, x, y; i <= n; ++i) {
    read(x), read(y);
    a[x] = y;
  }
  smt.build(1, 1, n);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    smt.tag(1, -1);
    while (t1 && a[s1[t1]] > a[i]) {
      smt.modify(1, s1[t1 - 1] + 1, s1[t1], a[s1[t1]] - a[i]);
      --t1;
    } 
    while (t2 && a[s2[t2]] < a[i]) {
      smt.modify(1, s2[t2 - 1] + 1, s2[t2], a[i] - a[s2[t2]]);
      --t2;
    }
    ans += smt.cnt[1];
    s1[++t1] = i;
    s2[++t2] = i;
  }
  printf("%lld\n", ans);
  return 0;
}