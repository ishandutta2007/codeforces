#include <bits/stdc++.h>
const int N = 200005, K = 5;
int n, q, k, a[K];
struct SegmentTree {
  int val[N << 2];
  SegmentTree () {
    std::memset(val, 0xcf, sizeof(val));
  }
  void modify(int p, int l, int r, int pos, int add) {
    if (l == r) {
      val[p] = add;
      return;
    }
    int mid = l + r >> 1;
    if (mid >= pos) {
      modify(p << 1, l, mid, pos, add);
    } else {
      modify(p << 1 | 1, mid + 1, r, pos, add);
    }
    val[p] = std::max(val[p << 1], val[p << 1 | 1]);
  }
  int query(int p, int l, int r, int L, int R) {
    if (l >= L && r <= R) {
      return val[p];
    }
    int mid = l + r >> 1;
    if (mid >= L && mid < R) {
      return std::max(query(p << 1, l, mid, L, R), query(p << 1 | 1, mid + 1, r, L, R));
    } else if (mid >= L) {
      return query(p << 1, l, mid, L, R);
    } else {
      return query(p << 1 | 1, mid + 1, r, L, R);
    }
  }
} smt[1 << K];
int main() {
  scanf("%d%d", &n, &k);
  for (int pos = 1; pos <= n; ++pos) {
    for (int i = 0; i < k; ++i) {
      scanf("%d", &a[i]);
    }
    for (int s = 0; s < 1 << k; ++s) {
      int val = 0;
      for (int i = 0; i < k; ++i) {
        if (s >> i & 1) {
          val += a[i];
        } else {
          val -= a[i];
        }
      } 
      smt[s].modify(1, 1, n, pos, val);
    }  
  }
  scanf("%d", &q);
  for (int t = 1; t <= q; ++t) {
    int op;
    scanf("%d", &op);
    if (op & 1) {
      int pos;
      scanf("%d", &pos);
      for (int i = 0; i < k; ++i) {
        scanf("%d", &a[i]);
      }
      for (int s = 0; s < 1 << k; ++s) {
        int val = 0;
        for (int i = 0; i < k; ++i) {
          if (s >> i & 1) {
            val += a[i];
          } else {
            val -= a[i];
          }
        } 
        smt[s].modify(1, 1, n, pos, val);
      }
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      int ans = 0;
      for (int s = 0; s < 1 << k - 1; ++s) {
        ans = std::max(ans, smt[s].query(1, 1, n, l, r) + smt[s ^ ((1 << k) - 1)].query(1, 1, n, l, r));
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}