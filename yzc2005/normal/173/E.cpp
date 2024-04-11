#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = N * 3;
int n, m, k, q, p[M], v[N];
struct FenwickTree {
  int sum[M];
  inline void add(int p) {
    for (; p <= m; p += p & -p) {
      ++ sum[p];
    }
  }
  inline int query(int p) {
    int res = 0;
    for (; p; p -= p & -p) {
      res += sum[p];
    }
    return res;
  }
} bit;
struct node {
  int id, x, y, l, r;
} a[N];
int rev[N];
struct query {
  int l, r, id;
}; vector<query> que[N];
int ans[N];
struct SegmentTree {
  int val[M << 2];
  void modify(int p, int l, int r, int pos, int v) {
    if (l == r) {
      val[p] = max(val[p], v);
      return;
    }
    int mid = l + r >> 1;
    if (mid >= pos) {
      modify(p << 1, l, mid, pos, v);
    } else {
      modify(p << 1 | 1, mid + 1, r, pos, v);
    }
    val[p] = max(val[p << 1], val[p << 1 | 1]);
  }
  int query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
      return val[p];
    }
    int mid = l + r >> 1;
    if (mid >= ql && mid < qr) {
      return max(query(p << 1, l, mid, ql, qr), query(p << 1 | 1, mid + 1, r, ql, qr));
    } else if (mid >= ql) {
      return query(p << 1, l, mid, ql, qr);
    } else {
      return query(p << 1 | 1, mid + 1, r, ql, qr);
    }
  }
} smt;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i].x);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i].y);
    p[++m] = a[i].y;
    p[++m] = a[i].l = max(a[i].y - k, 0);
    p[++m] = a[i].r = a[i].y + k;
    a[i].id = i;
  }
  sort(a + 1, a + n + 1, [&](node x, node y) {
    return x.x > y.x;
  });
  sort(p + 1, p + m + 1);
  m = unique(p + 1, p + m + 1) - p - 1;
  for (int i = 1; i <= n; ++i) {
    rev[a[i].id] = i;
    auto get = [&](int &x) {
      x = lower_bound(p + 1, p + m + 1, x) - p;
    };
    get(a[i].y);
    get(a[i].l);
    get(a[i].r);
  }
  for (int r = n, l; r; r = l - 1) {
    for (l = r; l > 1 && a[l].x == a[l - 1].x; --l);
    for (int i = l; i <= r; ++i) {
      bit.add(a[i].y);
    }
    for (int i = l; i <= r; ++i) {
      v[i] = bit.query(a[i].r) - bit.query(a[i].l - 1);
    }
  }
  scanf("%d", &q);
  for (int i = 1, x, y; i <= q; ++i) {
    scanf("%d%d", &x, &y);
    x = rev[x];
    y = rev[y];
    if (x > y) {
      swap(x, y);
    }
    int l = max(a[x].l, a[y].l), r = min(a[x].r, a[y].r);
    if (l <= r) {
      que[x].push_back((query) {l, r, i});
    }
  }
  for (int l = 1, r; l <= n; l = r + 1) {
    for (r = l; r < n && a[r].x == a[r + 1].x; ++r);
    for (int i = l; i <= r; ++i) {
      smt.modify(1, 1, m, a[i].y, v[i]);
    }
    for (int i = l; i <= r; ++i) {
      for (auto q : que[i]) {
        ans[q.id] = smt.query(1, 1, m, q.l, q.r);
      }
    }
  }
  for (int i = 1; i <= q; ++i) {
    if (!ans[i]) {
      ans[i] = -1;
    }
    printf("%d\n", ans[i]);
  }
  return 0;
}