#include <bits/stdc++.h>
const int N = 200005;
int n, k, d, a[N], b[N], l = 1, r = 1;
struct SegmentTree {
  int l[N << 2], r[N << 2], min[N << 2], val[N << 2];
  void build(int p, int L, int R) {
    l[p] = L;
    r[p] = R;
    min[p] = L;
    val[p] = 0;
    if (L ^ R) {
      int mid = L + R >> 1;
      build(p << 1, L, mid);
      build(p << 1 | 1, mid + 1, R);
    }
  }
  inline void pushup(int p) {
    min[p] = std::min(min[p << 1], min[p << 1 | 1]);
  }
  inline void tag(int p, int v) {
    min[p] += v;
    val[p] += v;
  }
  inline void pushdown(int p) {
    if (val[p]) {
      tag(p << 1, val[p]);
      tag(p << 1 | 1, val[p]);
      val[p] = 0;
    }
  }
  void modify(int p, int L, int R, int v) {
    if (l[p] >= L && r[p] <= R) {
      tag(p, v);
      return;
    }
    pushdown(p);
    int mid = l[p] + r[p] >> 1;
    if (mid >= L) {
      modify(p << 1, L, R, v);
    } 
    if (mid < R) {
      modify(p << 1 | 1, L, R, v);
    }
    pushup(p);
  }
  int query(int p, int L, int R, int v) {
    if (l[p] > R || r[p] < L || min[p] > v) {
      return 1e9;
    }
    if (l[p] == r[p]) {
      return l[p];
    }
    pushdown(p);
    int pos = query(p << 1, L, R, v);
    if (pos != 1e9) {
      return pos;
    } else {
      return query(p << 1 | 1, L, R, v);
    }
  }
} smt;
void solve(int *a, int n, int s) {
  smt.build(1, 1, n);
  static int s1[N], s2[N];
  int t1 = 0, t2 = 0, pos = 0; 
  static std::map<int, int> last;
  last.clear();
  for (int i = 1; i <= n; ++i) {
    for (; t1 && a[s1[t1]] >= a[i]; --t1) {
      smt.modify(1, s1[t1 - 1] + 1, s1[t1], a[s1[t1]] - a[i]);
    }
    s1[++t1] = i;
    for (; t2 && a[s2[t2]] <= a[i]; --t2) {
      smt.modify(1, s2[t2 - 1] + 1, s2[t2], a[i] - a[s2[t2]]);
    }
    s2[++t2] = i;
    if (last.count(a[i])) {
      pos = std::max(pos, last[a[i]]);
    }
    last[a[i]] = i;
    int left = smt.query(1, pos + 1, i, k + i);
    if (i - left > r - l) {
      l = s + left;
      r = s + i;
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &k, &d);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  if (d == 0) {
    int l = 1, r = 1;
    for (int i = 1, j; i <= n; i = j + 1) {
      for (j = i; j < n && a[j] == a[j + 1]; ++j);
      if (j - i > r - l) {
        l = i, r = j;
      }
    }
    printf("%d %d\n", l, r);
    return 0;
  } 
  for (int i = 1; i <= n; ++i) {
    b[i] = (a[i] % d + d) % d;
    a[i] = (a[i] - b[i]) / d;
  }
  for (int i = 1, j = 1; i <= n; i = j) {
    for (; j <= n && b[j] == b[i]; ++j);
    solve(a + i - 1, j - i, i - 1);
  }
  printf("%d %d\n", l, r);
  return 0;
}